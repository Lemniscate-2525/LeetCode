class NumMatrix {
public:

    vector<vector<int>> ps;

    NumMatrix(vector<vector<int>>& p) {

        int m = p.size();
        int n = p[0].size();

        ps.assign(m+1, vector<int>(n+1, 0));

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {

                ps[i][j] = p[i-1][j-1] + ps[i][j-1] + ps[i-1][j] - ps[i-1][j-1];

            }
        } 

    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        
        return ps[r2+1][c2+1] - ps[r1][c2+1] - ps[r2+1][c1] + ps[r1][c1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna