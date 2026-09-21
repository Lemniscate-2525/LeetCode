class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n = s.size();
        vector<int> lps(n, 0);

        int i = 1;
        int len = 0;

        while(i < n) {

            if(s[i] == s[len]) {
                lps[i] = len + 1;
                i++;
                len++;
            } else if(len != 0) {
                len = lps[len - 1];
            } else {
                i++;
            }
        }

    int l = n;
    int l1 = lps[n-1];

    int p = l - l1;

    if(l % p == 0 && (l/p) > 1) {
        return true;
    }

    return false;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna