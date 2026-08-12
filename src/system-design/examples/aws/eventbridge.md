# Amazon EventBridge (service drill)

**Parent:** [`README.md`](./README.md) · **Topic:** [`../../topics/messaging-async.md](../../topics/messaging-async.md)

## When to use / when not

| Use when | Notes |
| --- | --- |
| Event bus routing with rules | Schema registry optional |
| SaaS integrations | AWS service events |
| Scheduled cron triggers | Serverless schedules |

| Avoid when | Why |
| --- | --- |
| Kafka-scale throughput on single bus | MSK for firehose logs |
| Ordering guarantees across all events | Use FIFO SQS or Kafka partition |

## Mental model

- **Rules:** pattern match on detail field → targets (Lambda, SQS, Step Functions).
- **Billing:** per million events published.

## Architecture sketch

```mermaid
flowchart TB
 svc[Microservices]
 bus[Amazon EventBridge]
 lambda[Lambda]
 sfn[Step Functions]

 svc -->|PutEvents| bus
 bus --> lambda
 bus --> sfn

 class svc app
 class bus async
 class lambda,sfn app

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
```

**Narrative:** Services publish **domain events** to a bus; **rules** route to handlers without point-to-point coupling.

## Capacity and cost (whiteboard)

| What to count | Meter | Ballpark |
| --- | --- | --- |
| Events | million/mo | ~$1/M custom events |

## Interview talking points

1. **Event envelope** versioning for consumers.
2. Archive & replay (feature) for debugging.
3. Contrast with **SNS** topic fan-out.

## Product examples that use this service

| Example | How it shows up |
| --- | --- |
| [`event-driven/event-driven-order-pipeline.md`](../event-driven/event-driven-order-pipeline.md) | Domain choreography |

## Related

- [AWS service drills index](./README.md)
- [AWS reference layout](../../topics/aws-reference-layout.md)
- [Topics index](../../topics-index.md)
- [Cloud capability matrix](../../topics/cloud-capability-matrix.md)
