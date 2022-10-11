package bitwiseOperators;

import java.util.Scanner;

public class OddEven {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        if((num & 1) == 1){
            System.out.println("Odd");
        }else{
            System.out.println("Even");
        }
    }
}
