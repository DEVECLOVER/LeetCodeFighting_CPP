/*
 * @lc app=leetcode.cn id=282 lang=cpp
 *
 * [282] 给表达式添加运算符
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<string>& res,const int& target,string& num, int step, int last, long sum, string &str) {
        if (step == num.size()) {
            if (sum == target) res.push_back(str);
            return;
        }
        int originSize = str.size();
        for (int i = step; i < num.size(); i++) {
            string curS = num.substr(step, i - step + 1);
            long cur = stol(curS);
            if (step == 0) {
                str += curS;
                dfs(res,target,num, i+1, cur, cur, str);
                str.resize(originSize);
            } else {
                // +
                str += "+" + curS;
                dfs(res,target,num, i+1, cur, sum+cur, str);
                str.resize(originSize);
                // -
                str += "-" + curS;
                dfs(res,target,num, i+1, -cur, sum-cur, str);
                str.resize(originSize);
                // *
                str += "*" + curS;
                dfs(res,target,num, i+1, last*cur, sum-last+last*cur, str);
                str.resize(originSize);
            }
            if (cur == 0) break;
        }
    }
    void BackCore(const string& num,string& path,vector<string>& res,const int& target,long sum,long pre,int index)
    {
        if(index == num.size())
        {
            if(sum == target)
                res.push_back(path);
            return ;
        }
        int len = path.size();
        for(int i = index;i < num.size();++i)
        {
            string sval = num.substr(index,i - index + 1);
            //把stol写成了stoi
            long val = stol(sval);
            if(index == 0)
            {
                path += sval;
                BackCore(num,path,res,target,val,val,i + 1);
                path.resize(len);
            }
            else
            {
                //+
                path += ('+' + sval);
                BackCore(num,path,res,target,sum + val,val,i + 1);
                path.resize(len);
                //-
                path += ('-' + sval);
                BackCore(num,path,res,target,sum - val,-val,i + 1);
                path.resize(len);
                //*
                path += ('*' + sval);
                BackCore(num,path,res,target,sum - pre + val * pre,pre * val,i + 1);
                path.resize(len);

            }
            if(val == 0)
                return ;
        }
    }



    vector<string> addOperators(string num, int target) {
        vector<string> res;
        string path = "";
        BackCore(num,path,res,target,0,1,0);
        //dfs(res,target,num, 0, 0, 0, path);
        return res; 
    }
};
// @lc code=end

