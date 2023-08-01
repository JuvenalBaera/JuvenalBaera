fun main(){
    for(i in 1..10){
        print("$i ")
    }
    println()
    for(i in 1 until 11){
        print("$i ")
    }
    println()
    for(i in 10 downTo 1){
        print("$i ")
    }
    println()
    var times = 100
    for(i in 1..times){
        print("The number $i is ")
        if(i % 2 == 0)
            println("Even")
        else
            println("Odd")
    }
}