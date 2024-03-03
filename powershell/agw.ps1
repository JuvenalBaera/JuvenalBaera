$agw = Get-AzApplicationGateway -Name "dev-agw-ne-01"
Stop-AzApplicationGateway -ApplicationGateway $agw
#Start-AzApplicationGateway -ApplicationGateway $agw