fun main(){
    //sayHello("Juvenal", 21)
    var max = getMax(5, 7)
    showData(max)
    max = getMax(9, 6, 7)
    showData(max)
    max = sum(n2=5, n1=6)
    showData(max)
}

fun sayHello(name: String, age: Int){
    println("Hello, $name")
    println("You're $age years old")
}

fun showData(data: Int){
    println("Your data: $data")
}

fun getMax(num1: Int, num2: Int): Int {
    return if (num1 > num2) num1 else num2
}

fun getMax(n1: Int, n2: Int, n3: Int) : Int{
    var max: Int
    if(n1 > n2 && n1 > n3)
        max = n1
    else if(n2 > n1 && n2 > n3)
        max = n2
    else
        max = n3
    return max
}

fun sum(n1: Int, n2: Int = 0): Int{
    return  n1 + n2
}