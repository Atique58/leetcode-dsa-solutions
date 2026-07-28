class Solution {
public:
    int maxArea(vector<int>& height) 
	{
        int first = 0;
        int last = height.size() - 1;
        int max_area = 0;
		int area;

        while (first < last)
		{
            area=(last-first)*(min(height[first],height[last]));
			if(area>max_area)
			{
				max_area=area;
			}
			if(height[first]<height[last])
			{
				first++;
			}
			else
			{
				last--;
			}
		}
        return max_area;
    }
};