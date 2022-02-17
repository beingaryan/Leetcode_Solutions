class KthLargest {
public:
    int k;
    vector<int>vec;
    priority_queue<int,vector<int>,greater<int>>pq;
    
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int i=0;i<nums.size();i++){
            add(nums[i]);
            // vec[i]=nums[i];
            // pq.push(nums[i]);
        }

    }
    
    int add(int val) {
       pq.push(val);
        if(pq.size()>k)
            pq.pop();
        return pq.top();
    }
};
//  vec.push_back(val);
//         int n=vec.size();
//         for(int i=0;i<n;i++){
// //             if(i<k-1){
                
// //             }
            
//             pq.push(vec[i]);
            
//         }
        
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */