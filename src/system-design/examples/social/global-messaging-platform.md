# Global messaging platform

## Introduction

A global messaging platform (WhatsApp / iMessage scale) optimizes **multi-region delivery**, **group fanout**, **media attachments**, and optional **E2E encryption** — extends [chat messenger](./chat-messenger.md) with **phone-number identity**, **low-bandwidth** clients, and **cross-region** presence.

**Primary users:** consumers (1:1, groups), businesses (API templates), operators (region failover).

**Interview pacing:** [60-minute runbook](../../topics/interview-runbook-60m.md) — deep dive **per-conversation ordering + group fanout + media CDN**.

Use [chat messenger](./chat-messenger.md) for full v3 depth; this doc is the **WhatsApp interview routing** variant.

## Requirements discovery

### Interview Q&A cheat sheet

| Lock (target) |
| --- |
| 2B users; 100B messages / day |
| Groups up to 1024 members |
| Media: images/video via CDN; metadata in DB |
| Multi-region: user home region for storage |
| E2E: optional deep dive (key distribution out of v1 API) |

## Architecture (user → database)

```mermaid
flowchart TB
 user([Mobile user])
 subgraph edge [Edge]
 cf[Amazon CloudFront · media]
 apigw[Amazon API Gateway]
 end
 gw[Message gateway · ECS]
 router[Region router · ECS]
 inbox[(DynamoDB · conversation log)]
 presence[(Redis · presence)]
 media[(Amazon S3 · attachments)]
 push[[SQS · push workers]]

 user --> cf
 user --> apigw --> gw --> router
 router --> inbox
 gw --> presence
 user -->|upload| cf --> media
 gw -.-> push
 router -->|fanout group| inbox

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
 class user user
 class cf,apigw edge
 class gw,router app
 class inbox,presence,media data
 class push async
```

**Narrative:** **Region router** pins conversation partition to user’s home region. **Gateway** appends message with monotonic `seq`; **group fanout** writes recipient inboxes in parallel batches. **Media** uploaded to S3 via presigned URL; message carries `media_key` only.

## Deep dive: delivery guarantees

- **Ordering:** total order per `conversation_id`; clients discard `seq <= last_ack`.
- **Offline:** store-and-forward; push via [notification platform](../platform/notification-platform.md).
- **E2E (optional):** server stores ciphertext blob; key exchange via Signal protocol — mention, don’t design full crypto unless asked.

## Related

- [Chat messenger](./chat-messenger.md) (gold-depth reference)
- [Notification platform](../platform/notification-platform.md)
- [S3 drill](../aws/s3.md)
- [DynamoDB drill](../aws/dynamodb.md)
