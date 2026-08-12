# 🖥️ Frontend strategies

## 📇 Index

1. [Where frontend shows up in system design](#where-frontend-shows-up-in-system-design)
2. [Rendering models](#rendering-models)
3. [Data fetching and consistency](#data-fetching-and-consistency)
4. [Performance](#performance)
5. [Realtime UX](#realtime-ux)
6. [Security and abuse](#security-and-abuse)
7. [Interview checklist](#interview-checklist)

Client/app concerns that affect API and infrastructure choices. Pair with [api-design.md](./api-design.md), [caching.md](./caching.md), [edge-and-ingress.md](./edge-and-ingress.md).

## Where frontend shows up in system design

Interviewers rarely want pixel-perfect CSS. They want:

* How the **client** loads data without melting the backend
* **Caching** and CDN for assets/API
* **Auth** session vs token handling
* **Optimistic UI** vs strong consistency
* Mobile / web **offline** or weak-network behavior when relevant

## Rendering models

| Model | Idea | System impact |
| --- | --- | --- |
| **CSR** | SPA fetches JSON | Many API calls; need BFF or aggregation |
| **SSR** | HTML on server | Cache HTML at CDN; TTFB matters |
| **SSG / ISR** | Prebuild or revalidate pages | Great for catalog/content; webhook rebuilds |
| **BFF** | Backend-for-frontend | Tailors payloads per client; hides microservices |

**AWS:** CloudFront + S3 for static; SSR on ECS/Lambda; AppSync/API Gateway for APIs.

## Data fetching and consistency

* **Avoid N+1** — batch endpoints or GraphQL/BFF field resolvers with dataloaders.
* **Pagination** — infinite scroll ⇒ cursor APIs ([api-design.md](./api-design.md)).
* **Stale-while-revalidate** — show cache, refresh in background; label freshness if money involved.
* **Optimistic updates** — UI updates before ack; reconcile on failure (ids, version vectors).
* **Idempotent mutations** — retries from flaky mobile networks.

## Performance

* **CDN** for JS/CSS/images; cache-control / hashed filenames.
* **Code splitting** and critical CSS; image resizing at edge or dedicated service.
* **Core Web Vitals** as product SLIs when the prompt is consumer web.
* **API payload size** — sparse fieldsets; compress; avoid huge lists.

## Realtime UX

* **Polling** — simple; wasteful at scale.
* **SSE** — one-way server push over HTTP.
* **WebSockets** — bidirectional; sticky sessions / connection gateway (see chat examples).
* Prefer **push notifications** + thin poll for mobile battery ([notifications.md](./notifications.md)).

## Security and abuse

* Tokens in **httpOnly** cookies or secure storage; CSRF strategy for cookie sessions.
* Never put long-lived secrets in the JS bundle.
* Rate limit by user/device; bot protection at edge/WAF.
* XSS: treat all user HTML as untrusted; CSP.

## Interview checklist

1. CDN + cache headers for static.
2. BFF or aggregated read API if many microservices.
3. Explicit consistency story for cart/checkout vs feed.
4. Realtime choice justified (poll vs WS).
5. Failure UX: offline queue, retry, idempotency.

## 🔗 Related

- [Topics index](../topics-index.md)
- [API design](./api-design.md)
- [Caching](./caching.md)
- [Edge and ingress](./edge-and-ingress.md)
- [Notifications](./notifications.md)
- [AWS reference layout](./aws-reference-layout.md)
