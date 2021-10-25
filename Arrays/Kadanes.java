public class Kadanes {
    public static void main(String[] args) {
        int[] a = {4, -2, -6, 9, 1, -3};
        System.out.println("Maximum contiguous sum is " +
                maximumSubArraySum(a, a.length));
    }

    static int maximumSubArraySum(int array[], int size) {
        int iterator, max = array[0], cur_max = 0;
        for (iterator = 0; iterator < size; iterator++) {
            cur_max += array[iterator];
            if (max < cur_max)
                max = cur_max;
            else if (cur_max < 0)
                cur_max = 0;
        }
        return max;
    }
}
