# Examples

**Parent:** [`../README.md`](../README.md)

Interview-style **system designs** for the full 60-minute loop. Each file is one practice round: clarify requirements → estimate scale and cost → draw **user → database** → APIs and storage → one deep dive.

**Authoring contract:** [`../topics/example-authoring-template.md`](../topics/example-authoring-template.md)
**Architecture patterns:** [`../topics/aws-reference-layout.md`](../topics/aws-reference-layout.md), [`../topics/event-driven-architecture.md`](../topics/event-driven-architecture.md)

## Browse by domain

| Folder | Systems | Start here |
| --- | --- | --- |
| [`platform/`](./platform/README.md) | Rate limits, gateway, identity, ads, email, flags, jobs, notifications, URL shortener | [`url-shortener.md`](./platform/url-shortener.md) |
| [`social/`](./social/README.md) | Feed, ranking, chat, WhatsApp, LinkedIn, dating, docs | [`news-feed.md`](./social/news-feed.md) |
| [`commerce/`](./commerce/README.md) | Cart, search, reviews, listings, ticketing, inventory | [`shopping-cart-checkout.md`](./commerce/shopping-cart-checkout.md) |
| [`logistics/`](./logistics/README.md) | Dispatch, tracking, ETA, maps | [`real-time-delivery-tracking.md`](./logistics/real-time-delivery-tracking.md) |
| [`fintech/`](./fintech/README.md) | Payments, cards, loans, trading, ledger | [`payment-workflow-platform.md`](./fintech/payment-workflow-platform.md) |
| [`media/`](./media/README.md) | VOD, live, Stories, Zoom | [`video-on-demand-platform.md`](./media/video-on-demand-platform.md) |
| [`event-driven/`](./event-driven/README.md) | Order pipeline, stream processing | [`event-driven-order-pipeline.md`](./event-driven/event-driven-order-pipeline.md) |
| [`infra/`](./infra/README.md) | Object storage, workflows, CRUD, file sync | [`object-storage.md`](./infra/object-storage.md) |
| [`aws/`](./aws/README.md) | **Service drills** — S3, DynamoDB, Lambda, SQS, … (not full product rounds) | [`s3.md`](./aws/s3.md) |

**Famous apps (A–Z):** [`famous-apps-index.md`](./famous-apps-index.md) · **By company:** [`../topics/high-profit-app-coverage.md`](../topics/high-profit-app-coverage.md)

## What every example includes (interview-ready)

| Pillar | Section | Use in the interview |
| --- | --- | --- |
| **Requirements Q&A** | Question bank, dialogue, **Interview Q&A cheat sheet**, parsed requirements, locked assumptions (prototype → growth → target) | Minutes 0–10: ask, verbalize math, lock numbers before boxes |
| **Services + cost** | AWS service map (with monthly meters), billable volume, **Cost at a glance**, cloud cost + timeline | Minutes 10–18: “same units AWS bills” + prototype vs target $/user |
| **User → database** | **Architecture (user → database)** mermaid (top = users, bottom = stores) + narrative | Minutes 18–32: redraw this on the whiteboard |
| **Contracts** | User-visible surface, UX → API, DB read/write paths | Minutes 32–46 |
| **Depth** | One catalog deep dive + scale/failure | Minutes 46–60 |

## Gold references (v3)

| Doc | Domain | Deep dive |
| --- | --- | --- |
| [`platform/url-shortener.md`](./platform/url-shortener.md) | Platform | Keyspace + redirect cache |
| [`social/news-feed.md`](./social/news-feed.md) | Social | Fanout (read vs write) |
| [`platform/sequential-replica-digestion.md`](./platform/sequential-replica-digestion.md) | Platform / replication | MEX + adaptive polling + lag |

When editing another example, diff against a gold sibling in the same domain folder. Diagram palette and layout: [`../topics/architecture-diagram-conventions.md`](../topics/architecture-diagram-conventions.md).

**Platform utility bucket** (custom user→database diagrams + cost at a glance + AWS meters): all files under [`platform/`](./platform/README.md).

## Modern expectations (nowadays)

Use this checklist when refreshing any example so it matches current interview answers and [`../topics/`](../topics/README.md):

