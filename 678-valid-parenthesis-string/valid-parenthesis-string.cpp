class Solution {
public:
    bool checkValidString(string s) {
        stack<char> stk;
        int minC = 0, maxC = 0;
        for (char c : s) {
            if (c == ')') {
                if (minC)
                    minC--;
                maxC--;
            } else if (c == '(') {
                minC++;
                maxC++;
            } else {
                if (minC)
                    minC--;
                maxC++;
            }
            if (maxC < 0)
                return false;
        }
        return minC == 0;
    }
};