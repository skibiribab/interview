# 🔔 Notifications

## 📇 Index

1. [Channels and requirements](#channels-and-requirements)
2. [Architecture shape](#architecture-shape)
3. [Fan-out and preferences](#fan-out-and-preferences)
4. [Reliability and idempotency](#reliability-and-idempotency)
5. [Provider and rate limits](#provider-and-rate-limits)
6. [Interview checklist](#interview-checklist)

Push notifications, email, SMS, in-app inbox. Builds on [messaging-async.md](./messaging-async.md) and [api-design.md](./api-design.md). Example deep-dive: [`../examples/platform/notification-platform.md`](../examples/platform/notification-platform.md).

## Channels and requirements

| Channel | Latency | Reliability expectation | Typical failure |
| --- | --- | --- | --- |
| In-app / feed | Seconds | High (your infra) | Bad fan-out query |
| Push (APNs/FCM) | Seconds | Best-effort + retry | Token invalid, provider outage |
| Email | Minutes OK | At-least-once + dedupe | Bounce, spam, provider limits |
| SMS | Seconds | Expensive; strict opt-in | Carrier filtering, cost |

Always capture **opt-in / preference** and **quiet hours** before sending.

## Architecture shape

```text
Producer (order service) → event bus/queue → notification service
    → preference check → template render → channel workers → providers
    → delivery status / DLQ / inbox write
```

* **Do not** call APNs/SendGrid synchronously from the checkout request path.
* Persist a **notification intent** (or outbox event) so crashes do not lose the send.
* Separate **priority** lanes (security OTP vs marketing).

## Fan-out and preferences

* **Topic subscriptions** or per-user preference rows (`user_id`, `channel`, `category`, `enabled`).
* Collapse / digest marketing; never digest security alerts.
* For large audiences, **fan-out asynchronously** (expand audience → many jobs); avoid N provider calls in one API request.

## Reliability and idempotency

* **Idempotency key** per logical notification (`order_id + type + channel`) so retries do not double-text.
* Store provider message id + status webhooks (delivered, bounced, opened).
* DLQ + alarm on sustained failure ([observability.md](./observability.md), [oncall-operations.md](./oncall-operations.md)).

## Provider and rate limits

* Abstract providers behind an interface; dual-vendor for email if SLA is strict.
* Respect **provider rate limits**; shard workers; backoff on `429`.
* Template + locale versioning; never embed secrets in client-rendered templates for push deep links without signing.

## Interview checklist

1. Sync API accepts “notify” → **202** + async pipeline.
2. Preferences + unsubscribe.
3. At-least-once + idempotent sends.
4. Per-channel workers and SLAs.
5. Metrics: send rate, success, bounce, queue lag; page on OTP pipeline failures.

## 🔗 Related

- [Topics index](../topics-index.md)
- [Messaging and async](./messaging-async.md)
- [API design](./api-design.md)
- [Observability](./observability.md)
- [Notification platform example](../examples/platform/notification-platform.md)
- [AWS reference layout](./aws-reference-layout.md)
