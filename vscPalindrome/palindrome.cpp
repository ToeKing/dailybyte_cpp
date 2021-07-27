#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* Given a string, return whether or not it forms a palindrome
   ignoring case and non-alphabetical characters.
   Note: a palindrome is a sequence of characters that reads
         the same forwards and backwards. */
bool isPalindrome(string str) {
    bool isPal = true;
    string stripped = "";

    for(auto& c : str) {
        if(isalpha(c))
            stripped += tolower(c);
    }

    for(int i = 0; i < stripped.length() / 2 && isPal; i++) {
        if(stripped[i] != stripped[stripped.length() - i - 1]) {
            isPal = false;
        }
    }
    return isPal;
}

int main()
{
    vector<string> tests { "level", "algorithm", "A man, a plan, a canal: Panama" };
    
    for(const string& s : tests) {
        cout << s << ": " << isPalindrome(s) << endl;
    }
    
    cout << endl;
}
