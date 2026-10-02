class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        
        int n = arr.size();

        int l = 0;
        int r = 0;

        int maxlen = 0;
        int z = 0;

        while(r < n) {

            if(arr[r] == 0)  z++;

                while(z > k) {

                    if(arr[l] == 0) z--;
                    
                    l++;
                }

            maxlen = max(maxlen, r-l+1);
            r++;

        }

        return maxlen;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna