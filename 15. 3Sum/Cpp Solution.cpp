class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        if(nums.size() < 3){   
            return {};
        }
        
        if(nums[0] > 0){     
            return {};
        }
        
        vector<vector<int>> res;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] > 0){  
                break;
            }
            
            if(i == 0 || i > 0 && nums[i] != nums[i - 1]){
                int s = i + 1, e = nums.size() - 1, ans = 0 - nums[i];
                
                while(s < e){

                    if(nums[s] + nums[e] == ans){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[s]);
                        temp.push_back(nums[e]);
                        res.push_back(temp);
                        
                        while(s < e && nums[s] == nums[s + 1]){
                            s++;
                        }
                        
                        while(s < e && nums[e] == nums[e - 1]){
                            e--;
                        }
                        
                        s++;
                        e--;              
                    }
                    
                    else if(nums[s] + nums[e] < ans){
                        s++;
                    }
                    
                    else{
                        e--;
                    }
                    
                }
            }
        }
        
        return res;
    }
};
