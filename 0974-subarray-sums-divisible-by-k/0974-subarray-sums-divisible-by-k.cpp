class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        
        int n = arr.size();

        int sum = 0;
        int ans = 0;

        unordered_map<int, int> mpp; // freq map; (remainder, freq)
        mpp[0] = 1;

        for(int i=0; i<n; i++) {

            sum += arr[i];

            int rem = sum % k;

            if(rem < 0) rem += k;

            if(mpp.count(rem)) ans += mpp[rem];
            
            mpp[rem]++;

        }

        return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna