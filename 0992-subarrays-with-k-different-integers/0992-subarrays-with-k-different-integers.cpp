class Solution {
public:

    int atmostk(vector<int> & arr, int k){

        int n = arr.size();

        int maxlen = 0;

        int l = 0;
        int r = 0;

        int d = 0;

        unordered_map<int, int> mpp;

        while(r < n) {

            if(mpp[arr[r]] == 0) d++;

            mpp[arr[r]]++;

            while(d > k) {

                mpp[arr[l]]--;
                
                if(mpp[arr[l]] == 0) d--;

                l++;

            }

            maxlen += (r-l+1);
            r++;

        }

        return maxlen;

    }

    int subarraysWithKDistinct(vector<int>& arr, int k) {
        
        return atmostk(arr, k) - atmostk(arr, k-1);

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna