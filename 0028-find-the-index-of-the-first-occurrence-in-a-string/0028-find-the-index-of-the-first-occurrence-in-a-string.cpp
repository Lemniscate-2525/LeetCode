class Solution {
public:
    int strStr(string h, string nee) {

        int n = h.size();
        int m = nee.size();

        if(m == 0) return 0;

        vector<int> lps(m, 0);

        int i = 1;
        int len = 0;

        while(i < m) {  // for loop won't work here as we need i++ only in case 3. 

            if(nee[i] == nee[len]) {
                lps[i] = len + 1;
                i++;
                len++;

            } else {

                if(len != 0){
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        i = 0;
        int j = 0;

        while(i < n) {

            if(h[i] == nee[j]) {
                i++;
                j++;
            }

            if(j == m) return i-j;

            else if(i < n && h[i] != nee[j]) {

                if(j != 0) {
                    j = lps[j-1];
                } else {
                    i++;
                }
            }
        }

        return -1;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna