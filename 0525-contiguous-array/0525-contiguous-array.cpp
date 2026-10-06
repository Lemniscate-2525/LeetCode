class Solution {
public:
    int findMaxLength(vector<int>& arr) {

        int n = arr.size();
        unordered_map<int, int> mpp;

        mpp[0] = -1; // at index -1, ie before even starting we have balance. 

        int maxlen = 0;
        int sum = 0; // cumulative sum.

        for(int i=0; i<n; i++) {

            if(arr[i] == 0) sum--;
            if(arr[i] == 1) sum++;

            if(mpp.count(sum)) {  

                maxlen = max(maxlen, i-mpp[sum]); // if cumulative sum we've calculated till now occurs in the map, then maxlen will be updated. 
                
                // This means that from i(curr ind) till the index we get cumulative sum as the exact sum that we've calculated, then bw those indices the cnt of 0 and 1 is the same, hence we found a valid subarr and we update it's length. 

            } else {

            mpp[sum] = i; // if cumulative sum calculated till now has not been seen before then we don't have balance yet, so we store the sum at the respective index and move forward, hoping to see it later at some other index.  

            }
        }

    return maxlen;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna