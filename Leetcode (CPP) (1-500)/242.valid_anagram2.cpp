class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1=s.length(), n2=t.length();
        if(n1 != n2)
            return false;
        vector<int> count(26,0);
        for(int i=0; i<n1; i++) 
        {
            count[s[i]-'a']++; //increment the count of corresponding letter of string s in count[] 
            count[t[i]-'a']--; //decrement the count of corresponding letter of string t in count[]
        }
        for(int i=0; i<26; i++) //check if count[] consists of all 0's
            if(count[i]!=0)
                return false;
        return true;
    }
};