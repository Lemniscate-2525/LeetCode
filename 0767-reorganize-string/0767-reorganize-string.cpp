class Solution {
public:
    string reorganizeString(string s) {

        int n = s.size();
        string ans(n, ' ');

        int mf = 0;
        int maxi = 0;

        vector<int> freq(26, 0);

        for(char ch : s) {

            int x = ch - 'a';  // ascii value
            freq[x]++;

            if(freq[x] > mf) {

                maxi = x;
                mf = freq[x];

            }
        }

        if(mf > (n+1)/2)
            return "";

        int idx = 0;

        while(freq[maxi] > 0) {

            if(idx >= n) idx = 1;

            ans[idx] = 'a' + maxi;
            freq[maxi]--;

            idx += 2;
        }

        for(int i=0; i<26; i++) {

            while(freq[i] > 0) {

                if(idx >= n)
                    idx = 1;

                ans[idx] = 'a' + i;
                freq[i]--;

                idx += 2;
                
            }
        }

        return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna