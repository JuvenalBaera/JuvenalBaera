Function Get-AZCostReport{
    [cmdletbinding()]
    Param(
        [Parameter(Mandatory=$true, HelpMessage="The Name of the document wih cost extraction must be set")][string]$client, # String
        [Parameter(Mandatory=$true, HelpMessage="Insert the billing period for the search in format yyyyMM01")][string]$subscriptionName, # yyyyMM01
        [Parameter(Mandatory=$true, HelpMessage="Insert the subscription")][string]$subscriptionId,
        [Parameter(Mandatory=$true, HelpMessage="Insert the subscription")][string]$containerName,
        [Parameter(Mandatory=$true, HelpMessage="Insert the subscription")][string]$finopsSTASSubscriptionId
    )

    process {
        # Global Var
        Set-AzContext -Subscription $finopsSTASSubscriptionId

        
        #Variables
        $folderLocation = "C:\Users\jbaer\Documents\develop\powershell\azure\"
        $xlsxFilename  = $folderLocation + "report.xlsx"
        $sheetName = "weeklyReport"

        # CREATE FOLDER 
        try{
            mkdir -Name $client
        }ca

        # Vars for report
        #[System.Collections.ArrayList]$list = [System.Collections.ArrayList]::new()#

        

        # STEP 1 - Download blob report
        $Context = (Get-AzStorageAccount -ResourceGroupName nttdatafirst).Context
        
        $blobs = Get-AzStorageBlob -Container $containerName -Context $Context | Sort-Object -Property LastModified -Descending



        if($blobs.GetType().BaseType.Name -eq "Array"){
            $blobName = $blobs.Item(0).Name
        }
        elseif($blobs.GetType().BaseType.Name -eq "AzureStorageBase"){
            $blobName = $blobs.Name
        }
        #$blobName = $blobName.Replace(".", "")
        $auxBlobName = $blobName.Split("/")

        ################# TO DO ##############
        # CREATE CLIENT'S FOLDER
        
        $destinationDownloadFile = $folderLocation + $client + "/" + $auxBlobName
        

        $DBLobHT = @{
            blob        = $blobName
            container   = $containerName
            destination = $destinationDownloadFile
            context     = $Context
        }

        Get-AzStorageBlobContent @DBLobHT

        $CSVFile = $destinationDownloadFile
        
        
        # STEP 2 -


        # STEP 3 -
    }
}


$subId = "10575410-795f-4bb6-acb1-3e7fdb34a62f"

$connection = Connect-AZAccount -Subscription $subId
$context = $connection.Context
$subscription = $context.Subscription

$subName = $subscription.Name
$containerName = "containerteste"
$client = "Juvenal"
$finopSTASub = $subId



Get-AZCostReport -client $client -subscriptionName $subName -subscriptionId $subId -containerName $containerName -finopsSTASSubscriptionId $finopSTASub

#Write-Host $subName
#Write-Host $containerName
#Write-Host $client
#Write-Host $subCostRow
#Write-Host $finopSTASub 
