class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size();
        int m = t.size();

        if(m > n) return "";

        int l = 0;
        int r = 0;

        int st = 0;

        int mini = INT_MAX;
        int f = 0;

        vector<int> need(256, 0);
        vector<int> have(256, 0);

        for(char ch : t) {
            need[ch]++;
        }

        int req = 0;

        for(int i=0; i<256; i++) {
            if(need[i] > 0) req++;
        }

        while(r < n) {

            have[s[r]]++;

            if(need[s[r]] > 0 && have[s[r]] == need[s[r]]){
                f++;
            }

            while(f == req) {

                if(r-l+1 < mini){
                    mini = min(mini, r-l+1);
                    st = l;
                }

                have[s[l]]--;

                if(need[s[l]] > 0 && have[s[l]] < need[s[l]]) f--;

                l++;

            }
            
            r++;

        }

        if(mini == INT_MAX) return "";

        return s.substr(st, mini);

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna