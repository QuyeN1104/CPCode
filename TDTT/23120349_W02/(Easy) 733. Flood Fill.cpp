class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // directions
        vector<int> iRow = {-1, 1, 0, 0};
        vector<int> iCol = {0, 0, 1, -1};

        int ori_color = image[sr][sc];

        int cols = image[0].size();
        int rows = image.size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        queue<pair<int,int>> q;
        q.push({sr, sc});
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            visited[t.first][t.second] = true;
            
            image[t.first][t.second] = color;
            
            for(int i = 0; i < 4; i++){
                int r = t.first+iRow[i]; int c = t.second + iCol[i];
                if(r < 0 || r >= rows || c < 0 || r >= cols || image[r][c] != ori_color) continue;
                if(!visited[r][c]){
                    q.push({r, c}); 
                }
            }
        }
        
        return image;
    }
};