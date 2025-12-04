class Solution {
public:
    int countCollisions(string directions) {
        int i = 0;
        int n = directions.size();
        int j = n - 1;
        int ans = 0;
        while (i < n && directions[i] == 'L')
            i++;
        while (j >= 0 && directions[j] == 'R')
            j--;
        while (i <= j) {
            /*
            if (directions[i] == 'L' || directions[i] == 'R')
                ans++;
            */
            // or
            if (directions[i] != 'S')
                ans++;
            i++;
        }
        return ans;
    }
};