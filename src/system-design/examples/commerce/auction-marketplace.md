# Auction marketplace (eBay)

## Introduction

An auction marketplace runs **timed bids**, **proxy bidding**, and **anti-sniping** extensions — different from fixed-price [shopping cart](./shopping-cart-checkout.md) and [event ticketing](./event-ticketing.md) (inventory count).

**Company anchors:** eBay, Sotheby’s online.

## Requirements discovery

| Lock (target) |
| --- |
| 10M active auctions |
| Bid accepted p99 &lt; 50 ms |
| Strong ordering per `auction_id` |
| Snipe window: extend 2 min if bid in last 30 s |

## Architecture (user → database)

```mermaid
flowchart TB
 bidder([Bidder])
 api[Auction API · ECS]
 engine[Bid processor · ECS]
 auctions[(Aurora · auctions)]
 bids[(DynamoDB · bids)]
 leader[(Redis · current high bid)]

 bidder --> api --> engine
 engine --> leader
 engine --> bids
 engine --> auctions
 api --> auctions

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
 class bidder user
 class api,engine app
 class auctions,bids,leader data
```

**Narrative:** **Bid processor** serializes per `auction_id` (shard lock). Compare amount to **Redis** high bid; persist row in **DynamoDB**; update **Aurora** auction state. **Scheduler** closes auction at `end_time` (+ extension rules).

## Deep dive

- **Proxy bid:** store max bid; engine raises to second-price + increment.
- **Idempotency:** `bid_id` from client.
- Hot auction: compare [event ticketing](./event-ticketing.md).

## Related

- [Event ticketing](./event-ticketing.md)
- [Marketplace listings](./marketplace-listings.md)
- [ElastiCache drill](../aws/elasticache-redis.md)
