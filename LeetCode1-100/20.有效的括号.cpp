/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
//可以改造成递归吗
    bool UglyCode(string s)
    {
        stack<char> container;
        if(s.size() < 1)
        {
            return true;
        }
        if (s.size() < 2)
		{
			return false;
		}
        for(int i= 0;i < s.size();++i)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                container.push(s[i]);
            }
            else
            {
                //关键点还有这个container的empty判断
                if(i == 0 || container.empty())
                {
                    return false;
                }
                if(s[i] == ')' && container.top() == '(')
                {
                    container.pop();
                }
                else if(s[i] == ']' && container.top() == '[')
                {
                    container.pop();
                }
                else if(s[i] == '}' && container.top() == '{')
                {
                    container.pop();
                }
                else
                {
                    //container.push(s[i]);//原本是这么写的
                    //关键在于什么呢？找到关键点 正确的可能情况与错误的情况，两相比较，
                    //取容易分析的那个判断  这就像概率论中从反面计算概率 或者数学证明中的反证法
                    //如果要是判断false的情况，那可能情况可就多了
                    return false;
                }
            }
        }
        // if(container.empty())
        // {
        //     return true;
        // }
        // return false;
        return container.empty(); // 将上述语句转换为这句话即可
    }
// [NAC]  想当然了，因为是三种不同的括号 (] 就应该是false。通过了70/76
// 所以，就得需要三种left和right了。
    bool DFS(string s,int index,int left,int right)
    {
        if(s[index] == '\0')
        {
            if(left == right)
                return true;
            else
            {
                return false;
            }
            
        }
        if(right > left)
            return false;
        if(s[index] == '(' || s[index] == '[' || s[index] == '{')
            return DFS(s,index + 1,left + 1,right);
        else
        {
            return DFS(s,index + 1,left,right + 1);
        }
    }
    bool isValid(string s) {
        //return DFS(s,0,0,0);
        return UglyCode(s);
    }
};
// @lc code=end

