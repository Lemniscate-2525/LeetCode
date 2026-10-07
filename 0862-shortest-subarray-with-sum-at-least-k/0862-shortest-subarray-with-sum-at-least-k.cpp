class Solution {
public:
    int shortestSubarray(vector<int>& arr, int k) {

        int n = arr.size();

        deque<pair<int, long long>> dq;
        vector<int> ps(n+1, 0);

        for(int i=0; i<n; i++) {    // calc prefix sum. 
            ps[i+1] = ps[i] + arr[i];
        }

        int ans = n+1;

        for(int i=0; i<=n; i++) {

            while(!dq.empty() && ps[i] - dq.front().second >= k) {
                    // calc len of valid subarrays 
                ans = min(ans, i - dq.front().first);
                dq.pop_front(); // keep popping in hopes of finding a smaller valid subarray. 

            }

            while(!dq.empty() && dq.back().second >= ps[i]) {
                dq.pop_back();
                // popping/removing dominated elem as they won't contribute towards future answers; we want a smaller pref sum, if we get a smaller pref sum at i, it'll give us a higher chance of finding our ans as the size of subarr will be smaller for a later index and the pref sum is small as well, so no point in keeping curr ind and pref sum; so we pop it. 
            }

            dq.push_back({i, ps[i]}); // push the ith index and pref sum. 
        }
        
        return ans == n+1 ? -1 : ans; // return ans after completing all iterations. 

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna