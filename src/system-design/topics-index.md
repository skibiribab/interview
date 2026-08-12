# Topics index

Keyword map for [`topics/`](./topics/README.md). Use during prep and mid-interview when you need the right note.

## Building blocks

| Topic | Open | Keywords |
| --- | --- | --- |
| API design | [`topics/api-design.md`](./topics/api-design.md) | REST, gRPC, WebSocket, idempotency, pagination, versioning, 429 |
| Data stores / DB compare | [`topics/data-stores.md`](./topics/data-stores.md) | SQL, Postgres, Aurora, DynamoDB, GSI, Redis, S3, OpenSearch |
| Caching | [`topics/caching.md`](./topics/caching.md) | cache-aside, TTL, stampede, Redis, CDN |
| Queues / messaging | [`topics/messaging-async.md`](./topics/messaging-async.md) | SQS, SNS, Kafka, MSK, Kinesis, DLQ, Step Functions |
| Notifications | [`topics/notifications.md`](./topics/notifications.md) | push, email, SMS, preferences, fan-out |
| Compute | [`topics/compute.md`](./topics/compute.md) | ECS, Fargate, EKS, Lambda |
| Server deployment | [`topics/deployment.md`](./topics/deployment.md) | CI/CD, blue-green, canary, IaC |
| Edge / ingress | [`topics/edge-and-ingress.md`](./topics/edge-and-ingress.md) | CloudFront, ALB, API Gateway, WAF |
| Frontend strategies | [`topics/frontend-strategies.md`](./topics/frontend-strategies.md) | CSR, SSR, BFF, optimistic UI |
| Observability / alarms | [`topics/observability.md`](./topics/observability.md) | logs, metrics, traces, SLO, CloudWatch |
| On-call efficiency | [`topics/oncall-operations.md`](./topics/oncall-operations.md) | auto-remediation, runbooks, toil |
| Reliability | [`topics/reliability.md`](./topics/reliability.md) | retries, circuit breaker |
| Concurrency | [`topics/concurrency.md`](./topics/concurrency.md) | races, locks |
| Security / networking | [`topics/security-networking.md`](./topics/security-networking.md) | VPC, IAM, secrets |
| Cloud name matrix | [`topics/cloud-services.md`](./topics/cloud-services.md) | AWS ↔ GCP ↔ Azure |
| Cloud capability self-check | [`topics/cloud-capability-matrix.md`](./topics/cloud-capability-matrix.md) | comfort scores |

## Architecture patterns

| Topic | Open | Keywords |
| --- | --- | --- |
| AWS reference layout | [`topics/aws-reference-layout.md`](./topics/aws-reference-layout.md) | topology, MSK, cache, S3 tiers |
| Event-driven architecture | [`topics/event-driven-architecture.md`](./topics/event-driven-architecture.md) | outbox, contracts, choreography, orchestration |

## Prep and authoring

| Topic | Open | Keywords |
| --- | --- | --- |
| Topic priority (A/B/C) | [`topics/topic-priority.md`](./topics/topic-priority.md) | frequency, study order |
| System catalog | [`topics/system-catalog.md`](./topics/system-catalog.md) | inventory, deep-dive axis |
| Archetype matrix | [`topics/archetype-coverage-matrix.md`](./topics/archetype-coverage-matrix.md) | product shape drills |
| 60-minute runbook | [`topics/interview-runbook-60m.md`](./topics/interview-runbook-60m.md) | mock interview cadence |
| Company / app coverage | [`topics/high-profit-app-coverage.md`](./topics/high-profit-app-coverage.md) | Meta, Uber, Amazon → examples |
| Example authoring template | [`topics/example-authoring-template.md`](./topics/example-authoring-template.md) | v3 contract |
| AWS drill template | [`topics/aws-service-drill-template.md`](./topics/aws-service-drill-template.md) | service page contract |
| Diagram conventions | [`topics/architecture-diagram-conventions.md`](./topics/architecture-diagram-conventions.md) | Mermaid palette |

## Suggested study order

1. [`topic-priority.md`](./topics/topic-priority.md) → pick A-tier themes  
2. Building blocks: data-stores → caching → messaging → api-design  
3. [`interview-runbook-60m.md`](./topics/interview-runbook-60m.md) + one [`examples/`](./examples/README.md) round  
4. Patterns: [`aws-reference-layout.md`](./topics/aws-reference-layout.md), [`event-driven-architecture.md`](./topics/event-driven-architecture.md)  
5. Ops: observability → oncall-operations → deployment  

## Related

- [Topics folder](./topics/README.md)
- [System design hub](./README.md)
- [Examples](./examples/README.md)
