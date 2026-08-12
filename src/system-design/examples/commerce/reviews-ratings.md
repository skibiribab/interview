# Reviews and ratings aggregation

## Introduction

Product **reviews** accept text + star ratings; the system maintains **aggregates** (histogram, average), **helpful votes**, and **fraud** signals for display on PDP and search.

**Primary users:** buyers (submit/read), moderators (flag), merchandising (sort order).

**Interview pacing:** Deep dive **aggregate consistency + fraud + read path**.

## Requirements discovery

| Lock (target) |
| --- |
| 100M products with reviews |
| 10M new reviews / month |
| Display aggregate stale &lt; 60 s |
| Helpful vote idempotent |

## Architecture (user → database)

```mermaid
flowchart TB
 buyer([Buyer])
 api[Review API · ECS]
 primary[(Aurora · reviews)]
 agg[(DynamoDB · aggregates)]
 stream[[SQS · aggregate workers]]

 buyer --> api --> primary
 primary -.-> stream --> agg
 api -->|read summary| agg

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
 class buyer user
 class api app
 class primary,agg data
 class stream async
```

**Narrative:** Writes append to **Aurora**; async workers recompute **histogram + average** in DynamoDB. Reads hit precomputed aggregate for fast PDP.

## Deep dive: aggregates under concurrency

- **Atomic increment** per star bucket; recompute average from histogram.
- **Fraud:** velocity limits, device graph, hold suspicious for moderation.
- **Eventual** display OK with “pending moderation” state.

## Related

- [Product search](./product-search.md)
- [Shopping cart](./shopping-cart-checkout.md)
- [SQS/SNS drill](../aws/sqs-sns.md)
