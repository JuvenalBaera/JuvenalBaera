fun main(){
    var age: Int = 17
    var miss: Int
    val canVote = 18

    if(age < canVote - 2){
        miss = canVote - age
        println("You're not old enough to vote")
        println("You will vote after $miss years")
    }
    else if(age > 65 || age >= canVote - 2){
        println("You can or can't vote")
    }
    else{
        println("You can vote.")
    }
}