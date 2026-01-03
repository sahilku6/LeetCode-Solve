class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1000000007;
        long long A = 6;  // 2-color pattern count
        long long B = 6;  // 3-color pattern count

        if (n == 1) {
            return (A + B) % MOD;
        }

        long long res = 0;
        for (int i = 1; i < n; i++) {
            long long newA = (3 * A + 2 * B) % MOD;
            long long newB = (2 * A + 2 * B) % MOD;
            res = (newA + newB) % MOD;
            A = newA;
            B = newB;
        }
        return res % MOD;
    }
};