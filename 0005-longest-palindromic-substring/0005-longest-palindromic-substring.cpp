class Solution {
public:
    string gen_from_centre(string &s, int l, int r) {

        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
        }

        return s.substr(l+1, r-l-1);
    }

    string longestPalindrome(string s) {
        
        int n = s.size();

        string ans = "";

        for(int i=0; i<n; i++){

            string odd = gen_from_centre(s, i , i);
            string even = gen_from_centre(s, i, i+1);

            if(odd.size() > ans.size()){
                ans = odd;
            }

            if(even.size() > ans.size()){
                ans = even;
            }
        }

        return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna