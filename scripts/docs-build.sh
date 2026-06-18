#!/usr/bin/env bash
# Full documentation pipeline: Doxygen (checkpoint + deliverable), MkDocs, API merge.
# Run from anywhere; resolves repository root from this script's location.

set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

require_doxygen_html() {
  local label="$1"
  local index="$2"

  if [[ ! -f "$index" ]]; then
    echo "error: missing Doxygen output $index ($label)" >&2
    exit 1
  fi
}

if ! command -v doxygen >/dev/null 2>&1; then
  echo "error: doxygen not found in PATH" >&2
  exit 1
fi

if ! command -v mkdocs >/dev/null 2>&1; then
  echo "error: mkdocs not found in PATH" >&2
  exit 1
fi

for doxyfile in Doxyfile.checkpoint Doxyfile.deliverable; do
  if [[ ! -f "$doxyfile" ]]; then
    echo "error: missing $doxyfile (expected at repository root)" >&2
    exit 1
  fi
done

mkdir -p build/doxygen/checkpoint build/doxygen/deliverable

echo "==> Step 1/4: Doxygen checkpoint (Academic_Edition)"
doxygen Doxyfile.checkpoint
require_doxygen_html "checkpoint" "build/doxygen/checkpoint/html/index.html"

echo "==> Step 2/4: Doxygen deliverable (RadarLink_Extended/Montagem)"
doxygen Doxyfile.deliverable
require_doxygen_html "deliverable" "build/doxygen/deliverable/html/index.html"

echo "==> Step 3/4: MkDocs build"
mkdocs build

echo "==> Step 4/4: Merge API into site"
bash "$SCRIPT_DIR/merge-api-into-site.sh"

echo "Done."
echo "  Site:        site/index.html"
echo "  Checkpoint:  site/api/checkpoint/html/index.html"
echo "  Deliverable: site/api/deliverable/html/index.html"
