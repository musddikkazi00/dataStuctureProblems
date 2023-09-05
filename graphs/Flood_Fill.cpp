// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

// You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

// Return the modified image after performing the flood fill.



// catch in delRow && delCol just do  compairing its no hard its very easy 
// and apply bfs to traverse the matrix

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int srcCol = image[sr][sc]; 
        int row = image.size();
        int col = image[0].size();

        if(srcCol==color){
            return image;
        }  
        
        vector< vector<int> >vis = image; 
        
        
        queue<pair<int,int> >q; 
        
        q.push({sr,sc});
        vis[sr][sc] = color;
        
         int delRow[4] ={-1,0,+1,0};
        int delCol[4] = {0,+1,0,-1};
      
        while(!q.empty()){
                
             int r = q.front().first;
            int c =  q.front().second; 
            q.pop();
            for(int i=0; i<4; i++){
                int nRow = r + delRow[i];
                int nCol = c + delCol[i];
                
                if(nRow>=0 && nRow<row &&
                  nCol >=0 && nCol<col && 
                  image[nRow][nCol]==srcCol && 
                  vis[nRow][nCol]!= color){
                    vis[nRow][nCol] = color;
                    q.push({nRow,nCol});
                }
            }
            
        }
         
        return vis;
    }
};
