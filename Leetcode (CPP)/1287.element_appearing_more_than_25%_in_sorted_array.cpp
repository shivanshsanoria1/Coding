class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int freq25= n/4+1; //freq required to be > 25%
        int freq=1;
        for(int i=1; i<n; i++)
        {
            if(arr[i]==arr[i-1]) //increment freq
                freq++;
            else //reset freq
                freq=1;
            if(freq >= freq25) //curr freq >= required freq
                return arr[i];
        }
        return 1; //array has only 1 element
    }
};