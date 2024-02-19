Function createDummyFolder{
    Param([string]$folderLocation, [string]$folderName)
    $fullNameFolder = $folderLocation + $folderName
    try{
        if((Test-Path -Path $fullNameFolder) -eq $False){
            New-Item -Path $folderLocation -Name $folderName -ItemType Directory
        }
    }
    catch{}
}


Function dateForName{
    Param([datetime]$date)
    return $date.ToString().Replace("/","").Replace(":", "").Replace(" ", "")
}


# Some variables
$currentDate = Get-Date
$shouldStop = $false
$folderLocation = $PSScriptRoot + "\" # Get the current directory (script dir)
$folderForFiles = "dummyFolder" + (dateForName -date ($currentDate).Date)
$fileName = "dummyFile"
$fileExtension = ".txt"
$size = 0.1MB   # [CHANGE ME]


# Create folder for current date
createDummyFolder -folderLocation $folderLocation -folderName $folderForFiles

#Location for storing files
$fullFilesLocation = $folderLocation + $folderForFiles + "\"


#Setting content
$content = New-Object byte[] $size
(New-Object System.Random).NextBytes($content)

$stopDateTime = (Get-Date).AddMinutes(5)


do{
    $currentDateTime = Get-Date
    if($currentDateTime.CompareTo($stopDateTime) -gt 0){
        $shouldStop = $true
    }

    $fullFileName = $fileName + (dateForName -date $currentDateTime) + $fileExtension
    $path = Join-Path $fullFilesLocation $fullFileName
    [System.IO.File]::WriteAllBytes($path, $content)
    
    Write-Host "Created file:" $path

    Start-Sleep -Seconds 10 # [CHANGE ME]

}while(!$shouldStop)


#Get-ChildItem -Path $folderLocation -Include *.* -File -Recurse | foreach {$_.Delete()}