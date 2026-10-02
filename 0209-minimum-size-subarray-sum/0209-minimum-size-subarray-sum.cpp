class Solution {
public:
    int minSubArrayLen(int k, vector<int>& arr) {
        
        int n = arr.size();

        int l = 0;
        int r = 0;

        int tar = k;
        int sum = 0;

        int minlen = INT_MAX;

        while(r < n) {

            if(arr[r] == k) return 1;

            sum += arr[r];
           
            while(sum >= k) { // shrink when valid, usually opposite to what we do because we want a smaller window, so we shrink in search of a smaller window still satisfying constraints.

                minlen = min(minlen, r-l+1);
                sum -= arr[l];
                l++;

            }
            r++;
        }

        return minlen == INT_MAX ? 0 : minlen;  // if by chance minm length dosen't get updated from INT_MAX it means we don't have a valid sum upto our target here, so we return 0, else we return the obtained val of minlen.

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna