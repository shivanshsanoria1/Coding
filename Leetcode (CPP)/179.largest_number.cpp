class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size(), c=0;
        vector<string> str;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0)
                c++;
            str.push_back(to_string(nums[i]));
        }
        if(c==n) // the case where all elements in i/p array are 0
            return "0";
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(compare(str[i],str[j])==true)
                {
                    string temp=str[i];
                    str[i]=str[j];
                    str[j]=temp;
                }
            }
        }
        string ans;
        for(int i=0; i<n; i++)
            ans+=str[i];
        return ans;
    }
    
    bool compare(string s1, string s2) // return true if s1 and s2 needs to be swapped
    {
        if(s1+s2 >= s2+s1)
            return false;
        return true;
    }
};