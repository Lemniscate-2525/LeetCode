class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {

        int n = arr.size();
        unordered_map<int, int> mpp;

        mpp[0] = 1;

        int p = 0;
        int ans = 0;

        for(int i=0; i<n; i++) {

            p += arr[i];

            int need = p - k;

            if(mpp.count(need)) {
                ans += mpp[need];
            }

            mpp[p]++;
        }

        return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna