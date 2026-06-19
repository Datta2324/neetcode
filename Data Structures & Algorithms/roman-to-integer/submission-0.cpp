class Solution {
public:
    int val(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }

    int romanToInt(string s) {
        int sum = 0;

        for (int i = 0; i < s.size(); i++) {
            int curr = val(s[i]);

            if (i + 1 < s.size() && curr < val(s[i + 1]))
                sum -= curr;
            else
                sum += curr;
        }

        return sum;
    }
};