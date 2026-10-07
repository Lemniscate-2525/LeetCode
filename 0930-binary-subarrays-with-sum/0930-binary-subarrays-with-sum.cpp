class Solution {
public:
    int numSubarraysWithSum(vector<int>& arr, int k) {

        int n = arr.size();

        unordered_map<int, int> mpp; 
        mpp[0] = 1;

        int ps = 0;
        int ans = 0;

        for(int i=0; i<n; i++) {

            ps += arr[i];

            int need = ps - k;

            if(mpp.count(need)) {
                ans += mpp[need];
            }

            mpp[ps]++;
        }

        return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna