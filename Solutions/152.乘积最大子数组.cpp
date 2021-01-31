/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> max_Product;    //max_Product[i] 存放以 nums[i] 结尾的最大子乘积数组结果
    int maxProduct(vector<int>& nums)
    {
        int max = nums[0];
        max_Product.clear();
        for (int i = 0; i < nums.size(); i++)
        {
            max_Product.push_back(nums[i]);
        }
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                if (nums[i] * max_Product[i - 1] > nums[i])
                {
                    max_Product[i] = nums[i] * max_Product[i - 1];
                }
                else
                {
                    max_Product[i] = nums[i];
                }
            }
            else
            {//nums[i] < 0, 向前找到第一个负数
                int j = i - 1;
                int may_max = nums[i];
                for (j = i - 1; j >= 0 && nums[j] >= 0; j--)
                {
                    may_max *= nums[j];
                }
                if (j < 0)
                {//没找到
                    max_Product[i] = nums[i];
                }
                else
                {
                    max_Product[i] = may_max * nums[j];
                    if (j - 1 >= 0 && max_Product[j - 1] > 0)
                    {//比如 [7, -5, -2]
                        max_Product[i] *= max_Product[j - 1];
                    }
                }
            }
            max = (max > max_Product[i]) ? max : max_Product[i];
        }
        return max;
    }
};
// @lc code=end

