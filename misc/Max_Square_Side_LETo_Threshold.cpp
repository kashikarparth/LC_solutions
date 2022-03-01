class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size();
        int m=mat[0].size();
        int l=0;
        for(int i=0;i<n;i++){
            if(threshold < *min_element(mat[i].begin(), mat[i].end())) l++; 
        }
        if(l==n-1) return 0; //If there is no element less than threshold
        
        int g[n+1][m+1];
        memset(g,0,sizeof g);
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                g[i][j]=g[i][j-1];
                for(int l=i;l>0;l--){
                    g[i][j]+=mat[l-1][j-1];  //prefix sum
                }
            }
        }
        int ans =0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=1;k<min(n-i+1,m-j+1);k++){
                    if((g[i+k][j+k]+g[i][j]-g[i+k][j]-g[i][j+k]) <= threshold) ans = max(ans,k);  
                }
            }
        }
        return ans;
    }
};