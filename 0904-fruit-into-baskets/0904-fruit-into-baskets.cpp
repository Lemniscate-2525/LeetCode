class Solution {
public:
    int totalFruit(vector<int>& arr) {
// longest continuous subarr with k distinct elements. 
        int n = arr.size();

        int l = 0;
        int r = 0;

        unordered_map<int, int> mpp;

        int d = 0;
        int maxlen = 0;

        while(r < n) {

            if(mpp[arr[r]] == 0) { // if elem is new then it's a distinct element, so we inc d.
                d++;
            }

            mpp[arr[r]]++; // new elem or not we inc the freq

            while(d > 2) { // if there are more than 2 distinct fruits then we need to trim/shorten our window from the left. 

                mpp[arr[l]]--;

                if(mpp[arr[l]] == 0) d--; // if during the process of shortening the window freq of some elem becomes 0, it means we have 1 less distinct element. 

                l++;

            }

        maxlen = max(maxlen, r-l+1);
        r++;

        }

        return maxlen;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna