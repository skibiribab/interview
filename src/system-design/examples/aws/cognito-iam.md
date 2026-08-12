# Amazon Cognito and AWS IAM (service drill)

**Parent:** [`README.md`](./README.md) · **Topic:** [`../../topics/security-networking.md](../../topics/security-networking.md)

## When to use / when not

| Use when | Notes |
| --- | --- |
| Cognito: end-user sign-up/login | Hosted UI, social IdP federation |
| IAM: service-to-service permissions | Task roles for ECS/Lambda |
| JWT access tokens to APIs | API Gateway authorizer |

| Avoid when | Why |
| --- | --- |
| Cognito for complex B2B SAML-only without testing limits | May need custom IdP |
| Long-lived IAM user keys in app code | Roles + Secrets Manager |

**Deep rebuild:** [`identity-session-service.md`](../platform/identity-session-service.md)

## Mental model

- **Cognito:** user pools (directory) vs identity pools (AWS creds for mobile).
- **IAM:** least privilege policies; resource-based policies for S3/SQS.

## Architecture sketch

```mermaid
flowchart TB
 user([User])
 cognito[Amazon Cognito]
 apigw[API Gateway]
 api[ECS API]

 user --> cognito
 user -->|JWT| apigw --> api
 api -->|task role| s3[(S3)]

 class user user
 class cognito,apigw edge
 class api app
 class s3 data

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
```

**Narrative:** Users authenticate with **Cognito**; APIs validate **JWT**. Backend uses **IAM task role** to access AWS resources — no static keys.

## Capacity and cost (whiteboard)

| What to count | Meter | Ballpark |
| --- | --- | --- |
| MAU | Cognito | tiered per monthly active users |
| IAM | no direct charge | indirect via accessed services |

## Interview talking points

1. **Refresh token** rotation and device tracking.
2. **IAM policy** size limits; prefer roles per service.
3. Cross-account access: roles + trust policy.

## Product examples that use this service

| Example | How it shows up |
| --- | --- |
| [`platform/identity-session-service.md`](../platform/identity-session-service.md) | Sessions + OAuth |
| [`platform/api-gateway-rate-limiting.md`](../platform/api-gateway-rate-limiting.md) | Auth chain |

## Related

- [AWS service drills index](./README.md)
- [AWS reference layout](../../topics/aws-reference-layout.md)
- [Topics index](../../topics-index.md)
- [Cloud capability matrix](../../topics/cloud-capability-matrix.md)
