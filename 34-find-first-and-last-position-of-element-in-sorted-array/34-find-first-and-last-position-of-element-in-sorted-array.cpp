class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int>vec(2,-1);
        
        vec[0]=firstPos(nums,target);
        
        // if(firstPos==-1)return vec;
        
        vec[1]=lastPos(nums,target);
        
        return vec;
    }
    
    
    int firstPos(vector<int>&nums, int target)
    {
        int start=0;
        int end=nums.size()-1;
        int answer=-1;
        while(start<=end){
            
            int mid=start+(end-start)/2;
            
            if(nums[mid]==target){
                answer=mid;
                end=mid-1;
            }
            
            else if(nums[mid]>target){
                end=mid-1;
            }else
                start=mid+1;
        }
        return answer;
    }
    
    int lastPos(vector<int>&nums, int target)
    {
        int start=0;
        int end=nums.size()-1;
        int answer=-1;
        while(start<=end){
            
            int mid=start+(end-start)/2;
            
            if(nums[mid]==target){
                answer=mid;
                start=mid+1;
            }
            
            else if(nums[mid]>target){
                end=mid-1;
            }else
                start=mid+1;
        }
        return answer;
    }
    
};