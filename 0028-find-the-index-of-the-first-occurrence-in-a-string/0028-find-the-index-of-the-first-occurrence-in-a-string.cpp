class Solution {
public:
    int strStr(string h, string ned) {
        
        int n = h.size();
        int m = ned.size();

        int j = 0;

        for(int i=0; i<n; i++) {

            if(h[i] == ned[j]) {
                j++; // keep inc needle if equal char are being found
            } else {
                i = i - j;  // if not, then change/update new start ie. i to i-j.
                j = 0; // update start of needle ie. j back to 0. 
            }

            if(j == m) { // if j reaches length of needle then we return index of first occurrence of needle. 
                return i - m + 1;
            }
        }

        return -1;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna