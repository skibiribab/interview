# Archetype coverage matrix

Use this matrix to pick drills by product shape and deep-dive focus. All linked primary docs are **full-round (v3)** unless noted as a pattern reference (see [examples README](../examples/README.md) gold references).

| Archetype | Primary docs | Secondary docs | Current coverage |
| --- | --- | --- | --- |
| Social feed | [`news-feed.md`](../examples/social/news-feed.md) | [`event-driven-order-pipeline.md`](../examples/event-driven/event-driven-order-pipeline.md) | Strong |
| Chat/messenger | [`chat-messenger.md`](../examples/social/chat-messenger.md) | [`real-time-delivery-tracking.md`](../examples/logistics/real-time-delivery-tracking.md) | Medium |
| Dating/discovery | [`dating-discovery-matching.md`](../examples/social/dating-discovery-matching.md) | [`chat-messenger.md`](../examples/social/chat-messenger.md) | Medium |
| Collaboration docs | [`collaborative-document.md`](../examples/social/collaborative-document.md) | [`feature-flag-platform.md`](../examples/platform/feature-flag-platform.md) | Medium |
| Commerce checkout | [`shopping-cart-checkout.md`](../examples/commerce/shopping-cart-checkout.md) | [`event-ticketing.md`](../examples/commerce/event-ticketing.md) | Medium |
| Ticketing/inventory | [`event-ticketing.md`](../examples/commerce/event-ticketing.md) | [`multi-region-inventory-reservation.md`](../examples/commerce/multi-region-inventory-reservation.md) | Medium |
| Dispatch/tracking | [`delivery-dispatch-matching.md`](../examples/logistics/delivery-dispatch-matching.md) | [`real-time-delivery-tracking.md`](../examples/logistics/real-time-delivery-tracking.md) | Medium |
| ETA/maps | [`eta-prediction-service.md`](../examples/logistics/eta-prediction-service.md) | [`maps-navigation-routing.md`](../examples/logistics/maps-navigation-routing.md) | Medium |
| Notifications | [`notification-platform.md`](../examples/platform/notification-platform.md) | [`api-gateway-rate-limiting.md`](../examples/platform/api-gateway-rate-limiting.md) | Medium |
| Payment orchestration | [`payment-workflow-platform.md`](../examples/fintech/payment-workflow-platform.md) | [`event-ticketing.md`](../examples/commerce/event-ticketing.md) | Medium |
| Core banking | [`core-banking-ledger.md`](../examples/fintech/core-banking-ledger.md) | [`payment-workflow-platform.md`](../examples/fintech/payment-workflow-platform.md) | Medium |
| URL platform utility | [`url-shortener.md`](../examples/platform/url-shortener.md) | [`rate-limiter.md`](../examples/platform/rate-limiter.md) | Strong |
| Feature flags | [`feature-flag-platform.md`](../examples/platform/feature-flag-platform.md) | [`cross-service-audit-logging.md`](../examples/platform/cross-service-audit-logging.md) | Medium |
| Stream processing | [`stream-processing-platform.md`](../examples/event-driven/stream-processing-platform.md) | [`event-driven-order-pipeline.md`](../examples/event-driven/event-driven-order-pipeline.md) | Medium |
| Event-driven reference | [`event-driven-architecture.md`](./event-driven-architecture.md) | [`event-driven-order-pipeline.md`](../examples/event-driven/event-driven-order-pipeline.md) | Medium |
| Job/workflow scheduling | [`distributed-job-scheduler.md`](../examples/platform/distributed-job-scheduler.md) | [`workflow-orchestration.md`](../examples/infra/workflow-orchestration.md) | Strong |
| Object storage rebuild | [`object-storage.md`](../examples/infra/object-storage.md) | [`aws-reference-layout.md`](./aws-reference-layout.md) | Medium |
| Media live | [`live-video-streaming.md`](../examples/media/live-video-streaming.md) | [`stream-processing-platform.md`](../examples/event-driven/stream-processing-platform.md) | Medium |
| Media VOD | [`video-on-demand-platform.md`](../examples/media/video-on-demand-platform.md) | [`live-video-streaming.md`](../examples/media/live-video-streaming.md) | Medium |
| Blockchain audit anchoring | [`blockchain-settlement-audit.md`](../examples/fintech/blockchain-settlement-audit.md) | [`cross-service-audit-logging.md`](../examples/platform/cross-service-audit-logging.md) | Medium |
| Product search | [`product-search.md`](../examples/commerce/product-search.md) | [`marketplace-listings.md`](../examples/commerce/marketplace-listings.md) | Medium |
| Identity / sessions | [`identity-session-service.md`](../examples/platform/identity-session-service.md) | [`api-gateway-rate-limiting.md`](../examples/platform/api-gateway-rate-limiting.md) | Medium |
| Rideshare marketplace | [`rideshare-matching.md`](../examples/logistics/rideshare-matching.md) | [`delivery-dispatch-matching.md`](../examples/logistics/delivery-dispatch-matching.md) | Medium |
| Subscription billing | [`subscription-billing.md`](../examples/fintech/subscription-billing.md) | [`payment-workflow-platform.md`](../examples/fintech/payment-workflow-platform.md) | Medium |
| Feed ranking | [`feed-ranking-service.md`](../examples/social/feed-ranking-service.md) | [`news-feed.md`](../examples/social/news-feed.md) | Medium |
| Ads auction | [`ads-auction-platform.md`](../examples/platform/ads-auction-platform.md) | [`feed-ranking-service.md`](../examples/social/feed-ranking-service.md) | Medium |
| Reviews / ratings | [`reviews-ratings.md`](../examples/commerce/reviews-ratings.md) | [`shopping-cart-checkout.md`](../examples/commerce/shopping-cart-checkout.md) | Medium |
| Email delivery | [`email-delivery-platform.md`](../examples/platform/email-delivery-platform.md) | [`notification-platform.md`](../examples/platform/notification-platform.md) | Medium |
| File sync | [`file-sync-cloud.md`](../examples/infra/file-sync-cloud.md) | [`object-storage.md`](../examples/infra/object-storage.md) | Medium |
| Marketplace listings | [`marketplace-listings.md`](../examples/commerce/marketplace-listings.md) | [`event-ticketing.md`](../examples/commerce/event-ticketing.md) | Medium |
| Credit card / issuing | [`credit-card-platform.md`](../examples/fintech/credit-card-platform.md) | [`payment-workflow-platform.md`](../examples/fintech/payment-workflow-platform.md) | Medium |
| Loan origination | [`loan-origination-platform.md`](../examples/fintech/loan-origination-platform.md) | [`workflow-orchestration.md`](../examples/infra/workflow-orchestration.md) | Medium |
| Securities / trading | [`securities-trading-platform.md`](../examples/fintech/securities-trading-platform.md) | [`stream-processing-platform.md`](../examples/event-driven/stream-processing-platform.md) | Medium |
| Professional network | [`professional-network-platform.md`](../examples/social/professional-network-platform.md) | [`news-feed.md`](../examples/social/news-feed.md) | Medium |
| Global messaging (WhatsApp) | [`global-messaging-platform.md`](../examples/social/global-messaging-platform.md) | [`chat-messenger.md`](../examples/social/chat-messenger.md) | Medium |
| Microblog (X) | [`microblog-timeline.md`](../examples/social/microblog-timeline.md) | [`news-feed.md`](../examples/social/news-feed.md) | Medium |
| Community forum (Reddit) | [`community-forum-platform.md`](../examples/social/community-forum-platform.md) | [`reviews-ratings.md`](../examples/commerce/reviews-ratings.md) | Medium |
| Community chat (Discord) | [`community-chat-platform.md`](../examples/social/community-chat-platform.md) | [`chat-messenger.md`](../examples/social/chat-messenger.md) | Medium |
| Ephemeral stories | [`ephemeral-stories-platform.md`](../examples/media/ephemeral-stories-platform.md) | [`video-on-demand-platform.md`](../examples/media/video-on-demand-platform.md) | Medium |
| Video conferencing | [`video-conferencing-platform.md`](../examples/media/video-conferencing-platform.md) | [`live-video-streaming.md`](../examples/media/live-video-streaming.md) | Medium |
| Travel booking | [`travel-booking-platform.md`](../examples/commerce/travel-booking-platform.md) | [`marketplace-listings.md`](../examples/commerce/marketplace-listings.md) | Medium |
| Auction marketplace | [`auction-marketplace.md`](../examples/commerce/auction-marketplace.md) | [`event-ticketing.md`](../examples/commerce/event-ticketing.md) | Medium |
| Visual discovery | [`visual-discovery-platform.md`](../examples/commerce/visual-discovery-platform.md) | [`product-search.md`](../examples/commerce/product-search.md) | Medium |

