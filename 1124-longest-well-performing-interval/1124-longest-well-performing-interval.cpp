class Solution {
public:
    int longestWPI(vector<int>& h) {

        int n = h.size();
        int ans = 0;

        stack<int> st;
        vector<int> pref(n+1, 0);

        for(int i=0; i<n; i++) {
            pref[i+1] = pref[i] + (h[i] > 8 ? 1 : -1);
        }

        for(int i=0; i<=n; i++) {
            if(st.empty() || pref[st.top()] > pref[i]) {
                st.push(i);
            }
        }

        for(int i=n; i>=0; i--){

            while(!st.empty() && pref[i] > pref[st.top()]) {
                ans = max(ans, i - st.top());
                st.pop();
            }  
        }

        return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna