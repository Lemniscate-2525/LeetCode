class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size();
        int m = t.size();

        if(m > n) return "";

        int l = 0;
        int r = 0;

        int st = 0;

        int f = 0;
        int req = 0;

        int mini = INT_MAX;

        vector<int> need(256, 0);
        vector<int> have(256, 0);

        for(char ch : t) need[ch]++; // cnting no. of needed elem from the string t. 
        
        for(int i=0; i<256; i++) { // cnting no. of req elem from the need freq arr.
            if(need[i] > 0) req++;  
        }

        while(r < n) {

            have[s[r]]++; // inc freq of elem in string s.(elem we have)

            if(have[s[r]] == need[s[r]]) { // if freq of elem we need from s and elem we have from t become equal then we can form that elem in s.
                f++;
            }

            while(f == req) { // window validity if cnt of req elem and formed elem is equal.

                if(r-l+1 < mini) { // size of curr valid window smaller than prev globally smallest valid window.
                    mini = min(mini, r-l+1);
                    st = l; // curr valid window might be the globally shortestwe find, so we store it's starting point to form ans substring later.
                }

                have[s[l]]--; // shrinking window from left

                if(need[s[l]] > 0 && have[s[l]] < need[s[l]]) f--; // if at s[l] we had an elem which we just removed from the have arr, if the freq of needing that elem ie it's freq in t is greater than it's freq in the have arr it means that we need to reduce the cnt of elements we were able to form by 1.  

                l++; // moving l pointer forward to shrink the window. 

            }
            
            r++;

        }

        if(mini == INT_MAX) return "";
        return s.substr(st, mini); // st rep starting pnt of smallest valid window. 

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna