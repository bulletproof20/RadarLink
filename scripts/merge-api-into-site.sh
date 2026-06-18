#!/usr/bin/env bash
# Copy generated Doxygen HTML into the MkDocs site tree.
# Expects build/doxygen/*/html and an existing site/ from mkdocs build.

set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"

CHECKPOINT_SRC="build/doxygen/checkpoint/html"
DELIVERABLE_SRC="build/doxygen/deliverable/html"
CHECKPOINT_DST="site/api/checkpoint/html"
DELIVERABLE_DST="site/api/deliverable/html"

require_doxygen_html() {
  local label="$1"
  local src="$2"

  if [[ ! -d "$src" ]]; then
    echo "error: missing Doxygen output directory $src ($label) — run Doxygen first" >&2
    exit 1
  fi
  if [[ ! -f "$src/index.html" ]]; then
    echo "error: missing $src/index.html ($label)" >&2
    exit 1
  fi
}

if [[ ! -d site ]]; then
  echo "error: missing site/ — run mkdocs build first" >&2
  exit 1
fi

require_doxygen_html "checkpoint" "$CHECKPOINT_SRC"
require_doxygen_html "deliverable" "$DELIVERABLE_SRC"

rm -rf "$CHECKPOINT_DST" "$DELIVERABLE_DST"
mkdir -p "$CHECKPOINT_DST" "$DELIVERABLE_DST"

cp -r "$CHECKPOINT_SRC/." "$CHECKPOINT_DST/"
cp -r "$DELIVERABLE_SRC/." "$DELIVERABLE_DST/"

if [[ ! -f "$CHECKPOINT_DST/index.html" ]]; then
  echo "error: copy failed — missing $CHECKPOINT_DST/index.html" >&2
  exit 1
fi
if [[ ! -f "$DELIVERABLE_DST/index.html" ]]; then
  echo "error: copy failed — missing $DELIVERABLE_DST/index.html" >&2
  exit 1
fi

echo "Merged API documentation into site/"
echo "  Checkpoint:  $CHECKPOINT_DST/index.html"
echo "  Deliverable: $DELIVERABLE_DST/index.html"
