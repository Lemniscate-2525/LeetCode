class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        
        int n = arr.size();

        int sum = 0;
        int ans = 0;

        unordered_map<int, int> mpp; // freq map; (remainder, freq)
        mpp[0] = 1; // if 0 is a remainder. 

        for(int i=0; i<n; i++) {

            sum += arr[i];

            int rem = sum % k;

            if(rem < 0) rem += k;

            if(mpp.count(rem)) ans += mpp[rem]; // if we find any remainder in the map equal to curr one, it means we got a valid subarr. 
            
            mpp[rem]++; // whenever we encounter remainder rem, either for the first time or for any other we inc it's freq in the map. 

        }

        return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna