class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int x = pow(i, 2);
                int y = pow(j, 2);
                for (int k = 1; k <= n; k++) {
                    int z = pow(k, 2);
                    if ((x + y) == z)
                        count++;
                }
            }
        }
        return count;
    }
};