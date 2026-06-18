# Generate Doxygen HTML for checkpoint and deliverable editions.
# Run from anywhere; resolves repository root from this script's location.

$ErrorActionPreference = "Stop"

$Root = Split-Path -Parent $PSScriptRoot
Set-Location $Root

if (-not (Get-Command doxygen -ErrorAction SilentlyContinue)) {
    Write-Error "doxygen not found in PATH"
}

foreach ($Doxyfile in @("Doxyfile.checkpoint", "Doxyfile.deliverable")) {
    if (-not (Test-Path -LiteralPath $Doxyfile -PathType Leaf)) {
        Write-Error "missing $Doxyfile (expected at repository root)"
    }
}

New-Item -ItemType Directory -Force -Path `
    "build/doxygen/checkpoint", `
    "build/doxygen/deliverable" | Out-Null

Write-Host "==> Doxygen: checkpoint (Academic_Edition)"
doxygen Doxyfile.checkpoint
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Write-Host "==> Doxygen: deliverable (RadarLink_Extended/Montagem)"
doxygen Doxyfile.deliverable
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Write-Host "Done."
Write-Host "  Checkpoint:  build/doxygen/checkpoint/html/index.html"
Write-Host "  Deliverable: build/doxygen/deliverable/html/index.html"
