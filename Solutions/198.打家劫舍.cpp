/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> profit;

    int rob(vector<int>& nums)
    {
        profit.clear();
        int Num_of_Home = nums.size();
        for (int i = 0; i < Num_of_Home; i++)
        {
            profit.push_back(-1);
        }
        int max = (robFrom_i(nums, 0) > robFrom_i(nums, 1)) ? robFrom_i(nums, 0) : robFrom_i(nums, 1);
        return max;
    }

    //偷 idx 家能取得的最高收益
    int robFrom_i(vector<int> &nums, int idx)
    {
        int Num_of_Home = nums.size();
        if (idx >= Num_of_Home)
        {
            return 0;
        }
        if (idx == Num_of_Home - 1 || idx == Num_of_Home - 2)
        {   //最后两家之一, 直接偷
            profit[idx] = nums[idx];
            return nums[idx];
        }
        if (profit[idx] != -1)
        {
            return profit[idx];
        }
        int pro_1 = nums[idx] + robFrom_i(nums, idx + 2);
        int pro_2 = nums[idx] + robFrom_i(nums, idx + 3);
        profit[idx] = (pro_1 > pro_2) ? pro_1 : pro_2;
        return profit[idx];
    }
};
// @lc code=end

