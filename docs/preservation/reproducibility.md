# Reproducibility

This page describes the **preservation intent** for RadarLink and how the repository keeps builds and documentation reproducible.

## Principles

1. **Source is canonical** — executables (`.exe`), object files (`.o`), and generated Doxygen HTML are not versioned.
2. **Edition boundaries are fixed** — rebuild each tree from its own root without cross-copying source.
3. **Documentation is layered** — MkDocs carries the narrative; Doxygen regenerates API reference on demand.

## Ignored artifacts

The root `.gitignore` excludes:

- `build/`, `site/` — generated build and MkDocs output (not versioned)
- `*.exe`, `*.o` — binaries and object files
- `Academic_Edition/html/`, `RadarLink_Extended/Montagem/html/` — local Doxygen drops
- `.venv/`, `__pycache__/`, `.vscode/` — local tooling

## Build roots

| Artefact | Directory | Expected output |
|----------|-----------|-----------------|
| Checkpoint program | `Academic_Edition/` | `Programa` / `Programa.exe` |
| Deliverable program | `RadarLink_Extended/Montagem/` | `RadarLink` / `RadarLink.exe` |
| Narrative docs | repository root + `docs/` | `site/` (MkDocs) |
| API docs | `Doxyfile.checkpoint`, `Doxyfile.deliverable` | `build/doxygen/…/html/` → merged to `site/api/…/html/` |

## Test data

City files under `RadarLink_Extended/Montagem/cidades/` are the **single canonical set** for running the deliverable. The checkpoint keeps its own identical copy under `Academic_Edition/cidades/` for historical self-containment.

## Automation

| Capability | Location |
|------------|----------|
| Deliverable Docker build/run | `docker-compose.yml` |
| Documentation pipeline | `scripts/docs-build.sh` |
| GitHub Pages publication | `.github/workflows/docs.yml` → `https://bulletproof20.github.io/RadarLink/` |

## Local preview

Full published site (Doxygen + MkDocs + API merge), same as CI:

```bash
./scripts/docs-build.sh
# or (Windows)
./scripts/docs-build.ps1
```

Narrative-only preview when Python and MkDocs Material are available locally:

```bash
pip install mkdocs-material
mkdocs serve
```

Open the URL printed in the terminal, or open `site/index.html` after `docs-build`.
