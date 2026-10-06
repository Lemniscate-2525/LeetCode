class NumArray {
public:

    vector<int> p;

    NumArray(vector<int>& arr) { // contains main logic.

        int n = arr.size();

        p.resize(n+1);
        p[0] = 0;

        for(int i=1; i<n+1; i++){
            p[i] = p[i-1] + arr[i-1];
        }
    }
    
    int sumRange(int l, int r) { // just for the ans. 
        
        return p[r+1] - p[l];
    
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna