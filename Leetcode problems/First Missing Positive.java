//  https://leetcode.com/problems/first-missing-positive/

class Solution {
    static void swap(int[] a,int i,int j) {
		a[i]=a[i]+a[j];
		a[j]=a[i]-a[j];
		a[i]=a[i]-a[j];
	}
	
	
	public int firstMissingPositive(int[] a) {
		int n=a.length;
		int i=0;
		
		while(i<n) {
			if(a[i] > 0 && a[i]<=n && a[i] != a[a[i]-1]) swap(a,i,a[i]-1);
			else i++;
		}
		for(i=0;i<n;i++) if(a[i] != i+1) return i+1;
        return n+1;
    }
}
