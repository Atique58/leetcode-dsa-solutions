class Solution {

public:

    vector<vector<int>> threeSum(vector<int>& nums) 
    {

        vector<int> sum;

        vector<vector<int>> result;

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++)

        {

            if(nums[i]>0)

            {

                break;

            }

            if(i>0&&nums[i]==nums[i-1])

            {

                continue;

            }

            int first=i+1;

            int last=nums.size()-1;

            while(first<last)

            {

                if(nums[first]+nums[last]+nums[i]>0)

                {

                    last--;

                }

                else if(nums[first]+nums[last]+nums[i]<0)

                {

                    first++;

                }

                else

                {

                    sum={nums[first],nums[last],nums[i]};

                    result.push_back(sum);

                    last--;

                    first++;

                    while(first < last && nums[first] == nums[first - 1])

                    {

                        first++;

                    }

                    while(first < last && nums[last] == nums[last + 1])

                    {

                        last--;

                    }

                }

            }

        }

        return result;

    }

};
