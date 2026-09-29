class Solution {
public:

    int val(char ch) { // fn to assign int vals to characters.

        return ch == 'A' ? 0 :
               ch == 'C' ? 1 :
               ch == 'G' ? 2 : 3; 
    }

    vector<string> findRepeatedDnaSequences(string s) {

        // The pattern here is of fixed size ie. 10 but not fixed in terms of it's characters; so we have to put each 10 length substr pattern hash in a set to use for look-up later during comparison.

        // To get new pattern, we can roll the pattern by doing the usual. 

        unordered_set<int> seen;
        unordered_set<int> repeated;

        vector<string> ans;

        int n = s.size();

        int m = 10;
        int b = 4;

        if(n < m) return {};

        const long long mod = 1e9 + 7;

        long long highest_power = 1;
        long long oh = 0;

        for(int i=0; i<9; i++) { // calculating highest mult power.
            highest_power = (highest_power * b) % mod; 
        }

        for(int i=0; i<m; i++){ // hash of first window. 
            oh = (oh*b + val(s[i])) % mod;
        }

        seen.insert(oh);  

        for(int i=1; i<n-m+1; i++) { // hash of all windows from i=1 ---> n-m+1.

            oh = (oh - val(s[i-1]) * highest_power) % mod; // if i is starting character of curr window then outgoing character will be one previous ie. i-1. 

            if(oh < 0) oh += mod;

            oh = (oh * b) % mod;

            oh = (oh + val(s[i+m-1])) % mod; // incoming character will be at i+m-1

            if(seen.count(oh)) {

                if(!repeated.count(oh)) {
                    ans.push_back(s.substr(i, m));
                    repeated.insert(oh);
                }
            }

            else {
                seen.insert(oh);
            }
        }

        return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna