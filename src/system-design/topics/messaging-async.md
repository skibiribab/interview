# 📬 Queues, streams, and async messaging

## 📇 Index

1. [Delivery semantics](#delivery-semantics)
2. [Queue vs stream vs pub/sub](#queue-vs-stream-vs-pubsub)
3. [Partitioning and ordering](#partitioning-and-ordering)
4. [Batching and DLQs](#batching-and-dlqs)
5. [Product comparison](#product-comparison)
6. [Workflow orchestration](#workflow-orchestration)

Delivery semantics, partitioning, DLQs, and orchestration. Maps to **Amazon SQS**, **Amazon SNS**, **Amazon MSK**, **Amazon Kinesis**, **Amazon EventBridge**, **AWS Step Functions**.

User-facing push (email/push/SMS) is covered in [notifications.md](./notifications.md)—this file is the **transport** layer.

## Delivery semantics

* **At-most-once** — may lose; no retries (metrics fire-and-forget).
* **At-least-once** — retries until ack; **duplicates**; need idempotent consumers (default interview answer).
* **Exactly-once** — end-to-end is rare/expensive; usually “effectively once” via idempotency keys + dedupe store.

## Queue vs stream vs pub/sub

| Pattern | Behavior | Pick when |
| --- | --- | --- |
| **Queue** (competing consumers) | Each message → one worker | Jobs, retries, backlog smoothing |
| **Pub/sub** | One publish → many subscriptions | Fan-out (notify search, cache, analytics) |
| **Log / stream** | Durable ordered partitions; replay | Event sourcing-ish, multiple consumer groups, reprocess |

## Partitioning and ordering

* Hash a stable key (`user_id`, `order_id`) → partition/shard.
* Same key ⇒ same partition ⇒ sequential processing without distributed locks.
* More partitions ⇒ throughput; hot keys still hurt.

## Batching and DLQs

* Poll/process in **batches** for efficiency; tune size vs latency.
* **DLQ** after N failures — poison pills must not block the main queue.
* Alert on DLQ depth; runbook to replay or discard.

## Product comparison

| Product | Model | Interview fit |
| --- | --- | --- |
| **SQS** | Managed queue; standard (best-effort) or FIFO | Simple async work, buffering API → workers |
| **SNS** | Pub/sub topics → SQS/Lambda/HTTP | Fan-out + filter policies |
| **EventBridge** | Event bus + rules | SaaS/AWS event routing, scheduled rules |
| **MSK (Kafka)** | Durable log, consumer groups, replay | Multi-subscriber event platform |
| **Kinesis Data Streams** | AWS-native shards | AWS-centric streaming + Lambda/Flink |
| **RabbitMQ** (portable) | Broker queues/exchanges | Classic microservice messaging (name in prose) |

**SQS vs Kafka:** SQS = “get work done once”; Kafka = “many systems read the same history.”

**MSK vs Kinesis:** Kafka ecosystem / multi-consumer log → MSK; AWS-native shard stream → Kinesis.

## Workflow orchestration

Multi-step sagas: **Step Functions** (Standard vs Express), or portable **Temporal**-style durable execution (prose). Design: idempotent activities, timeouts, compensation, correlation IDs ([observability.md](./observability.md)).

## 🔗 Related

- [Topics index](../topics-index.md)
- [Notifications](./notifications.md)
- [Reliability](./reliability.md)
- [Observability](./observability.md)
- [On-call operations](./oncall-operations.md)
- [Compute](./compute.md)
- [AWS reference layout](./aws-reference-layout.md)
