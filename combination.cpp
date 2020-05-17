/**
To generate combination using k numbers out of n.
this can be augumented to work with other data, for example an array of string
*/
    void bk(std::vector<std::vector<int>>& result, int n, int k, int step,  std::vector<int>& temp){
        if(step == k){
            result.push_back(temp);
            return;
        }
        int start_index = step > 0 ? temp[step-1] + 1 : 1 ;
        //std::cout << "start index : " << start_index << std::endl;
        for(int i = start_index ; i <= n; i++){
            temp[step] = i;
            bk(result, n, k, step+1, temp);
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::unordered_set<int> nums;
        std::vector<int> temp(k, 0);
        bk(result, n, k, 0,  temp);
        return std::move(result);
        
    }
