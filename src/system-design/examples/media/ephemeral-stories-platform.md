# Ephemeral stories platform (Snapchat / IG Stories)

## Introduction

Stories are **short media** that **expire in 24h**, viewed in sequence by followers — write path is media upload + metadata; read path is CDN + view counter, not a ranked [feed ranking](../social/feed-ranking-service.md) problem.

**Company anchors:** Snapchat, Instagram Stories, WhatsApp Status.

## Requirements discovery

| Lock (target) |
| --- |
| 500M DAU posting stories |
| TTL 24 h hard delete |
| View list per story ring |
| p99 view &lt; 100 ms (CDN hit) |

## Architecture (user → database)

```mermaid
flowchart TB
 viewer([Viewer])
 creator([Creator])
 cf[Amazon CloudFront]
 api[Stories API · ECS]
 meta[(DynamoDB · story rings)]
 s3[(Amazon S3 · segments)]
 ttl[[EventBridge · expiry]]

 creator --> api --> meta
 creator -->|upload| cf --> s3
 viewer --> cf
 viewer --> api --> meta
 meta -.-> ttl --> s3

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
 class viewer,creator user
 class cf edge
 class api app
 class meta,s3 data
 class ttl async
```

**Narrative:** **Creator** uploads segments to **S3**; **DynamoDB** stores ordered segment IDs + `expires_at`. **Viewers** fetch manifest from API, stream from **CloudFront**. **EventBridge** triggers deletion at TTL.

## Deep dive

- **Viewers list** as append-only set per story (cap cardinality).
- **Prefetch** next segment while playing current.
- Reels long-form: [video on demand](./video-on-demand-platform.md).

## Related

- [Video on demand](./video-on-demand-platform.md)
- [S3 drill](../aws/s3.md)
- [EventBridge drill](../aws/eventbridge.md)
