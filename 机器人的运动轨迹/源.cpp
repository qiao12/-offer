#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}
class Solution {

public:
    // 计算 x 的数位之和
    int get(int x) {
        int res = 0;
        for (; x; x /= 10) {
            res += x % 10;
        }
        return res;
    }

    int movingCount(int threshold, int rows, int cols) {
        int ans = 0;
        vector<vector<int>> matrix(rows, vector<int>(cols,-1));
        dfs(matrix, 0, 0, threshold, rows, cols, ans);
        return ans;
    };
    void dfs(vector<vector<int>>& matrix, int i, int j, int threshold, int row, int cols,int& ans ) {
        if (i >= row || j >= cols || i < 0 || j < 0 || get(i) + get(j) >= threshold || matrix[i][j] != -1  )
        {
            return;
        }
        ans += 1;
        matrix[i][j] = 0;
        dfs(matrix, i + 1, j, threshold, row, cols, ans);
        dfs(matrix, i, j + 1, threshold, row, cols, ans);
        //dfs(matrix, i - 1, j, threshold, row, cols, ans);
        //dfs(matrix, i, j - 1, threshold, row, cols, ans);
    }
};

class Solution {

public:
    // 计算 x 的数位之和
    int get(int x) {
        int res = 0;
        for (; x; x /= 10) {
            res += x % 10;
        }
        return res;
    }

    int movingCount(int threshold, int rows, int cols) {
        int ans = 0;
        vector<vector<int>> matrix(rows, vector<int>(cols,-1));
        dfs(matrix, 0, 0, threshold, rows, cols, ans);
        return ans;
    };
    void dfs(vector<vector<int>>& matrix, int i, int j, int threshold, int row, int cols,int& ans ) {
        if (i >= row || j >= cols || i < 0 || j < 0 || get(i) + get(j) >= threshold || matrix[i][j] != -1  )
        {
            return;
        }
        ans += 1;
        matrix[i][j] = 0;
        dfs(matrix, i + 1, j, threshold, row, cols, ans);
        dfs(matrix, i, j + 1, threshold, row, cols, ans);
        //dfs(matrix, i - 1, j, threshold, row, cols, ans);
        //dfs(matrix, i, j - 1, threshold, row, cols, ans);
    }
};
class Solution {
    // 计算 x 的数位之和
    int get(int x) {
        int res = 0;
        for (; x; x /= 10) {
            res += x % 10;
        }
        return res;
    }
public:
    int movingCount(int k, int m, int n) {
        if (!k) return 1;
        queue<pair<int, int> > Q;
        // 向右和向下的方向数组
        int dx[2] = { 0, 1 };
        int dy[2] = { 1, 0 };
        vector<vector<int> > vis(m, vector<int>(n, 0));
        Q.push(make_pair(0, 0));
        vis[0][0] = 1;
        int ans = 1;
        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();
            for (int i = 0; i < 2; ++i) {
                int tx = dx[i] + x;
                int ty = dy[i] + y;
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || get(tx) + get(ty) > k) continue;
                Q.push(make_pair(tx, ty));
                vis[tx][ty] = 1;
                ans++;
            }
        }
        return ans;
    }
};

