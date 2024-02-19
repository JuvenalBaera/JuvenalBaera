Function Get-CostReport{
    [CmdletBinding()]
    Param(
        [Parameter(Mandatory=$true, HelpMessage="The Name of the document wih cost extraction must be set")][string]$client,
        [Parameter(Mandatory=$true, HelpMessage="Insert the billing period for the search in format yyyyMM01")][string]$subscriptionName,
        [Parameter(Mandatory=$true, HelpMessage="Insert the subscription")][string]$subscriptionId,
        [Parameter(Mandatory=$true, HelpMessage="Insert the subscription")][string]$containerName,
        [Parameter(Mandatory=$true, HelpMessage="Insert the subscription")][string]$finopsSTASSubscriptionId
    )

    process {
        Set-AzContext -Subscription $finopsSTASSubscriptionId

        #Variables
        $atualDate = Get-Date
        Write-Host $atualDate

        # STEP 1 - Download blob report
        $Context = (Get-AzStorageAccount -ResourceGroupName nttdatafirst).Context
        $tempSub = "subscriptions/" + $subscriptionId
        $exported = Get-AzCostManagementExport -Scope $tempSub
        
        Write-Host $exported
    }
}


####################### START #######################
$subId = "10575410-795f-4bb6-acb1-3e7fdb34a62f"
$connection = Connect-AZAccount -Subscription $subId
#Write-Host $connection.Context
$context = $connection.Context
$subscription = $context.Subscription

$subName = $subscription.Name
$containerName = "containerteste"
$client = "Juvenal"
$finopSTASub = $subId

Get-CostReport -client $client -subscriptionName $subName -subscriptionId $subId -containerName $containerName -finopsSTASSubscriptionId $finopSTASub
