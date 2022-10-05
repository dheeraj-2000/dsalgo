// JAVA solution for Do Not Be Distracted CodeForces bruteforce problem #719-A
// https://codeforces.com/contest/1520/problem/A

// A. Do Not Be Distracted!

// Polycarp has 26 tasks. Each task is designated by a capital letter of the Latin alphabet.

// The teacher asked Polycarp to solve tasks in the following way: if Polycarp began to solve some task, then he must solve it to the end, without being distracted by another task. After switching to another task, Polycarp cannot return to the previous task.

// Polycarp can only solve one task during the day. Every day he wrote down what task he solved. Now the teacher wants to know if Polycarp followed his advice.

// For example, if Polycarp solved tasks in the following order: "DDBBCCCBBEZ", then the teacher will see that on the third day Polycarp began to solve the task 'B', then on the fifth day he got distracted and began to solve the task 'C', on the eighth day Polycarp returned to the task 'B'. Other examples of when the teacher is suspicious: "BAB", "AABBCCDDEEBZZ" and "AAAAZAAAAA".

// If Polycarp solved the tasks as follows: "FFGZZZY", then the teacher cannot have any suspicions. Please note that Polycarp is not obligated to solve all tasks. Other examples of when the teacher doesn't have any suspicious: "BA", "AFFFCC" and "YYYYY".

// Help Polycarp find out if his teacher might be suspicious.

// Submission : 174650702
// Author : codedmachine111
// Verdict : Accepted
// Time : 140ms
// Memory : 0KB
// When : 2022-10-04

// Code
import java.util.*;

public class DoNotBeDistracted {
    public static void main(String[] args) {
      
      Scanner input = new Scanner(System.in);
      
      // Input number of test cases
      int tries = input.nextInt();
      
      // Repeat for all test cases
      for(int i=0; i<tries; i++){
        // Input number of days worked 
        int ntasks = input.nextInt();
        // Input string of tasks
        String tasks = input.next();
        if(!isSus(tasks)){
          // If teacher not suspicious print YES
          System.out.println("Yes");
        }else{
          // If suspicious print NO
          System.out.println("No");
        }
      }
  }   
  // Function to check duplicate elements in an array
  static boolean isDuplicate(char[] arr, int count){
    int status=0;
    for(int i=0; i<count;i++){
      for(int j=i+1; j<count; j++){
        if(arr[i]==arr[j]){
          return true;
        }
      }
    }
    return false;
  }
  
  // Function to check if teacher is Suspicious
  static boolean isSus(String s){
    //Convert string to a character array
    char[] str = s.toCharArray();
    
    char ftask = str[0];
    
    // Initialize new array to store all tasks
    char[] arr = new char[str.length];
    arr[0]=ftask;
   
    // k maintains the index of char[] arr
    int k=1;
    
    // count maintains the total number of unique tasks
    int count=1;
    // Traverse and compare two elements of array
    for(int i=1; i<str.length; i++){
      if(str[i] == str[i-1]){
        continue;
      }else{
        // append to array if not same
        arr[k]=str[i];
        count++;
        k++;
      }
    }
    // check if duplicate and return boolean value
    return isDuplicate(arr,count);
  }
}


