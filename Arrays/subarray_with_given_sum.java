import java.util.* ;  

class Main {  
    static void subarray(int arr[] , int n , int sum )      {  
        int currentsum, i , j ; 
  
        for ( i = 0 ; i < n ; i++ ) {  
            currentsum = arr[i] ;  
            for (j = i + 1 ; j <= n ; j++) {  
                if (currentsum == sum) {  
                    int end = j - 1 ;  
                    System.out.println("Sum found between indexes  " + i  + " and " + end) ;  
                }  
                if (currentsum > sum || j == n)  {
                    break ; 
                }
                currentsum = currentsum + arr[j] ;  
            }  
        }  
        System.out.println(" No subarray found " ) ;  
    }  
  
    public static void main( String[] args )      {  
        Scanner sc = new Scanner ( System.in ) ;   
        System.out.println ("Enter number of elements :  " ) ;  
        int n = sc.nextInt() ;  
        int [] array = new int[ 100 ] ;  
        System.out.println ("Enter elements of the array :  " ) ;  
        for ( int i = 0 ; i < n ; i++ )   {  
           array[ i ] = sc.nextInt() ;  
        }  
        System.out.println("Enter value of sum : " ) ;  
        int sum = sc.nextInt() ;  
        subarray(array , n , sum) ;  
    }  
} 
