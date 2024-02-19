Function factorial{
    Param($n)
    $fact = 1

    For($i = 1; $i -le $n; $i++){
        $fact *= $i
    }
    return $fact
}

$num = Read-Host -Prompt "Digite um número: "
$fact = factorial -n $num
$res = "Factorial: {0} = {1}" -f $num, $fact

Write-Host $res