# 💾 Caching

## 📇 Index

1. [What and where to cache](#what-and-where-to-cache)
2. [Read/write patterns](#readwrite-patterns)
3. [Invalidation](#invalidation)
4. [Failure modes](#failure-modes)
5. [Redis vs Memcached vs CDN](#redis-vs-memcached-vs-cdn)

What, where, and how to cache; invalidation and stampede. Maps to **Amazon ElastiCache** (Redis), **Amazon CloudFront**, local process caches.

## What and where to cache

### What

* **Read-heavy**: profiles, metadata, config, feature flags
* **Expensive**: aggregations, rankings, recommendations
* **Slow-changing**: pricing rules, reference data

### Where

| Layer | Examples | Good for |
| --- | --- | --- |
| Client | Browser HTTP cache, mobile disk | Static assets, user-private short TTL |
| CDN | CloudFront | Public static + cacheable API GETs |
| App / sidecar | In-process LRU | Micro-optimizations; careful with multi-instance drift |
| Distributed | Redis / Memcached | Shared hot keys across fleet |

### Avoid caching

* Strongly consistent money paths (unless carefully versioned)
* Unbounded result sets
* Highly volatile data without a clear invalidation story

## Read/write patterns

* **Cache-aside (lazy)** — app reads cache; on miss load DB and populate. Most common interview default.
* **Read-through** — library/cache layer loads on miss (hides DB from app).
* **Write-through** — write DB and cache together; higher write latency, fresher reads.
* **Write-behind** — write cache first, flush DB async; risk of loss—rare for critical data.
* **Refresh-ahead** — proactively refresh before TTL for hot keys.

## Invalidation

* **TTL** — simple; stale window = TTL; great default.
* **Explicit delete/update on write** — tighter consistency; must hit every cache key shape.
* **Event / CDC invalidation** — pub/sub or stream after commit; scales; eventual.

**Hard truth:** invalidation is hard because correctness depends on **timing and key design**, not a clever API.

**Versioned keys** (`user:123:v7`) avoid some thundering herds when content changes.

## Failure modes

* **Stampede / thundering herd** — many misses on one key; mitigate with single-flight locks, probabilistic early refresh, or slightly jittered TTLs.
* **Hot key** — one key dominates; replicate locally, shard value, or coalesce.
* **Stampede on deploy** — cold caches; warm critical keys or use longer TTLs during rollout.
* **Cache as source of truth** — outage or flush ⇒ wrong product behavior; always have DB fallback.

## Redis vs Memcached vs CDN

| | Redis | Memcached | CDN |
| --- | --- | --- | --- |
| Structures | Strings, hashes, sets, sorted sets, streams | Opaque blobs | HTTP objects |
| Persistence | Optional AOF/RDB | Typically none | Origin is truth |
| Use | Sessions, rate limits, leaderboards, locks | Simple KV speed | Global static/API edge |

**AWS:** **ElastiCache for Redis** behind Lambda/ECS; **CloudFront** at the edge ([edge-and-ingress.md](./edge-and-ingress.md)).

## 🔗 Related

- [Topics index](../topics-index.md)
- [Data stores](./data-stores.md)
- [Edge and ingress](./edge-and-ingress.md)
- [Notifications](./notifications.md)
- [AWS reference layout](./aws-reference-layout.md)
