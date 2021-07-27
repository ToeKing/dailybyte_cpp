#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/* Given a string representing the sequence of moves a 
   robot vacuum makes, return whether or not it will 
   return to its original position. The string will only 
   contain L, R, U, and D characters, representing left, 
   right, up, and down respectively. */

bool checkRout(string str) {
    // Check if the input string goes back to the beginning.
    // Only expecting 'L', 'R', 'U', 'D' inputs.
    int x = 0, y = 0;
    bool orgin = false;
    for(int i = 0; i < str.length(); i++) {
        switch(str[i]) {
            case 'L':
                x++;
                break;
            case 'R':
                x--;
                break;
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
            default:
                // illegal character, do nothing...
                break;
        }
    }

    if(0 == x && 0 == y)
        orgin = true;

    return orgin;  
}

int main()
{
    vector<string> msg {"LR", "URURD", "RUULLDRD" };
    
    for(auto& s : msg) {
        cout << s << ": " << checkRout(s) << endl;
    }
    cout << endl;
}