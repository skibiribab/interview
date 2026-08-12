# 📟 On-call operations

## 📇 Index

1. [Goal](#goal)
2. [Alarm → human vs alarm → automation](#alarm--human-vs-alarm--automation)
3. [Automated triggers](#automated-triggers)
4. [Runbooks and tickets](#runbooks-and-tickets)
5. [Toil reduction patterns](#toil-reduction-patterns)
6. [Interview talking points](#interview-talking-points)

Efficient on-call: **fewer pages**, faster mitigation, automation for known failure modes. Builds on [observability.md](./observability.md) and [deployment.md](./deployment.md).

## Goal

On-call should spend time on **novel** failures. Recurring classes should become **auto-mitigations**, better alarms, or product fixes—not heroics.

## Alarm → human vs alarm → automation

| Severity | Action |
| --- | --- |
| **Customer-impacting, unclear cause** | Page human + dashboard + runbook |
| **Known signature** (disk full, DLQ spike, replica lag) | **Automate** first; page only if automation fails |
| **Capacity foresight** | Ticket / scheduled scale; do not wake people at 3am for predictable growth |

## Automated triggers

Wire alarms (or EventBridge rules) to **safe, idempotent** actions:

| Trigger | Automated response | Guardrails |
| --- | --- | --- |
| ASG/ECS CPU or queue lag high | Scale out + notify Slack | Max capacity cap; cooldown |
| Disk / inode alarm | Cleanup script (temp/logs) + ticket | Dry-run mode; allowlist paths |
| DLQ depth > N | Pause consumer / divert traffic; open ticket | Never auto-drop without policy |
| 5xx after deploy | Rollback to previous task def / Lambda alias | Only during deploy window |
| Dependency circuit open | Enable degraded mode feature flag | Explicit product-approved behavior |
| Certificate / secret expiry approaching | Renew pipeline + ticket | Human approval for prod secrets if required |

**AWS shape:** CloudWatch Alarm → **SNS** → **Lambda** (mitigation) + PagerDuty. Or EventBridge → Step Functions for multi-step runbooks.

Log every automation with `alarm_name`, `action`, `result`, `correlation_id` for audit.

## Runbooks and tickets

* Every pageable alarm links a **runbook**: symptoms → checks → mitigate → escalate → follow-up.
* Auto-open tickets for non-paging issues (disk warnings) with owner and SLO to close.
* Post-incident: either **fix the bug**, **improve the signal**, or **automate the mitigate**—pick at least one.

## Toil reduction patterns

* **Self-healing** for soft failures (restart unhealthy tasks via ASG/ECS health).
* **Game days** to validate automation does not make outages worse.
* **Error budgets** so chronic toil becomes a roadmap item.
* Reduce alert cardinality; silence dependent alarms during known maintenance.

## Interview talking points

1. Separate **detect** (metrics/alarms) from **act** (Lambda/runbook).
2. Give a concrete example: disk alarm → cleanup Lambda → 10% fewer tickets (pattern from ops stories).
3. Say what you **would not** automate (data deletion, irreversible failover) without human gates.
4. Tie to reliability: retries/DLQ + automation beats waking people for poison messages.

## 🔗 Related

- [Topics index](../topics-index.md)
- [Observability](./observability.md)
- [Deployment](./deployment.md)
- [Reliability](./reliability.md)
- [Messaging and async](./messaging-async.md)
- [AWS reference layout](./aws-reference-layout.md)
