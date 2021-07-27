#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

/* Given a string, return whether or not it uses capitalization
   correctly. A string correctly uses capitalization if all letters
   are capitalized, no letters are capitalized, or only the first
   letter is capitalized. */
bool checkCaps(string& str) {
    bool ok = true, hasCap = false;

    for(int i = 0; i < str.length() && ok; i++) {
        if(str[i] <= 'Z' && isalpha(str[i])) {
            if(0 == i)
                hasCap = true;
            else if(!hasCap)
                ok = false;
        }
    }
    return ok;
}

int main()
{
    vector<string> s1 { "USA", "Calvin", "compUter", "coding" };
    
    for(auto &s : s1) {
        cout << s << ": " << checkCaps(s) << endl;
    }
    cout << endl;
}
