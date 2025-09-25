class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans=0,l=triangle.size();
        for(int i=l-1;i>=0;i--)
        {
            for(int j=0;j<i;j++)
            {
                triangle[i-1][j]+=min(triangle[i][j],triangle[i][j+1]);
            }
        }
        return triangle[0][0];
    }
};