# Amazon OpenSearch Service (service drill)

**Parent:** [`README.md`](./README.md) · **Topic:** [`../../topics/data-stores.md](../../topics/data-stores.md)

## When to use / when not

| Use when | Notes |
| --- | --- |
| Full-text search, facets, autocomplete | Inverted index |
| Log analytics (historically ELK) | High ingest volume |
| Secondary index from OLTP via CDC | Eventually consistent search |

| Avoid when | Why |
| --- | --- |
| Primary transactional store | Aurora/Dynamo source of truth |
| Tiny datasets | Postgres full-text may suffice |

**Deep rebuild:** [`product-search.md`](../commerce/product-search.md)

## Mental model

- **Shards + replicas** for scale; query fan-out cost.
- **Billing:** instance hours + EBS storage.

## Architecture sketch

```mermaid
flowchart TB
 api[API]
 os[(Amazon OpenSearch)]
 cdc[[CDC / SQS]]
 db[(OLTP)]

 api -->|search query| os
 db -.-> cdc --> os

 class api app
 class os data
 class cdc async
 class db data

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
```

**Narrative:** OLTP remains source of truth; **CDC** updates search index. Queries hit **OpenSearch** for fuzzy match, filters, sort by relevance.

## Capacity and cost (whiteboard)

| What to count | Meter | Ballpark |
| --- | --- | --- |
| Instances | r6g.search × 730h | $100s+/mo small cluster |
| Storage | GB EBS | grows with index size |

## Interview talking points

1. **Index mapping** and analyzers for typeahead.
2. Reindex strategy on schema change.
3. Near-real-time lag acceptable for search.

## Product examples that use this service

| Example | How it shows up |
| --- | --- |
| [`commerce/product-search.md`](../commerce/product-search.md) | Catalog search |

## Related

- [AWS service drills index](./README.md)
- [AWS reference layout](../../topics/aws-reference-layout.md)
- [Topics index](../../topics-index.md)
- [Cloud capability matrix](../../topics/cloud-capability-matrix.md)
