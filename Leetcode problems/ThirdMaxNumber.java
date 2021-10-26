/*
 * This is a testing/proving ground for solution for Leetcode problems or maybe even other problems at a later date.
 * When a solution is found, I will create another file with the problem name and number and then clean out this file.
 *
 * Evan C.
 * October 26, 2021
 * Current Leetcode Problem: 414. Third Maximum Number
 */

public class ThirdMaxNumber {

    public int thirdMax(int[] nums) {
        // THESE HAVE TO BE NULL due to the constraints of the question. I didn't read them and that caused me a massive headache.
        Integer first = null;
        Integer second = null;
        Integer third = null;
        for(Integer num : nums){ // Foreach loop
            if(num.equals(first)|| num.equals(second) || num.equals(third)) continue; // Note the .equals prevents a null pointer exception
            if(first == null || num > first){
                third = second;
                second = first;
                first = num;
            } else if(second == null || num > second) {
                third = second;
                second = num;
            } else if(third == null || num > third){
                third = num;
            }


        }
        if(third == null) third = first; // Needed in case the nums array is less than 3.
        return third;
    }

}
