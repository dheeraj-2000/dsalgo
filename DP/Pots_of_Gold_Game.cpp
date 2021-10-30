#include <iostream>
#include <string>
using namespace std;
 
// Recursive function to maximize the number of coins collected by a player,
// assuming that the opponent also plays optimally
int findMaxCoins(int coin[], int i, int j)
{
    // base case: one pot left, only one choice possible
    if (i == j) {
        return coin[i];
    }
 
    // if we are left with only two pots, choose one with maximum coins
    if (i + 1 == j) {
        return max(coin[i], coin[j]);
    }
 
    // if a player chooses the front pot `i`, the opponent is left to choose
    // from [i+1, j].
    // 1. If the opponent chooses front pot `i+1`, recur for [i+2, j]
    // 2. If the opponent chooses rear pot `j`, recur for [i+1, j-1]
 
    int start = coin[i] + min(findMaxCoins(coin, i + 2, j),
                            findMaxCoins(coin, i + 1, j - 1));
 
    // if a player chooses rear pot `j`, the opponent is left to choose
    // from [i, j-1].
    // 1. If the opponent chooses front pot `i`, recur for [i+1, j-1]
    // 2. If the opponent chooses rear pot `j-1`, recur for [i, j-2]
 
    int end = coin[j] + min(findMaxCoins(coin, i + 1, j - 1),
                    findMaxCoins(coin, i, j - 2));
 
    // return the maximum of two choices
    return max(start, end);
}
 
// Pots of gold game using dynamic programming
int main()
{
    // pots of gold arranged in a line
    int coin[] = { 4, 6, 2, 3 };
 
    // total number of pots (`n` is even)
    int n = sizeof(coin) / sizeof(coin[0]);
 
    cout << "The Maximum coins collected by player is "
         << findMaxCoins(coin, 0, n - 1);
 
    return 0;
}
// this code is contributed by vikash kumar patel