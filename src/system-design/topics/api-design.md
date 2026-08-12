# 📡 API design

## 📇 Index

1. [Protocol choice](#protocol-choice)
2. [Resource design](#resource-design)
3. [Idempotency](#idempotency)
4. [Versioning](#versioning)
5. [Pagination](#pagination)
6. [Errors and contracts](#errors-and-contracts)
7. [Auth, rate limits, and backpressure](#auth-rate-limits-and-backpressure)
8. [Sync vs async APIs](#sync-vs-async-apis)

Public **REST**, internal **gRPC**, HTTP ergonomics. Ingress: [edge-and-ingress.md](./edge-and-ingress.md). Load balancing: [compute.md](./compute.md).

## Protocol choice

| | REST/JSON | gRPC | WebSocket / SSE |
| --- | --- | --- | --- |
| Best for | Public/partner HTTP | Service-to-service | Real-time push |
| Contract | OpenAPI | Protobuf | App-level |
| Browser | Natural | Limited | Native WS / EventSource |
| Debug | curl-friendly | Harder | Sessionful |

**Rule:** REST outside; gRPC inside; WS/SSE when the server must push.

**AWS:** API Gateway or ALB for public REST; ALB/NLB for internal gRPC.

## Resource design

* Nouns in paths: `/trips/{tripId}`, not `/createTrip`.
* Path params = identity; query = filter/sort/page; headers = auth/trace/idempotency.
* Prefer coarse resources over chatty N+1 endpoints; offer **batch** or **expand** when needed.
* **HATEOAS** rarely required in interviews—clarity > purity.

## Idempotency

Safe retries need idempotent writes.

* `PUT`/`DELETE` often naturally idempotent; `POST` needs **Idempotency-Key** (or client-generated UUID resource id).
* Store key → response for TTL window; same key + same body ⇒ same result; conflict on mismatch.

## Versioning

* **URI** `/v1/...` — explicit, cacheable, easy to route.
* **Header** `Accept-Version` — clean URLs, harder to debug.
* Prefer **additive** changes; breaking changes ⇒ new version + sunset policy.

## Pagination

* **Offset** — simple; slow/inconsistent under inserts at high offsets.
* **Cursor** — stable for feeds; needs sort key (id/time).

Prefer cursors for large or frequently updated lists: `?after=trip_123&limit=20`.

## Errors and contracts

Use precise status codes:

* `400` validation · `401` auth · `403` forbidden · `404` missing · `409` conflict · `429` rate limit · `5xx` server

Return a **stable error body** (`code`, `message`, `request_id`). Publish **OpenAPI** / protobuf as the contract; contract tests in CI.

## Auth, rate limits, and backpressure

* **AuthN/Z** — OAuth2/OIDC, mTLS internal, signed webhooks for partners.
* **Rate limits** — per API key / user / IP; return `429` + `Retry-After`.
* **Timeouts** — every outbound call; never hang the request thread.
* **Bulkheads** — isolate pools so one dependency cannot exhaust the service.

See [reliability.md](./reliability.md) and [edge-and-ingress.md](./edge-and-ingress.md).

## Sync vs async APIs

* **Sync** — client needs the result now (read, small write).
* **Accepted async** — `202` + `Location` job URL, or return id and process via queue ([messaging-async.md](./messaging-async.md)).
* **Webhooks** — partner callbacks; verify signatures; idempotent handlers.

External HTTP: treat as unreliable dependency (timeouts, retries, circuit breaker).

## 🔗 Related

- [Topics index](../topics-index.md)
- [Edge and ingress](./edge-and-ingress.md)
- [Frontend strategies](./frontend-strategies.md)
- [Compute](./compute.md)
- [Reliability](./reliability.md)
- [AWS reference layout](./aws-reference-layout.md)
