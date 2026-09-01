#include <iostream>
#include <vector>
#include <queue>
#include <array>
using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size();
        int n=classroom[0].size();
        int sr,sc;
        int cnt=0;
        vector<vector<int>> id(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S'){
                    sr=i;
                    sc=j;
                }
                if(classroom[i][j]=='L'){
                    id[i][j]=cnt++;
                }
            }
        }
        int fullmask=(1<<cnt)-1;
        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(n,vector<int>(1<<cnt,-1))
        );
        queue<array<int,4>> q;
        q.push({sr,sc,energy,0});
        best[sr][sc][0]=energy;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        int moves=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [r,c,e,mask]=q.front();
                q.pop();
                if(mask==fullmask){
                    return moves;
                }
                if(e==0){
                    continue;
                }
                for(int d=0;d<4;d++){
                    int nr=r+dr[d];
                    int nc=c+dc[d];
                    if(nr<0 || nr>=m || nc<0 || nc>=n){
                        continue;
                    }
                    if(classroom[nr][nc]=='X'){
                        continue;
                    }
                    int ne=e-1;
                    int nmask=mask;
                    if(classroom[nr][nc]=='R'){
                        ne=energy;
                    }
                    if(classroom[nr][nc]=='L'){
                        int bit=id[nr][nc];
                        nmask |= (1<<bit);
                    }
                    if(best[nr][nc][nmask]>=ne){
                        continue;
                    }
                    best[nr][nc][nmask]=ne;
                    q.push({nr,nc,ne,nmask});
                }
            }
            moves++;
        }
        return -1;
    }
};