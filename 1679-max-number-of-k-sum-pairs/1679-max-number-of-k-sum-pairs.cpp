class Solution {
public:
    int maxOperations(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int result=0;
        int size=nums.size();
        int first=0;
        int last=size-1;
        while(first<last)
        {
            int sum=nums[first]+nums[last];
            if(sum==k)
            {
                result++;
                first++;
                last--;
            }
            else if(sum<k)
            {
                first++;
            }
            else
            {
                last--;
            }
        }
        return result;
    }
};