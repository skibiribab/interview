# Two-sided marketplace listings

## Introduction

Marketplace connects **sellers** listing goods/services with **buyers** searching and booking. Core challenges: **listing CRUD**, **geo search**, **availability holds**, and **trust** (reviews link).

**Primary users:** sellers (listings), buyers (search/book), ops (fraud, featured slots).

**Interview pacing:** Deep dive **listings index + geo search + booking hold**.

## Requirements discovery

| Lock (target) |
| --- |
| 10M active listings |
| 1M searches / day |
| Hold TTL 15 min for booking |
| Geo radius search p99 &lt; 300 ms |

## Architecture (user → database)

```mermaid
flowchart TB
 buyer([Buyer])
 seller([Seller])
 api[Marketplace API · ECS]
 os[(OpenSearch · listings)]
 listings[(Aurora · listings)]
 holds[(DynamoDB · holds)]

 seller --> api --> listings
 listings -.->|CDC| os
 buyer --> api --> os
 buyer -->|book| api --> holds

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
 class buyer,seller user
 class api app
 class os,listings,holds data
```

**Narrative:** **Listings** in Aurora indexed to **OpenSearch** with geo_point. **Booking** creates TTL **hold** in DynamoDB before payment capture.

## Deep dive: geo + hold

- **Geo filter** + sort by distance/score.
- **Hold** conditional write prevents double booking.
- Link [reviews](./reviews-ratings.md) and [product search](./product-search.md).

## Related

- [Event ticketing](./event-ticketing.md) (hot inventory contrast)
- [Product search](./product-search.md)
- [Payment workflow](../fintech/payment-workflow-platform.md)
