# 🌐 Edge and ingress

## 📇 Index

1. [Edge caching and static content](#edge-caching-and-static-content)
2. [Application Load Balancer (ALB)](#application-load-balancer-alb)
3. [Amazon API Gateway](#amazon-api-gateway)
4. [Edge security](#edge-security)
5. [Identity at the API edge](#identity-at-the-api-edge)
6. [🔗 Related](#-related)

CDN, static delivery, L7 load balancing, API gateway patterns, and **edge security**. Maps to **Amazon CloudFront**, **Amazon S3** (static hosting), **Application Load Balancer**, **Amazon API Gateway**, **AWS WAF**, and **AWS Shield** on AWS.

## Edge caching and static content

**CDN** (on AWS, **Amazon CloudFront**) caches static assets and optionally dynamic responses at **edge locations** to cut latency and origin load. Pair with **Amazon S3** for immutable UI bundles; use **cache keys** and **invalidation** deliberately (invalidation is operationally costly at scale).

**Interview angle:** separate **static** path (CloudFront → S3) from **dynamic** APIs (ALB or API Gateway → compute).

---

## Application Load Balancer (ALB)

**Elastic Load Balancing** offers several load balancer types. The **Application Load Balancer** is **Layer 7 (HTTP/HTTPS)** with routing rules (path, host, header), integration with **AWS WAF**, and support for **gRPC** and WebSockets. Use it when traffic is HTTP-based and you need **smart routing** to **Amazon ECS**, **Amazon EKS**, or **EC2** targets.

For **pure L4** TCP/UDP or extreme performance tuning, **Network Load Balancer (NLB)** is the AWS answer—see [compute.md](./compute.md).

---

## Amazon API Gateway

**HTTP API** or **REST API** in front of **AWS Lambda** or **HTTP integrations** (including VPC integrations to VPC resources). Provides **throttling**, **API keys**, **usage plans**, **authorizers** (JWT, Lambda), and **request validation** at the edge of serverless or hybrid designs.

Compare with **ALB** directly to services when you do not need API Gateway’s API-management features.

---

## Edge security

**AWS WAF** attaches to **CloudFront** or **Application Load Balancer** (and **API Gateway** in supported setups) for **managed rules**, **rate-based rules**, and **geo** restrictions.

**AWS Shield Standard** is baseline DDoS protection; **Shield Advanced** adds higher-touch support and cost protection for eligible resources—mention **Standard** in most interview depth unless the prompt is security-heavy.

---

## Identity at the API edge

**Amazon Cognito** provides user pools (sign-up/sign-in) and identity pools (temporary AWS credentials for mobile/web). Many teams instead use a **third-party IdP** (Okta, Auth0, etc.) with **Lambda authorizers** or **JWT** validation on **API Gateway**.

Details of OAuth2 flows live next to [api-design.md](./api-design.md) (headers, tokens).

---

## 🔗 Related

- [api-design.md](./api-design.md) — REST, pagination, errors
- [caching.md](./caching.md) — CDN and Redis
- [security-networking.md](./security-networking.md) — VPC, interface endpoints, secrets
- [Topics index](../topics-index.md)
- [AWS reference layout]./aws-reference-layout.md
