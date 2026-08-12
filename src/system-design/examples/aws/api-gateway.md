# Amazon API Gateway (service drill)

**Parent:** [`README.md`](./README.md) · **Topic:** [`../../topics/edge-and-ingress.md](../../topics/edge-and-ingress.md)

## When to use / when not

| Use when | Notes |
| --- | --- |
| Managed REST/HTTP API front door | Auth, throttling, request validation |
| Lambda/HTTP integration | Serverless BFF |
| Usage plans and API keys | Partner rate limits |

| Avoid when | Why |
| --- | --- |
| Ultra-low-latency internal east-west | ALB + service mesh |
| WebSocket at massive scale without design | API GW WS has limits; consider ALB |
| Replacing full L7 routing complexity | Often ALB + service for simpler internal |

## Mental model

- **HTTP API** cheaper/simpler than REST API v1.
- **Billing:** per million requests + optional cache.
- **Throttling:** account-level and stage-level burst.

## Architecture sketch

```mermaid
flowchart TB
 client([Mobile / partner])
 apigw[Amazon API Gateway]
 lambda[AWS Lambda]
 ecs[ECS service]

 client --> apigw
 apigw --> lambda
 apigw --> ecs

 class client user
 class apigw edge
 class lambda,ecs app

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
```

**Narrative:** **API Gateway** terminates TLS, enforces **throttle/auth**, routes to Lambda or VPC integration to VPC ECS.

## Capacity and cost (whiteboard)

| What to count | Meter | Ballpark |
| --- | --- | --- |
| Requests | million/mo | ~$1/M HTTP API |
| Cache | optional | reduces backend load |

## Interview talking points

1. Compare to **ALB** for long-lived connections and gRPC.
2. Cognito authorizer vs Lambda authorizer tradeoffs.
3. **Idempotency keys** still enforced in app layer.

## Product examples that use this service

| Example | How it shows up |
| --- | --- |
| [`platform/api-gateway-rate-limiting.md`](../platform/api-gateway-rate-limiting.md) | Auth + throttle chain |

## Related

- [AWS service drills index](./README.md)
- [AWS reference layout](../../topics/aws-reference-layout.md)
- [Topics index](../../topics-index.md)
- [Cloud capability matrix](../../topics/cloud-capability-matrix.md)
