$sports = @("Football", "Voleiball", "Basktball", "Baseball")

#Write-Host $sports
#Write-Host $sports.Count
#Write-Host $sports.Length
#Write-Host $sports.Contains("Voleiball")

Write-Host $sports.GetType()
Write-Host "Get by index (first): " $sports[0]
Write-Host "Get by index (last ): " $sports[3]
Write-Host

Foreach($sport in $sports){
    Write-Host $sport
}