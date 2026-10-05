class Solution {
public:
    vector<int> runningSum(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> pref(n);

        pref[0] = arr[0];

        for(int i=1; i<n; i++) {

            pref[i] = pref[i-1] + arr[i];

        }

        return pref;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna