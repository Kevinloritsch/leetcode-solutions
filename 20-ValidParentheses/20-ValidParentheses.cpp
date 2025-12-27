// Last updated: 12/27/2025, 3:45:31 PM
class Solution {
public:
    bool isValid(string s) {

        stack<char> valid;
        for(auto& c : s) {
            if(c == '(' || c == '{' || c == '[') valid.push(c);

            else if(!valid.empty() && ((c == ')' && valid.top() == '(') || (c == '}' && valid.top() == '{') || (c == ']' && valid.top() == '['))) {
                valid.pop();
            }

            else return false;
        }
        return valid.empty();
    }
};