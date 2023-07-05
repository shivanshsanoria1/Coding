class Solution {
public:
    bool isPalin(string s)
    {
        int left=0, right=s.length()-1;
        while(left < right) 
        {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        for(int i=0; i<words.size(); i++)
            if(isPalin(words[i]))
                return words[i];
        return "";
    }
};