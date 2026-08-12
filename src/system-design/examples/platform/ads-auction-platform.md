# Ads auction and pacing platform

## Introduction

Real-time **ad auction** selects sponsored placements in feed/search with **budget pacing**, **frequency caps**, and **billing events**. Latency budget is tens of milliseconds inside the request path.

**Primary users:** advertisers (campaigns), publishers (inventory), finance (billing).

**Interview pacing:** Deep dive **RTB auction + pacing + frequency cap**.

## Requirements discovery

| Lock (target) |
| --- |
| 500k ad requests/s peak |
| Auction p99 &lt; 50 ms |
| Daily budget pacing smooth |
| Frequency cap 3 impressions / user / day / campaign |

## Architecture (user → database)

```mermaid
flowchart TB
 user([End user])
 pub[Publisher API]
 auction[Auction service · ECS]
 redis[(Redis · counters pacing)]
 ddb[(DynamoDB · campaigns)]
 stream[[MSK · impression events]]

 user --> pub --> auction
 auction --> redis
 auction --> ddb
 auction -.->|win notice| stream

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
 class user user
 class pub,auction app
 class redis,ddb data
 class stream async
```

**Narrative:** Each ad slot runs **second-price** or **first-price** auction among eligible campaigns passing **pacing** and **frequency** checks in Redis. **Impression/click** events stream to billing.

## Deep dive: pacing + auction

- **Pacing token bucket** per campaign per day.
- **Filter** ineligible (geo, device, budget exhausted).
- **eCPM rank** = bid × predicted CTR.

## Related

- [Feed ranking](../social/feed-ranking-service.md)
- [News feed](../social/news-feed.md)
- [ElastiCache drill](../aws/elasticache-redis.md)
