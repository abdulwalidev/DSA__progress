
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>	

using namespace std;
int main()
{
	map<string, int> mapname = { {"wali",41122 } }	;
	

    //find elements
	cout << mapname.at("wali");
    //or
    cout << mapname["wali"];



    // Add new elements
    people["Jenny"] = 22;
    //or
    people.insert({"Jenny", 22});
    

	unordered_map<int, string> mapname2 = { {007,"wali"} ,{ 119,"zliza" } ,{99, "sundas" } };
	int x;
	cout << "Enter roll number to search:";

	cin >> x;
	if (mapname2.find(x) != mapname2.end()) { //if mapname.find doesnt find it equals to mapname.end
		cout << mapname2[x] << endl;
	}
	else
		cout << "Roll number not found!";





}