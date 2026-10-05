class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> n;
        unordered_set<int> result;
        for(auto i:nums1)
        {
            n.insert(i);
        }        
        for(auto j:nums2)
        {
            if(n.find(j)!=n.end())
            {
                    result.insert(j);
               
            }
        }
        vector<int> ans(result.begin(),result.end());
        return ans;
    }
};