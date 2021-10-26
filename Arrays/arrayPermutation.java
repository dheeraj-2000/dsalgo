public class ArrayFromPermutaion
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the number of elements of the array :- ");
        int a = in.nextInt();
        int[] arr = new int[a];
        int[] num = new int[a];
        System.out.println("Enter the elements of the array and please make sure the elements are less than " + a);

        //Filling the array
        for (int i = 0; i < a ; i += 1)
        {
            arr[i] = in.nextInt();
        }

        //Building array from permutaion
        for(int i = 0; i < a ; i += 1)
        {
            num[i] = arr[ arr[i] ];
        }

        System.out.println("The new array created from permutation is :- ");

        //Printing the array build from permutation
        for(int i = 0; i < a ; i += 1)
        {
            System.out.print( num[i] + "     ");
        }
    }
}