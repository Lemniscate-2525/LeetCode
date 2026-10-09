class Solution { 
public: // keep elem with sum ts-x. 
// len of longest subarr with sum ts-x.
    int minOperations(vector<int>& arr, int x) {

        int n = arr.size();

        int s = accumulate(arr.begin(), arr.end(), 0);
        int k = s - x;

        if(k < 0) return -1;
        if(k == 0) return n;

        unordered_map<int, int> mpp;
        mpp[0] = 0;

        int ps = 0;
        int maxlen = -1;

        for(int i=0; i<n; i++) {

            ps += arr[i];

            int need = ps - k;

            if(mpp.count(need)) {
                maxlen = max(maxlen, i + 1 - mpp[need]);
            }

            if(!mpp.count(ps)) {
                mpp[ps] = i + 1;
            }
        }

        return maxlen == -1 ? -1 : n - maxlen;
   
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna