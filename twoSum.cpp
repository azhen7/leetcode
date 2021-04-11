#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
            vector<int> ans(2);
            ans.clear();
            int first_num = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                first_num = nums[i];
                for (int j = i + 1; j < nums.size(); j++)
                {
                    if (first_num + nums[j] == target)
                    {
                        ans.push_back(i);
                        ans.push_back(j);
                        break;
                    }
                }
            }
            return ans;
        }
};
