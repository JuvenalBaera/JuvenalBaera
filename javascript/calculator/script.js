let buttons = [...document.getElementsByClassName("buts")]
let display = document.getElementById("display")
let operations = [...document.getElementsByClassName("operation")]

let boolVal = false
let operation = ""
let num1=0
let num2=0


buttons.map(btn => {
    btn.addEventListener("click", () => {
        operations.map(oper => {
            if(oper.innerText == btn.innerText ){
                if(oper.innerText != "=")
                    operation = oper.innerText
                boolVal = true
            }
        })

        if(!boolVal){
            if(display.innerText == "0")
                display.innerHTML = `${btn.innerHTML}`
            else
                display.innerHTML += `${btn.innerHTML}`
        }
        else{
            if(btn.innerText == "c")
                display.innerText = "0"
            else if(btn.innerText != "="){
                num1 = Number(display.innerText)
                display.innerText = ""
            }
            else{
                num2 = Number(display.innerText)
                let result = 0
                if(operation == "+"){
                    result = `${num1 + num2}`;
                }
                else if(operation == "-"){
                    result = `${num1 - num2}`;
                }
                else if(operation == "x"){
                    result = `${num1 * num2}`;
                }
                else if(operation == "%"){
                    result = `${num1 % num2}`;
                }
                display.innerHTML = `${num1} ${operation} ${num2} = ${result}`
            }
        }
        boolVal = false
    })
})