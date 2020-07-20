/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
public:
//[AC]
    int GMT(string v1,string v2)
    {
        int len1 = v1.size();
        int len2 = v2.size();
        int index1 = 0;
        int index2 = 0;
        while(index1 < len1 || index2 < len2)
        {
            string str1 = "";
            string str2 = "";
            while(index1 < len1 && v1[index1] != '.')
                str1 += v1[index1++];
            while(index2 < len2 && v2[index2] != '.')
                str2 += v2[index2++];
            int num1 = str1 == "" ? 0 : stol(str1);
            int num2 = str2 == "" ? 0 : stol(str2);
            if(num1 > num2)
                return 1;
            else if(num1 < num2)
                return -1;
            else
            {
                ++index1;
                ++index2;
            }
         }
         return 0;
    }
    int compareVersion(string version1, string version2) {
        return GMT(version1,version2);
    }
};
// @lc code=end

