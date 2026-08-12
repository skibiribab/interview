# Transactional email delivery platform

## Introduction

High-volume **transactional email** (receipts, password reset, notifications) with **queueing**, **provider failover**, **bounce/complaint** handling, and **reputation** protection.

**Primary users:** product teams (send API), deliverability ops (domain warmup), compliance (unsubscribe).

Distinct from [notification platform](./notification-platform.md) (**push/SMS** channels).

**Interview pacing:** Deep dive **queue + reputation + idempotent send**.

## Requirements discovery

| Lock (target) |
| --- |
| 500M emails / day |
| p99 enqueue &lt; 100 ms |
| At-least-once send with dedupe |
| Separate IP pools per domain reputation |

## Architecture (user → database)

```mermaid
flowchart TB
 svc[Product services]
 api[Email API · ECS]
 q[[Amazon SQS · priority queues]]
 worker[Send workers · ECS]
 ses[Amazon SES]
 meta[(DynamoDB · send log)]
 bounce[[SNS · bounce/complaint]]

 svc --> api --> q --> worker --> ses
 ses -.-> bounce --> worker
 worker --> meta

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
 class svc app
 class api,worker app
 class meta data
 class q,bounce async
```

**Narrative:** **API** enqueues templated jobs; **workers** render and send via **SES** with per-recipient dedupe key. **Bounces** suppress future sends to bad addresses.

## Deep dive: deliverability

- **Dedicated vs shared** IPs; warmup schedule.
- **Suppression list** global; complaint rate alarms.
- **Template versioning** and sandbox for new senders.

## Related

- [Notification platform](./notification-platform.md)
- [SQS/SNS drill](../aws/sqs-sns.md)
- [Identity service](./identity-session-service.md)
