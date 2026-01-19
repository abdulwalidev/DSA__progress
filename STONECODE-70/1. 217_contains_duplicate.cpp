//if duplicate return true
/*

so bacially my solution is to put the things in a map one by one and if there is a duplicate in the map
it just stops and sends a true there.

*/
//so first we do 


class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

//first we make a map
   map<int, int> mp;
//then we put all the map elements into the vector BUTTT
    for (int x : nums) {
      //  before putting them we check if they already exist 
       if(mp.count(x))
       {return true;} // if they do return true
        else 
        mp[x];  //if not put them in array

    }
    return false;//if not dublicate
    }
};


// this apparently is 0(n)
//and probably and hopefully the best solution
