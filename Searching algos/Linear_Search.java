public class Linear_Search {
    
    public static int linear(int array[], int key)
    {
        int size=array.length;
        int index;
        for (index=0; index<size; index++)
        {
            if (array[index]==key)
            {
                return index;
            }
        }
        return -1;
    }

    public static void main(String[] args)
    {
        int array[]={5, 6, 12, 4, 56, 87, 12};
        int key = 56;
        int index=linear(array, key);
        if (index==-1)
        {
            System.out.println("Element not found.");
        }
        else
        {
            System.out.println("Element found at index " + index);
        }
     }
}
