//
//  main.cpp
//  980. 不同路径 III
//
//  Created by SeacenLiu on 2019/3/30.
//  Copyright © 2019 成. All rights reserved.
//

/**
 在二维网格 grid 上，有 4 种类型的方格：
 
 1 表示起始方格。且只有一个起始方格。
 2 表示结束方格，且只有一个结束方格。
 0 表示我们可以走过的空方格。
 -1 表示我们无法跨越的障碍。
 返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目，
 每一个无障碍方格都要通过一次。
 
 示例 1：
 
 输入：[
 [1,0,0,0],
 [0,0,0,0],
 [0,0,2,-1]
 ]
 输出：2
 解释：我们有以下两条路径：
 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
 示例 2：
 
 输入：[
 [1,0,0,0],
 [0,0,0,0],
 [0,0,0,2]]
 输出：4
 解释：我们有以下四条路径：
 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
 示例 3：
 
 输入：[[0,1],[2,0]]
 输出：0
 解释：
 没有一条路能完全穿过每一个空的方格一次。
 请注意，起始和结束方格可以位于网格中的任意位置。
 
 
 提示：
 
 1 <= grid.length * grid[0].length <= 20
 */

/**
 - 减少空间占用
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int zeros = 0; // 0 的个数
        int x = 0, y = 0;
        bool flag = false;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) zeros++; // 计算 0 的个数
                else if (grid[i][j] == 1) {
                    x = i; // 记录起点横坐标
                    y = j; // 记录起点纵坐标
                    flag = true;
                }
            }
        }
        if (flag == false)
            return 0;
        return helper(grid, x, y, zeros, 0); // helper(网格，起点横坐标，起点纵坐标，0 的个数，走过的 0 的个数)
    }
    
    int helper(vector<vector<int>> grid, int x, int y, int zeros, int n) {
        int up = 0, down = 0, left = 0, right = 0;
        
        if (grid[x][y] == 2) {
            return zeros == n - 1 ? 1 : 0; // 如果所有 0 都走过，此路可行，记 1 次
        }
        
        grid[x][y] = 1; // 标记当前位置已经走过
        
        if (x != 0 && (grid[x - 1][y] == 0 || grid[x - 1][y] == 2)) {
            up = helper(grid, x - 1, y, zeros, n + 1);
        }
        if (x != grid.size() - 1 && (grid[x + 1][y] == 0 || grid[x + 1][y] == 2)) {
            down = helper(grid, x + 1, y, zeros, n + 1);
        }
        if (y != 0 && (grid[x][y - 1] == 0 || grid[x][y - 1] == 2)) {
            left = helper(grid, x, y - 1, zeros, n + 1);
        }
        if (y != grid[0].size() - 1 && (grid[x][y + 1] == 0 || grid[x][y + 1] == 2)) {
            right = helper(grid, x, y + 1, zeros, n + 1);
        }
        
        grid[x][y] = 0; // 将当前位置标记为没走过
        
        return up + down + left + right;
    }
};

class Solution1 {
private:
    int res;
    bool checkComplete(vector<vector<bool>>& visited, vector<vector<int>>& grid) {
        int m = (int)visited.size(), n = (int)visited[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j] == false && grid[i][j] == 0)
                    return false;
            }
        }
        return true;
    }
    void f(int i, int j, vector<vector<bool>> visited , vector<vector<int>>& grid) {
        int m = (int)visited.size(), n = (int)visited[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;
        if (visited[i][j])
            return;
        visited[i][j] = true;
        if (grid[i][j] == -1)
            return;
        if (grid[i][j] == 2 && checkComplete(visited, grid)) {
            res += 1;
            return;
        }
        f(i-1, j, visited, grid);
        f(i, j-1, visited, grid);
        f(i+1, j, visited, grid);
        f(i, j+1, visited, grid);
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = (int)grid.size(), n = (int)grid[0].size();
        res = 0;
        int i = 0, j = 0;
        bool flag = false;
        for (; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag == false)
            return 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        f(i, j, visited, grid);
        return res;
    }
};

void test(vector<vector<int>>& grid) {
    cout << "-------------------------------" << endl;
    for (auto arr: grid) {
        for (auto v: arr) {
            cout << v << " ";
        }
        cout << endl;
    }
    Solution sol = Solution();
    cout << sol.uniquePathsIII(grid) << endl;
    cout << "-------------------------------" << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    vector<int> a1 = {1,0,0,0};
    vector<int> a2 = {0,0,0,0};
    vector<int> a3 = {0,0,2,-1};
    vector<vector<int>> a = {a1,a2,a3};
    test(a);
    
    vector<int> b1 = {1,0,0,0};
    vector<int> b2 = {0,0,0,0};
    vector<int> b3 = {0,0,0,2};
    vector<vector<int>> b = {b1,b2,b3};
    test(b);
    
    vector<int> c1 = {0,1};
    vector<int> c2 = {2,0};
    vector<vector<int>> c = {c1,c2};
    test(c);
    
    vector<int> d1 = {1,0};
    vector<vector<int>> d = {d1};
    test(d);
    
    vector<int> e1 = {};
    vector<vector<int>> e = {e1};
    test(e);
    
    vector<int> f1 = {0,0};
    vector<int> f2 = {2,0};
    vector<vector<int>> f = {f1,f2};
    test(f);
    
    return 0;
}
