# Deliverable — RadarLink Extended

`RadarLink_Extended/` holds the **evaluated final deliverable**: an integrated program that combines both parts of the practical work. The canonical build and execution root is **`RadarLink_Extended/Montagem/`**.

!!! info "Enunciado original"
    [Open assignment PDF (Enunciado.docx.pdf)](../assets/Enunciado.docx.pdf)

!!! tip "Technical documentation (Doxygen)"
    | Edition | Link |
    |---------|------|
    | **Deliverable API** (this tree) | [**Open Deliverable API →**](/RadarLink/api/deliverable/html/index.html) |
    | Checkpoint API (for comparison) | [Checkpoint API →](/RadarLink/api/checkpoint/html/index.html) |

    Full reference hub: [API Overview](../reference/index.md).

## Role in the project story

This tree answers: *“What was submitted and graded as the integrated deliverable?”* It reflects a deliberate **integration pass** after the checkpoint — merging matrix manipulation, extended analysis, and the original graph queries into one codebase.

It is **not** an open-ended product roadmap inside this repository. Ongoing repository work (documentation, Docker, CI, publication) belongs to the **preservation phase**, not to feature development inside the deliverable source.

## Project timeline

| Phase | Description |
|-------|-------------|
| **1st year, 2nd semester** | Development within **Estruturas Avançadas de Dados (EAD)**, IPCA, EIM. |
| **Academic Edition** | Intermediate evaluated checkpoint — graph and geometry core without NEF module. |
| **Final deliverable** | Integrated hand-in in `RadarLink_Extended/Montagem/` — both assignment parts, matrix editing, *efeitos nefastos*. |
| **Documentation preservation** | MkDocs narrative, Doxygen API, Docker reproducibility — **no functional changes** to application source. |
| **GitHub Pages publication** | Automated build and deploy via GitHub Actions → [published site](https://bulletproof20.github.io/RadarLink/). |

## What changed relative to the checkpoint

| Area | Extended deliverable |
|------|----------------------|
| Assignment integration | Both practical parts combined in one executable and menu |
| Runtime matrix editing | Antennas can be placed or removed during execution |
| NEF analysis | `process_nef.c` / `process_nef.h` — harmful interference (“efeitos nefastos”) |
| Code integration | Checkpoint modules retained; new behaviour added without replacing the archive |

The core module layout (`estruturas`, `process_ficheiro`, `process_geral`, `process_esp`, `interface`) descends directly from the checkpoint; extended code **adds** modules rather than replacing the archive.

## Layout

```text
RadarLink_Extended/
├── Enunciado.docx.pdf
├── README.txt              Author reflection on the extended submission
└── Montagem/               ← build here
    ├── main.c
    ├── src/
    ├── cidades/
    ├── esquemas/
    └── README.txt
```

Duplicate city files that previously lived at `RadarLink_Extended/cidades/` were removed; **`Montagem/cidades/`** is the single canonical copy.

## Build (from source)

From `RadarLink_Extended/Montagem/`:

```bash
gcc -I src main.c src/*.c -o RadarLink
```

Recommended via Docker: [How to Run](../guide/how-to-run.md).

## Author note

The `README.txt` in this tree records that the extended integration was implemented in roughly **147 minutes**, as a measure of improved fluency after completing the EAD course — with acknowledged imperfections left uncorrected due to concurrent assessment pressure.

## Next

[Checkpoint vs Deliverable](checkpoint-to-deliverable.md) explains the relationship between the two trees without merging them.
