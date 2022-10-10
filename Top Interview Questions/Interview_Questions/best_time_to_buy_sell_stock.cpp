class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int maxPro = 0;
        int minprice = INT_MAX;
        for(int i=0; i<n; i++){
            // here we are going to find minimum stock price before current day 
            minprice = min(prices[i],minprice);
            
/*here we are going to calculate the maximum profit compare with before [just taking difference of current stock price and minprice for maximize the diff(profit)]..
maxPro = profit
*/
            
            maxPro = max(maxPro, prices[i]-minprice);
        }
        
        return maxPro;
    }
};
