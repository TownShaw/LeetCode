/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    int numSquares(int n)
    {
        std::vector<int> DP(n + 1, -1);
        DP[0] = 0;
        DP[1] = 1;
        return MinSquare(n, DP);
    }

    int MinSquare(int n, std::vector<int> &DP)  //返回数字 n 的 Min_num_Square
    {
        if (DP[n] != -1)
        {
            return DP[n];
        }
        int less_Num = int(sqrt(n));    //平方小于 n 的最大整数, less_Num
        int Min = 10000;
        while (less_Num >= 1)
        {
            int count = MinSquare(n - less_Num * less_Num, DP) + 1;
            Min = (Min < count) ? Min : count;
            less_Num--;
        }
        DP[n] = Min;
        return Min;
    }
};
// @lc code=end

