//Median of Two Sorted Arrays

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

class Solution {
    public double findMedianSortedArrays(int[] arr1, int[] arr2) {
        if (arr1.length > arr2.length) {
            int[] tmp = arr1;
            arr1 = arr2;
            arr2 = tmp;
        }
        int left = 0;
        int right = arr1.length;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int s_mid = (arr1.length + arr2.length) / 2 - mid;
            int arr1l = mid == 0 ? Integer.MIN_VALUE : arr1[mid-1];
            int arr1r = mid == arr1.length ? Integer.MAX_VALUE : arr1[mid];
            int arr2l = s_mid == 0 ? Integer.MIN_VALUE : arr2[s_mid-1];
            int arr2r = s_mid == arr2.length ? Integer.MAX_VALUE : arr2[s_mid];

            if (arr1l <= arr2r && arr2l <= arr1r) {
                if ((arr1.length + arr2.length) % 2 == 0) {
                    return (Math.max(arr1l, arr2l) + Math.min(arr1r, arr2r)) * 0.5;
                } else {
                    return Math.min(arr1r, arr2r);
                }
            } else if (arr1l > arr2r) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return 0.0;
        
    }
}