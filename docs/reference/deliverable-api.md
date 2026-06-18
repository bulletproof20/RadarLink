# Deliverable API Reference

This page links to the **Doxygen HTML reference** for `RadarLink_Extended/Montagem/` — the evaluated integrated deliverable.

## Historical context

The deliverable continues the project timeline from the checkpoint: same module layout, extended with `process_nef.c` / `process_nef.h`, runtime matrix editing, and integration of both assignment parts in one executable. This Doxygen output is historical context for the evaluated hand-in moment—it is regenerated from the deliverable source tree and documents that milestone, not a separate product roadmap.

## Generated output

| Item | Path |
|------|------|
| Doxyfile | `Doxyfile.deliverable` |
| HTML output | `build/doxygen/deliverable/html/` |
| Entry page | `build/doxygen/deliverable/html/index.html` |

Build locally:

```bash
./scripts/docs-build.sh
# or (Windows)
./scripts/docs-build.ps1
```

To generate only the deliverable reference:

```bash
doxygen Doxyfile.deliverable
```

## Published API

Browse the deliverable Doxygen reference on GitHub Pages:

- [Deliverable API index](/api/deliverable/html/index.html)
- [Deliverable API root](/api/deliverable/html/)

Local builds write to `build/doxygen/deliverable/html/` before the docs-build merge step copies output into the published site tree.
