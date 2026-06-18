# RadarLink

RadarLink is a graph-based application written in **C** that models a city-wide network of radar antennas from text-based maps. Each occupied position in the city grid represents an antenna operating at a specific resonance frequency.

The project combines **file processing**, **dynamic data structures**, **graph algorithms**, and **geometric analysis** to study relationships between antennas, discover communication paths, and identify signal intersections.

**Documentation Website:** https://bulletproof20.github.io/RadarLink/

---

## Academic Context

| Detail        | Value                                  |
| ------------- | -------------------------------------- |
| Unit          | Estruturas Avançadas de Dados (EAD)    |
| Programme     | Engenharia de Informática Médica (EIM) |
| Institution   | IPCA                                   |
| Academic Year | 1st Year, 2nd Semester                 |

RadarLink was developed during the second semester of the first year of the degree programme as part of the **Estruturas Avançadas de Dados (EAD)** course.

It was one of my first independent projects written in **C**, representing my first substantial contact with low-level programming concepts such as manual memory management, graph modelling, and algorithm implementation.

Beyond the academic requirements, the project also became an opportunity for personal experimentation, curiosity-driven learning, and technical growth.

**Original Assignment (Enunciado):**

* Documentation Site: `Enunciado.docx.pdf`
* Repository: `RadarLink_Extended/Enunciado.docx.pdf`

---

## Project Overview

```text
City File
    ↓
City Matrix
    ↓
Radar Antennas
    ↓
Frequency-Based Subgraphs
    ↓
Graph Construction
    ↓
Traversal & Analysis
    ↓
Signal Intersection Detection
```

The application loads a city description from a text file and constructs graph structures representing antenna networks grouped by frequency.

The resulting graph can then be analysed through several traversal and path-discovery algorithms.

---

## Key Features

* City modelling through text-based matrices
* Antenna grouping by resonance frequency
* Multi-layer graph construction
* Breadth-First Search (BFS)
* Depth-First Search (DFS)
* Path discovery and enumeration
* Signal segment generation
* Geometric intersection detection
* Interactive console interface
* Docker-based reproducible builds
* Doxygen API documentation
* GitHub Pages publication

---

## Project Timeline

```text
1st Year, 2nd Semester
        ↓
Original Assignment
        ↓
Academic_Edition (Checkpoint)
        ↓
RadarLink_Extended (Final Deliverable)
        ↓
Evaluation
        ↓
Documentation Preservation
        ↓
GitHub Pages Publication
```

This repository preserves a single academic project at multiple stages of its lifecycle.

| Stage             | Folder                         | Description                               |
| ----------------- | ------------------------------ | ----------------------------------------- |
| Checkpoint        | `Academic_Edition/`            | Intermediate evaluated submission         |
| Final Deliverable | `RadarLink_Extended/Montagem/` | Final evaluated version                   |
| Documentation     | `docs/`                        | Narrative documentation and API reference |

The checkpoint and deliverable are historical milestones of the same project rather than independent versions.

---

## Running the Deliverable

Build:

```bash
docker compose run --rm deliverable-build
```

Run:

```bash
docker compose run --rm -it deliverable-run
```

Example city file:

```text
cidades/cidade1.txt
```

Generated binary:

```text
build/deliverable/RadarLink
```

For detailed instructions see the documentation website.

---

## Technical Documentation

### Documentation Website

https://bulletproof20.github.io/RadarLink/

### Doxygen API

| Edition           | Documentation   |
| ----------------- | --------------- |
| Academic Edition  | Checkpoint API  |
| Final Deliverable | Deliverable API |

### Assignment

Original project statement available through:

* Documentation site PDF
* Repository copy (`RadarLink_Extended/Enunciado.docx.pdf`)

---

## Learning Outcomes

Through the development of RadarLink I gained practical experience with:

* Programming in C
* Dynamic memory allocation
* Linked data structures
* Graph representation and traversal
* BFS and DFS algorithms
* Path enumeration techniques
* Geometric computations
* Software documentation with Doxygen
* Build reproducibility using Docker
* Long-term software preservation using MkDocs and GitHub Pages

---

## Repository Preservation

The application source code preserved in:

* `Academic_Edition/`
* `RadarLink_Extended/Montagem/`

has not been functionally modified after academic evaluation.

Recent work on this repository focused exclusively on:

* Documentation generation
* Doxygen integration
* MkDocs documentation
* GitHub Actions automation
* GitHub Pages publication
* Repository preservation

The objective is to preserve and document the original project rather than rewrite or modernise it.

---

## Technologies

* C
* Docker
* Doxygen
* MkDocs Material
* GitHub Actions
* GitHub Pages

---

## Author

**Ivo Sá**

* Engenharia de Informática Médica (EIM)
* IPCA
* Estruturas Avançadas de Dados (EAD)

Project preserved and documented as part of an ongoing software engineering portfolio.
