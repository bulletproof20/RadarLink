# Assignment and Problem

The starting point for RadarLink is the **EAD practical assignment** (`Enunciado.docx.pdf`), preserved in both edition folders at the repository root of each tree.

## Problem domain

The program simulates a **city covered by radar antennas** arranged on a rectangular grid. Input files describe which cells contain antennas and which **resonance frequency** (a single character) each antenna emits.

From that matrix the software must:

1. **Load and validate** city data from text files.
2. **Build a graph model** — vertices (antennas), edges (links within a frequency layer), and supporting geometric structures for signal segments.
3. **Answer queries** through an interactive terminal menu, including:
   - depth-first and breadth-first traversals from a chosen antenna;
   - all paths between two antennas;
   - intersections between signal segments of different frequencies;
   - diagnostic views of the internal structure (subgraphs, segments, compatible pairs).

## Expected behaviour (checkpoint scope)

At the **Academic Edition** checkpoint, the emphasis was on correct data structures and algorithms over the graph and geometry modules — without runtime matrix editing or the extended “efeitos nefastos” (harmful effects) analysis.

## Inputs

Test cities live under `Academic_Edition/cidades/` and `RadarLink_Extended/Montagem/cidades/` (seven files each, including edge-case names such as `cidade#.txt` and `cidade-.txt`).

## Where to look next

- [Checkpoint (Academic Edition)](checkpoint-academic-edition.md) — what was frozen as the evaluated submission.
- [Deliverable (RadarLink Extended)](deliverable-radarlink-extended.md) — the integrated deliverable milestone in the project timeline.

The assignment PDF itself is **not duplicated in this site**; open `Enunciado.docx.pdf` in either edition folder for the authoritative wording from the faculty.
