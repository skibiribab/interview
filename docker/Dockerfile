# syntax=docker/dockerfile:1

FROM skibiribab/cli:1.8.0-node AS lint

WORKDIR /workspace
COPY . .
RUN cli repo lint /workspace

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
