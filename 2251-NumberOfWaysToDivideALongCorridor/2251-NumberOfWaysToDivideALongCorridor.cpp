// Last updated: 12/27/2025, 3:44:10 PM
class Solution {
public:
    int numberOfWays(string corridor) {

        int seats = 0;
        int plants = 0;
        long long answer = 1;


        for(auto s : corridor) {
            if(s == 'S') ++seats;
            else if(seats == 2) ++plants;

            if(seats == 3) {
                answer = (answer * (plants + 1)) % (1000000007);
                seats = 1;
                plants = 0;
            }

        }

        if(seats != 2) return 0;

        return answer;
        
    }
};