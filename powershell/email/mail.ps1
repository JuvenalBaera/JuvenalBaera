#Setup Credentials
$credentials = Get-Credential
$UserName = $credentials.UserName
$Password = $credentials.Password
$SecurePassword = ConvertTo-SecureString -string $password -AsPlainText -Force
$Cred = New-Object System.Management.Automation.PSCredential -argumentlist $UserName, $SecurePassword
 
#Set Parameters for the Email
$EmailParams = @{
    From = $UserName
    To = "j.baera@campus.fct.unl.pt"
    Subject = "Permission Report"
    Body = "Please find the attached Reports"
    SmtpServer = "smtp.gmail.com"
    Port = 587
    UseSsl = $true
    Credential = $Cred
   # Attachments = "C:\Reports\PermissionReport.csv", "C:\Reports\UsersReport.csv"
}
 
#Call the Send-MailMessage to Send Email
Send-MailMessage @EmailParams

# Juven@l15b
#Read more: https://www.sharepointdiary.com/2020/08/send-email-powershell.html#ixzz8QO7H10Pq