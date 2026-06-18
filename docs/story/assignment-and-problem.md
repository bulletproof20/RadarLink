# Assignment and Problem

The starting point for RadarLink is the **EAD practical assignment** — the faculty *enunciado* preserved in the repository and on this site.

!!! info "Enunciado original"
    [Open assignment PDF (Enunciado.docx.pdf)](../assets/Enunciado.docx.pdf)

The same file exists at `Academic_Edition/Enunciado.docx.pdf` and `RadarLink_Extended/Enunciado.docx.pdf`.

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

## Technical reference

For automatically generated API documentation:

!!! tip "Doxygen API"
    - [**Checkpoint API →**](/api/checkpoint/html/index.html) — `Academic_Edition/`
    - [**Deliverable API →**](/api/deliverable/html/index.html) — `RadarLink_Extended/Montagem/`

## Where to look next

- [Academic Context](academic-context.md) — unit, institution, and motivation.
- [Checkpoint (Academic Edition)](checkpoint-academic-edition.md) — evaluated checkpoint submission.
- [Deliverable (RadarLink Extended)](deliverable-radarlink-extended.md) — integrated deliverable milestone.
