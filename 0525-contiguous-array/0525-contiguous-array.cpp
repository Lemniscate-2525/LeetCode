class Solution {
public:
    int findMaxLength(vector<int>& arr) {

        int n = arr.size();
        unordered_map<int, int> mpp;

        mpp[0] = -1;

        int maxlen = 0;
        int sum = 0;

        for(int i=0; i<n; i++) {

            if(arr[i] == 0) sum--;
            if(arr[i] == 1) sum++;

            if(mpp.count(sum)) {

                maxlen = max(maxlen, i-mpp[sum]);

            } else {

            mpp[sum] = i;

            }
        }

    return maxlen;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna