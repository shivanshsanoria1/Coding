class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int min_price=prices[0],max_profit=0;
        for(int i=0; i<n; i++)
        {
            if(prices[i] < min_price)
                min_price=prices[i];
            else if(prices[i]-min_price > max_profit)
                max_profit=prices[i]-min_price;
        }
        return max_profit;
    }
};

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),max=0,profit;
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                profit=prices[j]-prices[i];
                if(profit > max)
                    max=profit;
            }
        }
        return max;
    }
};
*/