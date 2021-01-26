/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
/*
        int max = -10000000;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                max = (max > sum) ? max : sum;
            }
        }
        return max;
*/

        int max = nums[0];
        int *dp = new int [nums.size()];
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i] = nums[i];
        }
        for (int i = 1; i < nums.size(); i++)
        {
            int larger = 0;
            if (dp[i - 1] + nums[i] > nums[i])
            {
                larger = dp[i - 1] + nums[i];
                dp[i] = dp[i - 1] + nums[i];
            }
            else
            {
                larger = nums[i];
            }
            max = (max > larger) ? max : larger;
        }
        return max;

/*
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums)
        {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
*/
    }
};
// @lc code=end

