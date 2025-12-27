// Last updated: 12/27/2025, 3:44:35 PM
class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        const int DRAW = 0, MOUSE_WIN = 1, CAT_WIN = 2;
        const int MOUSE_TURN = 0, CAT_TURN = 1;
        
        // memo[mouse][cat][turn]: -1 = unknown, 0 = draw, 1 = mouse win, 2 = cat win
        vector<vector<vector<int>>> color(n, vector<vector<int>>(n, vector<int>(2, -1)));
        
        // Number of moves left to explore for each state
        vector<vector<vector<int>>> degree(n, vector<vector<int>>(n, vector<int>(2, 0)));
        
        // Calculate degrees
        for (int m = 0; m < n; m++) {
            for (int c = 0; c < n; c++) {
                degree[m][c][MOUSE_TURN] = graph[m].size();
                degree[m][c][CAT_TURN] = graph[c].size();
                for (int node : graph[c]) {
                    if (node == 0) {
                        degree[m][c][CAT_TURN]--;
                        break;
                    }
                }
            }
        }
        
        queue<tuple<int, int, int>> q;
        
        // Initialize winning states
        for (int c = 0; c < n; c++) {
            for (int t = 0; t < 2; t++) {
                color[0][c][t] = MOUSE_WIN;
                q.push({0, c, t});
                if (c > 0) {
                    color[c][c][t] = CAT_WIN;
                    q.push({c, c, t});
                }
            }
        }
        
        // BFS backwards from winning states
        while (!q.empty()) {
            auto [mouse, cat, turn] = q.front();
            q.pop();
            
            int currentColor = color[mouse][cat][turn];
            
            if (turn == MOUSE_TURN) {
                // Previous turn was cat's turn
                for (int prevCat : graph[cat]) {
                    if (prevCat == 0) continue;
                    
                    if (color[mouse][prevCat][CAT_TURN] != -1) continue;
                    
                    if (currentColor == CAT_WIN) {
                        color[mouse][prevCat][CAT_TURN] = CAT_WIN;
                        q.push({mouse, prevCat, CAT_TURN});
                    } else {
                        degree[mouse][prevCat][CAT_TURN]--;
                        if (degree[mouse][prevCat][CAT_TURN] == 0) {
                            color[mouse][prevCat][CAT_TURN] = MOUSE_WIN;
                            q.push({mouse, prevCat, CAT_TURN});
                        }
                    }
                }
            } else {
                // Previous turn was mouse's turn
                for (int prevMouse : graph[mouse]) {
                    if (color[prevMouse][cat][MOUSE_TURN] != -1) continue;
                    
                    if (currentColor == MOUSE_WIN) {
                        color[prevMouse][cat][MOUSE_TURN] = MOUSE_WIN;
                        q.push({prevMouse, cat, MOUSE_TURN});
                    } else {
                        degree[prevMouse][cat][MOUSE_TURN]--;
                        if (degree[prevMouse][cat][MOUSE_TURN] == 0) {
                            color[prevMouse][cat][MOUSE_TURN] = CAT_WIN;
                            q.push({prevMouse, cat, MOUSE_TURN});
                        }
                    }
                }
            }
        }
        
        return color[1][2][MOUSE_TURN] == -1 ? DRAW : color[1][2][MOUSE_TURN];
    }
};