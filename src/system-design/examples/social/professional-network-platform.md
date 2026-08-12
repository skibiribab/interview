# Professional network platform

## Introduction

A professional network (LinkedIn-shaped) combines a **connection graph**, **feed** of posts/jobs, **search** over profiles, and **messaging** — graph queries and ranked feed differ from pure [news feed](./news-feed.md) or [dating discovery](./dating-discovery-matching.md).

**Primary users:** members (post, connect), recruiters (search, InMail), ads (sponsored jobs).

**Interview pacing:** [60-minute runbook](../../topics/interview-runbook-60m.md) — deep dive **2nd/3rd-degree feed candidate generation + connection graph**.

**Company anchors:** LinkedIn, Xing, Handshake.

## Requirements discovery

### Interview Q&A cheat sheet

| Lock (target) |
| --- |
| 900M members; 300M MAU |
| Feed: 500 candidates → top 50 |
| Connection request idempotent |
| Profile search p99 &lt; 300 ms |
| Jobs module: separate index (defer detail) |

## Architecture (user → database)

```mermaid
flowchart TB
 member([Member])
 subgraph edge [Edge]
 cf[Amazon CloudFront]
 apigw[Amazon API Gateway]
 end
 feedApi[Feed API · ECS]
 graphSvc[Graph service · ECS]
 searchApi[Profile search · ECS]
 connGraph[(Neptune / graph store)]
 feedRank[Ranker · ECS]
 posts[(Aurora · posts)]
 os[(OpenSearch · profiles)]

 member --> cf --> apigw
 apigw --> feedApi
 apigw --> searchApi
 feedApi --> graphSvc --> connGraph
 feedApi --> feedRank --> posts
 searchApi --> os
 graphSvc --> feedRank

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
 class member user
 class cf,apigw edge
 class feedApi,graphSvc,searchApi,feedRank app
 class connGraph,posts,os data
```

**Narrative:** **Graph service** returns 1st/2nd-degree author IDs for feed retrieval. **Ranker** scores by affinity, recency, job relevance. **OpenSearch** powers recruiter **profile search** with facets (title, geo, company).

## Deep dive: feed from social graph

- **Write path:** post → fanout to followers’ feed lists (hybrid with read-merge for influencers).
- **Connection:** mutual accept → symmetric edge; block removes edge both ways.
- **Messaging:** defer to [chat messenger](./chat-messenger.md) (InMail = paid edge case).

## Related

- [News feed](./news-feed.md) (fanout mechanics)
- [Feed ranking service](./feed-ranking-service.md) (scoring)
- [Dating discovery](./dating-discovery-matching.md) (mutual match pattern)
- [Product search](../commerce/product-search.md) (OpenSearch)
- [OpenSearch drill](../aws/opensearch.md)
