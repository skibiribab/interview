# Topic deep-dives

Interview-oriented notes: building blocks, architecture patterns, and prep overlays.

**Full index:** [`../topics-index.md`](../topics-index.md)

## Building blocks

| File | Focus |
| --- | --- |
| [`api-design.md`](./api-design.md) | REST, gRPC, idempotency, pagination, rate limits |
| [`data-stores.md`](./data-stores.md) | DB comparison matrix, SQL vs NoSQL, indexes, multi-store |
| [`caching.md`](./caching.md) | Cache-aside, invalidation, Redis vs CDN, stampedes |
| [`messaging-async.md`](./messaging-async.md) | Queues vs streams, SQS/SNS/Kafka, DLQ, orchestration |
| [`notifications.md`](./notifications.md) | Push/email/SMS pipelines, preferences, idempotent sends |
| [`concurrency.md`](./concurrency.md) | Races, locking |
| [`compute.md`](./compute.md) | ECS, Lambda, load balancing |
| [`deployment.md`](./deployment.md) | CI/CD, rolling/blue-green/canary, IaC |
| [`edge-and-ingress.md`](./edge-and-ingress.md) | CloudFront, ALB, API Gateway |
| [`frontend-strategies.md`](./frontend-strategies.md) | CSR/SSR/BFF, fetching, realtime UX, CDN |
| [`observability.md`](./observability.md) | Logs, metrics, SLOs, alarms that page |
| [`oncall-operations.md`](./oncall-operations.md) | Auto-mitigations from alarms, runbooks, toil reduction |
| [`reliability.md`](./reliability.md) | Retries, circuit breakers, degradation |
| [`security-networking.md`](./security-networking.md) | VPC, IAM, secrets |
| [`cloud-services.md`](./cloud-services.md) | AWS / GCP / Azure name matrix |
| [`cloud-capability-matrix.md`](./cloud-capability-matrix.md) | Self-assessed AWS comfort by capability |

## Architecture patterns

| File | Focus |
| --- | --- |
| [`aws-reference-layout.md`](./aws-reference-layout.md) | Canonical AWS topology + multi-cloud roles |
| [`event-driven-architecture.md`](./event-driven-architecture.md) | Outbox, contracts, choreography vs orchestration |

## Prep and authoring

| File | Focus |
| --- | --- |
| [`topic-priority.md`](./topic-priority.md) | A/B/C topic frequency for study order |
| [`system-catalog.md`](./system-catalog.md) | One row per system → example link |
| [`archetype-coverage-matrix.md`](./archetype-coverage-matrix.md) | Drills by product shape |
| [`interview-runbook-60m.md`](./interview-runbook-60m.md) | 60-minute mock cadence |
| [`high-profit-app-coverage.md`](./high-profit-app-coverage.md) | Company / app → which example |
| [`example-authoring-template.md`](./example-authoring-template.md) | Contract for `examples/**` product rounds |
| [`aws-service-drill-template.md`](./aws-service-drill-template.md) | Contract for `examples/aws/*` |
| [`architecture-diagram-conventions.md`](./architecture-diagram-conventions.md) | Mermaid palette for examples |
