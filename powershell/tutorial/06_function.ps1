Function GreatingWorld{
    Write-Host "Hello World"
}

Function GreatingPerson{
    Param([string]$name)
    Write-Host "Hello $name"
}

Function Birthday{
    Param([string] $name, [int]$age)
    Write-Host "Happy birthday to you"
    Write-Host "Happy birthday $name"
    Write-Host "You're now $age YO"
}

Function Factorial{
    [cmdletbinding()]
    Param([Parameter(Mandatory=$true, HelpMessage="Number to calc factorial")][int]$num)
    $fact = 1
    For($i = 1; $i -le $num; $i++){
        $fact *= $i
    }
    return $fact
}

#GreatingWorld
GreatingPerson
#Birthday -name "Baera" -age 23

$number = Factorial
Write-Host $number