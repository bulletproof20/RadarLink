# From Checkpoint to Deliverable

The repository preserves **two moments of the same academic project**, not two independent codebases.

```text
Enunciado → problem analysis → Academic_Edition → RadarLink_Extended → evaluation → preservation & publication
```

## Same project, different moments

| Moment | Folder | Question it answers |
|--------|--------|---------------------|
| Checkpoint | `Academic_Edition/` | What was evaluated as the checkpoint submission at that stage of the project? |
| Deliverable | `RadarLink_Extended/Montagem/` | What was evaluated as the integrated deliverable? |
| Preservation | `docs/`, Docker, CI (later) | How is the story kept reproducible and public? |

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

## Documentation split (planned)

| Layer | Tool | Audience |
|-------|------|----------|
| Narrative (this site) | MkDocs | Story, engineering explanation, preservation |
| API reference | Doxygen (linked, not embedded) | Function and struct-level detail per edition |

Engineering deep-dives and Doxygen links will appear in later documentation phases.

## PDF copies

`Enunciado.docx.pdf` exists at both edition roots with **identical content** (same SHA-256). Both are kept intentionally; consolidation is optional and not required for correctness.
