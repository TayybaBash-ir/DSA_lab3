#include <iostream>
#include <string>
using namespace std;
//class to manage a pool of strings 
class StringPool {
private:
    string* stringPool; 
    int currentSize;   
    int maxSize;       

public: 
    StringPool() {
        maxSize = 5;                       
        currentSize = 0;                  
        stringPool = new string[maxSize];  
    }

    // Destructor
    ~StringPool() {
        delete[] stringPool;
        cout << "\n[ Dynamic memory delete[] stringPool successfully freed." << endl;
    }

    // addString method
    void addString(string str) {
        if (currentSize < maxSize) {
            stringPool[currentSize] = str;
            currentSize++;
            cout << "String added to pool: " << str << endl;
        } else {
            cout << "String pool is full" << endl;
        }
    }

    // removeString method
    void removeString(string str) {
        int index = -1;

        // Search for target string
        for (int i = 0; i < currentSize; i++) {
            if (stringPool[i] == str) {
                index = i;
                break;
            }
        }

        // Shift elements
        if (index != -1) {
            for (int i = index; i < currentSize - 1; i++) {
                stringPool[i] = stringPool[i + 1];
            }
            currentSize--; 
            cout << "Removed \"" << str << "\" from pool" << endl;
        } else {
            cout << "String not found in pool" << endl;
        }
    }

    // Displays current pool status
    void displayStatus() {
        cout << "Pool Status (" << currentSize << "/" << maxSize << "): [ ";
        for (int i = 0; i < currentSize; i++) {
            cout << "\"" << stringPool[i] << "\" ";
        }
        cout << "]" << endl;
    }
};
// Main function 
int main() {
    
    cout << "Adding multiple strings to pool";
    StringPool pool;
    pool.addString("Apple");  
    pool.addString("Banana"); 
    pool.addString("Cherry"); 
    pool.displayStatus();     

    
    cout << "Removing string without freeing memory";
    pool.removeString("Banana"); 
    pool.displayStatus();         

    
    cout << "Memory Leak Detection & Fix Explanation:\n";
    cout << "- 'Banana' was removed logically by shifting items and decrementing currentSize.\n";
    cout << "- However, the underlying dynamic array still retains allocated heap memory for 5 elements.\n";
    
    cout << "\nMEMORY LEAK FIXED:\n";
    cout << "- The allocated heap memory will be cleaned up automatically by the destructor (~StringPool) when the pool object exits main().\n";

    return 0; // ~StringPool() executes here automatically
}