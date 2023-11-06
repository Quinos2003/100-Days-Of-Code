class Solution {
public:
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isValid(int i, int j, int m, int n) {
    return i >= 0 && j >= 0 && i < m && j < n;
}

bool dfs(vector<vector<char> > &board, int i, int j, string &word, int wordInd, vector<vector<int> > &vis) {
    int m = board.size();
    int n = board[0].size();

    if (wordInd == word.size()) return true;
    
    for (int z = 0; z < 4; z++) {
        int nrow = i + dx[z];
        int ncol = j + dy[z];

        if (isValid(nrow, ncol, m, n) && board[nrow][ncol] == word[wordInd] && !vis[nrow][ncol]) {
            vis[nrow][ncol] = 1;
            if (dfs(board, nrow, ncol, word, wordInd + 1, vis)) {
                return true;
            }
            vis[nrow][ncol] = 0;  // Backtrack
        }
    }

    return false;
}

    bool exist(vector<vector<char> > &board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int> > vis(m, vector<int>(n, 0));
                    vis[i][j] = 1;
                    if (dfs(board, i, j, word, 1, vis)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
