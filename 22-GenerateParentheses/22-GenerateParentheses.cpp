// Last updated: 12/27/2025, 3:45:29 PM
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string> solution;
        vector<string> temp;
        

    
        string a;
        int pow = 2;
        for(int i = 0; i < n*2; i++)
        {
            pow *= 2;
        }

        for(int i = 0; i < pow; ++i)
        {
            int t = i;
            temp.push_back("");
            //a.at(i).push_back((i%2 == 0)*'(' + (i%2 != 0) * ')');
            for(int j = 0; j < n*2; j++)
            {
                char c;
                if(t%2 == 0)
                {
                    c = '('; 
                }
                else{c = ')';}
                t /= 2;
                temp.at(i).push_back(c);
            }
            
        }
        for(int i = 0; i < temp.size()/2; i++)
        {
            int stack = 0;
            for(int j = 0; j < temp.at(i).size(); j++)
            {
                if(temp.at(i).at(j) == '(')
                {
                    stack++;
                }
                else{stack--;}
                if(stack < 0){break;}
            }
            if(stack == 0){solution.push_back(temp.at(i));}
        }
    return solution;
        
    }

    
};