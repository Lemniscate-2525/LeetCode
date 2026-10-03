class Solution {
public: // exactly k odd numbers

//no of subarr having exactly k odd nos = no of subarr having atmost k odd nos(<= k) - no of subarr having at most k-1 odd nos.(< k)

    bool isodd(int m) {

        if(m % 2 == 1) return true;
        else return false;

    }

    long long EK(vector<int>& arr, int k) {

        int n = arr.size();

        int l = 0;
        int r = 0;

        int cnt_odd = 0;

        long long scnt = 0;

        while(r < n) {

            if(isodd(arr[r])) cnt_odd++;

            while(cnt_odd > k) {

                if(isodd(arr[l])) cnt_odd--; // left pointer will move forward anyway to trim/shrink the window, but cnt of odd nos will be reduced only if the boundary elem at arr[l] will be an odd elem.
                l++;

            }

            scnt += (r-l+1);
            r++;
        }

        return scnt;
    }

    int numberOfSubarrays(vector<int>& arr, int k) {
        
        return EK(arr, k) - EK(arr, k-1);

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna