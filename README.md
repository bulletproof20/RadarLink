# RadarLink

RadarLink is a graph-based application written in **C** that models a city-wide network of radar antennas from text-based maps. Each occupied position in the city grid represents an antenna operating at a specific resonance frequency.

The project was developed to explore how radar antennas distributed across a city can be represented, analysed, and connected through graph structures. By transforming a city map into a network of frequency-based subgraphs, RadarLink enables the study of connectivity, traversal strategies, path discovery, and signal intersection analysis.

The application combines **file processing**, **dynamic data structures**, **graph algorithms**, and **geometric computations**, providing a practical introduction to algorithmic problem solving and data structure design in C.

**Documentation Website:**
https://bulletproof20.github.io/RadarLink/

---

## Academic Context

| Detail           | Value                                          |
| ---------------- | ---------------------------------------------- |
| Student          | Ivo Sá (22604)                                 |
| Course Unit      | Advanced Data Structures                       |
| Degree Programme | Medical Informatics Engineering             |
| Institution      | Polytechnic Institute of Cávado and Ave (IPCA) |
| Academic Period  | First Year, Second Semester                    |

RadarLink was developed during the second semester of the first year of the Biomedical Informatics Engineering degree programme as part of the **Advanced Data Structures** course.

This project represented one of my first independent software development experiences in **C**, providing substantial exposure to manual memory management, graph modelling, algorithm implementation, and low-level programming concepts.

Although developed within an academic setting, the project also became an opportunity for personal experimentation, curiosity-driven learning, and technical growth beyond the minimum course requirements.

The current repository preserves both the original evaluated work and the documentation infrastructure created afterwards to ensure long-term accessibility, reproducibility, and public availability.

### Original Assignment

The original project specification is available through:

* Documentation website PDF
* Repository copy: `RadarLink_Extended/Enunciado.docx.pdf`

---

## Problem Overview

The project begins with a city description stored in a text file.

Each valid position in the map may contain a radar antenna identified by a resonance frequency. Antennas operating at the same frequency are grouped together, allowing the creation of frequency-specific graph structures.

These graphs can then be analysed using traversal and path-discovery algorithms, while geometric calculations are used to identify potential intersections between signal paths.

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

---

## Key Features

* City modelling through text-based matrices
* Radar antenna grouping by resonance frequency
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
First Year, Second Semester
            ↓
Original Assignment
            ↓
Academic_Edition (Checkpoint)
            ↓
RadarLink_Extended (Final Deliverable)
            ↓
Academic Evaluation
            ↓
Documentation & Preservation
            ↓
GitHub Pages Publication
```

This repository preserves a single academic project at multiple stages of its lifecycle.

| Stage                        | Folder                         | Description                                                             |
| ---------------------------- | ------------------------------ | ----------------------------------------------------------------------- |
| Checkpoint                   | `Academic_Edition/`            | Intermediate evaluated submission                                       |
| Final Deliverable            | `RadarLink_Extended/Montagem/` | Final evaluated version                                                 |
| Documentation & Preservation | `docs/`                        | Documentation, API reference, reproducibility, and project preservation |

The checkpoint and deliverable are historical milestones of the same project rather than separate software products.

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

For detailed instructions, refer to the documentation website.

---

## Technical Documentation

### Documentation Website

https://bulletproof20.github.io/RadarLink/

### Doxygen API Reference

| Edition           | Documentation                                                             |
| ----------------- | ------------------------------------------------------------------------- |
| Academic Edition  | https://bulletproof20.github.io/RadarLink/api/checkpoint/html/index.html  |
| Final Deliverable | https://bulletproof20.github.io/RadarLink/api/deliverable/html/index.html |

### Original Assignment

Available through:

* Documentation website PDF
* Repository copy (`RadarLink_Extended/Enunciado.docx.pdf`)

---

## Learning Outcomes

Through the development of RadarLink I gained practical experience with:

* Programming in C
* Dynamic memory allocation
* Linked data structures
* Graph representation and traversal
* Breadth-First Search (BFS)
* Depth-First Search (DFS)
* Path enumeration techniques
* Geometric computations
* Software architecture and organisation
* Problem-solving using graph-based models

The later preservation phase also provided experience with:

* Docker
* Doxygen
* MkDocs
* GitHub Actions
* GitHub Pages
* Documentation automation
* Software preservation practices

---

## Repository Preservation

The source code preserved in:

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

The objective of this repository is to preserve, document, and present the original academic project rather than rewrite, refactor, or modernise it.

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

**Ivo Sá (22604)**

* Bachelor's Degree in Biomedical Informatics Engineering
* Polytechnic Institute of Cávado and Ave (IPCA)
* Advanced Data Structures

RadarLink was originally developed during the second semester of the first year of the Biomedical Informatics Engineering degree programme as part of the Advanced Data Structures course.

The project represents one of my earliest substantial experiences with the C programming language, introducing concepts such as manual memory management, graph modelling, algorithm implementation, and data structure design.

While initially developed to satisfy academic requirements, it also became an opportunity for independent exploration, curiosity-driven learning, and technical growth beyond the scope of the coursework.

The current repository preserves both the original evaluated project and the documentation infrastructure added afterwards, ensuring long-term accessibility, reproducibility, and public availability through Docker, Doxygen, MkDocs, GitHub Actions, and GitHub Pages.
