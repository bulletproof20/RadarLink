# Checkpoint API Reference

!!! tip "Published Checkpoint API (Doxygen)"
    [**Open Checkpoint API →**](/api/checkpoint/html/index.html)

    Alternate entry: [Checkpoint API root](/api/checkpoint/html/)

This page links to the **Doxygen HTML reference** for `Academic_Edition/` — the frozen historical checkpoint submitted for academic evaluation.

## Historical context

The checkpoint source documents the project at an intermediate evaluated moment in the same timeline: graph construction, traversals, path enumeration, and intersection analysis, without runtime matrix editing or `process_nef` (efeitos nefastos). The tree is preserved as an archive. This Doxygen output is historical context for that checkpoint moment—it is regenerated from frozen source and does not track ongoing development.

Compare with the [Deliverable API](deliverable-api.md) or the [API Overview](index.md).

## Generated output

| Item | Path |
|------|------|
| Doxyfile | `Doxyfile.checkpoint` |
| HTML output | `build/doxygen/checkpoint/html/` |
| Entry page | `build/doxygen/checkpoint/html/index.html` |

Build locally:

```bash
./scripts/docs-build.sh
# or (Windows)
./scripts/docs-build.ps1
```

To generate only the checkpoint reference:

```bash
doxygen Doxyfile.checkpoint
```

## Published API

Browse the checkpoint Doxygen reference on GitHub Pages:

- [Checkpoint API index](/api/checkpoint/html/index.html)
- [Checkpoint API root](/api/checkpoint/html/)

Local builds write to `build/doxygen/checkpoint/html/` before the docs-build merge step copies output into the published site tree.
