# ☁️ Cloud services by provider (quick reference)

**Parent:** [`README.md`](./README.md) · **Topics:** [`topics-index.md`](../topics-index.md)

## 📇 Index

1. [🧾 Summary](#-summary)
2. [🌐 Provider matrix](#-provider-matrix)
3. [📘 Interview angles](#-interview-angles)
4. [🔬 Rebuild drills (examples)](#-rebuild-drills-examples)
5. [🔗 Related](#-related)

## 🧾 Summary

One-page **name mapping** across the three hyperscalers (**AWS**, **Google Cloud**, **Microsoft Azure**) for services you draw or mention in interviews. Cells are **closest equivalents**, not identical products—semantics (ordering, consistency, quotas) always differ.

For **how to sketch** rebuilding S3-class or Step Functions–class systems, see the linked drills under [examples](../examples/README.md).

## 🌐 Provider matrix

Rough **equivalence only**; verify in vendor docs before any real architecture decision.

| Capability | AWS | Google Cloud | Azure |
| --- | --- | --- | --- |
| Object storage | Amazon S3 | Cloud Storage | Blob Storage |
| Block volume | Amazon EBS | Persistent Disk | Managed Disks |
| Shared file (NFS) | Amazon EFS | Filestore | Azure Files |
| Relational DB | Amazon RDS / Aurora | Cloud SQL / AlloyDB | Azure SQL Database / Flexible Server |
| Key-value / wide-column | Amazon DynamoDB | Firestore; Bigtable | Azure Cosmos DB (API families) |
| In-memory cache | Amazon ElastiCache | Memorystore | Azure Cache for Redis |
| Message queue | Amazon SQS | Cloud Tasks; Pub/Sub (pull differs) | Service Bus queues; Storage Queues |
| Pub/sub fan-out | Amazon SNS | Pub/Sub | Event Grid; Service Bus topics |
| Managed Kafka | Amazon MSK | Confluent / Kafka on GKE | Event Hubs (Kafka protocol) |
| Event bus / routing | Amazon EventBridge | Eventarc; Pub/Sub | Event Grid |
| Workflow / state machine | AWS Step Functions | Workflows | Logic Apps; Durable Functions |
| Serverless functions | AWS Lambda | Cloud Functions; Cloud Run | Azure Functions |
| Long-running containers | Amazon ECS on Fargate | Cloud Run; GKE | Container Apps; AKS |
| Kubernetes | Amazon EKS | GKE | AKS |
| Container registry | Amazon ECR | Artifact Registry | Azure Container Registry |
| CDN | Amazon CloudFront | Cloud CDN | Azure Front Door; Azure CDN |
| L7 HTTP load balancer | Application Load Balancer | Cloud Load Balancing (HTTP/S) | Application Gateway |
| L4 / TCP load balancer | Network Load Balancer | Network TCP/UDP LB | Azure Load Balancer |
| API gateway | Amazon API Gateway | API Gateway | Azure API Management |
| DNS | Amazon Route 53 | Cloud DNS | Azure DNS |
| Identity / directory | AWS IAM; Cognito; IAM Identity Center | IAM; Identity Platform; Workspace | Microsoft Entra ID; Managed identities |
| Secrets | AWS Secrets Manager; SSM Parameter Store | Secret Manager | Azure Key Vault |
| Certificates (TLS) | AWS Certificate Manager | Certificate Manager | Key Vault certificates |
| WAF / L7 firewall | AWS WAF | Cloud Armor | WAF on Application Gateway / Front Door |
| VPC / isolated network | Amazon VPC | VPC | Virtual Network |
| SaaS / API attachment (no public internet) | AWS interface VPC endpoints | Google PSC | Azure service endpoints |
| Log aggregation | Amazon CloudWatch Logs | Cloud Logging | Log Analytics |
| Metrics / monitoring | Amazon CloudWatch | Cloud Monitoring | Azure Monitor |
| Distributed trace | AWS X-Ray | Cloud Trace | Application Insights |
| Data warehouse | Amazon Redshift | BigQuery | Azure Synapse dedicated pools |
| Stream processing | Amazon Kinesis Data Analytics; Managed Flink | Dataflow | Stream Analytics |
| Search (managed) | Amazon OpenSearch Service | Vertex AI Search (product varies) | Azure AI Search |
| Backup | AWS Backup | Backup and DR Service | Azure Backup |
| Outbound email | Amazon SES | (third-party common); Gmail API not same | Azure Communication Services Email |

## 📘 Interview angles

- **Say “equivalent, not identical”** when comparing queues, Kafka protocol surfaces, or Cosmos multi-model APIs.
- **Pin one dimension** the interviewer cares about: **ordering**, **delivery** (at-least-once vs exactly-once), **regional failover**, **cost model** (egress, API calls, storage class).
- **Draw one cloud** consistently; use this table only to **translate** if they name another provider.

## 🔬 Service drills (examples)

| Kind | Index |
| --- | --- |
| **Per-service interview drills** (S3, DynamoDB, Lambda, …) | [`examples/aws/README.md`](../examples/aws/README.md) |
| **S3-class deep rebuild** | [`infra/object-storage.md`](../examples/infra/object-storage.md) |
| **Step Functions–class deep rebuild** | [`infra/workflow-orchestration.md`](../examples/infra/workflow-orchestration.md) |

## 🔗 Related

- [Topics index](../topics-index.md)
- [Examples hub](../examples/README.md)
- [Event ticketing (example)](../examples/commerce/event-ticketing.md)
- [Collaborative document (example)](../examples/social/collaborative-document.md)
- [AWS reference layout](./aws-reference-layout.md)
- [Data stores](./data-stores.md)
- [Messaging and async](./messaging-async.md)
- [Edge and ingress](./edge-and-ingress.md)
- [System design README](../README.md)
