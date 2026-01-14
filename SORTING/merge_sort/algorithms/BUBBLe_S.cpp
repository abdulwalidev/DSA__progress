#include <iostream>
using	namespace std;

int main() {

	int array[6]={15,2,5,244,3,600};
	int temp;
	
	//O(n^2)
	for (int i = 0; i < 6-1; i++)
	{
		for (int j = 0; j < 6-i-1; j++) //-i because i is already sorted
		{
			if (array[j]>array[j+1])
			{
				temp= array[j + 1];
				array[j+1]=array[j];
				array[j] = temp;
			}
		}
	}


    //END


	for (int i = 0; i < 6-1; i++)
	{
		cout << array[i] << endl;

	}
	return 0;

}