/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int *Num = nullptr;     //爬上楼梯的方式个数
    int climbStairs(int n)
    {
        Num = new int [n];
        for (int i = 0; i < n; i++)
        {
            Num[i] = 0;
        }
        Num[n - 1] = 1;
        if (n >= 2)
        {
            Num[n - 2] = 2;
        }
        int NumofKinds = Count(0, n);
        delete [] Num;
        return NumofKinds;
    }

    int Count(int pos, int n)
    {
        if (pos >= n)
        {
            return 0;
        }
        if (Num[pos] != 0)
        {
            return Num[pos];
        }
        Num[pos] = Count(pos + 1, n) + Count(pos + 2, n);
        return Num[pos];
    }
};
// @lc code=end

