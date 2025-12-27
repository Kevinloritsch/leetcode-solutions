// Last updated: 12/27/2025, 3:45:04 PM
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1, -1);
        
        for(int i = 0; i < row.size(); ++i) {
            if(row[i] != -1) break;
            if(i == 0) {
                row[i] = 1;
                row[row.size() - 1] = 1;
                continue;
            }

            long calc = (long(row[i-1]) * rowIndex) / i;
            row[i] = int(calc);
            row[row.size() - i - 1] = row[i];
            rowIndex--;
        }

        return row;
    }
};