class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> freq;

		for(int x:nums)
		{
			freq[x]++;
		}
		vector<pair<int ,int >> output;
		for(auto &i:freq)
		{
			output.push_back({i.second,i.first});
		}
		sort(output.rbegin(),output.rend());

		vector<int> ans;
		for(int i=0;i<k;i++)
		{
			ans.push_back(output[i].second);
		}

		return ans;
    }
};