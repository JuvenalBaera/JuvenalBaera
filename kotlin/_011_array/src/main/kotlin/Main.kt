fun main() {
    var cars : Array<String> = arrayOf("BMW", "Ford Mustang", "Toyota Corrola", "Mark X")
    var numbers : Array<Int> = arrayOf(0, 1, 2, 3, 4, 5, 6, 7, 8, 9)

    for(car in cars){
        println("I have in my garage $car")
    }

    for(i in 0 until numbers.size){
        println("My Number: ${numbers[i]}")
    }
}
