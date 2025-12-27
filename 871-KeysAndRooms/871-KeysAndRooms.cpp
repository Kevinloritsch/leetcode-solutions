// Last updated: 12/27/2025, 3:44:37 PM
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // each room has 3 states
        // -1, we know nothing
        // 0 we have been/can go

        vector<int> roomState(rooms.size(), 0);

        queue<int> toVisit;
        toVisit.push(0);
        roomState[0] = 1;

        while(!toVisit.empty()) {
            int top = toVisit.front();

            toVisit.pop();
            for(auto j : rooms[top]) {
                if(!roomState[j]) {
                    roomState[j] = 1;
                    toVisit.push(j);
                }
            }

        }

        for(auto i : roomState) if (i == 0) return false;
        return true;
    }
};