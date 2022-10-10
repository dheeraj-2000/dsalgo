//983. Minimum Cost For Tickets
/*
You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.
 */
  
#include <iostream>

using namespace std;

int mincostTickets(vector<int>& days, vector<int>& costs) {
    unordered_set<int> travel(begin(days), end(days));
    int dp[30] = {};
    for (int i = days.front(); i <= days.back(); ++i) {
        if (travel.find(i) == travel.end()) 
            dp[i % 30] = dp[(i - 1) % 30];
        else dp[i % 30] = min({ dp[(i - 1) % 30] + costs[0],
            dp[max(0, i - 7) % 30] + costs[1], dp[max(0, i - 30) % 30] + costs[2] });
    }
  return dp[days.back() % 30];
}

//// Main function for testing
int main() {
   vector<int> days = {1,4,6,7,8,20};
   vector<int> costs = {2,7,15};
   cout << mincostTickets(days, costs);
}


