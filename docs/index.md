# RadarLink

**RadarLink** is a console application in C that models a city grid of radar antennas. Each occupied cell in a text file represents an antenna with a resonance frequency. The program loads a city matrix, builds a multi-layer graph grouped by frequency, and supports graph traversals, path enumeration, and geometric intersection analysis between signal segments.

This documentation site is an **academic, technical, and historical record** of one project — from the *enunciado* through an evaluated checkpoint and deliverable to documentation preservation. It is not two parallel products.

**Published site:** [https://bulletproof20.github.io/RadarLink/](https://bulletproof20.github.io/RadarLink/) · **Repository:** [README.md](https://github.com/bulletproof20/RadarLink/blob/main/README.md)

## Quick access

!!! info "Original assignment (Enunciado)"
    [Open assignment PDF (Enunciado.docx.pdf)](assets/Enunciado.docx.pdf)

!!! tip "Technical documentation (Doxygen)"
    | Edition | Link |
    |---------|------|
    | **Checkpoint API** — `Academic_Edition/` | [**Open Checkpoint API →**](/api/checkpoint/html/index.html) |
    | **Deliverable API** — `RadarLink_Extended/Montagem/` | [**Open Deliverable API →**](/api/deliverable/html/index.html) |

    See also the [API Overview](reference/index.md) page for build instructions and context.

## Academic context

RadarLink was developed in **Estruturas Avançadas de Dados (EAD)** within **Engenharia de Informática Médica (EIM)** at **IPCA** — 1st year, 2nd semester. It was among the first independent practical work with **C**.

Full context: [Academic Context](story/academic-context.md).

## Preservation, not rewrite

Recent repository work changed **documentation, automation, GitHub Actions, GitHub Pages, MkDocs, and Doxygen integration** only. The application source in `Academic_Edition/` and `RadarLink_Extended/Montagem/` was **not** functionally modified, refactored, or extended after evaluation.

Details: [Repository Evolution](preservation/repository-evolution.md).

## How to read this site

| Section | Purpose |
|---------|---------|
| **Story** | Academic context, assignment, checkpoint vs deliverable, learning outcomes. |
| **Guide** | How to build and run the deliverable with Docker. |
| **Preservation** | Repository evolution and reproducible builds. |
| **Reference** | Published Doxygen API for checkpoint and deliverable. |

## Project timeline

```text
Enunciado → Academic_Edition (checkpoint) → RadarLink_Extended/Montagem (deliverable)
         → evaluation → documentation & preservation → GitHub Pages
```

| Moment | Folder / output |
|--------|-----------------|
| Checkpoint | `Academic_Edition/` |
| Deliverable | `RadarLink_Extended/Montagem/` |
| Documentation | `docs/`, `site/` (MkDocs + merged Doxygen) |

## Run the deliverable

```bash
docker compose run --rm deliverable-build
docker compose run --rm -it deliverable-run
```

See [How to Run](guide/how-to-run.md).

## Author

Ivo Sá — IPCA, EIM, Estruturas Avançadas de Dados (EAD).
