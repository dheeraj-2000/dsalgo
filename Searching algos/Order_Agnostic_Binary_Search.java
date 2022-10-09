import java.util.Scanner;
public class OrderAgnostic {
        static int bsearch(int arr[],int key){
        		int start=0;
        		int end=arr.length-1;
        		boolean isasscending;
        		if(arr[start]<arr[end])
            		isasscending=true;
        		else
            		isasscending=false;
        
        		while(start <= end){
            		int mid= start+(end-start)/2;
            		if(arr[mid]==key)
                			return mid;
            		if(isasscending){
                			if(key<arr[mid])
                    			end=mid-1;
                			else
                    			start=mid+1;
            		}
           		 else{
                			if(key > arr[mid])
                    			end=mid-1;
                			else
                    			start=mid+1;
            		}
        		}
        		return -1;
    	}
    	public static void main(String[] args){
        		int[] arr={1926,2756,3581,4386,5145};
        		int key=4386;
        		System.out.println(bsearch(arr,key));
    	}
}
