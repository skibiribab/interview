# 📊 Observability

## 📇 Index

1. [Signals](#signals)
2. [Logs](#logs)
3. [Metrics and SLOs](#metrics-and-slos)
4. [Alarms that page](#alarms-that-page)
5. [Tracing](#tracing)
6. [Correlation and debug practice](#correlation-and-debug-practice)
7. [Analytics planes](#analytics-planes)

Logs, metrics, traces, and **actionable alarms**. Maps to **CloudWatch**, **X-Ray**, **OpenSearch**, **CloudTrail**, OpenTelemetry.

Automated response to alarms → [oncall-operations.md](./oncall-operations.md).

## Signals

| Signal | Answers |
| --- | --- |
| **Logs** | What happened on this request / entity? |
| **Metrics** | Is the system healthy *now* and trending? |
| **Traces** | Where did latency / errors accumulate? |

## Logs

Prefer **structured** JSON (`service`, `level`, `trace_id`, `user_id`, `error_code`).

**AWS:** CloudWatch Logs + Insights; long retention → S3; heavy search → OpenSearch.

## Metrics and SLOs

Instrument **RED** (rate, errors, duration) or **USE** (utilization, saturation, errors).

Define **SLIs** (e.g. availability, p99 latency) and **SLOs**; alert on **burn rate** / symptoms, not only CPU.

Custom metrics from ECS/Lambda; business metrics (orders/min) alongside infra.

## Alarms that page

Good pages are **rare, actionable, and owned**.

| Do | Don't |
| --- | --- |
| Alert on **user symptom** (5xx rate, checkout latency, queue lag, DLQ depth) | Page on every CPU blip |
| Include **runbook link** + dashboard | Vague “something wrong” |
| Severity: page vs ticket vs log | Everything = Sev1 |
| Multi-window / anomaly to cut noise | Single noisy threshold forever |

**Composite alarms** (CloudWatch) and **anomaly detection** reduce flapping. Pair with ticket auto-create for non-urgent.

**AWS:** CloudWatch Alarms → SNS → PagerDuty/Opsgenie/Slack; Lambda for enrichment.

## Tracing

Spans across Gateway → compute → DB/queue. **X-Ray** or **OpenTelemetry** → Jaeger/Tempo/SaaS.

## Correlation and debug practice

* Generate **correlation / trace id** at the edge; propagate on HTTP and message headers; never regenerate mid-flight.
* Spike → filter by `trace_id` → span timeline → offending dependency.
* Profilers (pprof, async-profiler) for CPU hotspots.
* Feature flags / shadow traffic to reproduce safely.
* Stream **replay** into a shadow consumer for event bugs.

## Analytics planes

Product analytics ≠ on-call metrics. Lake/warehouse: S3 + Glue + Athena / Redshift; stream windows via Flink. Do not overload OLTP for heavy aggregates.

**Audit:** CloudTrail = control plane; ALB/app logs = data plane.

## 🔗 Related

- [Topics index](../topics-index.md)
- [On-call operations](./oncall-operations.md)
- [Messaging and async](./messaging-async.md)
- [Reliability](./reliability.md)
- [Data stores](./data-stores.md)
- [AWS reference layout](./aws-reference-layout.md)
