import java.util.Scanner;

public class Fibonacci {

    public static int fibonacci(int number) {
        if (number <= 1)
            return number;
        else
            return fibonacci(number - 2) + fibonacci(number - 1);
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter nth digit");
        int number = in.nextInt()+1;
        System.out.println(fibonacci(number));
    }

}
