# Ecosystem — repo → tech map

**Parent:** [`README.md`](./README.md)

How the repositories relate to the toolchains they run on. Every language is the best tool for its job — one toolchain per purpose, deliberately chosen.

```mermaid
flowchart LR
    subgraph REPOS[Repositories]
        PRIV[0-private]
        CP[1-control-plane]
        INT[2-interview]
        EXT[3-browser-extensions]
        RADAR[4-radar-alerts]
        GAMES[5-browser-games]
    end

    subgraph TOOLS[Toolchains]
        MD[Markdown]
        BASH[Bash]
        DOCKER[Docker]
        CPP[C++17]
        TS[TypeScript]
        VJS[Vanilla JS]
        GO[Go]
        PY[Python]
        REACT[React]
        RUSTW[Rust / WASM]
        RUSTB[Rust backend]
    end

    PRIV --> MD
    CP --> BASH
    CP --> DOCKER
    INT --> MD
    INT --> CPP
    EXT --> TS
    EXT --> VJS
    RADAR --> GO
    RADAR --> PY
    RADAR --> VJS
    GAMES --> RUSTW
    GAMES --> RUSTB
    GAMES --> REACT
    GAMES --> TS

    classDef repo fill:#e8f5e9,#66bb6a,stroke:#2e7d32,color:#111
    classDef tool fill:#e3f2fd,#42a5f5,stroke:#1565c0,color:#111
    class PRIV,CP,INT,EXT,RADAR,GAMES repo
    class MD,BASH,DOCKER,CPP,TS,VJS,GO,PY,REACT,RUSTW,RUSTB tool
```

## Repo → tools

| Repo | Tools | Why |
|---|---|---|
| 0-private | Markdown · PDF · images | Heavy note-taking vault — content as plain text, versionable and diffable. |
| 1-control-plane | Bash · Docker · YAML · Markdown | The shell is the interface; one pinned docker image per toolchain. |
| 2-interview | Markdown · C++17 · LaTeX · Mermaid | Interview prep — notes + CP baseline + resume; mermaid for architecture. |
| 3-browser-extensions | TypeScript · Vanilla JS · Vite | Typed JS for the browser runtime, ships without a server. |
| 4-radar-alerts | Go · Python · Vanilla JS · Docker Compose | Go for the pipeline, Python for scraping, plain JS for the static UI. |
| 5-browser-games | Rust/WASM · Rust backend · React · TypeScript · Tailwind | One Rust codebase from engine (WASM) to backend; React where a SPA earns it. |
