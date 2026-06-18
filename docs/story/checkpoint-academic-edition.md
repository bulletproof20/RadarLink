# Checkpoint — Academic Edition

`Academic_Edition/` is a **historical checkpoint**: the project as it existed for academic evaluation. Its source is **frozen** — no refactoring, feature work, or architectural changes belong in this tree.

## Role in the project story

This folder answers the question: *“What did the checkpoint look like at that stage of the project?”* It is not an inferior product line or a “version 1” maintained in parallel. It is an **archived moment** in a single narrative.

## Contents

| Path | Description |
|------|-------------|
| `main.c` | Entry point and menu orchestration |
| `src/` | Modules: structures, file I/O, graph algorithms, interface |
| `cidades/` | Test city files |
| `esquemas/` | Draw.io diagrams (V1–V3) |
| `Enunciado.docx.pdf` | Assignment statement |
| `README.txt` | Author notes and manual `gcc` build hint |
| `icon.ico`, `logo.png`, `recurso.rc` | Windows resource branding |

## Module set (checkpoint)

The checkpoint `src/` tree contains **nine files**: one shared header and **four implementation modules** (each with `.c` and `.h`). There is no `process_nef`.

| File | Role |
|------|------|
| `estruturas.h` | Graph and geometry types |
| `process_ficheiro.c` / `process_ficheiro.h` | Matrix loading |
| `process_geral.c` / `process_geral.h` | General graph operations |
| `process_esp.c` / `process_esp.h` | Specialized traversals and paths |
| `interface.c` / `interface.h` | Terminal UI and menus |

## Build (from source)

From `Academic_Edition/`:

```bash
gcc -I src main.c src/*.c -o Programa
```

With Windows icon resource:

```bash
windres recurso.rc -o recurso.o
gcc -I src main.c src/*.c recurso.o -o Programa.exe
```

Prebuilt binaries and Doxygen HTML are **not** kept in the repository; they are regenerated when needed (see [Reproducibility](../preservation/reproducibility.md)).

## What this edition deliberately excludes

- Runtime matrix editing
- “Efeitos nefastos” (NEF) computation (`process_nef`)
- Post-evaluation integration of both assignment parts into one executable

Those capabilities appear only in the [deliverable tree](deliverable-radarlink-extended.md).
