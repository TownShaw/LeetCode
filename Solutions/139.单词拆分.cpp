/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<char> can_Split; // 0 代表未定义, 1 代表 false, 2 代表 true
    bool wordBreak(string s, vector<string>& wordDict)
    {
        can_Split.clear();
        for (int i = 0; i < s.size(); i++)
        {
            can_Split.push_back(char(0));
        }
        return Match(s, 0, wordDict);
    }

    inline bool Convert_to_bool(char kind)
    {
        return (kind == char(2));
    }

    inline char Convert_to_char(bool kind)
    {
        return (kind ? char(2) : char(1));
    }

    bool Match(string &s, int index, vector<string> &wordDict)
    {// 从 s[index] 开始判断是否能被拆分为 wordDict 中的单词
        if (index >= s.size())
        {
            return true;
        }
        if (can_Split[index] != 0)
        {
            return Convert_to_bool(can_Split[index]);
        }
        bool matched = false;
        for (string &word : wordDict)
        {
            if (s.substr(index, word.size()) == word)
            {
                matched = Match(s, index + word.size(), wordDict);
                if (matched)
                {//一旦后续 string 也能匹配, 则直接返回 true, 否则继续下一轮判断
                    break;
                }
            }
        }
        can_Split[index] = Convert_to_char(matched);
        return matched;
    }
};
// @lc code=end

