# 🔀 Concurrency

## 📇 Index

1. [3. Concurrency](#3-concurrency)

Race conditions and locking strategies for shared mutable state (rides, inventory, wallets). Complements [reliability.md](./reliability.md) for retries and [data-stores.md](./data-stores.md) for transactional stores.

## 3. Concurrency

### Race Conditions

* Occur when multiple writers update shared state concurrently
* Leads to lost updates, double processing, or invalid states

**Example**: Two drivers accept the same ride at the same time → both think they won.

### Locking Strategies

#### Optimistic Locking
* Assumes conflicts are **rare**
* No lock upfront — detect conflicts at write time

**How it works**
* Attach a `version` / `etag` / `updated_at` field
* Update succeeds only if the version matches
* On conflict → retry or fail

**Example**
```sql
UPDATE rides
SET status = 'ASSIGNED', version = version + 1
WHERE ride_id = 42 AND version = 3;
```

**Pros**
* High throughput
* No blocking
* Scales well under low contention

**Cons**
* Retries under contention
* Clients must handle failures

#### Pessimistic Locking

* Assumes conflicts are **common**
* Lock resource before modifying it

**How it works**
* Acquire lock (row lock, mutex, distributed lock)
* Perform update
* Release lock

**Example**
```sql
SELECT * FROM rides
WHERE ride_id = 42
FOR UPDATE;

UPDATE rides
SET status = 'ASSIGNED', driver_id = 7
WHERE ride_id = 42 AND status = 'AVAILABLE';
```

**Pros**
* Strong consistency
* No retries needed

**Cons**
* Lower throughput
* Risk of deadlocks
* Harder to scale in distributed systems

## 🔗 Related

- [Topics index](../topics-index.md)
- [Data stores](./data-stores.md)
- [Reliability](./reliability.md)
- [AWS reference layout]./aws-reference-layout.md
