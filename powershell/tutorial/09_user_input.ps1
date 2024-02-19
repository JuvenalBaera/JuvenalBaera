$name = Read-Host -Prompt "What's your name"
$age = Read-Host -Prompt "How old are you"
$age = [int]::Parse($age)

Write-Host $name
Write-Host ($age + 1)