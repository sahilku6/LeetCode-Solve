class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string res;
        
        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) res += "-";
        
        // Convert to long long to prevent overflow
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);
        
        // Integer part
        long long integerPart = n / d;
        res += to_string(integerPart);
        
        long long remainder = n % d;
        if (remainder == 0) return res; // No fractional part
        
        res += ".";
        
        // Map remainder -> position in result string
        unordered_map<long long, int> remainderMap;
        
        while (remainder) {
            if (remainderMap.count(remainder)) {
                // Insert '(' at the first occurrence of repeating remainder
                res.insert(remainderMap[remainder], "(");
                res += ")";
                break;
            }
            
            // Store remainder position
            remainderMap[remainder] = res.size();
            
            remainder *= 10;
            res += to_string(remainder / d);
            remainder %= d;
        }
        
        return res;
    }
};
