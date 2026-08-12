# High-profit app coverage

**Parent:** [`README.md`](./README.md) · **Catalog:** [`system-catalog.md`](./system-catalog.md) · **AWS drills:** [`../examples/aws/README.md`](../examples/aws/README.md)

Route “design {company product}” to **one primary** example (full v3 round) plus optional companions.

**Status:** `Exists` = file in repo · `Index` = use primary + narrative in this table (no separate file)

---

## Google

| Product | Money driver | Primary example | Companions |
| --- | --- | --- | --- |
| **Search** | Query ads + conversion | [`commerce/product-search.md`](../examples/commerce/product-search.md) | [`aws/opensearch.md`](../examples/aws/opensearch.md) |
| **YouTube** | Ads + Premium | [`media/video-on-demand-platform.md`](../examples/media/video-on-demand-platform.md) | [`social/feed-ranking-service.md`](../examples/social/feed-ranking-service.md), [`platform/ads-auction-platform.md`](../examples/platform/ads-auction-platform.md) |
| **YouTube Live** | Live ads | [`media/live-video-streaming.md`](../examples/media/live-video-streaming.md) | Twitch row |
| **Maps** | API + local ads | [`logistics/maps-navigation-routing.md`](../examples/logistics/maps-navigation-routing.md) | [`logistics/eta-prediction-service.md`](../examples/logistics/eta-prediction-service.md) |
| **Gmail** | Workspace retention | [`platform/email-delivery-platform.md`](../examples/platform/email-delivery-platform.md) | — |
| **Docs** | Collaboration SaaS | [`social/collaborative-document.md`](../examples/social/collaborative-document.md) | — |
| **Drive** | Storage ARPU | [`infra/file-sync-cloud.md`](../examples/infra/file-sync-cloud.md) | [`infra/object-storage.md`](../examples/infra/object-storage.md) |
| **Ads (AdSense/Display)** | Ad ARPU | [`platform/ads-auction-platform.md`](../examples/platform/ads-auction-platform.md) | product-search (PLA) |

---

## Meta (Facebook, Instagram, WhatsApp)

| Product | Money driver | Primary example | Companions |
| --- | --- | --- | --- |
| **News Feed** | Engagement + ads | [`social/news-feed.md`](../examples/social/news-feed.md) | feed-ranking, ads-auction |
| **Instagram** (feed + Reels) | Watch time + ads | [`social/feed-ranking-service.md`](../examples/social/feed-ranking-service.md) | news-feed, VOD |
| **Messenger** | Stickiness | [`social/chat-messenger.md`](../examples/social/chat-messenger.md) | — |
| **WhatsApp** | Global messaging | [`social/global-messaging-platform.md`](../examples/social/global-messaging-platform.md) | chat-messenger (full depth) |
| **Ads** | Auction revenue | [`platform/ads-auction-platform.md`](../examples/platform/ads-auction-platform.md) | — |

---

## Amazon

| Product | Money driver | Primary example | Companions |
| --- | --- | --- | --- |
| **Retail checkout** | GMV | [`commerce/shopping-cart-checkout.md`](../examples/commerce/shopping-cart-checkout.md) | — |
| **Search** | Conversion | [`commerce/product-search.md`](../examples/commerce/product-search.md) | — |
| **Reviews** | Trust | [`commerce/reviews-ratings.md`](../examples/commerce/reviews-ratings.md) | — |
| **Inventory / Prime** | Fulfillment | [`commerce/multi-region-inventory-reservation.md`](../examples/commerce/multi-region-inventory-reservation.md) | — |
| **Flash sales / tickets** | Hot keys | [`commerce/event-ticketing.md`](../examples/commerce/event-ticketing.md) | — |
| **Marketplace (3P sellers)** | GMV + fees | [`commerce/marketplace-listings.md`](../examples/commerce/marketplace-listings.md) | — |
| **AWS** (primitives) | Infra margin | [`topics/aws-reference-layout.md`](./aws-reference-layout.md) | [`examples/aws/README.md`](../examples/aws/README.md) |

---

## Streaming and media

| Company / product | Money driver | Primary example | Companions |
| --- | --- | --- | --- |
| **Netflix** | Subs + egress | [`media/video-on-demand-platform.md`](../examples/media/video-on-demand-platform.md) | [`fintech/subscription-billing.md`](../examples/fintech/subscription-billing.md) |
| **Twitch** | Live + subs | [`media/live-video-streaming.md`](../examples/media/live-video-streaming.md) | MSK/Kinesis drill |
| **Spotify** (audio) | Subs | [`fintech/subscription-billing.md`](../examples/fintech/subscription-billing.md) | VOD (catalog metadata) |

---

## Mobility and logistics

| Company / product | Money driver | Primary example | Companions |
| --- | --- | --- | --- |
| **Uber / Lyft** | Take rate | [`logistics/rideshare-matching.md`](../examples/logistics/rideshare-matching.md) | maps, tracking, dispatch |
| **DoorDash** | Delivery fees | [`logistics/delivery-dispatch-matching.md`](../examples/logistics/delivery-dispatch-matching.md) | tracking, ETA |

---

## Social and professional

