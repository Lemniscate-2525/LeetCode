class Solution {
public:
    string removeDuplicateLetters(string s) {

        vector<bool> vis(26, 0);
        vector<int> freq(26, 0);

        stack<char> st;

        for(char ch : s){
            freq[ch - 'a']++;
        }

        for(char ch : s){

            freq[ch - 'a']--;

            if(vis[ch - 'a']) continue;

            while(!st.empty() && ch < st.top() && freq[st.top() - 'a'] > 0){

                vis[st.top() - 'a'] = false;
                st.pop();

            }

            st.push(ch);
            vis[ch - 'a'] = true;

        }

        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna