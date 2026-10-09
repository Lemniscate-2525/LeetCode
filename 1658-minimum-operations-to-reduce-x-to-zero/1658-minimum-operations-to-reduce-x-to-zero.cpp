class Solution { 
public: // keep elem with sum ts-x. 
// len of longest subarr with sum ts-x.
    int minOperations(vector<int>& arr, int x) {

        int n = arr.size();

        if(arr[0] > x && arr[n-1] > x) return -1;
        if(arr[0] == x || arr[n-1] == x) return 1;

        int s = accumulate(arr.begin(), arr.end(), 0);
        int k = s - x;

        if(k < 0) return -1;
        if(k == 0) return n;

        int l = 0;
        int r = 0;

        int cs = 0;
        int maxlen = -1;

        while(r < n) {

            cs += arr[r];

            while(l <= r  && cs > k) {
                cs -= arr[l++];
            }

            if(cs == k) {
                maxlen = max(maxlen, r-l+1);
            }

            r++;
        }

        return maxlen == -1 ? -1 : n - maxlen;
   
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna