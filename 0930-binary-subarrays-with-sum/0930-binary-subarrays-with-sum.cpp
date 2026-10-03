class Solution {
public:

 // no of subarrays with sum exactly goal = no of subarrays with sum at msot goal - no of subarrays with sum at most goal - 1

    int atmostk(vector<int>& arr, int k) {

        if(k < 0) return 0;

        int n = arr.size();

        int maxcnt = 0;
        int s = 0;

        int l = 0;
        int r = 0;

        while(r < n) {

            s += arr[r];

            while(s > k) {

                s -= arr[l];
                l++;

            }

            maxcnt += (r-l+1);
            r++;

        }

        return maxcnt;
    }

    int numSubarraysWithSum(vector<int>& arr, int goal) {

        return atmostk(arr, goal) - atmostk(arr, goal-1);

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna