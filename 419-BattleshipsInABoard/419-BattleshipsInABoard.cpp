// Last updated: 12/27/2025, 3:44:49 PM
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {

        int counter = 0;

        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'X') {
                    counter++;
                    destroyBattleship(board, i, j);
                }
            }
        }

        return counter;
    }

    void destroyBattleship(vector<vector<char>>& board, int m, int n) {

        if(m < 0 || m > board.size() - 1) return;
        if(n < 0 || n > board[m].size() - 1) return;
        if(board[m][n] == '.') return;

        board[m][n] = '.';
        destroyBattleship(board, m-1, n);
        destroyBattleship(board, m+1, n);
        destroyBattleship(board, m, n-1);
        destroyBattleship(board, m, n+1);
    }
};