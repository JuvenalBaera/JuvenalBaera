fun main() {
    var colors = arrayOf("Red", "Blue", "Purple")

    showArray(colors)

    println()
    showArray(colors)

}

fun showArray(arr: Array<String>){
    for(a in arr)
        println(a)
}