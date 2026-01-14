#include <iostream>
using namespace std;

int main() {

    int array[6] = { 15, 2, 5, 244, 3, 600 };
    int temp;
    int min; // added to track min element index

    // O(idek)
    
     for (int i = 1; i < 6; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }

    //END

    for (int i = 0; i < 6; i++) {
        cout << array[i] << endl;
    }

    return 0;
}
