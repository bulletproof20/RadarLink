# RadarLink

**RadarLink** is a console application in C that models a city grid of radar antennas. Each occupied cell in a text file represents an antenna with a resonance frequency. The program loads a city matrix, builds a multi-layer graph grouped by frequency, and supports graph traversals, path enumeration, and geometric intersection analysis between signal segments.

This documentation site tells **one academic project story** in chronological order — not two parallel products.

## How to read this site

| Section | Purpose |
|---------|---------|
| **Story** | Why the project exists, the checkpoint submission, the integrated deliverable milestone, and how the two artefacts relate in the project timeline. |
| **Preservation** | How the repository keeps source, builds, and documentation reproducible over time. |
| **Reference** | Published Doxygen API reference for the checkpoint and deliverable moments (`/api/…/html/`). |

The **Reference** section links to generated API HTML merged into the published site; narrative pages stay in MkDocs without embedding Doxygen output.

## Repository layout

```text
Academic_Edition/          Historical checkpoint — frozen source as evaluated
RadarLink_Extended/        Evaluated final deliverable — build and run target
  └── Montagem/            Canonical build root for the extended program
docs/                      Narrative documentation (this site)
```

## Author

Ivo Filipe Carvalho de Sá — IPCA, EIM, Estruturas de Dados e Algoritmos (EAD).
