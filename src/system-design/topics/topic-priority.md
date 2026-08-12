# Frequency tiers - System Design

Source anchors:
- `../README.md`
- `examples/README.md`
- `topics/cloud-services.md`

Comfort scale: `0-unknown`, `1-read`, `2-toy`, `3-debugged`, `4-owned-in-prod`, `5-taught-others`

| Tier | Topic | Typical prompt | Primary issue | Repo anchor | Comfort |
| --- | --- | --- | --- | --- | --- |
| A | Event-driven order pipeline | Design an order lifecycle at scale | #8 | `topics/messaging-async.md` | 3 |
| A | Transactional outbox | Avoid dual-write inconsistency | #10 | `topics/messaging-async.md` | 3 |
| A | Idempotency | Safe retries for APIs/webhooks | #12 | `topics/api-design.md` | 4 |
| A | Delivery semantics | Exactly-once vs at-least-once | #13 | `topics/messaging-async.md` | 3 |
| A | Payment orchestration | Authorize/capture/refund workflow | #17 | `examples/fintech/payment-workflow-platform.md` | 3 |
| A | Cart consistency | Two-device cart conflicts | #19 | `examples/commerce/shopping-cart-checkout.md` | 2 |
| A | Notification fan-out | Multi-channel notifications | #22 | `examples/platform/notification-platform.md` | 3 |
| A | API gateway + rate limiting | Distributed throttling | #26 | `examples/platform/rate-limiter.md` | 4 |
| A | Observability across async | Trace and correlate events | #14 | `topics/messaging-async.md` | 3 |
| A | Failure recovery | Partial failure and compensation | #15 | `examples/infra/workflow-orchestration.md` | 3 |
| B | Consumer autoscaling | Lag-based scale policy | #16 | `topics/compute.md` | 2 |
| B | Multi-region inventory | Global reservations and TTL | #20 | `examples/commerce/multi-region-inventory-reservation.md` | 2 |
| B | Real-time delivery tracking | Websocket + pub/sub tracking | #21 | `topics/compute.md` | 2 |
| B | Distributed scheduler | Leases and retries | #23 | `examples/platform/distributed-job-scheduler.md` | 2 |
| B | Cross-service audit logging | Immutable audit/replay | #24 | `topics/security-networking.md` | 2 |
| B | Feature flag platform | Rollout and kill switch | #25 | `topics/data-stores.md` | 2 |
| B | Dispatch matching | Courier assignment under load | #27 | `examples/logistics/delivery-dispatch-matching.md` | 1 |
| B | ETA prediction | Prediction + smoothing loop | #28 | `examples/logistics/eta-prediction-service.md` | 1 |
| C | Schema versioning governance | Safe contract upgrades | #9 | `topics/messaging-async.md` | 3 |
| C | DLQ/replay governance | Poison message runbooks | #11 | `topics/messaging-async.md` | 3 |
| C | Payment architecture deep dive | 2PC vs saga patterns | #18 | `examples/event-driven/event-driven-order-pipeline.md` | 3 |
| A | Product search | Catalog search + typeahead | — | `examples/commerce/product-search.md` | 2 |
| A | Identity / sessions | Login, OAuth, JWT rotation | — | `examples/platform/identity-session-service.md` | 2 |
| A | Rideshare matching | Uber-class supply/demand | — | `examples/logistics/rideshare-matching.md` | 2 |
| B | Subscription billing | Renewals + dunning | — | `examples/fintech/subscription-billing.md` | 2 |
| B | Feed ranking | Personalized For You | — | `examples/social/feed-ranking-service.md` | 2 |
| B | Ads auction | RTB + pacing | — | `examples/platform/ads-auction-platform.md` | 1 |
| B | Reviews aggregates | Star histogram + fraud | — | `examples/commerce/reviews-ratings.md` | 2 |
| B | Transactional email | SMTP-scale delivery | — | `examples/platform/email-delivery-platform.md` | 2 |
| B | File sync | Delta upload + conflicts | — | `examples/infra/file-sync-cloud.md` | 1 |
| B | Marketplace listings | Geo search + booking hold | — | `examples/commerce/marketplace-listings.md` | 2 |
| A | DynamoDB interview drill | Partition keys + hot shards | — | `examples/aws/dynamodb.md` | 3 |
| A | S3 interview drill | Storage classes + egress | — | `examples/aws/s3.md` | 3 |
| B | SQS / SNS drill | Queues vs fan-out | — | `examples/aws/sqs-sns.md` | 3 |

## Weekly review loop

1. Rehearse 3 topics from Tier A each day.
2. Rehearse 2 topics from Tier B every 2 days.
3. Rehearse 1 topic from Tier C each week.
