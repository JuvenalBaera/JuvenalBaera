Import-Module ImportExcel

Function createXLSXfile{
    Param($fileXSLX)
    $excel = Export-Excel $fileXSLX -PassThru -WorksheetName "Data" -AutoSize
    $wsChart = Add-Worksheet -ExcelPackage $excel -WorksheetName "Chart"
    $wsData = $excel.Workbook.Worksheets.Item("Data")

    $title = $wsData.Cells.Item("A1:E1")
    $title.Value = "Report of Cost last month"

    $title.Style.HorizontalAlignment = "Center"
    $title.Style.Font.Bold = $true
    $title.Style.Font.Size = 20
    
    $title.merge = $true

    $excel.Save()
    
}


Function addData{
    Param($filexlsx, $row, $column, $data, $titles)
    
    $excel = New-Object -ComObject Excel.Application

    $wb = $excel.Workbooks.Open($filexlsx)

    $ws = $wb.Sheets.Item("Data")

    $ws.Cells.Item($row, $column) = $titles[0]
    $ws.Cells.Item($row, $column + 1) = $titles[1]

    $ws.Cells.Item($row, $column).Font.Bold = $true
    $ws.Cells.Item($row, $column + 1).Font.Bold = $true

    
    $row++
    foreach($k in $data.Keys){
        $ws.Cells.Item($row, $column) = $k
        $ws.Cells.Item($row, $column + 1) = $data.$k
        $row++
    }

    $wb.Save()
    $excel.Quit()
    Start-Sleep 2
}


Function putBorderSide{
    Param($element, $side, $size)
    $border = $element.Borders.Item($side) # Top
    $border.LineStyle = 1 # Solid
    $border.Weight = $size # Weight
}


Function putAllBorder{
    Param($element, $size)
    putBorderSide -element $element -side 1 -size $size
    putBorderSide -element $element -side 2 -size $size
    putBorderSide -element $element -side 3 -size $size
    putBorderSide -element $element -side 4 -size $size
}


Function paintInfo{
    Param($ele)
    $ele.Interior.Color = ([System.Drawing.Color]::Green).ToArgb()
    $ele.Font.Color = 16777215 #([System.Drawing.Color]::White).ToArgb()
}


Function mergeCenter{
    Param($ran, $size)
    $ran.Merge()
    $ran.HorizontalAlignment = -4108
    $ran.Font.Bold = $true
    $ran.Font.Size = $size
}


Function resume{
     Param($filexlsx, $startRow, $col, $data)
    $excel = New-Object -ComObject Excel.Application
    $wb = $excel.Workbooks.Open($filexlsx)
    $excel.DisplayAlerts = $false

    $sizeBorder = 3

    # sheets (data & chart)
    $ws = $wb.Sheets.Item("Chart")

    $title = $ws.Range(("I{0}:J{0}" -f $startRow))
    $title.Value = "Resume"

    paintInfo -ele $title
    mergeCenter -ran $title -size 14
    putAllBorder -element $title -size $sizeBorder

    $row    = $startRow + 1
    $column = $col
    foreach($k in $data.Keys){
        if($k -ne "percentage"){
            $ws.Cells.Item($row, $column) = $k
            $ws.Cells.Item($row, $column + 1) = $data.$k
            putAllBorder -element ($ws.Cells.Item($row, $column)) -size $sizeBorder
            putAllBorder -element ($ws.Cells.Item($row, $column+1)) -size $sizeBorder
            $row++
        }
    }

    $per = $ws.Range(("I{0}:J{0}" -f $row))
    $per.Value = ("Paid: " + $data["percentage"])

    paintInfo -ele $per
    mergeCenter -ran $per -size 12
    putAllBorder -element $per -size $sizeBorder

    # save and exit
    $wb.Save()
    $excel.Quit()
    Start-Sleep 2
}


