fun main() {
    var a = 3
    var b = 7
    println("--Before swap--")
    println("A = $a")
    println("B = $b")
    a = a - b
    b = b + a
    a = b - a
    println("--After swap--")
    println("A = $a")
    println("B = $b")
}