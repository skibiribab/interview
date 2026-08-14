# Resume

LaTeX sources for different resume variants (role / company). Files live directly under this folder (`general.tex`, …).

Compile locally:

```bash
docker build --target resume -t interview-resume -f docker/Dockerfile .
docker run interview-resume
```

Or:

```bash
latexmk -pdf src/resume/general.tex
```

## CI

- **PR:** builds `docker/Dockerfile` stage `resume` and compiles all `src/resume/*.tex`.
- **Release** (main push): builds the resumes, auto-tags with a timestamp, and attaches the PDFs to the GitHub release for that tag.
