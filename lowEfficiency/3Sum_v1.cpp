#include <vector>
#include <algorithm>

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int> &nums) 
        {
            vector<int> triple;
            vector<vector<int>> ans;
            triple.clear();
            
            if (nums.size() < 3)
                return ans;
            
            int num_1, num_2;
            for (int i = 0; i < nums.size(); i++)
            {
                num_1 = nums[i];
                for (int j = i + 1; j < nums.size(); j++)
                {
                    num_2 = nums[j];
                    for (int k = j + 1; k < nums.size(); k++)
                    {
                        if (num_1 + num_2 + nums[k] == 0)
                        {
                            triple.push_back(num_1);
                            triple.push_back(num_2);
                            triple.push_back(nums[k]);
                            sort(triple.begin(), triple.end());
                            if (find(ans.begin(), ans.end(), triple) == ans.end())
                                ans.push_back(triple);
                            triple.clear();
                        }
                    }
                }
            }
            return ans;
        }
};
