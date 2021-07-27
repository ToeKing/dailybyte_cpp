#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string reverseStr(string str) {
  #if 0
    string s;
    
    for(int i = 0; i < str.length(); i++) {
       
        s += str[str.length() - i - 1];
    }
    return s;
  #else
    reverse(str.begin(), str.end());
    return str;
  #endif    
}

void reverseRecurse(vector<char>& s, int strt, int end) {
    if(strt < end) {
        swap(s[strt++], s[end--]);
        reverseRecurse(s, strt, end);
    }
}

void reverseString(vector<char>& s) {
    if(s[0] != 0)
        reverseRecurse(s, 0, s.size() - 1);
}

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    
    for (const string& word : msg)
    {
        cout << word << " - " << reverseStr(word) << endl;
    }

    vector<char> t2 { 'h', 'e', 'l', 'l', 'o', '1', '2', '3'};
    for(auto& c : t2) cout << c;
    cout << " - ";
    reverseString(t2);
    for(auto& c : t2) cout << c;
    cout << endl;
}
