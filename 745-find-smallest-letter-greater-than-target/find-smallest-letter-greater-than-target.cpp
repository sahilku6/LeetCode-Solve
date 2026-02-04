class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int intCharTarget = (int)target;
        for (char ch : letters) {
            int char1 = (int)ch;
            if (char1 > intCharTarget) {
                return ch;
            }
        }
        return letters[0];
    }
};