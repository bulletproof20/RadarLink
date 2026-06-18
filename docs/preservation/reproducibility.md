# Reproducibility

This page describes the **preservation intent** for RadarLink. Tooling (Docker, CI, Doxygen configs) will be added in later phases; this document anchors the strategy early.

## Principles

1. **Source is canonical** — executables (`.exe`), object files (`.o`), and generated Doxygen HTML are not versioned.
2. **Edition boundaries are fixed** — rebuild each tree from its own root without cross-copying source.
3. **Documentation is layered** — MkDocs carries the narrative; Doxygen regenerates API reference on demand.

## Ignored artifacts

The root `.gitignore` excludes:

- `build/`, `site/` — future build and MkDocs output
- `*.exe`, `*.o` — binaries and object files
- `Academic_Edition/html/`, `RadarLink_Extended/Montagem/html/` — local Doxygen drops
- `.venv/`, `__pycache__/`, `.vscode/` — local tooling

## Build roots

| Artefact | Directory | Expected output |
|----------|-----------|-----------------|
| Checkpoint program | `Academic_Edition/` | `Programa` / `Programa.exe` |
| Deliverable program | `RadarLink_Extended/Montagem/` | `RadarLink` / `RadarLink.exe` |
| Narrative docs | repository root + `docs/` | `site/` (MkDocs) |
| API docs (planned) | per-edition Doxyfile | `build/doxygen/…/html/` |

## Test data

City files under `RadarLink_Extended/Montagem/cidades/` are the **single canonical set** for running the deliverable. The checkpoint keeps its own identical copy under `Academic_Edition/cidades/` for historical self-containment.

## Planned next steps (not implemented yet)

- Docker images for `gcc` build and MkDocs/Doxygen generation
- GitHub Actions workflow validating build + docs
- GitHub Pages publishing from CI

These will be introduced in subsequent preservation work on the repository.

## Local preview (MkDocs)

When Python and MkDocs Material are available:

```bash
pip install mkdocs-material
mkdocs serve
```

Open the URL printed in the terminal to validate navigation before deployment.
