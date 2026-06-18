# How to Run

This page covers the **evaluated deliverable** only — the canonical build and run target is `RadarLink_Extended/Montagem/`. Docker is used so the program can be built and executed without installing a local C toolchain.

## Build

Compile the deliverable binary inside a Linux container:

```bash
docker compose run --rm deliverable-build
```

This command runs `gcc` against the Montagem source tree and writes the executable to `build/deliverable/RadarLink`.

## Run

Start the interactive console program (requires a TTY):

```bash
docker compose run --rm -it deliverable-run
```

When prompted for a city file, enter a path relative to the Montagem working directory, for example:

```text
cidades/cidade1.txt
```

## What these commands do

| Command | Purpose |
|---------|---------|
| `deliverable-build` | One-off compilation of the frozen deliverable source; output is not committed to the repository. |
| `deliverable-run` | Executes the compiled binary with stdin/stdout attached so the terminal menu is usable. |

For checkpoint build instructions (manual `gcc` from `Academic_Edition/`), see [Checkpoint (Academic Edition)](../story/checkpoint-academic-edition.md).

For the full preservation and documentation pipeline, see [Reproducibility](../preservation/reproducibility.md).
