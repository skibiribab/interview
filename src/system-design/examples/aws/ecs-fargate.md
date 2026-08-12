# Amazon ECS on Fargate (service drill)

**Parent:** [`README.md`](./README.md) · **Topic:** [`../../topics/compute.md](../../topics/compute.md)

## When to use / when not

| Use when | Notes |
| --- | --- |
| Long-running containers without managing EC2 | Task = unit of deploy |
| Microservices default on AWS | ALB target groups |
| Background workers + API in same cluster | Service autoscaling on CPU/RPS/custom |

| Avoid when | Why |
| --- | --- |
| Per-invocation millisecond billing only | Lambda |
| Kubernetes-specific tooling required | EKS instead |
| Bare-metal latency tuning | EC2 with ECS |

## Mental model

- **Task CPU/RAM** chosen per task definition; billed per second.
- **Services** maintain desired count; deployments rolling.

## Architecture sketch

```mermaid
flowchart TB
 alb[Application Load Balancer]
 svc[ECS service · Fargate]
 task1[Task]
 task2[Task]
 ecr[Amazon ECR]

 alb --> svc
 svc --> task1
 svc --> task2
 ecr -.->|image pull| task1

 class alb edge
 class svc,task1,task2 app
 class ecr data

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
```

**Narrative:** **Fargate** runs tasks without EC2 fleet management; **ALB** routes traffic; **ECR** stores images. Autoscale on CPU or custom metric (queue lag).

## Capacity and cost (whiteboard)

| What to count | Meter | Ballpark |
| --- | --- | --- |
| vCPU-h + GB-h | per task | ~$0.04/vCPU-h + $0.004/GB-h ballpark |

## Interview talking points

1. **Health checks** and graceful shutdown on deploy.
2. Sidecars for observability (FireLens, ADOT).
3. When interviewer says containers on AWS — default to **ECS Fargate** unless K8s required.

## Product examples that use this service

| Example | How it shows up |
| --- | --- |
| [examples index](../README.md) | App tier default |

## Related

- [AWS service drills index](./README.md)
- [AWS reference layout](../../topics/aws-reference-layout.md)
- [Topics index](../../topics-index.md)
- [Cloud capability matrix](../../topics/cloud-capability-matrix.md)
