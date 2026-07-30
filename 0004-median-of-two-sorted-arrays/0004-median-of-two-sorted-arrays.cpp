class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<double> arr;
        double median;
        for(int i=0;i<nums1.size();i++)
        {
            arr.push_back(nums1[i]);
        }       
        for(int i=0;i<nums2.size();i++)
        {
            arr.push_back(nums2[i]);
        }   
        sort(arr.begin(),arr.end());
        int s=arr.size();
        if(s%2==0)
        {
            int r=s/2;
            r--;
            median=(arr[r]+(arr[r+1]))/2;
            return median;
        }
        else
        {
            median=(s+1)/2;
            return arr[median-1];
        }
    }
};