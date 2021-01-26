/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int **MinPath;
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        MinPath = new int *[m];
        for (int i = 0; i < m; i++)
        {
            MinPath[i] = new int [n];
            for (int j = 0; j < n; j++)
            {
                MinPath[i][j] = -1;
            }
        }
        MinPath[m - 1][n - 1] = grid[m - 1][n - 1];
        int Min = ComputeMin(grid, 0, 0, m, n);
        for (int i = 0; i < m; i++)
        {
            delete [] MinPath[i];
        }
        delete [] MinPath;
        return Min;
    }
    int ComputeMin(vector<vector<int>> &grid, int x, int y, int m, int n)
    {
        if (x >= m || y >= n)
        {
            return 1000000;
        }
        if (MinPath[x][y] != -1)
        {
            return MinPath[x][y];
        }
        int Right_Min = grid[x][y] + ComputeMin(grid, x, y + 1, m, n);
        int Down_Min = grid[x][y] + ComputeMin(grid, x + 1, y, m, n);
        MinPath[x][y] = (Right_Min < Down_Min) ? Right_Min : Down_Min;
        return MinPath[x][y];
    }
};
// @lc code=end

