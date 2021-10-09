class Solution {
    public double findMedianSortedArrays(int[] A, int[] B) {
        int m = A.length;
        int n = B.length;
        
        if(m > n){
            int []temp = A;
            A = B;
            B = temp;
            int tmp = m;
            m = n;
            n = tmp;
        }
        
        int iMin = 0;
        int iMax = m;
        int halflen = (m + n + 1) / 2;
        
        while(iMin <= iMax){
            int i = (iMax + iMin) / 2;
            int j = halflen - i;
            if(i < iMax && B[j-1] > A[i]){
                iMin = i + 1;
            }
            else if(i > iMin && A[i-1] > B[j]){
                iMax = i - 1;
            }
            else{
                int MaxLeft = 0;
                if(i == 0){
                    MaxLeft = B[j - 1];
                }
                else if(j == 0){
                    MaxLeft = A[i - 1];
                }
                else{
                    MaxLeft = Math.max(A[i-1],B[j-1]);
                }
                if((m + n) % 2 == 1){
                    return MaxLeft;
                }
                int MaxRight = 0;
                if(i == m){
                    MaxRight = B[j];
                }
                else if(j == n){
                    MaxRight = A[i];
                }
                else{
                    MaxRight = Math.min(A[i],B[j]);
                }
                return (MaxLeft + MaxRight) / 2.0;
            }
        }
        return 0.0;
    }
}