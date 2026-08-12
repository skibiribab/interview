# 🛡️ Failure handling and reliability

## 📇 Index

1. [7. Failure handling & reliability](#7-failure-handling--reliability)

Retries, timeouts, circuit breakers, and graceful degradation. Ties to [messaging-async.md](./messaging-async.md) (DLQ, at-least-once) and [api-design.md](./api-design.md) (idempotency).

## 7. Failure Handling & Reliability

* Retries with exponential backoff
 * Increase delay between retries to reduce load
* Timeouts everywhere
 * Never wait indefinitely for a response
* Circuit breakers
 * Stop sending requests to unhealthy dependencies
* Graceful degradation
 * Reduce functionality instead of failing completely

**Kafka / MSK replay:** When consumers use **at-least-once** delivery, combine retries with **idempotent** processing so **replays** do not double-apply side effects. Poison messages belong in a **DLQ** path or dead-letter topic (see [Dead-Letter Queues (DLQ)](./messaging-async.md#dead-letter-queues-dlq)).

**AWS Step Functions** built-in retries map cleanly to **transient** downstream failures; pair with **idempotent** Lambda or activity implementations.

## 🔗 Related

- [Topics index](../topics-index.md)
- [Messaging and async](./messaging-async.md)
- [API design](./api-design.md)
- [AWS reference layout]./aws-reference-layout.md
