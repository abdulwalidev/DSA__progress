#include <iostream>
#include <cstdlib> // for malloc
using namespace std;

#define SIZE 10  // Define the size of the hash table

// -----------------------------
// Structure for each data item
// -----------------------------
struct DataItem {
    int data; // The actual value we want to store
    int key;  // The key used for hashing (unique identifier)
};

// -----------------------------
// Global hash table array
// -----------------------------
DataItem* hashArray[SIZE]; // Array to store pointers to DataItems
DataItem* dummyItem;       // Dummy item used to mark deleted cells

// -----------------------------
// Hash function: key -> index
// -----------------------------
int hashCode(int key) {
    return key % SIZE; // Ensures key maps to an index within table size
}

// -----------------------------
// Insert a new element into hash table
// -----------------------------
void insert(int key, int data) {
    // Step 1: Create a new data item in memory
    DataItem* item = (DataItem*) malloc(sizeof(DataItem));
    item->data = data; // store the value
    item->key = key;   // store the key

    // Step 2: Compute initial hash index
    int hashIndex = hashCode(key);

    // Step 3: Handle collisions using linear probing
    // If the calculated index is already occupied and not deleted (-1 key)
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
        ++hashIndex;          // Move to the next cell
        hashIndex %= SIZE;     // Wrap around to 0 if we reach the end
    }

    // Step 4: Place the new item in the found empty or deleted slot
    hashArray[hashIndex] = item;
}

// -----------------------------
// Delete an element from hash table
// -----------------------------
DataItem* deleteItem(DataItem* item) {
    int key = item->key;        // Key of the item to delete
    int hashIndex = hashCode(key); // Start at its hash index

    // Step 1: Search for the item using linear probing
    while(hashArray[hashIndex] != NULL) { // Stop if we hit an empty cell
        if(hashArray[hashIndex]->key == key) { // Found the key
            DataItem* temp = hashArray[hashIndex]; // Save pointer to delete
            hashArray[hashIndex] = dummyItem;     // Replace with dummy item
            return temp;                           // Return deleted item
        }
        ++hashIndex;          // Move to next cell
        hashIndex %= SIZE;     // Wrap around if needed
    }

    return NULL; // Key not found in table
}

// -----------------------------
// Search for an element by key
// -----------------------------
DataItem* search(int key) {
    int hashIndex = hashCode(key); // Compute hash index

    // Step 1: Traverse until empty cell is found
    while(hashArray[hashIndex] != NULL) {
        if(hashArray[hashIndex]->key == key) // Found the key
            return hashArray[hashIndex];     // Return the item

        ++hashIndex;          // Move to next cell
        hashIndex %= SIZE;     // Wrap around if needed
    }

    return NULL; // Key not found
}

// -----------------------------
// Display the entire hash table
// -----------------------------
void display() {
    cout << "Hash Table: \n";
    for(int i = 0; i < SIZE; i++) {
        if(hashArray[i] != NULL && hashArray[i]->key != -1) {
            // If cell is occupied and not a dummy, print key and data
            cout << i << " --> (" << hashArray[i]->key << ", " << hashArray[i]->data << ")\n";
        } else {
            // If cell is empty or a dummy, show as empty (~)
            cout << i << " --> ~\n";
        }
    }
    cout << endl;
}

// -----------------------------
// Main program to test hash table
// -----------------------------
int main() {
    // Step 1: Initialize hash table cells to NULL
    for(int i = 0; i < SIZE; i++)
        hashArray[i] = NULL;

    // Step 2: Create a dummy item for deletion marks
    dummyItem = (DataItem*) malloc(sizeof(DataItem));
    dummyItem->key = -1;  // Key -1 indicates deleted
    dummyItem->data = -1; // Value doesn't matter

    // -----------------------------
    // Step 3: Insert some items
    // -----------------------------
    insert(1, 20);  // key=1, value=20
    insert(2, 70);  // key=2, value=70
    insert(42, 80); // key=42, value=80 (will collide with key 2 -> linear probing)
    insert(4, 25);  // key=4, value=25
    insert(12, 44); // key=12, value=44 (collision with key 2)

    cout << "After insertion:\n";
    display(); // Display hash table after insertion

    // -----------------------------
    // Step 4: Search for a key
    // -----------------------------
    int keyToSearch = 42;
    DataItem* found = search(keyToSearch);
    if(found != NULL)
        cout << "Key " << keyToSearch << " found with value: " << found->data << "\n";
    else
        cout << "Key " << keyToSearch << " not found\n";

    // -----------------------------
    // Step 5: Delete a key
    // -----------------------------
    int keyToDelete = 2;
    DataItem tempItem; tempItem.key = keyToDelete;
    deleteItem(&tempItem);

    cout << "\nAfter deleting key " << keyToDelete << ":\n";
    display(); // Display hash table after deletion

    return 0;
}
