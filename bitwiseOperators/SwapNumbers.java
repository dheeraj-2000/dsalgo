/*
Swaping the Two variable without using bitwise operator.
*/

package bitwiseOperators;

import java.util.Scanner;

public class SwapNumbers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println("Value of 'a' After Swap: " + a + " and Value of 'b' after Swap: " + b);
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;

        System.out.println("Value of 'a' After Swap: " + a + " and Value of 'b' after Swap: " + b);
    }
}
