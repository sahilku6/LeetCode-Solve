class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;

        // Handle sign
        if ((numerator < 0) ^ (denominator < 0))
            result += "-";

        // Work with positive values using long long
        long long absNumerator = llabs((long long)numerator);
        long long absDenominator = llabs((long long)denominator);

        // Integer part
        long long intDiv = absNumerator / absDenominator;
        result += to_string(intDiv);

        long long remain = absNumerator % absDenominator;
        if (remain == 0) return result;

        result += ".";
        unordered_map<long long, int> mp;  // remainder → index

        while (remain != 0) {
            if (mp.count(remain)) {
                result.insert(mp[remain], "(");
                result += ")";
                break;
            }

            mp[remain] = result.length();

            remain *= 10;
            int digit = remain / absDenominator;
            result += to_string(digit);
            remain %= absDenominator;
        }

        return result;
    }
};
