# Video conferencing platform (Zoom / Meet)

## Introduction

Video conferencing connects **many participants** in a **real-time room** with SFU/MCU routing, screen share, and recording — distinct from [live streaming](./live-video-streaming.md) (one-to-many broadcast) and [VOD](./video-on-demand-platform.md).

**Company anchors:** Zoom, Google Meet, Microsoft Teams meetings.

## Requirements discovery

| Lock (target) |
| --- |
| 100 participants / room |
| p99 join &lt; 3 s |
| Audio/video via SFU (no full mesh) |
| Optional cloud recording to S3 |

## Architecture (user → database)

```mermaid
flowchart TB
 host([Host])
 guest([Guest])
 signal[Signaling · WebSocket]
 sfu[Media SFU cluster · ECS]
 turn[TURN relay]
 rooms[(DynamoDB · rooms)]
 record[(Amazon S3 · recordings)]

 host --> signal
 guest --> signal
 signal --> rooms
 host -->|WebRTC| sfu
 guest -->|WebRTC| sfu
 guest -.-> turn
 sfu -.->|optional| record

 classDef user fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
 classDef edge fill:#fff8e1,#ffb74d,stroke:#ef6c00,color:#111
 classDef app fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
 classDef data fill:#fce4ec,#ef5350,stroke:#c62828,color:#111
 classDef async fill:#f3e5f5,#ab47bc,stroke:#6a1b9a,color:#111
 class host,guest user
 class signal,sfu,turn app
 class rooms,record data
```

**Narrative:** **Signaling** exchanges SDP/ICE via WebSocket. **SFU** forwards streams (no transcoding per peer). **TURN** punches NAT. **Recording** taps SFU output to **S3**.

## Deep dive

- **SFU vs MCU** tradeoff on whiteboard.
- **Simulcast** layers for bandwidth adaptation.
- Large webinar: hybrid with [live streaming](./live-video-streaming.md).

## Related

- [Live video streaming](./live-video-streaming.md)
- [Chat messenger](../social/chat-messenger.md)
- [Community chat](../social/community-chat-platform.md)
