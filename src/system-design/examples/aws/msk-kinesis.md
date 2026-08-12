# Amazon MSK and Kinesis Data Streams (service drill)

**Parent:** [`README.md`](./README.md) · **Topic:** [`../../topics/messaging-async.md](../../topics/messaging-async.md)

## When to use / when not

| Use when | Notes |
| --- | --- |
| High-volume ordered event log | Partitions = parallelism unit |
| Replay for reprocessing | Retention hours–days (configurable) |
| Stream analytics pipelines | Consumers with consumer groups |

| Avoid when | Why |
| --- | --- |
| Simple task queue with few consumers | SQS cheaper/simpler |
| Many tiny messages if batching possible | Per-shard overhead |
| Exactly-once end-to-end without design | Idempotent consumers + offsets |

## Mental model

- **Kinesis:** shards provision throughput; hot shard problem.
- **MSK:** managed Kafka; broker hours + storage.
- **Consumers:** at-least-once; commit offset after side effect.

## Architecture sketch

```mermaid
flowchart TB
 producers[Producers · ECS]
 stream[[Amazon MSK / Kinesis]]
 consumers[Consumers · ECS]

 producers -->|append| stream
 stream -->|poll| consumers

 class producers,consumers app
 class stream async

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
```

**Narrative:** Producers append **ordered partitions**; consumer groups divide partitions for scale. **Lag** drives autoscaling policy.

## Capacity and cost (whiteboard)

| What to count | Meter | Ballpark |
| --- | --- | --- |
| Kinesis shards | shard-h | ~$0.015/h per shard |
| MSK brokers | broker-h + storage | dominates at scale |
| Ingress/egress | GB | cross-AZ adds up |

## Interview talking points

1. **Partition key** choice = interview core.
2. **Retention** vs disk cost; compaction in MSK.
3. Compare **Kinesis** (AWS-native) vs **MSK** (Kafka ecosystem).

## Product examples that use this service

| Example | How it shows up |
| --- | --- |
| [`event-driven/stream-processing-platform.md`](../event-driven/stream-processing-platform.md) | Windowed state |
| [`logistics/real-time-delivery-tracking.md`](../logistics/real-time-delivery-tracking.md) | Location events |
| [`platform/url-shortener.md`](../platform/url-shortener.md) | Click stream |

## Related

- [AWS service drills index](./README.md)
- [AWS reference layout](../../topics/aws-reference-layout.md)
- [Topics index](../../topics-index.md)
- [Cloud capability matrix](../../topics/cloud-capability-matrix.md)
