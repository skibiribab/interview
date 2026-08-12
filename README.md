# gardusig/interview

Interview preparation monorepo — behavioral, system design, coding, and resumes.

## Focus

Three pillars (resume is a separate output produced from them):

- **Behavioral** — work stories + reference prep guidance.
- **System design** — architecture examples, patterns, AWS drills, runbooks.
- **Coding** — C++17 CP reference handbook, contest submissions.

## Sections

| Path | Content |
| --- | --- |
| [`behavioral/`](behavioral/README.md) | Work stories + [`reference/`](behavioral/reference/README.md) prep guidance for behavioral rounds |
| [`system-design/`](system-design/README.md) | Architecture examples, patterns, AWS drills, 60-minute runbooks |
| [`coding/`](coding/README.md) | C++17 CP reference handbook, contest submissions |
| [`resume/`](resume/README.md) | LaTeX resume versions for different roles/companies |

## Quick start

```bash
# Lint all markdown
markdownlint '**/*.md' --ignore node_modules

# Check links
lychee '**/*.md' --exclude 'https://linkedin.com'

# Compile a resume
latexmk -pdf resume/general.tex
```
