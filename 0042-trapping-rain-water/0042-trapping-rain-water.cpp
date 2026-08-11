class Solution {
public:
    int trap(vector<int>& height) 
    {
        int size=height.size();
        int left=0;
        int right=size-1;
        int maxleft=0;
        int maxright=0;
        int trapped=0;
        if(size<2)
        {
            return 0;
        }       
        while(left<right)
        {
            if(height[left]<height[right])
            {
                if(maxleft<height[left])
                {
                    maxleft=height[left];
                }
                else 
                {
                    trapped += maxleft - height[left];
                }
                left++;
            }     
            else
            {
                if(maxright<height[right])
                {
                    maxright=height[right];
                }
                else 
                {
                    trapped += maxright - height[right];
                }
                right--;
            }   
            
        } 
        return trapped; 
    }
};