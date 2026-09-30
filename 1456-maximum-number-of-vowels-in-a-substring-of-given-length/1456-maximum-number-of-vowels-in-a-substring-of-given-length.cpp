class Solution {
public:
    int maxVowels(string s, int k) {
        
        int n = s.size();
        string vowels = "aeiou";

        int l = 0;
        int r = 0;

        int cnt = 0;
        int max_cnt = 0;

        while(r < n){

            for(char ch : vowels) {

                if(s[r] == ch) cnt++;

            }

            if(r-l+1 == k) {

                max_cnt = max(cnt, max_cnt);

                for(char ch : vowels) {

                    if(s[l] == ch) cnt -= 1; 

                }
                l++;

            }

            r++;
        }

    return max_cnt;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna