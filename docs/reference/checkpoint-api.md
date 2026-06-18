# Checkpoint API Reference

This page links to the **Doxygen HTML reference** for `Academic_Edition/` — the frozen historical checkpoint submitted for academic evaluation.

## Historical context

The checkpoint source documents the project at an intermediate evaluated moment in the same timeline: graph construction, traversals, path enumeration, and intersection analysis, without runtime matrix editing or `process_nef` (efeitos nefastos). The tree is preserved as an archive. This Doxygen output is historical context for that checkpoint moment—it is regenerated from frozen source and does not track ongoing development.

## Generated output

| Item | Path |
|------|------|
| Doxyfile | `Doxyfile.checkpoint` |
| HTML output | `build/doxygen/checkpoint/html/` |
| Entry page | `build/doxygen/checkpoint/html/index.html` |

Build locally:

```bash
./scripts/build-docs.sh
# or (Windows)
./scripts/build-docs.ps1
```

To generate only the checkpoint reference:

```bash
doxygen Doxyfile.checkpoint
```

## API browser (placeholder)

MkDocs integration and published links will be added in a later phase. For now, open the generated HTML directly after running the build scripts above.

<!-- Future: link to published checkpoint API root, e.g. reference/checkpoint/index.html -->
