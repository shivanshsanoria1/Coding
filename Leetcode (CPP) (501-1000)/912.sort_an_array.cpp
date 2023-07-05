class Solution {
public:
    void merge(vector<int>& vec, int left, int mid, int right) 
    { //left-subarray from [left,mid], right-subarray from [mid+1,right], merged-subarray from [left,right]
        vector<int> merged;
        int i=left; //start index of left-subarray
        int j=mid+1; //start index of right-subarray
        while(i<=mid && j<=right) //both subarrays have elements remaining
        {
            if(vec[i] <= vec[j])
            {
                merged.push_back(vec[i]);
                i++;
            }
            else
            {
                merged.push_back(vec[j]);
                j++;
            }
        }
        while(i<=mid) //elements are remaining in left-subarray
        {
            merged.push_back(vec[i]);
            i++;
        }
        while(j<=right) //elements are remaining in right-subarray
        {
            merged.push_back(vec[j]);
            j++;
        }
        for(int k=left; k<=right; k++) //copy the elements from temp subarray into the original array
            vec[k] = merged[k-left];
    }
    
    void mergeSort(vector<int>& vec, int left, int right)
    {
        if(left < right)
        {
            int mid= (left+right)/2;
            mergeSort(vec,left,mid); //left-subarray from [left,mid]
            mergeSort(vec,mid+1,right); //right-subarray from [mid+1,right]
            merge(vec,left,mid,right); //merged-subarray from [left,right]
        }
    }
    
    vector<int> sortArray(vector<int>& nums) { //using merge sort
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};