| Company / product | Money driver | Primary example | Companions |
| --- | --- | --- | --- |
| **LinkedIn** | Jobs + ads + subs | [`social/professional-network-platform.md`](../examples/social/professional-network-platform.md) | news-feed, product-search |
| **X (Twitter)** | Ads + engagement | [`social/microblog-timeline.md`](../examples/social/microblog-timeline.md) | news-feed |
| **Reddit** | Ads + awards | [`social/community-forum-platform.md`](../examples/social/community-forum-platform.md) | news-feed |
| **Discord / Slack** | Premium + seats | [`social/community-chat-platform.md`](../examples/social/community-chat-platform.md) | chat-messenger |
| **TikTok** | Ads + watch time | [`social/feed-ranking-service.md`](../examples/social/feed-ranking-service.md) | live-video, VOD |
| **Snapchat** | Ads + AR | [`media/ephemeral-stories-platform.md`](../examples/media/ephemeral-stories-platform.md) | VOD |
| **Pinterest** | Ads + shopping | [`commerce/visual-discovery-platform.md`](../examples/commerce/visual-discovery-platform.md) | product-search |
| **Tinder / Bumble** | Match → chat | [`social/dating-discovery-matching.md`](../examples/social/dating-discovery-matching.md) | chat-messenger |
| **Microsoft Teams** | Enterprise seats | [`social/community-chat-platform.md`](../examples/social/community-chat-platform.md) | video-conferencing |
| **Zoom** | SaaS seats | [`media/video-conferencing-platform.md`](../examples/media/video-conferencing-platform.md) | live-video-streaming |

---

## Travel and marketplaces

| Company / product | Money driver | Primary example | Companions |
| --- | --- | --- | --- |
| **Airbnb / Booking** | Booking fees | [`commerce/travel-booking-platform.md`](../examples/commerce/travel-booking-platform.md) | marketplace-listings |
| **eBay** | Auction + GMV | [`commerce/auction-marketplace.md`](../examples/commerce/auction-marketplace.md) | event-ticketing |
| **Shopify** | Merchant SaaS | [`infra/crud-data-manager.md`](../examples/infra/crud-data-manager.md) | marketplace-listings |

---

## Fintech and markets

| Company / product | Money driver | Primary example | Companions |
| --- | --- | --- | --- |
| **Stripe / PayPal** | Payment take rate | [`fintech/payment-workflow-platform.md`](../examples/fintech/payment-workflow-platform.md) | — |
| **Credit card issuing** | Interchange + interest | [`fintech/credit-card-platform.md`](../examples/fintech/credit-card-platform.md) | core-banking-ledger |
| **Loans / mortgage / BNPL** | Interest + fees | [`fintech/loan-origination-platform.md`](../examples/fintech/loan-origination-platform.md) | Step Functions |
| **Stock / crypto exchange** | Trading fees | [`fintech/securities-trading-platform.md`](../examples/fintech/securities-trading-platform.md) | stream-processing |
| **Retail banking ledger** | Deposits | [`fintech/core-banking-ledger.md`](../examples/fintech/core-banking-ledger.md) | — |
| **Subscriptions** | Recurring ARPU | [`fintech/subscription-billing.md`](../examples/fintech/subscription-billing.md) | payment-workflow |

---

## Coverage snapshot

| Bucket | Example count | Gaps (index-only OK) |
| --- | --- | --- |
| Google portfolio | 8 products → 7 files | Photos ≈ VOD + S3 |
| Meta portfolio | 5 products → 5 files | — |
| Amazon retail | 6 surfaces → 5 files | AWS separate |
| Famous social (X, Reddit, Discord, …) | 8 apps → 8 files | — |
| Fintech / markets | 6 surfaces → 6 files | Insurance, FX optional later |
| Streaming + meetings | Netflix, Twitch, Zoom, Stories | 4 files |
| **A–Z index** | 40+ apps | [`examples/famous-apps-index.md`](../examples/famous-apps-index.md) |

---

## Platform primitives

| Surface | Example | AWS drill |
| --- | --- | --- |
| Rate limiting | [`platform/rate-limiter.md`](../examples/platform/rate-limiter.md) | ElastiCache |
| API edge | [`platform/api-gateway-rate-limiting.md`](../examples/platform/api-gateway-rate-limiting.md) | API Gateway, ALB |
| Notifications | [`platform/notification-platform.md`](../examples/platform/notification-platform.md) | SQS/SNS |
| Identity / sessions | [`platform/identity-session-service.md`](../examples/platform/identity-session-service.md) | Cognito |
| Ads | [`platform/ads-auction-platform.md`](../examples/platform/ads-auction-platform.md) | ElastiCache, streams |
| Event-driven core | [`event-driven/event-driven-order-pipeline.md`](../examples/event-driven/event-driven-order-pipeline.md) | EventBridge, MSK |
| AWS per-service | [`examples/aws/README.md`](../examples/aws/README.md) | All boxes |

---

## Interview one-liners

| If they say… | Open | Lead with |
| --- | --- | --- |
| Instagram | feed-ranking + VOD | Rank vs fanout; CDN for media |
| YouTube | VOD + feed-ranking + ads | Transcode; suggest; auction |
| WhatsApp | global-messaging | Region + group fanout |
| LinkedIn | professional-network | Graph + feed + search |
| Uber | rideshare-matching | Surge + geo match |
| Amazon | cart + product-search | Merge; index |
| Netflix | VOD + subscription-billing | CDN; renewals |
| Credit card | credit-card-platform | Auth hold + limits |
| Stock market | securities-trading | Order book shard |
| Loan app | loan-origination | Step Functions + human step |

---

## Related

- [Archetype coverage matrix](./archetype-coverage-matrix.md)
- [System catalog](./system-catalog.md)
- [Examples index](../examples/README.md)
