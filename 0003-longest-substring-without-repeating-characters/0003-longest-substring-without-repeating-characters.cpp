class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        vector<int> f(256, -1);

        int l = 0;
        int r = 0;

        int maxlen = 0;

        while(r < n) {

            if(f[s[r]] != -1) {

                if(f[s[r]] >= l) {
                    l = f[s[r]] + 1;
                }
            }

            maxlen = max(maxlen, r-l+1);

            f[s[r]] = r;
            r++;

        }

        return maxlen;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna