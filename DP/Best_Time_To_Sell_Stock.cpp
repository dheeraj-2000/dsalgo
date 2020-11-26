 int maxProfit(vector<int>& prices) {
    
        int k=2;
        int n = prices.size();
        if(n==0)
            return 0;
        
        vector <int> evenProfits(n,0);
        vector <int> oddProfits(n,0);
        
        int result=0;
     
        for(int i=1; i<=k; i++)
        {
            int maxThusFar = INT_MIN;
            // cout<<maxThusFar<<endl;
            // cout<<i<<endl;
       
            if(i%2==0)
            {
               
                for(int j=1; j<n; j++)
                {   


                    maxThusFar = max(maxThusFar, oddProfits[j-1]-prices[j-1]);

                    evenProfits[j] = max(evenProfits[j-1], prices[j]+maxThusFar);
                 
                }
            }
            else
            {
             
                for(int j=1; j<n; j++)
                {   


                    maxThusFar = max(maxThusFar, evenProfits[j-1]-prices[j-1]);

                    oddProfits[j] = max(oddProfits[j-1], prices[j]+maxThusFar);
                   
                }
            }      
        }
        
        
        return k%2==0 ? evenProfits.back(): oddProfits.back();
    }