| Expectation | Topic |
| --- | --- |
| Store choice with a 3-row compare (why this DB) | [`data-stores.md`](../topics/data-stores.md) |
| Cache-aside + stampede/TTL; CDN vs Redis | [`caching.md`](../topics/caching.md) |
| Outbox/CDC for side effects; DLQ | [`messaging-async.md`](../topics/messaging-async.md), [`event-driven-architecture.md`](../topics/event-driven-architecture.md) |
| Notifications off the hot path; prefs | [`notifications.md`](../topics/notifications.md) |
| CDN + BFF / optimistic UI where relevant | [`frontend-strategies.md`](../topics/frontend-strategies.md) |
| OTel traces + RED + SLO burn paging | [`observability.md`](../topics/observability.md) |
| Canary / blue-green + auto-rollback | [`deployment.md`](../topics/deployment.md) |
| Alarm → automation before waking humans | [`oncall-operations.md`](../topics/oncall-operations.md) |

**Recently refreshed for 2025–26 practice:** [`commerce/product-search.md`](./commerce/product-search.md) (hybrid BM25+vector), [`logistics/rideshare-matching.md`](./logistics/rideshare-matching.md), [`platform/identity-session-service.md`](./platform/identity-session-service.md) (passkeys), [`social/feed-ranking-service.md`](./social/feed-ranking-service.md) (ANN + shadow models).

**Still thin (stubs — expand next):** LinkedIn / WhatsApp / X timelines, Discord/Slack, Zoom, ads RTB, subscription billing, email deliverability, travel/auction/Pinterest-style commerce, Stories. Prefer promoting these to v3 over polishing golds again.

## Full inventory

