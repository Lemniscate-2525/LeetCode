class Solution {
private:

    bool check_vowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:

    int findTheLongestSubstring(string s) {
        
        int n = s.size();

        unordered_map<char, int> vp = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
        unordered_map<int, int> mpp;

        mpp[0] = -1;

        int curr = 0;
        int maxlen = 0;

        for(int i=0; i<n; i++) {
            if(check_vowel(s[i])) {

                curr ^= (1 << vp[s[i]]); // toggle upon seeing a vowel. 
            }

            if(mpp.count(curr)) {
                maxlen = max(maxlen, i - mpp[curr]);
            } else {
                mpp[curr] = i;
            }
        }


        return maxlen;
        


    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna