fun main() {
    var i = 1
    /*while(i < 10){
        println("while $i")
        i++
    }
    println()
    i = 0
    do{
        println("do-while $i")
        i++
    }while(i < 10)
    */

    while(true){
        if(i % 10 == 0)
                println("$i Divisivel por 10")
        if(i % 100 == 0)
            break
        i++
    }
}