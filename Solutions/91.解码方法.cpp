/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> numofDecode;

    int numDecodings(string s)
    {
        numofDecode.clear();
        for (int i = 0; i < s.size(); i++)
        {
            numofDecode.push_back(0);
        }
        int Kind_Num = Decode(s, 0);
        return Kind_Num;
    }

    bool isCode(string &s, int begin, int length)
    {   // s[begin] --- s[begin + length - 1] 是否为一个编码
        if (s[begin] == '0' || begin + length > s.size())
        {
            return false;
        }
        int num = 0;
        for (int i = begin; i < begin + length; i++)
        {
            num = num * 10 + (s[i] - '0');
        }
        if (num <= 26)
        {
            return true;
        }
        return false;
    }

    int Decode(string &s, int begin)
    {
        if (begin >= s.size())
        {
            return 0;
        }
        if (numofDecode[begin] != 0)
        {
            return numofDecode[begin];
        }
        if (isCode(s, begin, 1))
        {
            numofDecode[begin] += Decode(s, begin + 1);
            if (begin + 1 == s.size())  //本身就是一种解码方式
            {
                numofDecode[begin]++;
            }
        }
        if (isCode(s, begin, 2))
        {
            numofDecode[begin] += Decode(s, begin + 2);
            if (begin + 2 == s.size())  //本身就是一种解码方式
            {
                numofDecode[begin]++;
            }
        }
        return numofDecode[begin];
    }
};
// @lc code=end

