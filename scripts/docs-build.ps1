# Full documentation pipeline: Doxygen (checkpoint + deliverable), MkDocs, API merge.
# Run from anywhere; resolves repository root from this script's location.

$ErrorActionPreference = "Stop"

$Root = Split-Path -Parent $PSScriptRoot
$ScriptDir = $PSScriptRoot
Set-Location $Root

function Require-DoxygenHtml {
    param(
        [string]$Label,
        [string]$IndexPath
    )

    if (-not (Test-Path -LiteralPath $IndexPath -PathType Leaf)) {
        Write-Error "missing Doxygen output $IndexPath ($Label)"
    }
}

if (-not (Get-Command doxygen -ErrorAction SilentlyContinue)) {
    Write-Error "doxygen not found in PATH"
}

if (-not (Get-Command mkdocs -ErrorAction SilentlyContinue)) {
    Write-Error "mkdocs not found in PATH"
}

foreach ($Doxyfile in @("Doxyfile.checkpoint", "Doxyfile.deliverable")) {
    if (-not (Test-Path -LiteralPath $Doxyfile -PathType Leaf)) {
        Write-Error "missing $Doxyfile (expected at repository root)"
    }
}

New-Item -ItemType Directory -Force -Path `
    "build/doxygen/checkpoint", `
    "build/doxygen/deliverable" | Out-Null

Write-Host "==> Step 1/4: Doxygen checkpoint (Academic_Edition)"
doxygen Doxyfile.checkpoint
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
Require-DoxygenHtml -Label "checkpoint" -IndexPath "build/doxygen/checkpoint/html/index.html"

Write-Host "==> Step 2/4: Doxygen deliverable (RadarLink_Extended/Montagem)"
doxygen Doxyfile.deliverable
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
Require-DoxygenHtml -Label "deliverable" -IndexPath "build/doxygen/deliverable/html/index.html"

Write-Host "==> Step 3/4: MkDocs build"
mkdocs build
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Write-Host "==> Step 4/4: Merge API into site"
& (Join-Path $ScriptDir "merge-api-into-site.ps1")

Write-Host "Done."
Write-Host "  Site:        site/index.html"
Write-Host "  Checkpoint:  site/api/checkpoint/html/index.html"
Write-Host "  Deliverable: site/api/deliverable/html/index.html"
