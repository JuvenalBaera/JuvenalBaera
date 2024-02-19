$age = [int]70

If ($age -lt 16){
    Write-Host "You can't vote"
}
Elseif ($age -lt 18 -or $age -gt 60){
    Write-Host "Optional Vote"
}
Else{
    Write-Host "You can vote"
}