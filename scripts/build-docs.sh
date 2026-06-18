#!/usr/bin/env bash
# Generate Doxygen HTML for checkpoint and deliverable editions.
# Run from anywhere; resolves repository root from this script's location.

set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"

if ! command -v doxygen >/dev/null 2>&1; then
  echo "error: doxygen not found in PATH" >&2
  exit 1
fi

for doxyfile in Doxyfile.checkpoint Doxyfile.deliverable; do
  if [[ ! -f "$doxyfile" ]]; then
    echo "error: missing $doxyfile (expected at repository root)" >&2
    exit 1
  fi
done

mkdir -p build/doxygen/checkpoint build/doxygen/deliverable

echo "==> Doxygen: checkpoint (Academic_Edition)"
doxygen Doxyfile.checkpoint

echo "==> Doxygen: deliverable (RadarLink_Extended/Montagem)"
doxygen Doxyfile.deliverable

echo "Done."
echo "  Checkpoint:  build/doxygen/checkpoint/html/index.html"
echo "  Deliverable: build/doxygen/deliverable/html/index.html"
