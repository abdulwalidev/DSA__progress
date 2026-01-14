// august 4 leetcode 1 easy

#include <iostream>
#include <unordered_map>
#include <vector>	


using namespace std;

int main()
{
	vector<int> x1;
	int x, y, z, y2;

	int c=0;
	cin >> x;
	cin >> y;
	cin >> z;
	cin >> y2;
	cout << "whcih no to find";
	int f;
	cin >> f;

	x1.push_back(x);
	x1.push_back(y);
	x1.push_back(z);
	x1.push_back(y2);
	for (int i = 0; i < x1.size(); i++)
	{
		if (x1[i]==f)
		{
			c=c+1;
		}
		
	}

	cout <<c<<"times gng";
}   