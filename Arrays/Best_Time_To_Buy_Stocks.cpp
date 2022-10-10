public:
   int maxProfit(vector<int>& prices)
   {
        if(prices.size() == 0)
            return 0;
     
       int Soln = 0;
       int begin = prices[0], finish = prices[0];
     
       for(int i = 0; i < prices.size(); i++)
       {
           if(prices[i] < begin){
               //start compared to 0
               Soln = max(Soln, finish - begin);
               begin = prices[i];
               finish = prices[i];
           }
           else
           {
               //continue
               finish = max(finish, prices[i]);
           }
       }
       Soln = max(Soln, finish - begin);
       return Soln;
   }
