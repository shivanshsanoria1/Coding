class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.length();
        vector<int> vec(26,0); //to store the freq of each char in string 
        for(int i=0; i<n; i++)
            vec[s[i]-'a']++;
        for(int i=0; i<n; i++) //first non-repeating char must have a freq of 1
            if(vec[s[i]-'a']==1)
                return i;
        return -1;
    }
};