class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
       sort(nums.begin(),nums.end());
       int result=0;
       int n=nums[0] + nums[1] + nums[2];
       for(int i=0;i<nums.size();i++)
       {
        int first=i+1;
        int last=nums.size()-1;
          while(first<last)
          {
             if(nums[first]+nums[last]+nums[i]>target)
             {
                result=nums[first]+nums[last]+nums[i];
                last--;
             }
             else if(nums[first]+nums[last]+nums[i]<target)
             {
                result=nums[first]+nums[last]+nums[i];
                first++;
             }
             else
             {
                result=nums[first]+nums[last]+nums[i];
                return result;
             }
            if(abs(result - target) < abs(n - target))
            {
                n = result;
            }
          }
       }  
       return n;       
    }
};