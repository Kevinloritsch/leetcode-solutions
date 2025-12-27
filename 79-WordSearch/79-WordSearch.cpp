// Last updated: 12/27/2025, 3:45:18 PM
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        char start = word[0];

        for(int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] == start) {
                    if(dfs(board, word, 0, i, j)) return true;
                }
            }
        }
        return false;
        
    }

    bool dfs(vector<vector<char>>& board, string& word, int pos, int i, int j) {
        if(pos == word.length() - 1) return true;

        char old = board[i][j];
        board[i][j] = '#';

        char next = word[pos+1];


        if(i > 0 && board[i - 1][j] == next) {
           if(dfs(board, word, pos+1, i-1, j)) {
            board[i][j] = old;
            return true;
           }
        }

        if(i + 1 < board.size() && board[i + 1][j] == next) {
            if(dfs(board, word, pos+1, i+1, j)) {
                board[i][j] = old;
                return true;
            }
        }

        if(j > 0 && board[i][j - 1] == next) {
            if(dfs(board, word, pos+1, i, j - 1)) {
                board[i][j] = old;
                return true;
            }
        }

        if(j + 1 < board[i].size() && board[i][j + 1] == next) {
            if(dfs(board, word, pos+1, i, j + 1)) {
                board[i][j] = old;
                return true;
            }
        }

        board[i][j] = old;

        return false;


    }

};