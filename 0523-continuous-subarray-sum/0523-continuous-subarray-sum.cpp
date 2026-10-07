// Get the 1st occurrence, like when we get a valid ans boom, no need to go further; we find out sum and the rem, if we have that remainder some index before the current one, it means that the subarr in bw has sum def divisible by k.

// So, we check for it to be of length greater than equal to 2.

// If we don't find current rem in map that means it's occurred for the first time, so we store the index of it's occurrence along with the rem. 

class Solution {
public:
    bool checkSubarraySum(vector<int>& arr, int k) {
        
        int n = arr.size();
        int ps = 0;

        if(n < 2) return false;

        unordered_map<int, int> mpp; // remainder, first occurrence
        mpp[0] = -1; // remainder 0 will always be there even before arr starts so it's occ is at index -1. 

        for(int i=0; i<n; i++) {

            ps += arr[i];
            int rem = ps % k;

            if(mpp.count(rem)) {  

                if(i - mpp[rem] >= 2) return true; // len of subarr. 

            } else {

            mpp[rem] = i; // storing first occurrence of remainder. 

        }
    }

        return false;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna