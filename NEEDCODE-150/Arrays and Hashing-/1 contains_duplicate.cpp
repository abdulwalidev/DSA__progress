
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
    
    map<int, int> wali;

    for(int num : nums){
        wali[num]++;	}


for(auto &p : wali)//puts the vector into map
            {if(p.second>1)
            {return true;
            }}
         return false;
         
         
    
  
        //end
    }
};