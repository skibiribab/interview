# 🚀 Server deployment

## 📇 Index

1. [What “deploy” means in interviews](#what-deploy-means-in-interviews)
2. [Packaging and environments](#packaging-and-environments)
3. [Rollout strategies](#rollout-strategies)
4. [Infrastructure as code and CI/CD](#infrastructure-as-code-and-cicd)
5. [Runtime platforms](#runtime-platforms)
6. [Safety rails](#safety-rails)

How code reaches production safely. Complements [compute.md](./compute.md) (what runs) and [oncall-operations.md](./oncall-operations.md) (what happens after).

## What “deploy” means in interviews

Show a path: **build → artifact → config → rollout → verify → rollback**. Name real pieces (container image, task def, ALB target group)—not “the DevOps team handles it.”

## Packaging and environments

* **Immutable artifacts** — container image or Lambda zip keyed by git SHA; no “ssh and edit.”
* **Config outside the image** — env, SSM Parameter Store / Secrets Manager, AppConfig.
* **Environments** — dev / staging / prod with promotion of the **same** artifact.

**AWS:** ECR for images; ECS task definitions / EKS Deployments / Lambda versions+aliases.

## Rollout strategies

| Strategy | How | When |
| --- | --- | --- |
| **Rolling** | Replace instances gradually | Default for many services |
| **Blue/green** | Two full environments; flip traffic | Fast rollback; needs 2× capacity briefly |
| **Canary** | Small % traffic → watch SLOs → continue | Risky changes, large fleets |
| **Feature flags** | Deploy dark; enable per cohort | Decouple deploy from release |

Always define **auto-rollback** signals (error rate, p99) during canary.

## Infrastructure as code and CI/CD

* **IaC** — CloudFormation / CDK / Terraform for networking, IAM, alarms (not only app code).
* **Pipeline** — test → build image → push → deploy staging → smoke → prod approval/auto.
* **Migrations** — expand/contract; never require downtime if you can avoid it; gate deploys on migration success.

## Runtime platforms

| Platform | Deploy unit | Notes |
| --- | --- | --- |
| **ECS/Fargate** | Task definition + service | ALB target registration; circuity deploys via deployment config |
| **EKS** | Deployment / Rollout | Familiar k8s story |
| **Lambda** | Version + alias weighted | Canary via alias traffic shifting |
| **EC2 ASG** | AMI / user-data | Still valid; prefer immutable AMI |

See [compute.md](./compute.md) and [edge-and-ingress.md](./edge-and-ingress.md).

## Safety rails

* Health checks before receiving traffic; **drain** old tasks.
* **Disk / FD / connection** limits sized from load tests (Black Friday–style).
* Alarms on deploy failure, unhealthy host count, 5xx spike ([observability.md](./observability.md)).
* Runbook: “rollback to previous task def / alias” in one command.

## 🔗 Related

- [Topics index](../topics-index.md)
- [Compute](./compute.md)
- [Observability](./observability.md)
- [On-call operations](./oncall-operations.md)
- [Reliability](./reliability.md)
- [AWS reference layout](./aws-reference-layout.md)
