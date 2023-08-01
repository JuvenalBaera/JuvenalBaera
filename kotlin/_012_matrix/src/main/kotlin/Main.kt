import java.util.HashMap
import kotlin.random.Random
import java.util.Scanner

var scanner = Scanner(System.`in`)

const val ROW = 3
const val COLUMN = 3

fun main() {
    val matrices = HashMap<Char, Array<Array<Float>>>()
    var matrix = Array(ROW) {Array(COLUMN) {0f} }

    var option: Int
    var insertOpt : Int
    var key = '0'

    var min = 0f
    var max = 0f

    do {
        option = mainMenu( "Exit", "Continue", "Insert Matrix")
        when (option) {
            0 -> break
            1 -> {
                if(matrices.isEmpty()) {
                    println("\nCannot continue. Insert at least 1 matrix")
                    continue
                }
                continueOption(matrices)
            }
            2 -> {
                do {
                    insertOpt = menuInsert("Back", "Input", "Random", "Identity Matrix")
                    when(insertOpt){
                        0 -> break
                        1 -> matrix = assignMatrix(true, min, max)
                        2 -> {
                            print("\nEnter min number: ")
                            min = scanner.nextFloat()
                            print("Enter max number: ")
                            max = scanner.nextFloat()

                            if(min > max){
                                val tmp = min
                                min = max
                                max = tmp
                            }
                            matrix = assignMatrix(false, min, max)
                        }
                        3 -> matrix = identityMatrix()
                        else -> println("Invalid option\n")
                    }
                }while(insertOpt !in 0..3)

                if(insertOpt in 1..3) {
                    matrices[key] = matrix
                    if(key == '9')
                        key = 'A' - 1
                    else if(key == 'Z')
                        key = 'a' - 1
                    key++
                }
            }
            else -> println("\nInvalid Option\n")
        }
    }while(true)

    println("\nThank you for visiting")
    scanner.close()
}

// ##################### CONTINUE ########################
fun continueOption(matrices : HashMap<Char, Array<Array<Float>>>){
    var matrix : Array<Array<Float>>
    var matrix2: Array<Array<Float>>

    var matChose : Char
    var matChose2 : Char
    var option : Int
    var number : Int

    do {
        option = insideMenu("Back", "Show matrix", "Show Matrices", "Multiply By", "Sum By")
        when(option){
            0 -> break
            1 -> {
                matChose = readKey(matrices, "Choose a matrix ")
                showMatrix(matrices[matChose]!!)
            }
            2 -> {
                for(mat in matrices.keys){
                    println("\nMatrix [$mat]")
                    matrices[mat]?.let { showMatrix(it) }
                }
            }
            3 -> {
                matChose = readKey(matrices, "Witch matrix? ")
                print("\nMultiply By #: ")
                number = scanner.nextInt()
                matrices[matChose] = multiplyBy(matrices[matChose]!!, number)
            }
            4 -> {
                matChose = readKey(matrices, "First Matrix? ")
                matChose2 = readKey(matrices, "Second Matrix? ")

                matrix = matrices[matChose]!!
                matrix2 = matrices[matChose2]!!
                matrix = sumBy(matrix, matrix2)
                println("\n[$matChose] + [$matChose2]\n")
                showMatrix(matrix)
            }
            else -> println("Invalid option\n")
        }
    }while(true)
}


// ##################### AUXILIARY #######################
fun line(ch: Char, size: Int){
    for(i in 1..size)
        print(ch)
    println()
}

fun menu(vararg options: String) : Int{
    var opt : Int
    val size = options.size
    println()
    do{
        for (i in 0 until size) {
            println("\t$i - ${options[i]}")
        }
        print("\nChoose an option: ")
        opt = scanner.nextInt()
        if(opt !in 0..size)
            println("\nInvalid option\n")
    }while(opt !in 0 until size)
    return  opt
}

fun menuInsert(vararg options: String) : Int{
    println("\nHow do you want fill the matrix: ")
    return menu(*options)
}

fun mainMenu(vararg options: String) : Int{
    println("\n============== MAIN MENU ===============")
    return menu(*options)
}

fun insideMenu(vararg options: String) : Int{
    println("\n================ INSIDE MENU ===============")
    println("What you want to do")
    return menu(*options)
}


// ###################### HANDLE MATRIX #################
fun assignMatrix(input: Boolean, min: Float, max: Float) : Array<Array<Float>>{
    val matrix : Array<Array<Float>> = Array(ROW) {Array(COLUMN) {0f} }

    for(i in 0 until ROW){
        for(j in 0 until COLUMN){
            if(input) {
                print("Value in [${i+1}-${j+1}]: ")
                matrix[i][j] = scanner.nextFloat()
            }
            else{
                matrix[i][j] = min + Random.nextFloat() * (max - min)
            }
        }
    }
    return matrix
}

fun identityMatrix() : Array<Array<Float>>{
    val matrix = Array(ROW) {Array(COLUMN) {0f} }
    for(i in 0..2){
        matrix[i][i] = 1f
    }
    return  matrix
}

fun showMatrix(mat: Array<Array<Float>>){
    line('-', 25)
    for(row in mat){
        print("|")
        for(column in row){
            print("${String.format("%.1f", column).padStart(5).padEnd(7)}|")
        }
        println()
        line('-', 25)
    }
}

fun readKey(matrices: HashMap<Char, Array<Array<Float>>>, msg: String) : Char{
    var matChose : Char
    val size = 27
    var cont = 1
    line('~', size)
    print("  ")
    for(k in matrices.keys){
        print("[$k]  ")
        if(cont++ % 5 == 0)
            print("\n  ")
    }
    println()
    line('~', size)
    do {
        print("$msg ")
        matChose = scanner.next().uppercase()[0]
    }while(matChose !in matrices.keys)
    return  matChose
}

// ################### OPERATION ON MATRIX ###############
fun multiplyBy(matrix: Array<Array<Float>>, num: Int) : Array<Array<Float>>{
    val mat = Array(ROW){Array(COLUMN) {0f}}

    for(i in 0 until ROW){
        for(j in 0 until COLUMN){
            mat[i][j] = matrix[i][j] * num
        }
    }
    return  mat
}

fun sumBy(matA : Array<Array<Float>>, matB : Array<Array<Float>>) : Array<Array<Float>>{
    val mat = Array(ROW){Array(COLUMN) {0f}}

    for(i in 0 until ROW){
        for(j in 0 until COLUMN){
            mat[i][j] = matA[i][j] + matB[i][j]
        }
    }
    return mat
}