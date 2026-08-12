# Architecture diagram conventions

**Parent:** [`README.md`](./README.md) · **Authoring contract:** [`example-authoring-template.md`](./example-authoring-template.md)

Use these rules for every **Architecture (user → database)** figure in `examples/**/`.

## Layout

- **Kind:** `flowchart TB` — users/actors at top, managed services in the middle, durable stores at the bottom.
- **Subgraphs (optional):** `Edge`, `Application`, `Data` (or domain-specific labels).
- **Actors:** stadium shape `([Mobile app])`, not anonymous boxes.
- **Stores:** cylinder `[(Amazon Aurora)]`; async/log `[[Amazon MSK]]`.
- **Edges:** label the hot path (`GET redirect`, `reserve inventory`); dashed `-.->` for async / analytics.

## Naming

- Use **real AWS product names** in labels (see [topics index](../topics-index.md) checklist).
- Avoid a second generic “template” diagram — one primary topology per example; optional **second figure** only for a named deep-dive (`### Purchase saga`, `### Fan-out write path`).

## Color palette (Mermaid `classDef`)

Apply at the end of every architecture block. Each class uses a **two-stop fill** (`light,deep`) so color ramps within the node while the five classes span the diagram (blue → amber → green → rose → purple).

| Class | Nodes | Fill gradient |
| --- | --- | --- |
| `user` | Actors, clients | `#e3f2fd` → `#42a5f5` |
| `edge` | CloudFront, ALB, API Gateway | `#fff8e1` → `#ffb74d` |
| `app` | ECS, Lambda, workers | `#e8f5e9` → `#66bb6a` |
| `data` | RDS, DynamoDB, Redis, S3 | `#fce4ec` → `#ef5350` |
| `async` | MSK, SQS, Kinesis, outbox drain | `#f3e5f5` → `#ab47bc` |

```text
classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
```

Use the `classDef` block above in every architecture figure.

## Gold references

- [`platform/url-shortener.md`](../examples/platform/url-shortener.md) — read-heavy, cache + stream
- [`social/news-feed.md`](../examples/social/news-feed.md) — fan-out + read merge
- [`platform/sequential-replica-digestion.md`](../examples/platform/sequential-replica-digestion.md) — operator/infra topology

## Related

- [AWS reference layout](./aws-reference-layout.md)
- [Examples index](../examples/README.md)
