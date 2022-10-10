/*
Given a number n and k (1 <= k <= 32), find the value of k-th bit in the binary representation of n.
Bits are numbered from right (Least Significant Bit) to left (Most Significant Bit).

Examples :

Input :
n = 13, k = 2
Output :
0
Explanation:
Binary representation of 13 is 1101.
Second bit from right is 0.

Input :
n = 14, k = 3
Output :
1
Explanation:
Binary representation of 14 is 1110.
Third bit from right is 1.
 */
package bitwiseOperators;


import java.util.Scanner;

public class Find_ith_bit {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int k = sc.nextInt();
        System.out.println((num >> (k-1)) % 2);
    }
}
