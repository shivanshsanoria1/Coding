class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) { // T.C.=O(n + k*logn)
        priority_queue<int> pq(nums.begin(),nums.end()); //max heap
        for(int i=1; i<k; i++) //pop (k-1) elements from heap
            pq.pop();
        return pq.top();
    }
};