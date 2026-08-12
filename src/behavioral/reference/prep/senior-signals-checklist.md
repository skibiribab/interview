# Senior backend signals checklist

Comfort scale: `0-unknown`, `1-read`, `2-toy`, `3-debugged`, `4-owned-in-prod`, `5-taught-others`

| Signal | Drill issue | Theory note | Practice anchor | Comfort |
| --- | --- | --- | --- | --- |
| Idempotency | #12 | Required for safe retries and duplicate events | API and workflow retry patterns | 4 |
| Retries | #11, #17 | Retry with backoff + bounded attempts | Incident and async processing workflows | 4 |
| Eventual consistency | #8, #18, #20 | Distributed systems rely on convergent state | Payment/inventory consistency tradeoffs | 3 |
| Observability | #14 | Metrics + logs + traces + correlation IDs | Production troubleshooting | 4 |
| Backpressure | #16, #22 | Control overload to preserve system health | Queue and worker scaling discussions | 3 |
| Rate limiting | #26 | Protect shared dependencies and abuse surfaces | API guardrails and quota designs | 4 |
| Partitioning/sharding | #8, #16, #20 | Throughput and isolation strategy | Event and data distribution design | 3 |
| Failure recovery | #15, #17 | Compensation and runbooks for partial failures | Incident response and process hardening | 4 |
| Queue semantics | #10, #11, #13 | Transport guarantees vs business guarantees | Async architecture and replay safety | 4 |
| Schema evolution | #9, #24 | Backward compatibility for independent deploys | API/event contract management | 3 |
| Cost/performance tradeoffs | #16, #26, #28 | Balance latency, throughput, and cost | Scaling and optimization discussions | 3 |
| Concurrency control | #19, #20 | Locks/versioning/leases to avoid lost updates | Cart and inventory race-condition handling | 3 |
| Data modeling | #17, #19, #24 | Models should reflect access patterns and invariants | Service and workflow data modeling | 4 |
| Cache invalidation | #22, #25, #26 | Correctness plus freshness under distributed caches | Config/cache update experience | 3 |

## Usage

- Review this table before system design interviews.
- Any row rated 4+ should always have a concrete story ready.
