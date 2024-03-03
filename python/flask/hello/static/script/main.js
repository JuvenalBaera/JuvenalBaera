let btnLogin = document.getElementById("btn_login")
let btnRegisto = document.getElementById("btn_registo")

if(btnLogin != null){
    btnLogin.addEventListener("click", (evt) => {
        console.log(evt)
        location.href = "/login"
    })
}

if(btnRegisto != null){
    btnRegisto.addEventListener("click", (evt) =>{
        console.log(evt)
        location.href = "/registo"
    })
}
