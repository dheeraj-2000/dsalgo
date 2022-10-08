import java.util.Scanner;

public class PrimesCheck {

    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);
        int number, start, end;

        System.out.println("PROGRAMS JAVA FOR SHOWING PRIMES NUMBER");
        System.out.print("Start : ");
        start=input.nextInt();
        System.out.print("End : ");
        end=input.nextInt();
        System.out.println("----------------------------------------------");
        for (int i=start; i<=end; i++){
            number=0;
            for (int j=1;j<=i;j++){
                if (i%j==0){
                    number=number+1;
                }
            }
            if (number==2){
                System.out.print(i+" ");
            }
        }
    }
}
