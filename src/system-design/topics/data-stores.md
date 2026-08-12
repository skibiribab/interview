# 🗄️ Data stores

## 📇 Index

1. [Interview comparison matrix](#interview-comparison-matrix)
2. [SQL databases](#sql-databases)
3. [NoSQL / key-value / document](#nosql--key-value--document)
4. [Wide-column and logs](#wide-column-and-logs)
5. [Indexes and access patterns](#indexes-and-access-patterns)
6. [Search and derived indexes](#search-and-derived-indexes)
7. [Multi-store patterns](#multi-store-patterns)

Pick the store from **access patterns + consistency needs**, not brand familiarity. Maps to **Amazon DynamoDB**, **Amazon RDS** / **Amazon Aurora**, **Amazon ElastiCache**, **Amazon OpenSearch Service**, **Amazon S3**.

## Interview comparison matrix

| Need | Prefer | Avoid / push back |
| --- | --- | --- |
| Money, inventory reservations, multi-row invariants | SQL (**Aurora/Postgres**) + transactions | Single-item DynamoDB without careful design |
| Known key lookups at huge QPS | **DynamoDB** / key-value | Ad-hoc SQL joins on hot path |
| Flexible filters, reporting, admin UIs | SQL + indexes (or warehouse) | Forcing DynamoDB GSIs for every report |
| Full-text / faceted search | **OpenSearch** (derived) | OLTP `LIKE '%foo%'` at scale |
| Ephemeral hot state, rate limits, sessions | **Redis** (cache / data structure store) | Durable source of truth in Redis alone |
| Huge blobs / immutable objects | **S3** + metadata in DB | Huge binary columns in OLTP |
| Time-ordered event log / replay | Kafka/MSK or Kinesis (see [messaging-async.md](./messaging-async.md)) | Using SQL as a queue |

**Rule:** one **source of truth** per entity; other stores are **projections** (cache, search, analytics).

## SQL databases

* **Strong consistency** — reads reflect latest committed write when you need correctness (payments, balances).
* **ACID** — atomic multi-row updates; constraints (FK, unique) enforce invariants in the DB.
* **Joins / ad-hoc queries** — good for relationships and evolving product questions.
* **Schema** — upfront cost; migrations are real work (expand/contract).
* **Scale** — vertical first; read replicas for read scale; sharding when a single primary cannot keep up.

**Use SQL when:** financial data, strong invariants, complex relationships, unpredictable query shapes.

**AWS:** **Amazon RDS** / **Amazon Aurora** (Postgres/MySQL). Aurora when you want managed storage scale and fast failover; call out **writer** vs **reader** endpoints.

### SQL indexes

B-tree (typical) maps column values → row locations.

* Speeds filters/sorts; slows writes; costs storage.
* Index what you query: e.g. `GET /trips?driver_id=&status=` → composite `(driver_id, status)`.
* Avoid indexing rarely filtered columns.

## NoSQL / key-value / document

* **Horizontal scale** by partition key.
* **High write throughput** when access patterns are key-shaped.
* **Eventual consistency** options on replicas/indexes.
* **Denormalize** for reads; model around queries.

**Use NoSQL when:** very high traffic, few well-known access patterns, temporary inconsistency OK.

**AWS:** **Amazon DynamoDB** — PK/SK, GSI/LSI. Every interview answer should list **exact** access patterns → keys.

### DynamoDB vs “document DB” vs Redis

| Store | Strength | Weakness in interviews |
| --- | --- | --- |
| DynamoDB | Predictable scale, serverless ops story | Bad for arbitrary queries; hot partitions |
| Document (Mongo-style) | Flexible documents | Still need index/query discipline; ops/consistency story |
| Redis | Ultra-low latency structures | Memory cost; durability/persistence tradeoffs |

## Wide-column and logs

* **Cassandra-style** — wide partitions, time-series-ish write paths, tunable consistency (mention when interviewer says “write-heavy globally”).
* **Append-only logs** (Kafka) — not a primary user DB; great for events and rebuildable projections.

## Indexes and access patterns

### SQL

Indexes are **additive** and usually can be added later (with care on large tables).

### DynamoDB / NoSQL

Indexes are **part of the data model**.

* **Primary key** — partition (+ optional sort); owns placement and local order.
* **GSI** — new PK/SK; eventually consistent by default; costs write units.
* **LSI** — same PK, different SK; strong consistency possible.

**NoSQL rule:** model for queries first; changing patterns later ≈ migration.

## Search and derived indexes

**OpenSearch** (or Elasticsearch) for full-text, facets, typo tolerance. Keep OLTP as truth; index async (CDC, stream, or batch). Accept lag; define rebuild story.

See [observability.md](./observability.md) when OpenSearch is also the log/search plane.

## Multi-store patterns

* **CQRS-ish** — write path to SQL/DynamoDB; read models in cache/search.
* **Outbox** — durable event next to the write so projections stay consistent (see [messaging-async.md](./messaging-async.md)).
* **Cache** — never the only copy of critical state ([caching.md](./caching.md)).

## 🔗 Related

- [Topics index](../topics-index.md)
- [Caching](./caching.md)
- [Messaging and async](./messaging-async.md)
- [Concurrency](./concurrency.md)
- [AWS reference layout](./aws-reference-layout.md)
