# Resume

LaTeX sources for different resume variants (role / company). Files live directly under this folder (`general.tex`, …).

Compile locally:

```bash
docker build --target resume -t interview-resume -f .github/docker/Dockerfile .
docker run interview-resume
```

Or:

```bash
latexmk -pdf resume/general.tex
```

## CI

- **PR:** builds `.github/docker/Dockerfile` stage `resume` and compiles all `resume/*.tex`.
- **Release** (any git tag): uploads `resumes` as a downloadable Actions artifact and attaches the PDFs to the GitHub release for that tag.
