# Travel booking platform (Airbnb / Booking.com)

## Introduction

Travel booking combines **search** (geo + dates), **inventory holds**, and **payment capture** — extends [marketplace listings](./marketplace-listings.md) with **date-range availability** and **cancellation policies**.

**Company anchors:** Airbnb, Booking.com, Expedia.

## Requirements discovery

| Lock (target) |
| --- |
| 50M listings |
| Search p99 &lt; 400 ms (city + dates) |
| Hold 15 min during checkout |
| Double-booking must be impossible |

## Architecture (user → database)

```mermaid
flowchart TB
 guest([Guest])
 host([Host])
 api[Booking API · ECS]
 search[Search · ECS]
 cal[(DynamoDB · availability calendar)]
 listings[(Aurora · listings)]
 holds[(DynamoDB · booking holds)]
 pay[Payment service]

 guest --> search --> listings
 search --> cal
 guest --> api --> holds --> cal
 api --> pay
 host --> api --> listings

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
 class guest,host user
 class api,search,pay app
 class cal,listings,holds data
```

**Narrative:** **Calendar** stores per-listing day bitmap or interval tree. **Hold** is conditional write on date range. **Search** filters geo index then availability intersection.

## Deep dive

- **Hold TTL** + sweep for expired holds.
- **Pricing** dynamic per night (defer ML).
- Link [payment workflow](../fintech/payment-workflow-platform.md).

## Related

- [Marketplace listings](./marketplace-listings.md)
- [Event ticketing](./event-ticketing.md) (inventory pressure)
- [Product search](./product-search.md)
