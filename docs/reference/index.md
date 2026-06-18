# API Overview

The **Doxygen** reference is a central part of this repository. It documents functions, structures, and modules for each preserved moment of the project — regenerated from frozen source, not maintained as hand-written pages.

!!! tip "Published technical documentation (Doxygen)"
    | Edition | Description | Link |
    |---------|-------------|------|
    | **Checkpoint API** | `Academic_Edition/` — intermediate evaluated submission | [**Open Checkpoint API →**](/RadarLink/api/checkpoint/html/index.html) |
    | **Deliverable API** | `RadarLink_Extended/Montagem/` — integrated final hand-in | [**Open Deliverable API →**](/RadarLink/api/deliverable/html/index.html) |

    Root indexes (no `index.html` suffix):

    - [Checkpoint API root](/RadarLink/api/checkpoint/html/)
    - [Deliverable API root](/RadarLink/api/deliverable/html/)

## Narrative vs API

| Layer | Tool | Location |
|-------|------|----------|
| Story, guide, preservation | MkDocs (this site) | `/` |
| Function and struct reference | Doxygen HTML | `/RadarLink/api/checkpoint/html/`, `/RadarLink/api/deliverable/html/` |

MkDocs pages describe **context and how to reproduce** builds; Doxygen pages describe **implementation detail** per edition.

## Build locally

Full site including merged API HTML:

```bash
./scripts/docs-build.sh
```

Windows (PowerShell):

```powershell
./scripts/docs-build.ps1
```

## Edition-specific pages

- [Checkpoint API](checkpoint-api.md) — Doxyfile, paths, and checkpoint scope.
- [Deliverable API](deliverable-api.md) — Doxyfile, paths, and deliverable scope.
