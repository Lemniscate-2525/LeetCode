class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {

        int n = arr.size();

        int ps = 0;
        int ans = 0;

        unordered_map<int, int> mpp; // sum,freq.
        mpp[0] = 1; // sum zero appears once before even starting the ps. 

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