class Solution {
public :

    int val(char ch) {
        return ch - 'a' + 1;
    }

    string check(string &s, int len) {

        unordered_map<unsigned long long, int> seen;

        int n = s.size();
        int m = len;

        int b = 131;
        //unsigned long long mod = 10e9+7;

        unsigned long long h = 0;
        unsigned long long hp = 1;

        for(int i=0; i<m; i++) {
            h = (h*b);
            h = (h + val(s[i]));  // first window hash.
        }

        seen[h] = 0;

        for(int i=0; i<m-1; i++) {
            hp = (hp * b);    // highest power. 
        }

        for(int i=1; i<n-m+1; i++) {   // remaining window hash.

            h -= val(s[i-1]) * hp;

            h = (h*b);
            h = (h + val(s[i+m-1]));

            if(seen.count(h)) {

                int j = seen[h];

                if(s.compare(j,m,s,i,m) == 0)
                    return s.substr(i, m);
                }
                else {
                    seen[h] = i;
                }
            }

        return "";
    }

    string longestDupSubstring(string s) {
        
        int n = s.size();
        string ans = "";

        int l = 1;
        int h = n;

        while(l <= h) {

            int mid = l + (h-l)/2;
            string curr = check(s, mid);

            if(!curr.empty()) {

                ans = curr;
                l = mid+1;

            } else {
                h = mid-1;
            }
        }

        return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna