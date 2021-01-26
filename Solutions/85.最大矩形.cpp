/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    struct Coor
    {   //以 Coor 为右下端点、内容全为 1、面积最大的矩形的左上端点坐标
        int X;
        int Y;
    };

    void pre_Process(vector<vector<char>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                matrix[i][j] -= '0';
            }
        }
    }
    
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        pre_Process(matrix);
        vector<vector<Coor>> Coordinate(row, vector<Coor>(col, {-1, -1}));
        int result = ComputeMaxArea(Coordinate, matrix, row - 1, col - 1);
        return result;
    }

    inline int get_Area(Coor &Pos, int x, int y)
    {
        if (Pos.X > x || Pos.Y > y)
        {
            return 0;
        }
        return (x - Pos.X + 1) * (y - Pos.Y + 1);
    }

    bool isRecTan(Coor &Pos, int x, int y)
    {
        return (Pos.X <= x && Pos.Y <= y);
    }

    int ComputeMaxArea(vector<vector<Coor>> &Coordinate, vector<vector<char>> &matrix, int x, int y)
    {   //返回矩阵 [0---x, 0---y] 中仅含 1 的矩形的最大面积
        int row = matrix.size();
        int col = matrix[0].size();
        if (x < 0 || y < 0 || x >= row || y >= col)
        {
            return 0;
        }
        if (Coordinate[x][y].X != -1 && Coordinate[x][y].Y != -1)
        {
            return get_Area(Coordinate[x][y], x, y);
        }
        if (matrix[x][y] == 0)
        {
            Coordinate[x][y].X = x + 1;
            Coordinate[x][y].Y = y + 1; //表示以当前为右下端点的、全为 1 的矩阵不存在
            int Area_1 = ComputeMaxArea(Coordinate, matrix, x - 1, y - 1);
            int Area_2 = ComputeMaxArea(Coordinate, matrix, x, y - 1);
            int Area_3 = ComputeMaxArea(Coordinate, matrix, x - 1, y);
            int max = (Area_1 > Area_2) ? Area_1 : Area_2;
            max = (max > Area_3) ? max : Area_3;
            return max;
        }
        else   // matrix[x][y] == 1
        {
            int sub_Area_1 = ComputeMaxArea(Coordinate, matrix, x - 1, y - 1);
            int sub_Area_2 = ComputeMaxArea(Coordinate, matrix, x, y - 1);
            int sub_Area_3 = ComputeMaxArea(Coordinate, matrix, x - 1, y);
            int Area_1 = 0;
            int Area_2 = 0;
            int Area_3 = 0;
            if (sub_Area_1 != 0)
            {
                bool edge_all_1 = true; //判断边缘是否都为 1
                if (isRecTan(Coordinate[x - 1][y - 1], x - 1, y - 1))
                {
                    for (int i = Coordinate[x - 1][y - 1].X; i <= x && edge_all_1; i++)
                    {
                        edge_all_1 = (matrix[i][y] == 1);
                    }
                    for (int j = Coordinate[x - 1][y - 1].Y; j <= y && edge_all_1; j++)
                    {
                        edge_all_1 = (matrix[x][j] == 1);
                    }
                    if (edge_all_1)
                    {
                        Area_1 = get_Area(Coordinate[x][y], x, y);
                    }
                }
            }
            else if (sub_Area_2 != 0)
            {
                bool edge_all_1 = true; //判断边缘是否都为 1
                if (isRecTan(Coordinate[x][y - 1], x, y - 1))
                {
                    for (int i = Coordinate[x][y - 1].X; i <= x && edge_all_1; i++)
                    {
                        edge_all_1 = (matrix[i][y] == 1);
                    }
                    if (edge_all_1)
                    {
                        Area_2 = get_Area(Coordinate[x][y], x, y);
                    }
                }
            }
            else if (sub_Area_3 != 0)
            {
                bool edge_all_1 = true; //判断边缘是否都为 1
                if (isRecTan(Coordinate[x - 1][y], x - 1, y))
                {
                    for (int j = Coordinate[x - 1][y].Y; j <= y && edge_all_1; j++)
                    {
                        edge_all_1 = (matrix[x][j] == 1);
                    }
                    if (edge_all_1)
                    {
                        Area_3 = get_Area(Coordinate[x][y], x, y);
                    }
                }
            }
            else
            {
                Coordinate[x][y].X = x;
                Coordinate[x][y].Y = y;
                return 1;
            }
            int max = 0;
            if (Area_1 > Area_2 && x >= 1 && y >= 1)
            {
                Coordinate[x][y].X = Coordinate[x - 1][y - 1].X;
                Coordinate[x][y].Y = Coordinate[x - 1][y - 1].Y;
                max = Area_1;
            }
            else if (y >= 1)
            {
                Coordinate[x][y].X = Coordinate[x][y - 1].X;
                Coordinate[x][y].Y = Coordinate[x][y - 1].Y;
                max = Area_2;
            }
            if (max < Area_3 && x >= 1)
            {
                Coordinate[x][y].X = Coordinate[x - 1][y].X;
                Coordinate[x][y].Y = Coordinate[x - 1][y].Y;
                max = Area_3;
            }
            return max;
        }
    }
};
// @lc code=end

