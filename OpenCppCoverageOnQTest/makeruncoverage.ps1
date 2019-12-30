Param( $workingDir, $testTarget )

$scriptdir = $PSScriptRoot

$contents = @'
$env:PATH = "${runenv}" + ";" + $env:PATH
OpenCppCoverage.exe --config_file=${configfile} --working_dir=${workingdir} -- ${testtarget}
'@

$runenv = Get-Content -Path ($scriptdir + "/runcoverage.runenv")

$contents = $contents.Replace( '${runenv}', $runenv )
$contents = $contents.Replace( '${configfile}', $scriptdir + "/runcoverage.config" )
$contents = $contents.Replace( '${workingdir}', $workingDir )
$contents = $contents.Replace( '${testtarget}', $testTarget )

$contents > runcoverage.ps1
