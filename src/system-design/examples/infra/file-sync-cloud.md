# Personal file sync cloud

## Introduction

File sync keeps **folders** consistent across devices with **delta uploads**, **conflict resolution**, and **version history** (Dropbox/iCloud class).

**Primary users:** consumers (sync clients), operators (storage cost, abuse).

**Interview pacing:** Deep dive **delta sync + conflict policy + metadata index**.

Complements [object storage](./object-storage.md) (S3 rebuild) — this is **product UX** on top of blobs.

## Requirements discovery

| Lock (target) |
| --- |
| 50M users; 100 GB average logical / paid tier |
| Block size 4 MB; dedupe by content hash |
| Conflict: last-writer-wins default + optional branch |

## Architecture (user → database)

```mermaid
flowchart TB
 client([Desktop / mobile client])
 api[Sync API · ECS]
 meta[(DynamoDB · file metadata)]
 s3[(Amazon S3 · blocks)]
 queue[[SQS · virus scan]]

 client -->|delta PUT| api
 api --> meta
 api --> s3
 api -.-> queue

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
 class client user
 class api app
 class meta,s3 data
 class queue async
```

**Narrative:** Clients send **only changed blocks** addressed by hash; **metadata** tracks file versions and paths. **S3** stores immutable blocks with lifecycle to IA/Glacier.

## Deep dive: sync protocol

- **Cursor / revision** per device folder.
- **Content-defined chunking** optional for large files.
- **Conflict copy** naming `file (conflict).ext`.

## Related

- [S3 drill](../aws/s3.md)
- [Object storage rebuild](./object-storage.md)
- [Collaborative document](../social/collaborative-document.md)