## AWS service drills (lighter than full rounds)

| Archetype | Primary drill | Product anchor | Coverage |
| --- | --- | --- | --- |
| S3 / object storage | [`aws/s3.md`](../examples/aws/s3.md) | VOD, data lake | Medium |
| DynamoDB / partitions | [`aws/dynamodb.md`](../examples/aws/dynamodb.md) | Feed keys, cart | Medium |
| Lambda / serverless | [`aws/lambda.md`](../examples/aws/lambda.md) | Webhooks, ETL | Medium |
| SQS + SNS | [`aws/sqs-sns.md`](../examples/aws/sqs-sns.md) | Async fan-out | Medium |
| Aurora / RDS | [`aws/aurora-rds.md`](../examples/aws/aurora-rds.md) | Ledger, OLTP | Medium |
| ElastiCache | [`aws/elasticache-redis.md`](../examples/aws/elasticache-redis.md) | Rate limits, cache | Medium |
| API Gateway | [`aws/api-gateway.md`](../examples/aws/api-gateway.md) | Edge API | Medium |
| CloudFront + ALB | [`aws/cloudfront-alb.md`](../examples/aws/cloudfront-alb.md) | CDN + ingress | Medium |
| MSK / Kinesis | [`aws/msk-kinesis.md`](../examples/aws/msk-kinesis.md) | Pipelines, tracking | Medium |
| EventBridge | [`aws/eventbridge.md`](../examples/aws/eventbridge.md) | Event routing | Medium |
| Step Functions | [`aws/step-functions.md`](../examples/aws/step-functions.md) | Sagas | Medium |
| ECS Fargate | [`aws/ecs-fargate.md`](../examples/aws/ecs-fargate.md) | App tier default | Medium |
| Cognito + IAM | [`aws/cognito-iam.md`](../examples/aws/cognito-iam.md) | Auth | Medium |
| OpenSearch | [`aws/opensearch.md`](../examples/aws/opensearch.md) | product-search | Medium |

Coverage scale (depth of interview practice, not template compliance):

- **Medium**: full v3 sections + capacity tiers; rehearse end-to-end once before interviews.
- **Strong**: gold exemplar in bucket or repeated drill — use for mock interviews.

Template compliance for all examples: [example-authoring-template.md](./example-authoring-template.md).
