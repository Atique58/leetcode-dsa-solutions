class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string,vector<string>> mp;

        for(int x=0;x<strs.size();x++)
        {
            string key=strs[x];
            sort(key.begin(), key.end());
            mp[key].push_back(strs[x]);
        }

        vector<vector<string>> output;
        for(auto &i:mp)
        {
            output.push_back(i.second);
        }
        return output;
    }
};