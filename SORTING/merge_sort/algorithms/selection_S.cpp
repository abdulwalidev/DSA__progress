#include <iostream>
using namespace std;

int main() {

    int array[6] = { 15, 2, 5, 244, 3, 600 };
    int temp;
    int min; // added to track min element index

    // O(n^2)
  
    // CANT swAP IMIDIETLY 

    for (int i = 0; i < 6 - 1; i++) { //bcz last is alr sorted
        min = i; 
        for (int j = i + 1; j < 6; j++) {
            if (array[j] < array[min]) 
                min = j; // finding min index
        }
        // swaping later because cant swap imidietly we gotta find MOST min first
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }


    //END


    for (int i = 0; i < 6; i++) {
        cout << array[i] << endl;
    }

    return 0;
}
