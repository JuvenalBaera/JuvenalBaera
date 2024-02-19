Write-Host "LOOP USING FOR"
For($i = 0; $i -lt 10; $i++){
    Write-Host "Hello for: " $i
}


Write-Host 
Write-Host "LOOP USING WHILE"
$counter = 9

While($counter -gt 0){
    Write-Host "Hello while: " $counter
    $counter--
}

Write-Host 
Write-Host "LOOP USING DO WHILE"

$counter = 0

Do{
    Write-Host "Hello do while: " $counter
    $counter += 2
}While($counter -le 20);