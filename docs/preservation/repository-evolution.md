# Repository Evolution

This page clarifies what changed in the repository **after** the academic evaluation — and what deliberately did **not** change.

## Application source — unchanged

The core application code remains **functionally the same** as submitted:

- No functional modernisation of algorithms or data structures.
- No post-evaluation refactoring of business logic.
- No new features added to the checkpoint or deliverable trees.

`Academic_Edition/` and `RadarLink_Extended/Montagem/` are preserved as **historical artefacts** on the project timeline, not as active product branches.

## Recent work — documentation and infrastructure only

Work on this repository after the hand-in focused exclusively on:

| Area | Examples |
|------|----------|
| **Repository organisation** | Folder naming (`Academic_Edition`, `RadarLink_Extended`), `.gitignore`, removal of generated binaries from version control |
| **Narrative documentation** | MkDocs site under `docs/`, README alignment |
| **Technical API reference** | Doxygen configs (`Doxyfile.checkpoint`, `Doxyfile.deliverable`) and merge into the published site |
| **Automation** | `scripts/docs-build.sh`, GitHub Actions workflow (`.github/workflows/docs.yml`) |
| **Publication** | GitHub Pages at [https://bulletproof20.github.io/RadarLink/](https://bulletproof20.github.io/RadarLink/) |
| **Reproducible builds** | Docker services for deliverable build/run and documentation generation |

This evolution is **honest preservation and presentation** — making the project understandable to teachers, peers, recruiters, and future readers — not a rewrite of the software.

## How to verify

- Compare checkpoint and deliverable folders to their evaluated state; no algorithmic changes are intended.
- Regenerate documentation with `./scripts/docs-build.sh`; application source is input only, not modified by the pipeline.
- Read [Reproducibility](reproducibility.md) for build roots and ignored artifacts.
