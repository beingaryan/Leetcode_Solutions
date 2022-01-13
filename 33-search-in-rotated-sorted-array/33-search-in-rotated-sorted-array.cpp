class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        // int comparator=0;
        int comparator=0;
        int pivot=nums[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(((target>=pivot)&&(nums[mid]>=pivot))||((target<pivot)&&(nums[mid]<pivot))){
                comparator=nums[mid];
            }
            
            else{
                if(target>=pivot)
                    comparator=INT_MAX;
                else
                    comparator=INT_MIN;
                
            }
            
            if(target==comparator)return mid;
            
            if(target>comparator){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
                      
        }
        
        return -1;
    }
};
// Source: https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/154836/The-INF-and-INF-method-but-with-a-better-explanation-for-dummies-like-me

// class Solution {
// public:
//     int search(vector<int>& nums, int target) 
//     {
//             int l = 0, r = nums.size()-1;
//             while(l <= r)
//             {
//                 int mid = (r - l)/2 + l;
//                 int comparator = nums[mid];
//                 // Checking if both target and nums[mid] are on same side.
//                 if((target < nums[0]) && (nums[mid] < nums[0]) || (target >= nums[0]) && (nums[mid] >= nums[0]))
//                     comparator = nums[mid];
//                 else
//                 {
//                     // Trying to figure out where nums[mid] is and making comparator as -INF or INF
//                     if(target <nums[0])
//                         comparator = INT_MIN;
//                     else 
//                         comparator = INT_MAX;

//                 }
//                 if(target == comparator) return mid;
//                 if(target > comparator)            
//                     l = mid+1;            
//                 else
//                     r = mid-1;

//             }
//             return -1;
//     }
// };