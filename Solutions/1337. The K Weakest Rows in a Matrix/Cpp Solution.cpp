class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();
        
        vector<pair<int,int>> SoldierCount;
        vector<int> res;
        
        for (int i = 0; i < row; i++){
            int s = 0, e = col - 1;
            
            while (s <= e){
                int mid = s + (e - s)/2;
                
                if (mat[i][mid] > 0)
                    s = mid + 1;
                
                else 
                    e = mid - 1;
            }
            
            SoldierCount.push_back({s + 1, i});
        }
        
        sort(SoldierCount.begin(), SoldierCount.end());
        
        for (auto& it : SoldierCount){
            if (k == 0) break;
            res.push_back(it.second);
            k--;
        }
        
        return res;    
    }
};
