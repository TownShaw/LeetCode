/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
#include <iostream>
#include <set>
#include <queue>
using namespace std;
class Solution {
private:

    std::priority_queue<int, vector<int>, greater<int>> pQ;
/*
    std::set<int> uglyNums;
*/
public:
    int nthUglyNumber(int n)
    {
    /*
        uglyNums.clear();
        uglyNums.insert(1);
        int UNum = 1;
        int count = 1;
        int i = 2;
        for ( ; count != n; i++)
        {
            if (isUglyNumber(i))
            {
                count++;
            }
        }
        return --i;
    */
    
        pQ.push(1);
        int Max = 1;
        int count = 1;
        while (true)
        {
            int temp = pQ.top();
            pQ.pop();
            std::cout << temp << ' ';
            pQ.push(temp * 2);
            Max = (Max > temp * 2) ? Max : temp * 2;
            if (++count == n)
            {
                break;
            }
            pQ.push(temp * 3);
            Max = (Max > temp * 3) ? Max : temp * 3;
            if (++count == n)
            {
                break;
            }
            pQ.push(temp * 5);
            Max = (Max > temp * 5) ? Max : temp * 5;
            if (++count == n)
            {
                break;
            }
        }
        
        return Max;
    
    }

    /*
    bool isUglyNumber(int Num)
    {
        if (uglyNums.find(Num / 2) != uglyNums.end() && Num % 2 == 0)
        {
            uglyNums.insert(Num);
            return true;
        }
        if (uglyNums.find(Num / 3) != uglyNums.end() && Num % 3 == 0)
        {
            uglyNums.insert(Num);
            return true;
        }
        if (uglyNums.find(Num / 5) != uglyNums.end() && Num % 5 == 0)
        {
            uglyNums.insert(Num);
            return true;
        }
        return false;
    }
    */
};
// @lc code=end

