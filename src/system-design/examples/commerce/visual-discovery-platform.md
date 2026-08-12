# Visual discovery platform (Pinterest)

## Introduction

Visual discovery lets users **pin** images to boards and search by **image similarity** + text — combines [product search](./product-search.md) with embedding index and social graph of boards/follows.

**Company anchors:** Pinterest, Google Lens (search-only variant).

## Requirements discovery

| Lock (target) |
| --- |
| 500M pins |
| Image search p99 &lt; 300 ms |
| Home feed: boards + recommendations |
| Upload: async embedding pipeline |

## Architecture (user → database)

```mermaid
flowchart TB
 user([User])
 api[Pin API · ECS]
 embed[Embedding workers · ECS]
 textIdx[(OpenSearch · text)]
 vecIdx[(Vector index · OpenSearch k-NN)]
 pins[(Aurora · pins)]
 s3[(Amazon S3 · images)]
 stream[[MSK · new pins]]

 user --> api --> pins
 user -->|upload| s3
 pins -.-> stream --> embed --> vecIdx
 api --> textIdx
 api --> vecIdx
 api --> s3

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
 class user user
 class api,embed app
 class textIdx,vecIdx,pins,s3 data
 class stream async
```

**Narrative:** **Upload** stores image in **S3**; **MSK** triggers **embedding** job → **vector index**. **Search** blends text (OpenSearch) + nearest-neighbor on embedding. **Home feed** uses follow graph + similar pins.

## Deep dive

- **k-NN** shard sizing vs recall.
- **Safe search** classifier on upload path.
- Compare [feed ranking](../social/feed-ranking-service.md).

## Related

- [Product search](./product-search.md)
- [OpenSearch drill](../aws/opensearch.md)
- [Feed ranking](../social/feed-ranking-service.md)
