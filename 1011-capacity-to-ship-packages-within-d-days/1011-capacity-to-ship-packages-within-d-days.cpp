class Solution {
public:
    int shipWithinDays(vector<int>& A, int M) {
        
        int N=A.size();
     int start=0;
        long totalSum=0;
        
        for(int x=0;x<N;x++)
        totalSum+=A[x];
        
        long int end=totalSum;
        int answer=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(isPossible(A,N,M,mid))
                {
                    answer=mid;
                    end=mid-1;
                }
                else
                start=mid+1;
        }
        return answer;
        
    }
    
    bool isPossible(vector<int>&  pages,int N,int M,int boundVal)
    {
        
        int studentsCount=1;
        int currentSum=0;
        
        for(int currentPage=0;currentPage<N;currentPage++)
        {
            if(pages[currentPage]>boundVal)
            return false;
            
            if(currentSum+pages[currentPage]<=boundVal)
                currentSum=currentSum+pages[currentPage];
                
            else
            {
                studentsCount+=1;
                currentSum=pages[currentPage];
                
                if(studentsCount>M)
                {
                return false;
                
                    
                }
            }
                
        }
        return true;
        
        
        
    }
};