| File | Domain | Bucket | Primary deep dive | GH issue |
| --- | --- | --- | --- | --- |
| [`platform/api-gateway-rate-limiting.md`](./platform/api-gateway-rate-limiting.md) | platform | Platform utility | Auth chain + distributed throttling | #26 |
| [`fintech/blockchain-settlement-audit.md`](./fintech/blockchain-settlement-audit.md) | fintech | Fintech/platform | Anchoring and trust boundaries | #52 |
| [`social/chat-messenger.md`](./social/chat-messenger.md) | social | Social/realtime | Presence + ordered delivery | #43 |
| [`social/collaborative-document.md`](./social/collaborative-document.md) | social | Collaboration | OT/CRDT and session routing | #39 |
| [`fintech/core-banking-ledger.md`](./fintech/core-banking-ledger.md) | fintech | Fintech | Ledger invariants and reconciliation | #49 |
| [`platform/cross-service-audit-logging.md`](./platform/cross-service-audit-logging.md) | platform | Platform utility | Immutable audit log | #24 |
| [`infra/crud-data-manager.md`](./infra/crud-data-manager.md) | infra | SaaS platform | Multi-tenant authz + indexing | #46 |
| [`social/dating-discovery-matching.md`](./social/dating-discovery-matching.md) | social | Social/discovery | Candidate generation + mutual match | #47 |
| [`logistics/delivery-dispatch-matching.md`](./logistics/delivery-dispatch-matching.md) | logistics | Logistics | Assignment scoring and retries | #27 |
| [`platform/distributed-job-scheduler.md`](./platform/distributed-job-scheduler.md) | platform | Platform utility | Lease safety and retries | #23 |
| [`logistics/eta-prediction-service.md`](./logistics/eta-prediction-service.md) | logistics | Logistics | ETA modeling and smoothing | #28 |
| [`event-driven/event-driven-order-pipeline.md`](./event-driven/event-driven-order-pipeline.md) | event-driven | Event-driven | Outbox + idempotency | #8 |
| [`commerce/event-ticketing.md`](./commerce/event-ticketing.md) | commerce | Commerce | Hot inventory + payment saga | #38 |
| [`platform/feature-flag-platform.md`](./platform/feature-flag-platform.md) | platform | Platform utility | Config propagation and rollback | #25 |
| [`media/live-video-streaming.md`](./media/live-video-streaming.md) | media | Media/realtime | Ingest/transcode/live fanout | #44 |
| [`logistics/maps-navigation-routing.md`](./logistics/maps-navigation-routing.md) | logistics | Geo platform | Routing graph + traffic updates | #48 |
| [`commerce/multi-region-inventory-reservation.md`](./commerce/multi-region-inventory-reservation.md) | commerce | Commerce/logistics | Global vs local reservation model | #20 |
| [`social/news-feed.md`](./social/news-feed.md) | social | Social | Fanout architecture | #37 |
| [`platform/notification-platform.md`](./platform/notification-platform.md) | platform | Platform utility | Multi-channel fanout + preferences | #22 |
| [`infra/object-storage.md`](./infra/object-storage.md) | infra | Infra rebuild | Durability and metadata indexing | #41 |
| [`fintech/payment-workflow-platform.md`](./fintech/payment-workflow-platform.md) | fintech | Fintech | State machine + reconciliation | #17 |
| [`platform/rate-limiter.md`](./platform/rate-limiter.md) | platform | Platform utility | Distributed counters + consistency | #36 |
| [`logistics/real-time-delivery-tracking.md`](./logistics/real-time-delivery-tracking.md) | logistics | Logistics | Realtime stream + reconnect | #21 |
| [`platform/sequential-replica-digestion.md`](./platform/sequential-replica-digestion.md) | platform | Platform utility / replication | MEX + polling + lag | #59 |
| [`commerce/shopping-cart-checkout.md`](./commerce/shopping-cart-checkout.md) | commerce | Commerce | Concurrency and checkout validation | #19 |
| [`event-driven/stream-processing-platform.md`](./event-driven/stream-processing-platform.md) | event-driven | Event-driven | Stateful windows and replay | #50 |
| [`platform/url-shortener.md`](./platform/url-shortener.md) | platform | Platform utility | Keyspace + redirect cache | #35 |
| [`media/video-on-demand-platform.md`](./media/video-on-demand-platform.md) | media | Media | Upload/transcode/CDN | #45 |
| [`infra/workflow-orchestration.md`](./infra/workflow-orchestration.md) | infra | Infra rebuild | Durable workflow execution | #42 |
| [`commerce/product-search.md`](./commerce/product-search.md) | commerce | Commerce | Index + ranking + typeahead | — |
| [`platform/identity-session-service.md`](./platform/identity-session-service.md) | platform | Platform utility | Sessions + OAuth | — |
| [`logistics/rideshare-matching.md`](./logistics/rideshare-matching.md) | logistics | Logistics | Rideshare match + surge | — |
| [`fintech/subscription-billing.md`](./fintech/subscription-billing.md) | fintech | Fintech | Subscription renewals | — |
| [`social/feed-ranking-service.md`](./social/feed-ranking-service.md) | social | Social | Feed ranking | — |
| [`platform/ads-auction-platform.md`](./platform/ads-auction-platform.md) | platform | Platform utility | RTB + pacing | — |
| [`commerce/reviews-ratings.md`](./commerce/reviews-ratings.md) | commerce | Commerce | Review aggregates | — |
| [`platform/email-delivery-platform.md`](./platform/email-delivery-platform.md) | platform | Platform utility | Transactional email | — |
| [`infra/file-sync-cloud.md`](./infra/file-sync-cloud.md) | infra | Consumer cloud | File sync | — |
| [`commerce/marketplace-listings.md`](./commerce/marketplace-listings.md) | commerce | Commerce | Listings + geo | — |
| [`fintech/credit-card-platform.md`](./fintech/credit-card-platform.md) | fintech | Fintech | Card auth + limits | — |
| [`fintech/loan-origination-platform.md`](./fintech/loan-origination-platform.md) | fintech | Fintech | Loan workflow | — |
| [`fintech/securities-trading-platform.md`](./fintech/securities-trading-platform.md) | fintech | Fintech | Matching + market data | — |
| [`social/professional-network-platform.md`](./social/professional-network-platform.md) | social | Social | LinkedIn graph + feed | — |
| [`social/global-messaging-platform.md`](./social/global-messaging-platform.md) | social | Social | WhatsApp-scale messaging | — |
| [`social/microblog-timeline.md`](./social/microblog-timeline.md) | social | Social | X / Twitter timeline | — |
| [`social/community-forum-platform.md`](./social/community-forum-platform.md) | social | Social | Reddit / voting forums | — |
| [`social/community-chat-platform.md`](./social/community-chat-platform.md) | social | Social | Discord / Slack | — |
| [`media/ephemeral-stories-platform.md`](./media/ephemeral-stories-platform.md) | media | Media | Snapchat / Stories | — |
| [`media/video-conferencing-platform.md`](./media/video-conferencing-platform.md) | media | Media | Zoom / Meet | — |
| [`commerce/travel-booking-platform.md`](./commerce/travel-booking-platform.md) | commerce | Commerce | Airbnb / Booking | — |
| [`commerce/auction-marketplace.md`](./commerce/auction-marketplace.md) | commerce | Commerce | eBay auctions | — |
| [`commerce/visual-discovery-platform.md`](./commerce/visual-discovery-platform.md) | commerce | Commerce | Pinterest | — |

See [`aws/README.md`](./aws/README.md) for per-service drills (S3, DynamoDB, Lambda, …).
**Company routing:** [`../topics/high-profit-app-coverage.md`](../topics/high-profit-app-coverage.md) (Google, Meta, Amazon, fintech, …).

## Related

- [System catalog](../topics/system-catalog.md)
- [High-profit app coverage](../topics/high-profit-app-coverage.md)
- [AWS service drills](./aws/README.md)
- [Topics index](../topics-index.md)
- [60-minute runbook](../topics/interview-runbook-60m.md)
