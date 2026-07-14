class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(n,-1));
        q.push({0,0});
        dist[0][0] = 1;
        int dr[8] = {-1,-1,-1,0,0,1,1,1};
        int dc[8] = {-1,0,1,-1,1,-1,0,1};
        while(!q.empty()){
            auto current = q.front();
            q.pop();
            int row = current.first;
            int col = current.second;

            if(row == n-1 && col == n-1){
                return dist[row][col];
            }
            for(int k=0; k<8; k++){
                int nr = row + dr[k];
                int nc = col + dc[k];

                if(nc >= 0 && nc < n && nr >= 0 && nr < n && grid[nr][nc] == 0 && dist[nr][nc] == -1){
                    dist[nr][nc] = dist[row][col] + 1;
                    q.push({nr,nc});
                }
            }
        }
        return -1;

    }
};