class Solution {
public:
    double findMaxAverage(vector<int>& arr, int k) {
        
        int n = arr.size();

        int l = 0;
        int r = 0;

        double ma = INT_MIN;
        double sum = 0;

        while(r < n) {

            sum += arr[r];
            
            if(r-l+1 == k) {

                double avg = sum/k;
                ma = max(avg, ma);

                sum -= arr[l];
                l++;

                avg = 0;
            }

            r++;
     
        }

        return ma;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna