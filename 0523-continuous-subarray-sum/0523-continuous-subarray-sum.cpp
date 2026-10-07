class Solution {
public:
    bool checkSubarraySum(vector<int>& arr, int k) {
        
        int n = arr.size();
        int ps = 0;

        if(n<2) return false;

        unordered_map<int, int> mpp; // remainder, first occurrence
        mpp[0] = -1;

        for(int i=0; i<n; i++) {

            ps += arr[i];
            int rem = ps % k;

            if(mpp.count(rem)) {
                
                if(i - mpp[rem] >= 2) return true;

            } else {

            mpp[rem] = i; // 

        }
    }

        return false;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna