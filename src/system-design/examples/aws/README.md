# AWS service drills

**Parent:** [`../README.md`](../README.md)

One **focused page per commonly drawn AWS service** — when to use it, billing units, a small topology sketch, and links to full product examples. Not a replacement for [`topics/aws-reference-layout.md`](../../topics/aws-reference-layout.md) (composite pattern) or [`topics/cloud-services.md`](../../topics/cloud-services.md) (multi-cloud matrix).

**Template:** [`../../topics/aws-service-drill-template.md`](../../topics/aws-service-drill-template.md)
**Comfort scores:** [`../../topics/cloud-capability-matrix.md`](../../topics/cloud-capability-matrix.md)

## If the interviewer says…

| They mention… | Open |
| --- | --- |
| Object storage, blobs, static assets | [`s3.md`](./s3.md) |
| Key-value, partition key, hot shard | [`dynamodb.md`](./dynamodb.md) |
| Serverless function, webhook handler | [`lambda.md`](./lambda.md) |
| Queue, fan-out, decouple | [`sqs-sns.md`](./sqs-sns.md) |
| SQL, transactions, joins | [`aurora-rds.md`](./aurora-rds.md) |
| Redis, cache, session | [`elasticache-redis.md`](./elasticache-redis.md) |
| Public API, throttling at edge | [`api-gateway.md`](./api-gateway.md) |
| CDN, load balancer, HTTPS ingress | [`cloudfront-alb.md`](./cloudfront-alb.md) |
| Kafka, event stream, ordering | [`msk-kinesis.md`](./msk-kinesis.md) |
| Event bus, rules, schedules | [`eventbridge.md`](./eventbridge.md) |
| Workflow, saga, state machine | [`step-functions.md`](./step-functions.md) |
| Containers, long-running service | [`ecs-fargate.md`](./ecs-fargate.md) |
| Login, OAuth, IAM roles | [`cognito-iam.md`](./cognito-iam.md) |
| Full-text search, facets | [`opensearch.md`](./opensearch.md) |

## All drills

| File | Service | Deep rebuild (optional) |
| --- | --- | --- |
| [`s3.md`](./s3.md) | Amazon S3 | [`../infra/object-storage.md`](../infra/object-storage.md) |
| [`dynamodb.md`](./dynamodb.md) | DynamoDB | — |
| [`lambda.md`](./lambda.md) | AWS Lambda | — |
| [`sqs-sns.md`](./sqs-sns.md) | SQS + SNS | — |
| [`aurora-rds.md`](./aurora-rds.md) | Aurora / RDS | — |
| [`elasticache-redis.md`](./elasticache-redis.md) | ElastiCache (Redis) | — |
| [`api-gateway.md`](./api-gateway.md) | API Gateway | [`../platform/api-gateway-rate-limiting.md`](../platform/api-gateway-rate-limiting.md) |
| [`cloudfront-alb.md`](./cloudfront-alb.md) | CloudFront + ALB | — |
| [`msk-kinesis.md`](./msk-kinesis.md) | MSK / Kinesis | [`../event-driven/stream-processing-platform.md`](../event-driven/stream-processing-platform.md) |
| [`eventbridge.md`](./eventbridge.md) | EventBridge | — |
| [`step-functions.md`](./step-functions.md) | Step Functions | [`../infra/workflow-orchestration.md`](../infra/workflow-orchestration.md) |
| [`ecs-fargate.md`](./ecs-fargate.md) | ECS on Fargate | — |
| [`cognito-iam.md`](./cognito-iam.md) | Cognito + IAM | [`../platform/identity-session-service.md`](../platform/identity-session-service.md) |
| [`opensearch.md`](./opensearch.md) | OpenSearch | [`../commerce/product-search.md`](../commerce/product-search.md) |

## Related

- [High-profit app coverage](../../topics/high-profit-app-coverage.md)
- [Topics index](../../topics-index.md)
- [Product examples](../README.md)
