class Solution {
public:

    int gen_from_centre(string &s){

        while(l >= 0 && r < n && s[l] == s[r]){
            l++;
            r--;
        }
    }

    string longestPalindrome(string s) {
        
        int n = s.size();
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna