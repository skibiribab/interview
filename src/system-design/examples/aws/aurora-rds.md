# Amazon Aurora and RDS (service drill)

**Parent:** [`README.md`](./README.md) · **Topic:** [`../../topics/data-stores.md](../../topics/data-stores.md)

## When to use / when not

| Use when | Notes |
| --- | --- |
| Relational OLTP, joins, transactions | Aurora: storage/compute separation |
| Strong consistency on primary | Read replicas for read scale |
| Ledger, orders, accounts | ACID across rows |

| Avoid when | Why |
| --- | --- |
| Massive key-only horizontal shard needs | DynamoDB or sharding app layer |
| Global write leader with multi-master unless Aurora Global | Clarify write region |
| Analytics on primary | Replica or warehouse export |

## Mental model

- **Aurora:** 6 copies storage across AZs; faster failover than vanilla RDS.
- **Scaling:** read replicas; Aurora Serverless v2 for spiky.
- **Billing:** instance hours + storage GB + IOPS.

## Architecture sketch

```mermaid
flowchart TB
 api[App tier · ECS]
 primary[(Aurora primary)]
 replica[(Aurora read replica)]

 api -->|writes| primary
 api -->|reads| replica
 primary -->|async replication| replica

 class api app
 class primary,replica data

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
```

**Narrative:** Writes go to **primary**; read-heavy paths use **replicas** with replication lag called out in interview. Failover promotes replica or Aurora storage-backed recovery.

## Capacity and cost (whiteboard)

| What to count | Meter | Ballpark |
| --- | --- | --- |
| Instance | db.r6g.large × 730h | $50–200+/mo per instance |
| Storage | GB-mo | ~$0.10/GB Aurora |
| IOPS | provisioned or auto | spiky write workloads |

## Interview talking points

1. Explain **replication lag** on read-your-own-write vs eventual read replica.
2. **Connection pooling** (RDS Proxy) at high connection counts.
3. Migrations: expand/contract schema; backward compatible deploys.

## Product examples that use this service

| Example | How it shows up |
| --- | --- |
| [`fintech/core-banking-ledger.md`](../fintech/core-banking-ledger.md) | Ledger invariants |
| [`fintech/payment-workflow-platform.md`](../fintech/payment-workflow-platform.md) | Payment state rows |
| [`platform/rate-limiter.md`](../platform/rate-limiter.md) | Policy metadata OLTP |

## Related

- [AWS service drills index](./README.md)
- [AWS reference layout](../../topics/aws-reference-layout.md)
- [Topics index](../../topics-index.md)
- [Cloud capability matrix](../../topics/cloud-capability-matrix.md)
