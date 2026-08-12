# Community chat platform (Discord / Slack)

## Introduction

Community chat adds **servers/workspaces**, **channels**, **roles**, and **permissions** on top of [chat messenger](./chat-messenger.md) 1:1/group semantics — interview focus is **permission cache** and **channel fanout**.

**Company anchors:** Discord, Slack, Microsoft Teams.

## Requirements discovery

| Lock (target) |
| --- |
| 200M MAU |
| 10M messages / minute peak |
| Channels per server up to 500 |
| Role-based read/post ACL |

## Architecture (user → database)

```mermaid
flowchart TB
 user([Member])
 gw[Gateway · WebSocket]
 perm[Permission service · ECS]
 chat[Channel service · ECS]
 acl[(Redis · ACL cache)]
 msgs[(DynamoDB · messages by channel)]
 members[(Aurora · membership)]

 user --> gw --> chat --> msgs
 chat --> perm --> acl
 perm --> members
 gw -->|subscribe channel| chat

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
 class user user
 class gw edge
 class perm,chat app
 class acl,msgs,members data
```

**Narrative:** **Gateway** authenticates and subscribes socket to `channel_id` list. **Permission service** resolves role → ACL (cached). **Channel service** appends messages with per-channel sequence.

## Deep dive

- **ACL cache** invalidation on role change (pub/sub).
- **Voice** (Discord): defer to [video conferencing](../media/video-conferencing-platform.md).
- Full message ordering: [chat messenger](./chat-messenger.md).

## Related

- [Chat messenger](./chat-messenger.md)
- [CRUD data manager](../infra/crud-data-manager.md) (multi-tenant SaaS)
- [Global messaging](./global-messaging-platform.md)
