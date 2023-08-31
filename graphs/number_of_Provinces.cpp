// Problem Statement : 
// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

// test cases : 
//        Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
//        Output: 2

//***********************************************************************************************************************************


class Solution {

    private:     

// dfs gives garentee to mark visited to  all connected nodes  
    
   void dfs(int node, vector<int>&vis, vector<int>adj[]){
          vis[node] =1;
          
          for(auto it:adj[node]){
              if(!vis[it]){
                  dfs(it,vis,adj);
              }
          }
      }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      
      int n = isConnected.size();      // find no of vertex in graph / rows 
        int m = isConnected[0].size();  // find the edges / colums


      // convert matrix to adjecency list 
       
      vector<int> adj[n];
        
        for(int i = 0 ; i<n; i++){
            for(int j = 0 ; j<m ; j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    
                }
            }
        } 
        
        vector<int> vis(n,0);   // visited array for not getting dfs call repitedly;
       
        int provinces = 0;    // count the provinces  
      
        for(int i = 0; i<n; i++){

            // if unvisited mean a new goup of cities are there  traverse through by dfs mark them as group of cities 
          if(!vis[i]){     
                dfs(i,vis,adj);
                provinces++;       // cout number of group called provinces
            }
        }
        return provinces;    // return it
    }
};
