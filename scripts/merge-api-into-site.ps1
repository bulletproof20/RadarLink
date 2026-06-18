# Copy generated Doxygen HTML into the MkDocs site tree.
# Expects build/doxygen/*/html and an existing site/ from mkdocs build.

$ErrorActionPreference = "Stop"

$Root = Split-Path -Parent $PSScriptRoot
Set-Location $Root

$CheckpointSrc = "build/doxygen/checkpoint/html"
$DeliverableSrc = "build/doxygen/deliverable/html"
$CheckpointDst = "site/api/checkpoint/html"
$DeliverableDst = "site/api/deliverable/html"

function Require-DoxygenHtml {
    param(
        [string]$Label,
        [string]$Src
    )

    if (-not (Test-Path -LiteralPath $Src -PathType Container)) {
        Write-Error "missing Doxygen output directory $Src ($Label) — run Doxygen first"
    }
    $Index = Join-Path $Src "index.html"
    if (-not (Test-Path -LiteralPath $Index -PathType Leaf)) {
        Write-Error "missing $Index ($Label)"
    }
}

if (-not (Test-Path -LiteralPath "site" -PathType Container)) {
    Write-Error "missing site/ — run mkdocs build first"
}

Require-DoxygenHtml -Label "checkpoint" -Src $CheckpointSrc
Require-DoxygenHtml -Label "deliverable" -Src $DeliverableSrc

Remove-Item -Recurse -Force -ErrorAction SilentlyContinue $CheckpointDst, $DeliverableDst
New-Item -ItemType Directory -Force -Path $CheckpointDst, $DeliverableDst | Out-Null

Copy-Item -Path (Join-Path $CheckpointSrc "*") -Destination $CheckpointDst -Recurse -Force
Copy-Item -Path (Join-Path $DeliverableSrc "*") -Destination $DeliverableDst -Recurse -Force

foreach ($Pair in @(
        @{ Label = "checkpoint"; Dst = $CheckpointDst },
        @{ Label = "deliverable"; Dst = $DeliverableDst }
    )) {
    $Index = Join-Path $Pair.Dst "index.html"
    if (-not (Test-Path -LiteralPath $Index -PathType Leaf)) {
        Write-Error "copy failed — missing $Index ($($Pair.Label))"
    }
}

Write-Host "Merged API documentation into site/"
Write-Host "  Checkpoint:  $CheckpointDst/index.html"
Write-Host "  Deliverable: $DeliverableDst/index.html"
