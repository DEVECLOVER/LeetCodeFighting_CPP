/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

// @lc code=start
class Solution {
public:
//第一遍的UglyCode
    bool UglyCode(string s)
    {
        bool issign = false;
        bool isexp = false;
        bool isdot = false;
        bool num = false;
        int len = s.size();
        for(int i = 0;i < len;++i)
        {
            if(s[i] == ' ')
                continue;
            if(s[i] == '-' || s[i] == '+')
            {
                if(issign && !isexp)
                    return false;
                issign = true;
            }
            else if(s[i] == 'e')
            {
                if(!num)
                    return false;
                if(i == len - 1 || isexp)
                    return false;
                isexp = true;
            }
            else if(s[i] == '.')
            {
                if(isdot || isexp)
                    return false;
                isdot = true;
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                num = true;
            }
            else
            {
                return false;
            }
        }
        return num;
    }
    bool IsNum(string s)
    {
        int len = s.size();
        if(len < 1)
            return false;
        int index = 0;
        while(s[index] == ' ' && index < len)
            ++index;
        if(index == len)
            return false;
        while (s[--len] == ' ');
        bool isdot = false;
        bool isexp = false;
        bool issign = false;
        if(s[index] == '+' || s[index] == '-')
        {
            issign = true;
            ++index;
        }
        for(int i = index;i <= len;++i)
        {
            if(s[i] == '-' || s[i] == '+')
            {
                if(issign && s[i - 1] != 'e')
                    return false;
                issign = true;
            }
            else if(s[i] == 'e')
            {
                if(i == index || i == len || isexp)
                    return false; 
                isexp = true;
            }
            else if(s[i] == '.')
            {
                if(isdot || isexp || index == len)
                    return false;
                isdot = true;
            }
            else if(s[i] < '0' || s[i] > '9')
                return false;
        }
        return true;
    }
// 【AC】  思路很清晰，十分值得借鉴
    bool Test(string s)
    {
        if (s.empty()) return false;
        int left = 0, right = s.size() - 1;
        // skip whitespaces in the begining
        while (left < s.size() && s[left] == ' ') left++;
        // if all characters are whitespace, just return false
        if (left == s.size()) return false;
        // skip whitespaces in the end
        while (right >= 0 && s[right] == ' ') right--;

        // skip + or - sign if has
        if (s[left] == '+' || s[left] == '-') left++;

        bool has_exponent = false;
        bool has_decimal_point = false;

        for (int i = left; i <= right;) {
            char c = s[i];
            if (c == 'e') {
                // if has exponent before, just return false
                if (has_exponent || i == left) return false;
                // skip + or - sign after exponent if has
                if (s[i + 1] == '+' || s[i + 1] == '-') i++;
                // after skip + or -, if e is last character, return false
                // eg: 10e, 10e+
                if (i == right) return false;
                has_exponent = true;
            }
            else if (c == '.') {
                // if it has decimal point or exponent before, return false
                if (has_decimal_point || has_exponent) return false;
                // case: "."
                if (left == right) return false;
                // if 'e' comes after decimal point, there should be atleast one digit before decimal point
                // eg: .e1 --> false, 1.e1 --> true
                if (s[i + 1] == 'e' && i == left) return false;
                has_decimal_point = true;
            } else if (!isdigit(c)) {
                return false;
            }

            i++;
	}

	return true;
    }
    bool isNumber(string s) {
        //return IsNum(s);
        return Test(s);
    }
};
// @lc code=end