Function drawChart{
    Param($filexlsx, $startRow, $row1, $row2)
    
    $excel = New-Object -ComObject Excel.Application
    $wb = $excel.Workbooks.Open($filexlsx)

    # sheets (data & chart)
    $wsdata = $wb.Sheets.Item("Data")
    $wschart = $wb.Sheets.Item("Chart")

    # Chart data
    $chart1Range = $wsData.Range(("A{0}" -f $startRow), ("B{0}" -f $row1))
    $chart2Range = $wsData.Range(("D{0}" -f $startRow), ("E{0}" -f $row2))


    $chart = $wschart.Shapes.AddChart().Chart
    $wschart.Activate()

    $chart.ChartType = 5 
    $charName = "Chart 1"
    

    #### MOVE CHART ####
    $wschart.Shapes.Item($charName).Top = 5
    $wschart.Shapes.Item($charName).Left = 5


    $chart.SetSourceData($chart1Range)
    $chart.HasTitle = $True
    Start-Sleep -seconds 2

    $chart.ApplyLayout(6,69)
    $chart.ChartTitle.Text = "Service By cost"
    $chart.ChartStyle = 26
    $chart.PlotVisibleOnly = $False

    $chart.SeriesCollection(1).DataLabels().ShowValue = $True
    $chart.SeriesCollection(1).DataLabels().Separator = ("{0}" -f [char]10)
    $chart.ChartArea.Height = 270


    # Chart 2
    $charName = "Chart 2"
    $chart = $wschart.Shapes.AddChart().Chart
    $wschart.Activate()

    $chart.ChartType = 52
    $chart.HasTitle = $True
    $chart.ChartTitle.Text = "Date by cost"
    $chart.ChartStyle = 4 #26
    $chart.PlotVisibleOnly = $False


    #### MOVE CHART ####
    $wschart.Shapes.Item($charName).Top = 5
    $wschart.Shapes.Item($charName).Left = 500

    $chart.SetSourceData($chart2Range) 
    Start-Sleep -seconds 2

    $chart.ApplyLayout(6,69)
    $chart.HasLegend = $False

    $chart.HasAxis(1, 1) = $true;
    $chart.HasAxis(2, 1) = $true;
    $chart.Axes(1, 1).HasTitle = $true
    $chart.Axes(2, 1).HasTitle = $true

    $chart.Axes(1, 1).AxisTitle.Text = "Date";
    $chart.Axes(2, 1).AxisTitle.Text = "Cost (€)";

    foreach($series in $chart.SeriesCollection()){
        $series.Format.Fill.ForeColor.RGB = ([System.Drawing.Color]::Green).ToArgb()
    }


    $excel.ActiveWindow.DisplayGridlines = $false
    $chart.ChartArea.Height = 270

    # save and exit
    $wb.Save()
    $excel.Quit()
    Start-Sleep 2
}



Function sentEmailReport{
    Param(
        [string]$to,
        [string]$msgBody,
        [string]$filePath
    )

    $userName = "jtembeba@emeal.nttdata.com"
    $password = "Juven@l15b" #$credentials.Password
    $securePassword = ConvertTo-SecureString -String $password -AsPlainText -Force
    $cred = New-Object System.Management.Automation.PSCredential -ArgumentList $userName, $securePassword


    $sendEmailMessageSplat = @{
        From = $userName;
        To = $to;
        Subject = "Cost Report last week" + (Get-Date);
        Body = $msgBody;
        SmtpServer = "smtp.office365.com";
        Attachments = $filePath
        Port = 587;
        UseSsl = $true
        Credential = $cred
    }

    Send-MailMessage @sendEmailMessageSplat
}



Function Get-AZCostReport {
    [cmdletbinding()]
    Param (
        [Parameter(Mandatory=$true,HelpMessage="The Name of the document with cost extraction must be set")][string]$client, #string
        [Parameter(Mandatory=$true,HelpMessage="Insert the billing period for the search in the format yyyyMM01")][string]$subscriptionName, #yyyyMM01
        [Parameter(Mandatory=$true,HelpMessage="Insert the subscription")][string]$subscriptionId,
        [Parameter(Mandatory=$true,HelpMessage="Insert the subscription")][string]$containerName,
        [Parameter(Mandatory=$true,HelpMessage="Insert the subscription")][string]$finopsSTASubscriptionId
    )
    # End of Parameters
    Process {
        #### Global Variables ####
        Set-AzContext -SubscriptionId $finopsSTASubscriptionId

        #### Variables for Cloud Cost Engine ####
        $folderLocation = $PSScriptRoot + "\"
        $clientFolder   = $folderLocation + $client
        
        ##### Variables for DATE #########
        $today     = (Get-Date).Date
        $lastWeek  = $today.AddDays(-7)
        $yesterday = $today.AddDays(-1)

        #### Vars for math operations ####
        $totalLastWeek  = 0
        $totalYesterday = 0
        $avgLastWeek    = 0
        $TOTAL_DAYS     = 7



        ############ NEW VARS ############
        $serviceAmount = @{}
        $dayCost       = @{}


        #### Create client's folder ####
        try{
            if((Test-Path -Path ($folderLocation + $client)) -eq $true){
                Remove-Item  -path ($folderLocation + $client) -Recurse
            }
            New-Item -Path $folderLocation -Name $client -ItemType Directory
        }
        catch{ Write-Host " "}
        

        # Step 1 - Download blob report
        $Context = (Get-AzStorageAccount -ResourceGroupName dev-rg-ne-01).Context
        $Blobs = Get-AzStorageBlob -Container $containerName -Context $Context | Sort-Object -Property LastModified -Descending


        if(($Blobs.GetType()).BaseType.Name -eq "Array"){
            $blobName = $Blobs.Item(0).Name
        }
        elseif(($Blobs.GetType()).BaseType.Name -eq "AzureStorageBase"){
            $blobName = $Blobs.Name
        }
        $auxBlobName = $blobName.Split("/")

        $destinationDownloadFile = $folderLocation + $client + "/"

        $DLBlob1HT = @{
            Blob        = $blobName
            Container   = $containerName
            Destination = $destinationDownloadFile
            Context     = $Context
        }

        $recentBlobCreated = Get-AzStorageBlobContent @DLBlob1HT


        $CSVFile = $destinationDownloadFile + $recentBlobCreated.Name

        $costDataCSV = Import-CSV $CSVFile | Select-Object @("costInBillingCurrency", "consumedService", "date", "ServiceFamily")


        foreach($data in $costDataCSV){
            $service = $data.ServiceFamily
            $atualBill = $data.costInBillingCurrency
            $atualBill = [math]::Round(([Double]$atualBill), 6)
            
            if(!$serviceAmount.ContainsKey($service)){
                $serviceAmount.$service = $atualBill
            }
            else{
                $a = $serviceAmount.$service + $atualBill
                $serviceAmount.$service = $a
            }


            $csvLoadDate = [Datetime]::ParseExact($data.date, "MM/dd/yyyy", $null)
            $keyDate = $csvLoadDate.ToString().Split(" ")[0]


            #If csvLoadDate is in last 7 days
            if($csvLoadDate.CompareTo($lastWeek) -ge 0 -and $csvLoadDate.CompareTo($today) -le 0){
                $totalLastWeek += $atualBill

                if(!$dayCost.ContainsKey($keyDate)){
                    $dayCost.$keyDate = $atualBill
                }
                else{
                    $dayCost.$keyDate += $atualBill
                }
            }
            if($csvLoadDate.CompareTo($yesterday) -eq 0){
                $totalYesterday += $atualBill
            }
        }


        $avgLastWeek = $totalLastWeek / $TOTAL_DAYS
        $percentage = [Math]::Round(($totalYesterday / $avgLastWeek) * 100, 0)
 
        $strPercentage = "Paid "
        if($totalYesterday - $avgLastWeek -le 0){
            $strPercentage += "$percentage% less"
        }
        else{
            $strPercentage += "$percentage% more"
        }
        
        $resume = @{
            "last 7 days" = $totalLastWeek
            "average"     = $avgLastWeek
            "yesterday"   = $totalYesterday
            "percentage"  = $strPercentage
        }
        
        # Filename xlsx in current folder
        $xlSourcefile = $folderLocation + "report.xlsx"

        if([System.IO.File]::Exists($xlSourcefile) -eq $true){
            Remove-Item -path $xlSourcefile 
        }

        createXLSXfile -fileXSLX $xlSourcefile

        $startRow = 2
        addData -filexlsx $xlSourcefile -row $startRow -column 1 -data $serviceAmount -titles @("Service", "Cost")
        addData -filexlsx $xlSourcefile -row $startRow -column 4 -data $dayCost -titles @("Date", "Cost")


        drawChart -filexlsx $xlSourcefile -startRow ($startRow+1) -row1 ($serviceAmount.Count+2) -row2 ($dayCost.Count+2)
        resume -filexlsx $xlSourcefile -startRow 8 -col 9 -data $resume

        ################## SEND EMAIL TO [] WITH ATTACHMENT #####################
        sentEmailReport -to "juvenalbaera15@gmail.com" -filePath $xlSourcefile -msgBody "Report Last Month"
    }
}



$subscriptionId   = "10575410-795f-4bb6-acb1-3e7fdb34a62f"
$connection       = Connect-AzAccount -Subscription $subscriptionId
$context          = $connection.Context
$subscription     = $context.Subscription
$subscriptionName = $subscription.Name
$containerName    = "dev-cnt-ne-01"
$client           = "juvenalbaera"
$finopSTASub      = $subscriptionId

Get-AZCostReport -client $client -subscriptionName $subscriptionName -subscriptionId $subscriptionId -containerName $containerName -finopsSTASubscriptionId $finopSTASub
