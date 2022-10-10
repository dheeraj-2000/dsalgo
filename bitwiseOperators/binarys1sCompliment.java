package bitwiseOperators;

import java.util.Scanner;

public class binarys1sCompliment {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int x = 0;
        int sum = 0;
        while(num > 0){
            int rem = num % 2;
            if(rem == 0){
                sum +=  Math.pow(2,x);
                x++;
            }
            else{
                x++;
            }
            num = num / 2;
        }
        System.out.println(sum);
    }
}
