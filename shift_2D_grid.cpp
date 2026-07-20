#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> grid_ans(m,vector<int>(n));

        int total=m*n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int indx=i*n+j;
                int newIndx=(indx+k)%total;

                int r=newIndx / n;
                int c=newIndx % n;

                grid_ans[r][c]=grid[i][j];
            }
        }
        return grid_ans;
    }
};