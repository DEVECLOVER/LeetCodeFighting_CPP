/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
//两种思路 
//是否允许排序  排序之后采用二分查找和双指针算法均可以
//是否允许使用额外空间  与上述比较，就是空间换时间
    void Merge(vector<int>& nums,int start,int mid,int end)
    {
        int left = start;
        int right = mid + 1;
        int index = start;
        int* tempnums = new int[end - start + 1];  //这个问题就是每次都得创建和销毁
        while(left <= mid && right <= end)
        {
            if(nums[left] <= nums[right])
            {
                tempnums[index++] = nums[left++];
            }
            else
            {
                tempnums[index++] = nums[right++];
            }
        }
        while(left <= mid)
        {
            tempnums[index++] = nums[left++];
        }
        while(right <= end)
        {
            tempnums[index++] = nums[right++];
        }
        index = 0;
        left = start;
        while(left <= end)
        {
            nums[left++] = tempnums[index++];
        }
        delete tempnums;
    }
    void MergeSort(vector<int>& nums,int start,int end)
    {
        if(start >= end)
        {
            return ;
        }
        int mid = (start + end) >> 1;
        MergeSort(nums,start,mid);
        MergeSort(nums,mid + 1,end);
        Merge(nums,start,mid,end);
    }
//【AC】
    vector<int> UglyCode(vector<int>& nums,int target)
    {
        unordered_map<int,int> mark;
        vector<int> result;
        int len = nums.size();
        for (int i = 0;i < len;++i)
        {
            mark[nums[i]] = i;
        }
        for(int i = 0;i < len;++i)
        {
            int gap = target - nums[i];
            //之所以加上后面的下标判断就是为了防止两个数相等的情况 比如 [3 2 4],target = 6 
            //如果不加下标判断 输出为[0 0]
            if(mark.find(gap) != mark.end() && mark[gap] > i)
            {
                result.push_back(i);
                result.push_back(mark[gap]);
                return result;
            }
        }
        return result;
    }
// 【AC】
    vector<int> GMT(vector<int>& nums,int target)
    {
        unordered_map<int,int> mark;
        vector<int> result;
        for(int i = 0;i < nums.size();++i)
        {
            int gap = target - nums[i];
            if(mark[gap])
            {
                result.push_back(mark[gap] - 1);
                result.push_back(i);
                return result;
            }
            mark[nums[i]] = i + 1;
        }
        return result;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        //return UglyCode(nums,target);
        return GMT(nums,target);
     }

};
// @lc code=end

