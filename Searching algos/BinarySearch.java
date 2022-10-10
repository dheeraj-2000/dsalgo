public class BinarySearch {
    
    
    public static void main(String[] args) {
        //IMPORTANT - array MUST be sorted for search to work
        int[] arrayToSearch = new int[]{1,4,5,6,7,10,14,15,21,34,33};
        System.out.println(iterativeBinarySearch(arrayToSearch, 6));
        System.out.println(recursiveBinarySearch(arrayToSearch, 15, 0, arrayToSearch.length - 1));
    }

    //iterative binary search
    public static int iterativeBinarySearch(int[] array, int valueToSearch) {
        //set your indexes for array traversal (beginning and end)
        int low = 0;
        int high = array.length - 1;

        int index = Integer.MAX_VALUE;
        
        //loop through array
        while (low <= high) {

            //set middle index to start search
            int middle = low  + ((high - low) / 2);

            //if value at index is less than value we are searching for, increment index down
            if (array[middle] < valueToSearch) {
                low = middle + 1;

            //if value at index is greater than value we are searching for, increment index up
            } else if (array[middle] > valueToSearch) {
                high = middle - 1;

            //here we have found the index of the value and can return 
            } else if (array[middle] == valueToSearch) {
                index = middle;
                break;
            }
        }
        return index;
    }


    //for recursive search
    public static int recursiveBinarySearch(int[] array, int valueToSearch, int low, int high) {
        //set middle index to start search
        int middle = low  + ((high - low) / 2);
            
        //if highest index becomes less than lowest index, value does not exist
        //breaks infinite recursion
        if (high < low) {
            return -1;
        }

        //return index if value matches
        if (valueToSearch == array[middle]) {
            return middle;
        
        //if value is less than middle index, call function again and search through left side of array
        } else if (valueToSearch < array[middle]) {
            return recursiveBinarySearch(array, valueToSearch, low, middle - 1);

        //if value is greater than middle index, call function again and search through right side of array
        } else {
            return recursiveBinarySearch(array, valueToSearch, middle + 1, high);
        }
    }
}

