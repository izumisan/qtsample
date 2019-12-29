Param( $workingDir, $testTarget )

$scriptdir = $PSScriptRoot

$templatefile = $scriptdir + "/runcoverage.template"
$contents = Get-Content -Path $templatefile

$runenvfile = $scriptdir + "/runenv"
$runenv = Get-Content -Path $runenvfile

$contents = $contents.Replace( '${runenv}', $runenv )
$contents = $contents.Replace( '${configfile}', $scriptdir + "/runcoverage.config" )
$contents = $contents.Replace( '${workingdir}', $workingDir )
$contents = $contents.Replace( '${testtarget}', $testTarget )

$contents > runcoverage.ps1
