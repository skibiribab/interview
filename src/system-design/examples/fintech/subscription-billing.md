# Subscription billing

## Introduction

Subscription billing manages **plans**, **renewals**, **proration**, **dunning** (failed payment retry), and **entitlement** state for recurring revenue (SaaS, streaming).

**Primary users:** subscribers (upgrade/cancel), finance (MRR reports), support (credits/refunds).

**Interview pacing:** [60-minute runbook](../../topics/interview-runbook-60m.md) — deep dive **renewal state machine + idempotent webhooks**.

Complements [payment workflow](./payment-workflow-platform.md) (one-shot capture) — here **time-based billing cycles** dominate.

## Requirements discovery

### Interview Q&A cheat sheet

| Lock (target) |
| --- |
| 30M paying subs |
| Monthly + annual plans |
| 3-day dunning retries |
| Webhooks idempotent from PSP |
| Proration on mid-cycle upgrade |

## Architecture (user → database)

```mermaid
flowchart TB
 user([Subscriber])
 api[Billing API · ECS]
 sfn[AWS Step Functions]
 psp[Payment PSP]
 subs[(Aurora · subscriptions)]
 ent[(DynamoDB · entitlements)]
 wh[[Webhook ingress · Lambda]]

 user --> api --> subs
 api --> sfn --> psp
 psp --> wh --> sfn
 sfn --> ent

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
 class user user
 class api,sfn app
 class subs,ent data
 class wh async
```

**Narrative:** **Step Functions** orchestrates renewals, retries, and proration. **PSP webhooks** advance state idempotently. **Entitlements** gate product access in near real time.

## Deep dive: renewal + dunning

- States: `ACTIVE → PAST_DUE → CANCELED`.
- **Idempotency-Key** per invoice period.
- **Ledger** optional link to [core banking ledger](./core-banking-ledger.md).

## Related

- [Payment workflow](./payment-workflow-platform.md)
- [Step Functions drill](../aws/step-functions.md)
- [Video on demand](../media/video-on-demand-platform.md)
