# Interview conventions

Interview preparation monorepo.

## Structure

- `src/behavioral/` — work stories + reference prep guidance.
- `src/system-design/` — architecture examples, patterns, AWS drills, runbooks.
- `src/coding/` — C++17 CP reference handbook, contest submissions.
- `src/resume/` — LaTeX resume versions for roles/companies.

## Rules

- Markdown: tables wrapped in `<!-- begin table -->` / `<!-- end table -->`; fenced code blocks declare a language.
- Keep sections self-contained with their own README + contents table.
- Theme: `GitHub Dark Default`.

## CI

- `test.yml` — PR gate: docker targets `lint` / `resume` / `coding`.
- `release.yml` — tag-driven: build + attach resume PDFs as a GitHub release.
