class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int m = s1.size();
        int n = s2.size();

        vector<int> f1(26, 0);
        vector<int> f2(26, 0);

        for(char ch : s1) { // freq signature of string s1.
            f1[ch - 'a']++;
        }

        int l = 0;
        int r = 0;

        while(r < n) {

            f2[s2[r] - 'a']++; // freq signature of windows in s2.

            if(r-l+1 > m) {    // if window size exceeds len of string s1, we trim from left.
                f2[s2[l] - 'a']--;
                l++;
            }

            r++;

            if(f1 == f2) return true; // if at any point the freq signature of the original string s1 is equal to the freq signature of any valid sized window in s2, we have a valid permutation match. 

        }

        return false;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna