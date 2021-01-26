/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int **NumofPaths;
    int uniquePaths(int m, int n) {
        NumofPaths = new int *[m];
        for (int i = 0; i < m; i++)
        {
            NumofPaths[i] = new int [n];
            for (int j = 0; j < n; j++)
            {
                NumofPaths[i][j] = 0;
            }
        }
        NumofPaths[m - 1][n - 1] = 1;
        int Path_Num = CountPaths(0, 0, m, n);
        for (int i = 0; i < m; i++)
        {
            delete [] NumofPaths[i];
        }
        delete [] NumofPaths;
        return Path_Num;
    }
    int CountPaths(int x, int y, int m, int n)
    {
        if (x >= m || y >= n)
        {
            return 0;
        }
        if (NumofPaths[x][y] != 0)
        {
            return NumofPaths[x][y];
        }
        NumofPaths[x][y] = CountPaths(x + 1, y, m, n) + CountPaths(x, y + 1, m, n);
        return NumofPaths[x][y];
    }
};
// @lc code=end

