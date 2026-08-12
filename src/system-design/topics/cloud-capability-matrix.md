# Cloud capability comfort matrix

Source of truth for names: [`cloud-services.md`](./cloud-services.md).

Comfort scale: `0-unknown`, `1-read`, `2-toy`, `3-debugged`, `4-owned-in-prod`, `5-taught-others`

| Capability | AWS | GCP | Azure | Theory | Practice anchor | Comfort | Last refreshed |
| --- | --- | --- | --- | --- | --- | --- | --- |
| Object storage | S3 | Cloud Storage | Blob Storage | Strong | Used for artifacts/document flows | 4 | 2026-05-10 |
| Relational DB | RDS/Aurora | Cloud SQL/AlloyDB | Azure SQL | Strong | Service-backed transactional workloads | 4 | 2026-05-10 |
| Key-value store | DynamoDB | Firestore/Bigtable | Cosmos DB | Strong | High-throughput metadata patterns | 3 | 2026-05-10 |
| In-memory cache | ElastiCache | Memorystore | Azure Cache for Redis | Strong | Caching/session and throttling aids | 3 | 2026-05-10 |
| Message queue | SQS | Cloud Tasks/PubSub | Service Bus | Strong | Async workflows, retries, buffering | 4 | 2026-05-10 |
| Pub/sub | SNS | Pub/Sub | Event Grid/Topics | Strong | Fan-out notification patterns | 4 | 2026-05-10 |
| Managed Kafka | MSK | Kafka on GKE/Confluent | Event Hubs (Kafka protocol) | Strong | Kafka-style design and consumer groups | 3 | 2026-05-10 |
| Event bus routing | EventBridge | Eventarc | Event Grid | Strong | Event-driven integration patterns | 3 | 2026-05-10 |
| Workflow/state machine | Step Functions | Workflows | Logic Apps/Durable Functions | Strong | Saga/orchestration designs | 3 | 2026-05-10 |
| Serverless functions | Lambda | Cloud Functions/Run | Azure Functions | Strong | Event handlers and automation | 4 | 2026-05-10 |
| Containers | ECS/Fargate | Cloud Run/GKE | Container Apps/AKS | Medium | Service deployment concepts | 3 | 2026-05-10 |
| Kubernetes | EKS | GKE | AKS | Medium | Operational understanding and design | 2 | 2026-05-10 |
| API gateway | API Gateway | API Gateway | API Management | Strong | Edge policy/rate limiting designs | 4 | 2026-05-10 |
| CDN | CloudFront | Cloud CDN | Front Door/CDN | Medium | Static acceleration patterns | 3 | 2026-05-10 |
| DNS | Route 53 | Cloud DNS | Azure DNS | Medium | Basic routing/failover knowledge | 3 | 2026-05-10 |
| Identity | IAM/Cognito | IAM/Identity Platform | Entra ID/Managed identities | Medium | Authn/authz architecture | 3 | 2026-05-10 |
| Secrets | Secrets Manager/SSM | Secret Manager | Key Vault | Medium | Secrets handling in service pipelines | 3 | 2026-05-10 |
| Monitoring | CloudWatch | Cloud Monitoring | Azure Monitor | Strong | Metrics/alerts in production ops | 4 | 2026-05-10 |
| Logging | CloudWatch Logs | Cloud Logging | Log Analytics | Strong | Incident investigations | 4 | 2026-05-10 |
| Tracing | X-Ray | Cloud Trace | Application Insights | Medium | Distributed tracing basics | 3 | 2026-05-10 |
| Data warehouse | Redshift | BigQuery | Synapse | Medium | Analytical architecture understanding | 2 | 2026-05-10 |
| Stream processing | Kinesis/Flink | Dataflow | Stream Analytics | Medium | Streaming concepts and tradeoffs | 2 | 2026-05-10 |
| Search | OpenSearch | Vertex AI Search | Azure AI Search | Medium | Search service patterns | 2 | 2026-05-10 |
| WAF/firewall | AWS WAF | Cloud Armor | Azure WAF | Medium | Security boundary concepts | 2 | 2026-05-10 |
| VPC-internal networking | VPC / interface endpoints | VPC / PSC | VNet / service endpoints | Medium | Connectivity and segmentation designs | 3 | 2026-05-10 |

## Note

Always communicate cloud mappings as equivalent capabilities, not identical products.
