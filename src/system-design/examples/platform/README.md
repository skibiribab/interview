# Platform utility examples

Cross-cutting infrastructure: ingress policy, limits, flags, jobs, notifications, short links, audit, replication digestion.

| Example | Deep dive |
| --- | --- |
| [`url-shortener.md`](./url-shortener.md) | Keyspace + redirect cache (gold) |
| [`rate-limiter.md`](./rate-limiter.md) | Distributed counters |
| [`api-gateway-rate-limiting.md`](./api-gateway-rate-limiting.md) | Auth chain + throttling |
| [`distributed-job-scheduler.md`](./distributed-job-scheduler.md) | Leases + duplicate suppression |
| [`feature-flag-platform.md`](./feature-flag-platform.md) | Config propagation |
| [`notification-platform.md`](./notification-platform.md) | Multi-channel fanout |
| [`cross-service-audit-logging.md`](./cross-service-audit-logging.md) | Immutable audit log |
| [`sequential-replica-digestion.md`](./sequential-replica-digestion.md) | MEX + lag (gold) |
| [`identity-session-service.md`](./identity-session-service.md) | Sessions + OAuth |
| [`ads-auction-platform.md`](./ads-auction-platform.md) | RTB + pacing |
| [`email-delivery-platform.md`](./email-delivery-platform.md) | SMTP pipeline + reputation |

[← All examples](../README.md)
