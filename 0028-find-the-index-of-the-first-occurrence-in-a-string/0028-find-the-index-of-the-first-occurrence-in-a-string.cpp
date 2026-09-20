class Solution {
public:
    int strStr(string h, string ned) {
        
        int n = h.size();
        int m = ned.size();

        int j = 0;

        for(int i=0; i<n; i++) {

            if(h[i] == ned[j]) {
                j++;
            } else {
                i = i - j;
                j = 0;
            }

            if(j == m) {
                return i - m + 1;
            }
        }

        return -1;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna