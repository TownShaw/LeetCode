/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    std::vector<std::vector<int>> Costs;

    int minimumTotal(vector<vector<int>>& triangle)
    {
        Costs.clear();
        for (int i = 0; i < triangle.size(); i++)
        {
            Costs.push_back(vector<int>(0));
            for (int j = 0; j < triangle[i].size(); j++)
            {
                Costs[i].push_back(0);
            }
        }
        int Min_Cost = getCost(triangle, 0, 0, triangle.size());
        return Min_Cost;
    }

    int getCost(vector<vector<int>> &triangle, int x, int y, int x_edge)
    {//三角形坐标为 (x, y) 的点向下的最小路径和
        if (x >= x_edge)
        {
            return 0;
        }
        if (Costs[x][y] != 0)
        {
            return Costs[x][y];
        }
        int Cost_1 = getCost(triangle, x + 1, y, x_edge);
        int Cost_2 = getCost(triangle, x + 1, y + 1, x_edge);
        int Min_Cost = (Cost_1 < Cost_2) ? Cost_1 : Cost_2;
        Costs[x][y] = triangle[x][y] + Min_Cost;
        return Costs[x][y];
    }
};
// @lc code=end

