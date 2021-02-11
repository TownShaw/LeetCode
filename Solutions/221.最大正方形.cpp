/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int min(int a, int b, int c)
    {
        if (a < b)
        {
            return (a > c) ? c : a;
        }
        return (b > c) ? c : b;
    }
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int Row_Max = matrix.size();
        int Column_Max = matrix[0].size();
        
        //存放以 (i, j) 为右下端点的最大正方形的边长
        vector<vector<int>> Edge_size(Row_Max, vector<int>(Column_Max, 0));
        int max_len = 0;
        for (int i = 0; i < Row_Max; i++)
        {
            for (int j = 0; j < Column_Max; j++)
            {
                if (matrix[i][j] == '0')
                {
                    Edge_size[i][j] = 0;
                    continue;
                }
                //matrix[i][j] == '1'

                //i == 0 || j == 0
                else if (i < 1 || j < 1)
                {
                    Edge_size[i][j] = 1;
                    max_len = (max_len == 0) ? 1 : max_len;
                    continue;
                }
                //i > 0 && j > 0
                else
                {
                /*
                    int len = Edge_size[i - 1][j - 1];
                    int row_temp = i;
                    int column_temp = j;
                    while (matrix[row_temp][j] == '1' && --row_temp >= 0);
                    while (matrix[i][column_temp] == '1' && --column_temp >= 0);
                    if (row_temp < i - len && column_temp < j - len)
                    {
                        Edge_size[i][j] = Edge_size[i - 1][j - 1] + 1;
                    }
                    else
                    {
                        int len = 1;
                        bool flag = true;
                        for ( ; i - len >= 0 && j - len >= 0; len++)
                        {
                            for (int row = i - len; row <= i; row++)
                            {
                                if (!flag)
                                {
                                    break;
                                }
                                flag = (matrix[row][j - len] == '1');
                            }
                            for (int column = j - len; column <= j; column++)
                            {
                                if (!flag)
                                {
                                    break;
                                }
                                flag = (matrix[i - len][column] == '1');
                            }
                            if (!flag)
                            {
                                break;
                            }
                        }
                        Edge_size[i][j] = len;
                    }
                */
                }
                // ?
                Edge_size[i][j] = min(Edge_size[i - 1][j - 1], Edge_size[i - 1][j], Edge_size[i][j - 1]) + 1;
                max_len = (max_len > Edge_size[i][j]) ? max_len : Edge_size[i][j];
            }
        }
        return max_len * max_len;
    }
};
// @lc code=end