class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int size=temperatures.size();
        vector<int> result(size,0); 
        stack<pair<int,int>> st;
        for(int i=0;i<size;i++)
        {
            while(!st.empty() && temperatures[i] > st.top().first)
            {
                int pre=st.top().second;
                result[pre] = i - pre;
                st.pop();
            }
            st.push({temperatures[i], i});
        } 
        return result;       
    }
};