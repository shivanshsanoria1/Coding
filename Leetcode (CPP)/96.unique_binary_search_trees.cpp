class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0); //dp[i] represents num of BSTs possible using i nodes (with values 1 to i)
        dp[0]=1; //0 BST possible using 0 nodes (but assumed to be 1 to solve the ques)
        dp[1]=1; //1 BST possible using 1 node (with value 1)
        for(int i=2; i<=n; i++)
        {
            int left=0, right=i-1; //left-subtree:'left' num of nodes, root:index j, right-subtree:'right' num of nodes
            for(int j=1; j<=i; j++) //num of BSTs possible for index j is dp[left]*dp[right]
            {
                dp[i] += dp[left]*dp[right];
                left++;
                right--;
            }
        }
        return dp[n]; //return the last element in dp
    }
};