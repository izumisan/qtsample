Param( $workingDir, $testTarget )

$scriptdir = $PSScriptRoot

$contents = Get-Content -Path ($scriptdir + "/runcoverage.template")

$runenv = Get-Content -Path ($scriptdir + "/runcoverage.runenv")

$contents = $contents.Replace( '${runenv}', $runenv )
$contents = $contents.Replace( '${configfile}', $scriptdir + "/runcoverage.config" )
$contents = $contents.Replace( '${workingdir}', $workingDir )
$contents = $contents.Replace( '${testtarget}', $testTarget )

$contents > runcoverage.ps1
