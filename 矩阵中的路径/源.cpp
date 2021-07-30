#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param matrix char字符型vector<vector<>>
     * @param word string字符串
     * @return bool布尔型
     */
    bool hasPath(vector<vector<char> >& matrix, string word) {
        // write code here
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (dfs(matrix, word, i, j, 0)) { return true; }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& matrix, string word, int i, int j, int q) {
        if (i >= matrix.size() || i < 0 || j < 0 || j >= matrix[0].size() || word[q] != matrix[i][j])
        {
            return false;
        }
        if (q == word.size() - 1)
        {
            return true;
        }
        matrix[i][j] = '\0';
        bool ans = dfs(matrix, word, i + 1, j, q + 1) || dfs(matrix, word, i, j + 1, q + 1) || dfs(matrix, word, i - 1, j, q + 1) || dfs(matrix, word, i, j - 1, q + 1);
        matrix[i][j] = word[q];
        return ans;
    }
};
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
private:
    int rows, cols;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        if (i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k]) return false;
        if (k == word.size() - 1) return true;
        board[i][j] = '\0';
        bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) ||
            dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);
        board[i][j] = word[k];
        return res;
    }
};
