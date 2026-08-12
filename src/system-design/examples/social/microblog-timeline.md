# Microblog timeline (X / Twitter)

## Introduction

A microblog serves a **home timeline** of short posts from follows, plus **global trending** and **search**. Unlike generic [news feed](./news-feed.md), emphasize **chronological vs ranked** modes, **retweet/quote** fanout, and **write-heavy celebrities**.

**Company anchors:** X (Twitter), Threads (Meta).

**Interview pacing:** [60-minute runbook](../../topics/interview-runbook-60m.md) — deep dive **timeline merge + hot-key fanout**.

## Requirements discovery

| Lock (target) |
| --- |
| 500M MAU; 500M posts / day |
| Home timeline p99 &lt; 200 ms |
| Celebrity with 100M followers: async fanout |
| Trending: top 50 topics / region |

## Architecture (user → database)

```mermaid
flowchart TB
 user([User])
 subgraph edge [Edge]
 apigw[Amazon API Gateway]
 end
 post[Post service · ECS]
 timeline[Timeline API · ECS]
 fanout[Fan-out workers · ECS]
 tweets[(DynamoDB · tweets)]
 home[(Redis · home timelines)]
 trend[(Redis · trending counters)]

 user --> apigw --> post --> tweets
 post -.-> fanout --> home
 user --> apigw --> timeline --> home
 post -.-> trend
 timeline --> tweets

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
 class user user
 class apigw edge
 class post,timeline,fanout app
 class tweets,home,trend data
```

**Narrative:** **Post** persists tweet; **fan-out** pushes `tweet_id` into follower home lists (Redis) or marks celebrity for **read-merge**. **Timeline API** merges follow list + ranking signals. **Trending** increments hashtag counters in Redis with TTL.

## Deep dive

- **Fanout on write** vs **merge on read** threshold by follower count.
- **Retweet:** pointer to original `tweet_id`; avoid duplicate storage.
- Compare [feed ranking](./feed-ranking-service.md) for For You mode.

## Related

- [News feed](./news-feed.md)
- [Feed ranking](./feed-ranking-service.md)
- [DynamoDB drill](../aws/dynamodb.md)
