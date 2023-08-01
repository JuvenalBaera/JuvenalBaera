fun main(){
    var day = 4

    var weekDay = when(day){
        1 -> "Sunday"
        2 -> "Monday"
        3 -> "Tuesday"
        4 -> "Wednesday"
        5 -> "Thursday"
        6 -> "Friday"
        7 -> "Saturday"
        else -> "Invalid day"
    }
    println("$day correspond $weekDay")
}