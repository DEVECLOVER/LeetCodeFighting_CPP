/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
//题解中的方法，自己连题目都没读懂
// 【AC】
    string Test(string path)
    {
        path += "/";
        stack<string> st;
        string dir;
        for (auto c : path) {
            // 以 / 为分隔符
            if (c == '/') {
                // 切换上一集目录
                if (dir == ".." && !st.empty()) {
                    st.pop();
                } 
                // 上一个 '/' 到 下一个 '/'
                else if (dir != ".." && dir != "." && !dir.empty()) {
                    st.push(dir);
                }
                dir.clear();
            } else {
                dir += c;
            }
        }

        // 遍历栈
        string result;
        while (!st.empty()) {
            string s = st.top();
            st.pop();
            result = "/" + s + result;
        }
        if(result.empty()) result = "/";
        return result;
     }
    string simplifyPath(string path) {
        return Test(path);
    }
};
// @lc code=end

