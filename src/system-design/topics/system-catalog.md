# System design catalog

Authoritative scope for mid-senior prep: one row per system, one issue per row.

## Template and pattern references

- Examples index: [`examples/README.md`](../examples/README.md)
- Example authoring template: [`example-authoring-template.md`](./example-authoring-template.md)
- AWS reference layout (pattern): [`aws-reference-layout.md`](./aws-reference-layout.md)
- Event-driven architecture (pattern): [`event-driven-architecture.md`](./event-driven-architecture.md)
- Gold references (full v3 capacity): [`platform/url-shortener.md`](../examples/platform/url-shortener.md), [`social/news-feed.md`](../examples/social/news-feed.md), [`platform/sequential-replica-digestion.md`](../examples/platform/sequential-replica-digestion.md)
- Compact platform reference (v3 sections, platform-scale capacity): [`platform/distributed-job-scheduler.md`](../examples/platform/distributed-job-scheduler.md)
- Supplementary commerce reference: [`commerce/event-ticketing.md`](../examples/commerce/event-ticketing.md)

## Catalog

| System | Abstract bucket | Primary deep dive axis | Target doc | Status | Template ref | Issue |
| --- | --- | --- | --- | --- | --- | --- |
| URL shortener | Platform utility | Keyspace + redirect cache | [`platform/url-shortener.md`](../examples/platform/url-shortener.md) | Exists (full-round) | Contract v3 + template | #35 |
| Rate limiter | Platform utility | Distributed counters + consistency | [`platform/rate-limiter.md`](../examples/platform/rate-limiter.md) | Exists (full-round) | Contract v3 + url-shortener | #36 |
| News feed | Social | Fanout strategy (read vs write) | [`social/news-feed.md`](../examples/social/news-feed.md) | Exists (full-round) | Contract v3 + url-shortener | #37 |
| Event ticketing | Commerce | Hot inventory + reservation saga | [`commerce/event-ticketing.md`](../examples/commerce/event-ticketing.md) | Exists (full-round) | Contract v3 + url-shortener | #38 |
| Collaborative document | Collaboration | OT/CRDT + session routing | [`social/collaborative-document.md`](../examples/social/collaborative-document.md) | Exists (full-round) | Contract v3 + url-shortener | #39 |
| AWS reference layout | Reference pattern | Async topology + cloud mapping | [`aws-reference-layout.md`](./aws-reference-layout.md) | Exists (reference pattern) | Pattern — not in `examples/` | #40 |
| Object storage rebuild | Infra rebuild | Metadata/chunk durability model | [`infra/object-storage.md`](../examples/infra/object-storage.md) | Exists (full-round) | Contract v3 + url-shortener | #41 |
| Workflow orchestration rebuild | Infra rebuild | Durable state transitions + retries | [`infra/workflow-orchestration.md`](../examples/infra/workflow-orchestration.md) | Exists (full-round) | Contract v3 + url-shortener | #42 |
| Event-driven order pipeline | Event-driven | Outbox + idempotency + replay | [`event-driven/event-driven-order-pipeline.md`](../examples/event-driven/event-driven-order-pipeline.md) | Exists (full-round) | Contract v3 + url-shortener | #8 |
| Payment workflow platform | Fintech | Payment state machine + reconciliation | [`fintech/payment-workflow-platform.md`](../examples/fintech/payment-workflow-platform.md) | Exists (full-round) | Contract v3 + url-shortener | #17 |
| Shopping cart checkout | Commerce | Concurrency + merge + checkout validation | [`commerce/shopping-cart-checkout.md`](../examples/commerce/shopping-cart-checkout.md) | Exists (full-round) | Contract v3 + url-shortener | #19 |
| Multi-region inventory reservation | Commerce/logistics | Region quota vs global consistency | [`commerce/multi-region-inventory-reservation.md`](../examples/commerce/multi-region-inventory-reservation.md) | Exists (full-round) | Contract v3 + url-shortener | #20 |
| Real-time delivery tracking | Logistics | Stream projection + reconnect semantics | [`logistics/real-time-delivery-tracking.md`](../examples/logistics/real-time-delivery-tracking.md) | Exists (full-round) | Contract v3 + url-shortener | #21 |
| Delivery dispatch matching | Logistics | Assignment scoring + retry loop | [`logistics/delivery-dispatch-matching.md`](../examples/logistics/delivery-dispatch-matching.md) | Exists (full-round) | Contract v3 + url-shortener | #27 |
| ETA prediction service | Logistics | Prediction pipeline + smoothing | [`logistics/eta-prediction-service.md`](../examples/logistics/eta-prediction-service.md) | Exists (full-round) | Contract v3 + url-shortener | #28 |
| Notification platform | Platform utility | Fanout + preference + provider backoff | [`platform/notification-platform.md`](../examples/platform/notification-platform.md) | Exists (full-round) | Contract v3 + url-shortener | #22 |
| Feature flag platform | Platform utility | Control-plane propagation + rollback | [`platform/feature-flag-platform.md`](../examples/platform/feature-flag-platform.md) | Exists (full-round) | Contract v3 + url-shortener | #25 |
| API gateway rate limiting | Platform utility | Auth chain + distributed throttling | [`platform/api-gateway-rate-limiting.md`](../examples/platform/api-gateway-rate-limiting.md) | Exists (full-round) | Contract v3 + rate-limiter | #26 |
| Cross-service audit logging | Platform utility | Immutable event log + query projection | [`platform/cross-service-audit-logging.md`](../examples/platform/cross-service-audit-logging.md) | Exists (full-round) | Contract v3 + url-shortener | #24 |
| Distributed job scheduler | Platform utility | Lease model + duplicate suppression | [`platform/distributed-job-scheduler.md`](../examples/platform/distributed-job-scheduler.md) | Exists (full-round) | Contract v3 + url-shortener | #23 |
| Chat messenger | Social/realtime | Presence + ordered delivery | [`social/chat-messenger.md`](../examples/social/chat-messenger.md) | Exists (full-round) | Contract v3 + url-shortener | #43 |
| Live video streaming | Media/realtime | Ingest/transcode/live fanout | [`media/live-video-streaming.md`](../examples/media/live-video-streaming.md) | Exists (full-round) | Contract v3 + url-shortener | #44 |
| Video on demand platform | Media | Upload/transcode/CDN/catalog | [`media/video-on-demand-platform.md`](../examples/media/video-on-demand-platform.md) | Exists (full-round) | Contract v3 + url-shortener | #45 |
| CRUD data manager | SaaS platform | Multi-tenant authz + query/index model | [`infra/crud-data-manager.md`](../examples/infra/crud-data-manager.md) | Exists (full-round) | Contract v3 + url-shortener | #46 |
| Dating discovery matching | Social/discovery | Candidate generation + mutual match | [`social/dating-discovery-matching.md`](../examples/social/dating-discovery-matching.md) | Exists (full-round) | Contract v3 + url-shortener | #47 |
| Maps navigation routing | Geo platform | Routing graph + traffic updates | [`logistics/maps-navigation-routing.md`](../examples/logistics/maps-navigation-routing.md) | Exists (full-round) | Contract v3 + url-shortener | #48 |
| Core banking ledger | Fintech | Ledger invariants + reconciliation | [`fintech/core-banking-ledger.md`](../examples/fintech/core-banking-ledger.md) | Exists (full-round) | Contract v3 + url-shortener | #49 |
| Stream processing platform | Event-driven | Windowed state + replay + backpressure | [`event-driven/stream-processing-platform.md`](../examples/event-driven/stream-processing-platform.md) | Exists (full-round) | Contract v3 + url-shortener | #50 |
| Event-driven architecture reference | Event-driven | Contract/versioning + orchestration boundaries | [`event-driven-architecture.md`](./event-driven-architecture.md) | Exists (reference pattern) | Pattern — not in `examples/` | #51 |
| Blockchain settlement and audit | Fintech/platform | Trust boundaries + anchoring strategy | [`fintech/blockchain-settlement-audit.md`](../examples/fintech/blockchain-settlement-audit.md) | Exists (full-round) | Contract v3 + url-shortener | #52 |
| Sequential replica digestion worker | Platform utility / data replication | MEX discovery + adaptive polling + lag estimation | [`platform/sequential-replica-digestion.md`](../examples/platform/sequential-replica-digestion.md) | Exists (full-round) | [example-authoring-template](./example-authoring-template.md) | #59 |
| Product search and typeahead | Commerce | Index + ranking + typeahead | [`commerce/product-search.md`](../examples/commerce/product-search.md) | Exists (full-round) | Contract v3 + url-shortener | — |
| Identity and session service | Platform utility | Sessions + OAuth + token rotation | [`platform/identity-session-service.md`](../examples/platform/identity-session-service.md) | Exists (full-round) | Contract v3 + url-shortener | — |
| Rideshare on-demand matching | Logistics | Supply/demand match + surge | [`logistics/rideshare-matching.md`](../examples/logistics/rideshare-matching.md) | Exists (full-round) | Contract v3 + dispatch | — |
| Subscription billing | Fintech | Renewals + dunning + entitlements | [`fintech/subscription-billing.md`](../examples/fintech/subscription-billing.md) | Exists (full-round) | Contract v3 + payment-workflow | — |
| Home feed ranking service | Social | Candidate retrieval + scoring | [`social/feed-ranking-service.md`](../examples/social/feed-ranking-service.md) | Exists (full-round) | Contract v3 + news-feed | — |
| Ads auction and pacing | Platform utility | RTB + pacing + frequency cap | [`platform/ads-auction-platform.md`](../examples/platform/ads-auction-platform.md) | Exists (full-round) | Contract v3 + notification | — |
| Reviews and ratings | Commerce | Aggregate consistency + fraud | [`commerce/reviews-ratings.md`](../examples/commerce/reviews-ratings.md) | Exists (full-round) | Contract v3 + url-shortener | — |
| Transactional email platform | Platform utility | Queue + reputation + dedupe send | [`platform/email-delivery-platform.md`](../examples/platform/email-delivery-platform.md) | Exists (full-round) | Contract v3 + notification | — |
| Personal file sync cloud | Infra / consumer | Delta sync + conflict policy | [`infra/file-sync-cloud.md`](../examples/infra/file-sync-cloud.md) | Exists (full-round) | Contract v3 + object-storage | — |
| Marketplace listings | Commerce | Geo search + booking hold | [`commerce/marketplace-listings.md`](../examples/commerce/marketplace-listings.md) | Exists (full-round) | Contract v3 + event-ticketing | — |
| Credit card platform | Fintech | Auth hold + limits + settlement | [`fintech/credit-card-platform.md`](../examples/fintech/credit-card-platform.md) | Exists (full-round) | Contract v3 + payment-workflow | — |
| Loan origination platform | Fintech | Underwriting workflow + disbursement | [`fintech/loan-origination-platform.md`](../examples/fintech/loan-origination-platform.md) | Exists (full-round) | Contract v3 + workflow-orchestration | — |
| Securities trading platform | Fintech | Order book + matching + market data | [`fintech/securities-trading-platform.md`](../examples/fintech/securities-trading-platform.md) | Exists (full-round) | Contract v3 + stream-processing | — |
| Professional network platform | Social | Graph + feed + profile search | [`social/professional-network-platform.md`](../examples/social/professional-network-platform.md) | Exists (full-round) | Contract v3 + news-feed | — |
| Global messaging platform | Social/realtime | WhatsApp-scale groups + multi-region | [`social/global-messaging-platform.md`](../examples/social/global-messaging-platform.md) | Exists (full-round) | Contract v3 + chat-messenger | — |
| Microblog timeline | Social | X/Twitter fanout + trending | [`social/microblog-timeline.md`](../examples/social/microblog-timeline.md) | Exists (full-round) | Contract v3 + news-feed | — |
| Community forum platform | Social | Reddit voting + hot rank | [`social/community-forum-platform.md`](../examples/social/community-forum-platform.md) | Exists (full-round) | Contract v3 + news-feed | — |
| Community chat platform | Social/realtime | Discord/Slack ACL + channels | [`social/community-chat-platform.md`](../examples/social/community-chat-platform.md) | Exists (full-round) | Contract v3 + chat-messenger | — |
| Ephemeral stories platform | Media | Snapchat TTL + CDN | [`media/ephemeral-stories-platform.md`](../examples/media/ephemeral-stories-platform.md) | Exists (full-round) | Contract v3 + VOD | — |
| Video conferencing platform | Media/realtime | Zoom SFU + signaling | [`media/video-conferencing-platform.md`](../examples/media/video-conferencing-platform.md) | Exists (full-round) | Contract v3 + live-stream | — |
| Travel booking platform | Commerce | Airbnb dates + holds | [`commerce/travel-booking-platform.md`](../examples/commerce/travel-booking-platform.md) | Exists (full-round) | Contract v3 + marketplace | — |
| Auction marketplace | Commerce | eBay bids + proxy | [`commerce/auction-marketplace.md`](../examples/commerce/auction-marketplace.md) | Exists (full-round) | Contract v3 + event-ticketing | — |
| Visual discovery platform | Commerce/social | Pinterest pins + vector search | [`commerce/visual-discovery-platform.md`](../examples/commerce/visual-discovery-platform.md) | Exists (full-round) | Contract v3 + product-search | — |

## AWS service drills (`examples/aws/`)

| Drill | AWS focus | Target doc | Status | Notes |
| --- | --- | --- | --- | --- |
| S3 | Object storage | [`aws/s3.md`](../examples/aws/s3.md) | Exists (service drill) | Companion to object-storage rebuild |
| DynamoDB | Key-value / partitions | [`aws/dynamodb.md`](../examples/aws/dynamodb.md) | Exists (service drill) | — |
| Lambda | Serverless handlers | [`aws/lambda.md`](../examples/aws/lambda.md) | Exists (service drill) | — |
| SQS + SNS | Queues and fan-out | [`aws/sqs-sns.md`](../examples/aws/sqs-sns.md) | Exists (service drill) | — |
| Aurora / RDS | Relational OLTP | [`aws/aurora-rds.md`](../examples/aws/aurora-rds.md) | Exists (service drill) | — |
| ElastiCache Redis | Cache / counters | [`aws/elasticache-redis.md`](../examples/aws/elasticache-redis.md) | Exists (service drill) | — |
| API Gateway | Edge API | [`aws/api-gateway.md`](../examples/aws/api-gateway.md) | Exists (service drill) | — |
| CloudFront + ALB | CDN + L7 ingress | [`aws/cloudfront-alb.md`](../examples/aws/cloudfront-alb.md) | Exists (service drill) | — |
| MSK / Kinesis | Event streams | [`aws/msk-kinesis.md`](../examples/aws/msk-kinesis.md) | Exists (service drill) | — |
| EventBridge | Event routing | [`aws/eventbridge.md`](../examples/aws/eventbridge.md) | Exists (service drill) | — |
| Step Functions | Workflows / sagas | [`aws/step-functions.md`](../examples/aws/step-functions.md) | Exists (service drill) | Companion to workflow-orchestration |
| ECS Fargate | Container app tier | [`aws/ecs-fargate.md`](../examples/aws/ecs-fargate.md) | Exists (service drill) | — |
| Cognito + IAM | Auth + roles | [`aws/cognito-iam.md`](../examples/aws/cognito-iam.md) | Exists (service drill) | — |
| OpenSearch | Search index | [`aws/opensearch.md`](../examples/aws/opensearch.md) | Exists (service drill) | — |

## Overlap notes

- `payment-workflow-platform` and `core-banking-ledger` are intentionally separate: payment orchestration vs account/ledger domain.
- `event-driven-order-pipeline` and `event-driven-architecture` are intentionally separate: worked example vs reusable interview reference.
- `distributed-job-scheduler` and `stream-processing-platform` are intentionally separate: scheduled work queue vs continuous partitioned stream processing.
- `sequential-replica-digestion` and `stream-processing-platform` are intentionally separate: poll-based gap closure on a replica vs continuous stream processing.
- `sequential-replica-digestion` and `core-banking-ledger` are intentionally separate: replication digestion worker vs ledger posting invariants.
- `news-feed` and `feed-ranking-service` are intentionally separate: fanout/write path vs personalized ranker read path.
- `delivery-dispatch-matching` and `rideshare-matching` are intentionally separate: courier job queue vs passenger ride marketplace.
- `payment-workflow-platform` and `subscription-billing` are intentionally separate: one-shot payments vs recurring billing cycles.
- `notification-platform` and `email-delivery-platform` are intentionally separate: push/SMS vs SMTP-scale email.
- `object-storage` (rebuild) and `aws/s3` are intentionally separate: deep rebuild vs interview quick drill.
- `product-search` and `news-feed` are intentionally separate: catalog search index vs social fanout feed.
- `chat-messenger` and `global-messaging-platform` are intentionally separate: full v3 chat depth vs WhatsApp routing doc.
- `professional-network-platform` and `news-feed` are intentionally separate: connection graph feed vs generic fanout.
- `credit-card-platform` and `payment-workflow-platform` are intentionally separate: issuing auth vs merchant capture.
- `securities-trading-platform` and `core-banking-ledger` are intentionally separate: matching engine vs account ledger.
- `loan-origination-platform` and `core-banking-ledger` are intentionally separate: application workflow vs posted balances.
