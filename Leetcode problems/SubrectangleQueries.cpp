/**** Problem link: https://leetcode.com/problems/subrectangle-queries/  *//

class SubrectangleQueries {
public:
    vector<vector<int>> vec;
    vector<pair<vector<int>,int> > up;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vec=rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        up.push_back({{row1,col1,row2,col2},newValue});
    }
    
    int getValue(int r, int c) {
        for(int i=up.size()-1;i>=0;i--)
        {
            vector<int>a=up[i].first;
            if(a[0]<=r&&r<=a[2]&&a[1]<=c&&c<=a[3])
                return up[i].second;
        }
        return vec[r][c];
    }
};
