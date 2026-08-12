# 60-minute system design runbook

Use this for mid-senior interviews where you must complete a coherent design and one deep dive.

## Time boxes

| Time | Focus | Output |
| --- | --- | --- |
| 0-10 min | Clarify requirements | Functional scope, non-functional targets, constraints |
| 10-18 min | Define vertical slice | One end-to-end user journey |
| 18-32 min | Draw high-level architecture | Boxes/arrows with boundaries and data flow |
| 32-46 min | API + data model | Key contracts, entities, partition/index choices |
| 46-56 min | Deep dive | One hard axis with explicit tradeoffs |
| 56-60 min | Failure + wrap | Risks, mitigations, observability, recap |

## Mandatory checklist

1. Confirm users, core actions, and out-of-scope features.
2. State latency/throughput/consistency assumptions explicitly.
3. Pick exactly one primary deep-dive axis:
 - Async/event reliability
 - Realtime session ordering
 - Payments/ledger correctness
 - Geo/routing or discovery matching
 - Stream processing state and replay
4. Tie failure handling to that deep dive (no generic filler).

## Recommended output structure

Follow [`example-authoring-template.md`](./example-authoring-template.md) and [`examples/README.md`](../examples/README.md):

1. **Interview Q&A cheat sheet** + parsed requirements + locked assumptions (prototype → growth → target)
2. Capacity sketch: input model → fleet totals → **AWS service map** → **billable volume** → **cost at a glance**
3. **Architecture (user → database)** mermaid — users at top, AWS services in the middle, databases at bottom
4. User-visible surface → **UX → API** map
5. Data model + numbered read/write paths
6. One deep dive + scale/failure

## Interview pacing heuristics

- If clarification is still fuzzy after 10 minutes, lock assumptions and proceed.
- Avoid spending more than 14 minutes in deep dive before recapping.
- Prefer complete architecture + one excellent deep dive over five shallow deep dives.

## Artifact links

- Catalog: [`system-catalog.md`](./system-catalog.md)
- Coverage matrix: [`archetype-coverage-matrix.md`](./archetype-coverage-matrix.md)
- Full-round reference: [`platform/distributed-job-scheduler.md`](../examples/platform/distributed-job-scheduler.md)
