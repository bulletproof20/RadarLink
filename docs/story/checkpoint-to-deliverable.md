# Checkpoint vs Deliverable

The repository preserves **two moments of the same academic project**, not two independent codebases or version lines.

```text
Enunciado → problem analysis → Academic_Edition → RadarLink_Extended → evaluation → preservation & publication
```

## Conceptual difference

| | **Academic Edition (checkpoint)** | **RadarLink Extended (deliverable)** |
|---|-----------------------------------|--------------------------------------|
| **Question it answers** | What was evaluated at the intermediate checkpoint stage? | What was evaluated as the integrated final hand-in? |
| **Folder** | `Academic_Edition/` | `RadarLink_Extended/Montagem/` |
| **Scope** | Graph model, traversals, paths, intersections — no runtime matrix editing, no `process_nef` | Both assignment parts merged; matrix editing; *efeitos nefastos* (NEF) |
| **Relationship** | Archived moment on the timeline | Extends checkpoint architecture; does not replace the archive |

This is **evolution along one project timeline**, not “v1 vs v2” or “legacy vs current product”.

## Same project, different moments

| Moment | Folder | Question it answers |
|--------|--------|---------------------|
| Checkpoint | `Academic_Edition/` | What was evaluated as the checkpoint submission at that stage of the project? |
| Deliverable | `RadarLink_Extended/Montagem/` | What was evaluated as the integrated deliverable? |
| Preservation | `docs/`, Docker, GitHub Pages | How is the story kept reproducible and public **without changing application logic**? |

## Technical lineage

The extended deliverable **copies and extends** the checkpoint architecture:

- Shared conceptual model: frequency-layer subgraphs, vertices, edges, segment geometry.
- Shared module names and responsibilities in `src/`.
- **Added** `process_nef` for matrix mutation and nefastos effects.
- **No merge** of the folders into one tree — merging would erase the checkpoint boundary the faculty evaluated.

## What we explicitly avoid

- Treating Academic Edition as “legacy” or “unsupported v1”
- Feature flags or shared libraries that replace the checkpoint source
- Rewriting checkpoint files to match the deliverable

## Documentation split

| Layer | Tool | Audience |
|-------|------|----------|
| Narrative (this site) | MkDocs | Story, preservation, project timeline |
| API reference | Doxygen (linked under `/api/…/html/`) | Function and struct-level detail per edition |

!!! tip "Technical documentation (Doxygen)"
    - [**Checkpoint API →**](/api/checkpoint/html/index.html)
    - [**Deliverable API →**](/api/deliverable/html/index.html)

    [API Overview](../reference/index.md)

## Assignment document

!!! info "Enunciado original"
    [Open assignment PDF (Enunciado.docx.pdf)](../assets/Enunciado.docx.pdf)

Identical copies exist at both edition roots in the repository (same SHA-256).
