/**************************************************************************************************

    Name : Ankit Dimri
    code : Longest Maximum Value Contiguous Subsequence using dynamic porgramming.

**************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>  // max_element

 // To compute the maximum value of a subsequence
 std::vector <int>::iterator MVCS (const std::vector <int>, std::vector <int>&);

 int main(int argc, char const *argv[]) {
     std::vector <int> sequence;
     std::vector <int>::iterator end, start, i, j;
     int n, input, value = 0;
     std::cout << "\n\n\t Enter the size of the sequence : ";
     std::cin >> n;
     // Check List to check 1 if the element is greater than the sum with previous elements
     std::vector <int> checkList (n, 0);
     std::cout << "\n\t Enter the values of the sequence : ";
     for (int i = 0; i < n; i++) {
         std::cin >> input;
         sequence.push_back (input);
     }
     start = end = MVCS (sequence, checkList);
     // Iterators to define the limits of the subsequence
     i = j = sequence.begin ();
     // To advance iterator of sequence to same position as that of iterator of checkList
     std::advance (i, std::distance (checkList.begin (), start));
     std::advance (j, std::distance (checkList.begin (), end));
     // To find the start limit of the subsequence
     while (!*start) {
         i--;
         start--;
     }
     start++;
     i++;
     // Printing the subsequence with maximum sum
     std::cout << "\n\n\t The maximum value subsequence is : ";
     while (i <= j) {
        std::cout << *i << ' ';
        value += *i;
        i++;
     }
     // Printing the maximum value
     std::cout << "\n\t The maximum value is : " << value << std::endl;
     return 0;
 }

 // Returning the position of the point at which the maximum value subsequence ends
 std::vector <int>::iterator MVCS (const std::vector <int> s, std::vector <int> &checkList) {
     // Dynamic table for calcuating the sum of the sequence
     std::vector <int> val (s.size (), 0);
     val [0] = s [0];
     std::vector <int>::iterator i = val.begin (), cc = checkList.begin ();
     /* Algorthm to find the Maximum value subsequence using dynamic programming */
     for (std::vector <int>::const_iterator it = ++s.begin (); it != s.end (); it++, i++, cc++) {
         if (*it + *i >= *it)
             *(i+1) = *it + *i;
         else {
             *(i+1) = *it;
             *cc = 1;  // checking 1 on checklist when element > element + sum [i-1]
         }
     }
     cc = checkList.begin ();
     std::advance (cc, std::distance (val.begin (), max_element (val.begin (), val.end ())));
     return cc;
 }
