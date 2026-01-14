#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include< algorithm >	
#include<cctype>
#include <vector>
using namespace std;
//SELF SOLVED FIND THE NUMBER OF ITEMS
int main()
{
	int n;
	cout << "enter the size of the array u want to yk...";
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	map<int, int> mapname;
	for (int num : arr){
		mapname[num]++;	
	}
	for (auto &pair1 : mapname)
	{
		cout << pair1.first << "-> this many times"<<pair1.second;
	}

}