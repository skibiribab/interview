# 🖥️ Compute

## 📇 Index

1. [Amazon ECS on Fargate and Amazon EKS](#amazon-ecs-on-fargate-and-amazon-eks)
2. [Amazon ECR](#amazon-ecr)
3. [AWS Lambda](#aws-lambda)
4. [Internal gRPC and load balancing](#internal-grpc-and-load-balancing)
5. [Stream consumers as compute](#stream-consumers-as-compute)

Containers vs serverless, scaling, and **internal RPC** load balancing on AWS.

## Amazon ECS on Fargate and Amazon EKS

**Amazon ECS** with **AWS Fargate** runs containers **without** managing EC2 instances for the control plane (you still define task CPU/memory and networking). **Amazon EKS** is managed **Kubernetes**—same **pod/service** mental model when the interviewer expects k8s.

**Interview picks:** Fargate for “managed tasks behind ALB”; EKS when the question assumes **Kubernetes**, **Helm**, or **service mesh** (e.g. **AWS App Mesh**).

---

## Amazon ECR

**Amazon Elastic Container Registry** stores **Docker/OCI** images used by **ECS** and **EKS**. Naming it shows end-to-end CI/CD awareness (build → push to ECR → deploy task/pod).

---

## AWS Lambda

**Event-driven**, **short-lived** compute with **per-invocation** scaling. Cold starts, **memory/CPU** coupling, and **15-minute** max duration matter for design. Common behind **Amazon API Gateway** and **Amazon EventBridge**, and as **Amazon MSK** / **Amazon Kinesis** consumers.

Use **ECS/EKS** for long-running connections, heavy always-on processes, or when you need **predictable** baseline capacity without invocation-based billing surprises.

---

## Internal gRPC and load balancing

Uber-shaped systems often use **gRPC** between services. On AWS:

* **Application Load Balancer** supports **gRPC** targets (HTTP/2) with health checks and routing.
* **Network Load Balancer** forwards **TCP** at L4 when you terminate TLS on instances or need extreme throughput with minimal L7 features.

Pair with [api-design.md](./api-design.md) for protobuf contracts and [security-networking.md](./security-networking.md) for **VPC** and **interface endpoints** between services.

---

## Stream consumers as compute

**Amazon MSK** and **Amazon Kinesis** consumers are often **ECS tasks**, **EKS pods**, or **Lambda** (with event source mapping constraints). Same **idempotency** and **scaling** concerns as HTTP workers (see [messaging-async.md](./messaging-async.md)).

## How compute gets to prod

Packaging, rollouts (rolling / blue-green / canary), and rollback belong in [deployment.md](./deployment.md). Alarms that scale or self-heal belong in [oncall-operations.md](./oncall-operations.md).

## 🔗 Related

- [Topics index](../topics-index.md)
- [Deployment](./deployment.md)
- [Edge and ingress](./edge-and-ingress.md)
- [API design](./api-design.md)
- [Messaging and async](./messaging-async.md)
- [On-call operations](./oncall-operations.md)
- [AWS reference layout](./aws-reference-layout.md)
