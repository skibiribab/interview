# AWS service drill template

**Parent:** [`README.md`](./README.md) · **Index:** [`../examples/aws/README.md`](../examples/aws/README.md)

Lightweight contract for files under `examples/aws/*.md` — **not** a full 60-minute product round. Target **4–6 pages**.

## Required sections

```markdown
# {AWS product name} (service drill)

**Parent:** [`README.md`](./README.md) · **Topic:** [`../../topics/{topic}.md`](../../topics/{topic}.md)

## When to use / when not

| Use when | Avoid when |
| --- | --- |

## Mental model

- **Consistency / durability:** …
- **Scaling knob:** …
- **Billing unit:** …

## Architecture sketch

```mermaid
flowchart TB
 ...
 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 ...
```

**Narrative:** 2–4 sentences.

## Capacity and cost (whiteboard)

| What to count | Typical meter | Order-of-magnitude ballpark |
| --- | --- | --- |

## Interview talking points

1. …
2. …
3. …

## Product examples that use this service

| Example | How it shows up |
| --- | --- |

## Related

- [topics …]
- [aws-reference-layout](./aws-reference-layout.md)
```

## Deep rebuild companion

If a full **rebuild** example exists (e.g. [`object-storage`](../examples/infra/object-storage.md) for S3), the drill links to it as “deep dive” — do not duplicate the full narrative.
