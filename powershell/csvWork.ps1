$CSVFilename = "C:\Users\jbaer\Documents\develop\powershell\costData.csv"

$costDataCSV = Import-CSV $CSVFilename | Select-Object @("costInBillingCurrency", "consumedService", "servicePeriodStartDate", "servicePeriodEndDate", "date")

$totalPaidLastWeek = 0
$totalPaidYesterday = 0
$TOTAL_DAYS = 7

############ DATE ##########
$atualdate = (Get-Date).Date
$last7Days = $atualdate.AddDays(-7)
$yesterday = $atualdate.AddDays(-1)


ForEach($data in $costDataCSV){
    $tempDateCSV = [Datetime]::ParseExact($data.date, "MM/dd/yyyy", $null)

    #If is in last 7 days
    if($tempDateCSV.CompareTo($last7Days) -ge 0 -and $tempDateCSV.CompareTo($atualdate)){
        $totalPaidLastWeek += $data.costInBillingCurrency
    }
    if($tempDateCSV.CompareTo($yesterday) -eq 0){
        $totalPaidYesterday += $data.costInBillingCurrency
    }
}

$avgPaidLastWeek = $totalPaidLastWeek / $TOTAL_DAYS
$percentage = [Math]::Round(($totalPaidYesterday / $avgPaidLastWeek) * 100, 2)

Write-Host "Billing Yesterday was " -NoNewline
if($totalPaidYesterday - $avgPaidLastWeek -le 0){
    Write-Host "$percentage% more than last week"
}
else{
    Write-Host "$percentage% more than last week"
}


Write-Host "Total paid Last $TOTAL_DAYS days.....:" $avgPaidLastWeek
Write-Host "Total Paid Yesterday.......:" $totalPaidYesterday

