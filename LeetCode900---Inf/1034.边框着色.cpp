/*
 * @lc app=leetcode.cn id=1034 lang=cpp
 *
 * [1034] 边框着色
 */

// @lc code=start
class Solution {
public:
//如何对边界进行处理，下属做法还是很巧妙的，利用，方向数组越界
//只有中间节点，加上方向数组后不会产生越界
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int color1 = grid[r0][c0];
        if (color1 == color) return grid;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(grid), visit(m, vector<int>(n));
        visit[r0][c0] = 1;
        queue<pair<int, int>> qu; qu.push({r0, c0});
        while (!qu.empty()) 
        {
            int x = qu.front().first, y = qu.front().second;
            qu.pop();
            for (int i = 0; i < 4; ++i) 
            {
                int nx = dir[i][0] + x, ny = dir[i][1] + y;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == color1) 
                {
                    if (!visit[nx][ny]) 
                    {
                        visit[nx][ny] = 1; qu.push({nx, ny});
                    }
                }
                else 
                    res[x][y] = color;
            }
        }
        return res;

    }
};
// @lc code=end

