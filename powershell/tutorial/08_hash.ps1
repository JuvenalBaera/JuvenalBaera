$Person = @{
    name = "Juvenal";
    age = 23;
    height = 1.7
}

#Write-Host $Person.GetType()
#Write-Host $Person.Add("hobbies", @("Coding", "Play Football"))

#Write-Host $Person["name"]
#Write-Host $Person."age"
#Write-Host $Person["hobbies"]

foreach($p in $Person.Keys){
    Write-Host $p " = " $Person.$p
}
