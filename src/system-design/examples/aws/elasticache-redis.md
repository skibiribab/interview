# Amazon ElastiCache for Redis (service drill)

**Parent:** [`README.md`](./README.md) · **Topic:** [`../../topics/caching.md](../../topics/caching.md)

## When to use / when not

| Use when | Notes |
| --- | --- |
| Sub-ms reads for hot keys | Sessions, rate counters, feed cache |
| TTL eviction | Cache-aside or write-through |
| Atomic INCR | Rate limiting token bucket |

| Avoid when | Why |
| --- | --- |
| Source of truth without DB behind | Cache is ephemeral |
| Huge values (> 512 MB per key practical limits) | Split or use S3 |
| Multi-region strong consistency | Redis Global Datastore has tradeoffs |

## Mental model

- **Cluster mode:** shards + replicas; hash slots.
- **Eviction:** volatile-lru etc. when memory full.
- **Billing:** node hours by instance type + memory.

## Architecture sketch

```mermaid
flowchart TB
 api[App · ECS]
 redis[(ElastiCache Redis)]
 db[(Aurora / DynamoDB)]

 api -->|cache-aside read| redis
 api -->|miss| db
 api -->|populate| redis

 class api app
 class redis data
 class db data

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
```

**Narrative:** **Cache-aside:** read Redis first; on miss load DB and set TTL. Rate limiters use **atomic** ops on counters without touching OLTP per check.

## Capacity and cost (whiteboard)

| What to count | Meter | Ballpark |
| --- | --- | --- |
| Nodes | cache.r6g.large × 730h | $100+/mo per node |
| Memory tier | total GB | size for working set |

## Interview talking points

1. **Stampede:** singleflight / probabilistic early expiration.
2. **Hot key:** client-side sharding of counter in Redis.
3. State **lost on failover** — design idempotent rebuild.

## Product examples that use this service

| Example | How it shows up |
| --- | --- |
| [`platform/url-shortener.md`](../platform/url-shortener.md) | Redirect cache |
| [`platform/rate-limiter.md`](../platform/rate-limiter.md) | Distributed counters |
| [`social/news-feed.md`](../social/news-feed.md) | Per-user feed materialization |

## Related

- [AWS service drills index](./README.md)
- [AWS reference layout](../../topics/aws-reference-layout.md)
- [Topics index](../../topics-index.md)
- [Cloud capability matrix](../../topics/cloud-capability-matrix.md)
