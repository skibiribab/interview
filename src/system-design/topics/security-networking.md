# 🔐 Security and networking

## 📇 Index

1. [VPC, subnets, and security groups](#vpc-subnets-and-security-groups)
2. [VPC interface endpoints](#vpc-interface-endpoints)
3. [Secrets and configuration](#secrets-and-configuration)
4. [DNS](#dns)
5. [Identity](#identity)
6. [🔗 Related](#-related)

VPC layout, VPC-internal access to AWS APIs and SaaS, secrets, DNS, and identity—typical **follow-up** depth after you draw the main architecture.

## VPC, subnets, and security groups

**Amazon VPC** gives you internal **RFC1918** address space. **Public subnets** hold NAT gateways or load balancers that face the internet; **internal subnets** hold **Amazon ECS** tasks, **AWS Lambda** (in VPC), **Amazon RDS**, and **Amazon MSK** brokers when you require network isolation.

**Security groups** are **stateful** virtual firewalls on ENIs; **network ACLs** are stateless subnet-level filters. Interviews usually focus on **security groups** (least privilege between tiers).

---

## VPC interface endpoints

**Interface VPC endpoints** let resources in a VPC call **AWS services** (S3, DynamoDB, **Secrets Manager**, etc.) **without** traversing the public internet. **Gateway endpoints** (e.g. **Amazon S3**, **Amazon DynamoDB**) are another cost-free pattern for AWS service access.

Interface endpoints also expose **your** services to other VPCs or accounts without VPC peering—useful for “shared platform” stories.

---

## Secrets and configuration

**AWS Secrets Manager** — **rotating** secrets (RDS credentials, API keys) with optional automatic rotation lambdas.

**AWS Systems Manager Parameter Store** — **hierarchical** configuration (`/prod/api/timeout`), **Standard** vs **Advanced** parameters, integration with **AWS Lambda** and **ECS** task definitions.

Never hardcode long-lived keys in images; inject at runtime from these services or **IAM roles** (preferred for AWS API access).

---

## DNS

**Amazon Route 53** — hosted zones, **health checks**, routing policies (latency, weighted, failover). Pairs with **CloudFront** and **ALB** for public names; use **internal hosted zones** for internal service discovery patterns (often complemented by **AWS Cloud Map** or k8s DNS on **EKS**).

---

## Identity

**Amazon Cognito** — end-user auth for apps (see [edge-and-ingress.md](./edge-and-ingress.md)).

**AWS IAM** — **roles** for compute (**task roles**, **Lambda execution roles**) to call AWS APIs; **least privilege** is the default interview expectation.

---

## 🔗 Related

- [edge-and-ingress.md](./edge-and-ingress.md) — WAF, API Gateway, Cognito at edge
- [compute.md](./compute.md) — task roles, VPC-attached Lambda
- [observability.md](./observability.md) — CloudTrail for audit
- [Topics index](../topics-index.md)
- [AWS reference layout]./aws-reference-layout.md
