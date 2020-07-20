/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
//二分查找  找右侧
    int BinarySearch(vector<char>& letters,char obj)
    {
        int left = 0;
        int right = letters.size() - 1;
        while(left <= right)   //  如何理解这个判断条件
        {
            int mid = left + ((right - left) >> 1);
            if(letters[mid] > obj)
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return right + 1;
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target < letters[0] || target >= letters.back())
            return letters[0];
        int index = BinarySearch(letters,target);
        return letters[index];
    }
};
// @lc code=end

