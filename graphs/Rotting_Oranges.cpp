// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// test cases : 
//        Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
//        Output: 4

//   Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.



class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector< vector<int > > vis(n , vector<int>(m,0));
        
        queue<pair< pair<int,int> , int> >st;
        
        for(int i = 0; i<n ; i++){
            for(int j = 0 ; j <m ;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    st.push({{i,j},0});
                }
            }
        }  
            int delRow[4] = {-1,0,+1,0};
            int delCol[4] = {0,+1,0,-1}; 
        
             int maxTime = 0;
        while(!st.empty()){
            int row = st.front().first.first;
            int col = st.front().first.second;
            int time = st.front().second;
            st.pop();
            
            maxTime = max(time,maxTime);
            
            for(int i = 0; i<4; i++){
                
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                
                if(nRow>=0 && nRow<n &&
                  nCol >=0 && nCol<m &&
                  vis[nRow][nCol]!=2 && 
                  grid[nRow][nCol]==1){
                    
                    vis[nRow][nCol]=2;
                    st.push({{nRow,nCol},time+1});
                }
            }
            
        }
         
        for(int i = 0; i<n ; i++){
            for(int j = 0 ; j <m ;j++){
                if(grid[i][j]==1 &&  vis[i][j]!=2){
                    return -1;
                }
            }
        } 
        
        return maxTime;
        
        
    }
};
