# RadarLink

**RadarLink** is a console application in C that models a city grid of radar antennas. Each occupied cell in a text file represents an antenna with a resonance frequency. The program loads a city matrix, builds a multi-layer graph grouped by frequency, and supports graph traversals, path enumeration, and geometric intersection analysis between signal segments.

This repository preserves **one academic project** at two moments in the same timeline — an evaluated checkpoint and an evaluated deliverable — plus the documentation and tooling that keep both reproducible and public.

**Documentation site:** [https://bulletproof20.github.io/RadarLink/](https://bulletproof20.github.io/RadarLink/)

## Academic context

| Detail | Value |
|--------|-------|
| **Unit** | Estruturas Avançadas de Dados (EAD) |
| **Programme** | Engenharia de Informática Médica (EIM) |
| **Institution** | IPCA |
| **Academic year** | 1st year, 2nd semester |

The project was among the first independent practical work with **C** during the degree. Full context on the [Academic Context](https://bulletproof20.github.io/RadarLink/story/academic-context/) page.

**Original assignment (*Enunciado*):**

- On the published site: [Enunciado.docx.pdf](https://bulletproof20.github.io/RadarLink/assets/Enunciado.docx.pdf)
- In the repository: `RadarLink_Extended/Enunciado.docx.pdf`

## Preservation, not rewrite

Recent work on this repository changed **documentation, automation, GitHub Actions, GitHub Pages, MkDocs, and Doxygen integration** only. The application source in `Academic_Edition/` and `RadarLink_Extended/Montagem/` was **not** functionally modified, refactored, or extended after evaluation.

Details: [Repository Evolution](https://bulletproof20.github.io/RadarLink/preservation/repository-evolution/) on the documentation site.

## Project Story

The project follows a single journey from assignment to preservation:

```text
Enunciado → analysis → Academic_Edition (checkpoint) → RadarLink_Extended/Montagem (deliverable) → evaluation → documentation & preservation
```

| Moment | Folder | Role |
|--------|--------|------|
| **Checkpoint** | `Academic_Edition/` | Frozen source as submitted at an intermediate evaluated stage of the project. |
| **Deliverable** | `RadarLink_Extended/Montagem/` | Integrated final hand-in — canonical build and run target. |
| **Documentation & preservation** | `docs/`, Docker, Doxygen, GitHub Pages | Narrative site, API reference, and reproducible builds. |

The checkpoint and deliverable are **not** two parallel products or version lines. They are historical artefacts on the same project timeline.

## Technical documentation (Doxygen)

| Edition | Published API |
|---------|-----------------|
| **Checkpoint** — `Academic_Edition/` | [Checkpoint API](https://bulletproof20.github.io/RadarLink/api/checkpoint/html/index.html) |
| **Deliverable** — `RadarLink_Extended/Montagem/` | [Deliverable API](https://bulletproof20.github.io/RadarLink/api/deliverable/html/index.html) |

API overview and build instructions: [Reference section](https://bulletproof20.github.io/RadarLink/reference/) on the documentation site.

## Repository Structure

```text
Academic_Edition/           Checkpoint source (frozen)
RadarLink_Extended/
  └── Montagem/             Deliverable source — build and run root
docs/                       MkDocs narrative (Story, Guide, Preservation, Reference)
  └── assets/               Site assets (icon, Enunciado PDF)
docker/                     Docker images for deliverable and documentation tooling
scripts/                    Build scripts (docs-build, merge-api)
Doxyfile.checkpoint         Doxygen config for checkpoint API
Doxyfile.deliverable        Doxygen config for deliverable API
mkdocs.yml                  MkDocs site configuration
docker-compose.yml          Deliverable build/run and documentation services
.github/workflows/docs.yml  GitHub Pages publication (docs-build on push/PR)
build/                      Generated binaries and Doxygen output (not versioned)
site/                       Generated MkDocs + merged API site (not versioned)
```

## Running the Evaluated Deliverable

Build the Linux binary with Docker:

```bash
docker compose run --rm deliverable-build
```

Run the interactive program (requires a TTY):

```bash
docker compose run --rm -it deliverable-run
```

When prompted for a city file, use a path relative to the Montagem working directory, for example:

```text
cidades/cidade1.txt
```

The binary is written to `build/deliverable/RadarLink`.

See [How to Run](https://bulletproof20.github.io/RadarLink/guide/how-to-run/) on the documentation site.

## Documentation

The project separates **narrative documentation** from **API reference**:

| Layer | Tool | Purpose |
|-------|------|---------|
| Story, guide, preservation | [MkDocs](https://www.mkdocs.org/) | Project journey, how to run, reproducibility |
| Function and struct reference | [Doxygen](https://www.doxygen.org/) | Per-edition API HTML, merged into the published site |

**Published site (GitHub Pages):**

| Resource | URL |
|----------|-----|
| Documentation home | https://bulletproof20.github.io/RadarLink/ |
| Checkpoint API | https://bulletproof20.github.io/RadarLink/api/checkpoint/html/ |
| Deliverable API | https://bulletproof20.github.io/RadarLink/api/deliverable/html/ |
| Assignment PDF | https://bulletproof20.github.io/RadarLink/assets/Enunciado.docx.pdf |

Publication is automated by [GitHub Actions](https://github.com/bulletproof20/RadarLink/blob/main/.github/workflows/docs.yml) on push to `main`.

## Reproducing Documentation Locally

**Full site (recommended)** — Doxygen checkpoint + deliverable, MkDocs build, and API merge into `site/`:

```bash
./scripts/docs-build.sh
```

Windows (PowerShell):

```powershell
./scripts/docs-build.ps1
```

**Docker — partial or preview services** (from repository root):

```bash
# Doxygen only
docker compose run --rm doxygen-checkpoint
docker compose run --rm doxygen-deliverable

# MkDocs narrative site only (does not merge API HTML)
docker compose run --rm mkdocs-build

# Live preview on http://localhost:8000 (narrative only)
docker compose run --rm -p 8000:8000 mkdocs-serve
```

Use `docs-build` for the complete published tree including `/api/checkpoint/html/` and `/api/deliverable/html/`.

## Technologies

- C
- Docker
- MkDocs (Material theme)
- Doxygen
- GitHub Pages
- GitHub Actions

## Author

Ivo Sá — IPCA, EIM, Estruturas Avançadas de Dados (EAD).
