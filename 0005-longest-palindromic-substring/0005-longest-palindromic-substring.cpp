class Solution {
public:
    string longestPalindrome(string s) {

        string t = "^";

        for(char ch : s) {
            t += "#";
            t += ch;
        }

        t += "#$";

        int n = t.size();
        vector<int> p(n, 0);

        int r = 0;
        int c = 0;

        for(int i=1; i<n-1; i++) {

            int m = 2*c - i;

            if(i < r) p[i] = min(p[m], r-i);
    
            while(t[i + (p[i] + 1)] == t[i - (p[i] + 1)]) {
                p[i]++;
            }

            if(i + p[i] > r) {
                c = i;
                r = p[i] + i;
            }
        }

            int ml = 0;
            int cent = 0;

            for(int i=1; i<n-1; i++) {

                if(p[i] > ml) {
                    ml = p[i];
                    c = i;
                }
            }

        int start = (c - ml)/2;

        return s.substr(start, ml);
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna