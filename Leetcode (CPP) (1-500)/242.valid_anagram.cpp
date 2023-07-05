class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1=s.length(), n2=t.length();
        if(n1 != n2)
            return false;
        vector<char> vec1(n1),vec2(n2);
        for(int i=0; i<n1; i++)
            vec1[i]=s[i];
        for(int i=0; i<n2; i++)
            vec2[i]=t[i];
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        for(int i=0; i<n1; i++)
            if(vec1[i]!=vec2[i])
                return false;
        return true;
    }
};