class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        for(int k = 0; k + 1 < mat.size(); k++){
            for(int i = 0; i + 1 < mat.size(); i++){
                 for(int j = 0; j + 1 < mat[i].size(); j++){
                    if(mat[i][j] > mat[i + 1][j + 1])
                        swap(mat[i][j], mat[i + 1][j + 1]);
                }
             }
        }          
        
        return mat;
        
    }
};
