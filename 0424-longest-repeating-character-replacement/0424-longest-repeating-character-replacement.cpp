class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size(); 

        int l = 0;
        int r = 0;

        vector<int> f(26, 0);

        int mf = 0;
        int max_len = 0;

        while(r < n) {

            f[s[r] - 'A']++;

            mf = max(mf, f[s[r] - 'A']);

            while((r-l+1) - mf > k) {
                f[s[l] - 'A']--;
                l++;
            }

            max_len = max(max_len, r-l+1);
            r++;
        }

        return max_len;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna