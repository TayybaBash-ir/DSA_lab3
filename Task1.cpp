#include <iostream>
using namespace std;
//Function to check if string is palindrome
void checkPalindrome(string str){
    int n = str.length();
    bool isPalindrome = true;
//iterative method
    for(int i = 0; i < n / 2; i++){
        if(str[i] != str[n - i - 1]){
            isPalindrome = false;
            break;
        }
    }

    if(isPalindrome){
        cout << str << " is a palindrome." << endl;
    } else {
        cout << str << " is not a palindrome." << endl;
    }
}
//main function
int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    checkPalindrome(str);

    return 0;
} 