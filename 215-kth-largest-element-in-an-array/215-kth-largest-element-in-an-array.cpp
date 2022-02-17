class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int,vector<int>, greater<int> >pq;
                for(int i=0;i<n;i++)
        {
    
            // if(i<k-1)
            // {
            // pq.push(arr[i]);   
            // v.push_back(-1);
            // continue;
            // }
            
            pq.push(nums[i]);
            
            if(pq.size()>k)
            pq.pop();
            
            // v.push_back(pq.top());
        }
    
    return pq.top();

    }
};