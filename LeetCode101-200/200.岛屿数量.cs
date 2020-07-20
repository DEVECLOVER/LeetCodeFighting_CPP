/*
 * @lc app=leetcode.cn id=200 lang=csharp
 *
 * [200] 岛屿数量
 */

// @lc code=start
public class Solution {
        public  void DFSCalc(ref char[][] grid, int row, int col)
        {
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (k == 0 && l == 0)
                    {
                        continue;
                    }
                    if (k * l != 0)
                    {
                        continue;
                    }
                    if (k + row >= 0 && k + row < grid.Length && l + col >= 0 && l + col < grid[0].Length)
                    {
                        if (grid[k + row][l + col] > '0')
                        {
                            grid[row + k][col + l] = '0';
                            DFSCalc(ref grid, row + k, col + l);
                        }
                    }

                }
            }
        }
    public int NumIslands(char[][] grid) {
            int count = 0;
            for (int i = 0; i < grid.Length; i++)
            {
                for (int j = 0; j < grid[0].Length; j++)
                {
                    if (grid[i][j] > '0')
                    {
                        count++;
                        grid[i][j] = '0';
                        DFSCalc(ref grid, i, j);
                    }
                }
            }
            return count;


    }
}
// @lc code=end

