# syntax=docker/dockerfile:1

FROM node:22-bookworm-slim AS lint

ARG LYCHEE_VERSION=0.18.0

RUN apt-get update \
    && apt-get install -y --no-install-recommends ca-certificates curl \
    && curl -fsSL "https://github.com/lycheeverse/lychee/releases/download/lychee-v${LYCHEE_VERSION}/lychee-x86_64-unknown-linux-gnu.tar.gz" \
        | tar -xz -C /usr/local/bin \
    && npm install -g markdownlint-cli \
    && apt-get purge -y curl \
    && apt-get autoremove -y \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace
COPY . .
CMD ["./.github/scripts/lint.sh"]

FROM debian:bookworm-slim AS resume

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        latexmk \
        texlive-fonts-extra \
        texlive-fonts-recommended \
        texlive-latex-base \
        texlive-latex-extra \
        texlive-latex-recommended \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace
COPY . .
CMD ["./.github/scripts/compile-resumes.sh"]

FROM debian:bookworm-slim AS coding

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        g++ \
        make \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace
COPY . .
CMD ["./.github/scripts/compile-coding.sh"]
