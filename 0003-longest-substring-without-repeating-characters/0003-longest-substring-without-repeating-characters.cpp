class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        vector<int> last_seen(256, -1);

        int l = 0;
        int r = 0;

        int maxlen = 0;

        while(r < n) {

            if(last_seen[s[r]] != -1) { // elem has been seen before. 

                if(last_seen[s[r]] >= l) {   // If elem seen before has been seen at index l or any index after l, it means we have a duplicate elem inside the same window which ain't allowed. So we update the window from the left, by moving one step forward from when we last saw the element. 
                    l = last_seen[s[r]] + 1;
                }                                              
            }

            maxlen = max(maxlen, r-l+1); // updating maxm length. 

            last_seen[s[r]] = r;        // elem never been seen before.
            r++; 
        }

        return maxlen;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna