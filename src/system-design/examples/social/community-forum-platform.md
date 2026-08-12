# Community forum platform (Reddit)

## Introduction

A forum organizes content into **subreddits** (communities), ranks posts by **votes** and **time decay**, and serves **comments** as trees — different from [news feed](./news-feed.md) (social graph) and [microblog timeline](./microblog-timeline.md) (follow-based).

**Company anchors:** Reddit, Hacker News (simpler), Stack Overflow (Q&A variant).

**Interview pacing:** Deep dive **vote aggregation + hot rank formula + comment tree**.

## Requirements discovery

| Lock (target) |
| --- |
| 100M WAU |
| Hot feed p99 &lt; 150 ms per subreddit |
| Vote writes: 1B / day |
| Comments: tree depth cap 10 |

## Architecture (user → database)

```mermaid
flowchart TB
 user([User])
 api[Forum API · ECS]
 rank[Hot ranker · ECS]
 posts[(Aurora · posts)]
 votes[(DynamoDB · vote by user+post)]
 scores[(Redis · hot scores)]
 comments[(Aurora · comments)]

 user --> api --> posts
 user -->|up/down| api --> votes
 votes -.-> rank --> scores
 api --> rank --> posts
 api --> comments

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
 class user user
 class api,rank app
 class posts,votes,scores,comments data
```

**Narrative:** **Votes** are idempotent per `(user_id, post_id)`. **Ranker** recomputes hot score `log(upvotes) + time_decay` into **Redis** sorted sets per subreddit. **Feed read** is `ZRANGE` + hydrate post bodies.

## Deep dive

- **Wilson score** or Reddit **hot** algorithm on whiteboard.
- **Comment tree:** `parent_id` index; load top N branches.
- Moderation queue: defer to [notification platform](../platform/notification-platform.md).

## Related

- [News feed](./news-feed.md)
- [Reviews aggregates](../commerce/reviews-ratings.md)
- [ElastiCache drill](../aws/elasticache-redis.md)
