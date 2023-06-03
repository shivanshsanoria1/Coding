class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int diff,sum=0;
        for(int i=1; i<n; i++)
        {
            diff=prices[i]-prices[i-1];
            if(diff > 0)
                sum=sum+diff;
        }
        return sum;
    }
};