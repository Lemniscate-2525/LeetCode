class Solution {
public:

 // no of subarrays with sum exactly goal = no of subarrays with sum at msot goal - no of subarrays with sum at most goal - 1

    long long atmostk(vector<int>& arr, int k) {

        if(k < 0) return 0; // subarr is binary so target goal/sum can never be negative. 

        int n = arr.size();

        long long scnt = 0;
        int s = 0;

        int l = 0;
        int r = 0;

        while(r < n) {

            s += arr[r];

            while(s > k) {

                s -= arr[l];
                l++;

            }

            scnt += (r-l+1);
            r++;

        }

        return scnt;
    }

    int numSubarraysWithSum(vector<int>& arr, int goal) {

        return atmostk(arr, goal) - atmostk(arr, goal-1);

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna