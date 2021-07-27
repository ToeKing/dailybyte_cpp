#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/* Given an array of strings, return the longest common prefix that
   is shared amongst all strings.

   Note: you may assume all strings only contain lowercase 
         alphabetical characters. */


// Method 1: This will test word by word. Find the prefix for the first two
//           words, if that is contained in the following words we have our
//           longest common string.
string GetPrefix(string& s1, string& s2) {
    string result = "";
    for(int i = 0; i < s1.length() && i < s2.length(); i++) {
        if(s1[i] != s2[i])
            break;
        result += s1[i];
    }
    return result;
}
string GetCommonPrefix(vector<string>& words) {
    string prefix = words[0];

    for(int i = 1; i < words.size(); i++ ) {
        if("" == prefix)
          break;
        prefix = GetPrefix(prefix, words[i]);
    }
    return prefix;
}

// Method 2: Look at the strings characters by character. First find the
//           smallest string, then check each string to find how much
//           of that may exist in others.
int GetShortestSize(vector<string>& words) {
    int strSz = INT_MAX;
    if(words.size()) {
        for(auto& w : words) {
            if(w.length() < strSz)
               strSz = w.length();
        }
    } else {
        strSz = 0;
    }
    return strSz;
}
string GetCommonPrefixChar(vector<string>& words) {
    int shortest = GetShortestSize(words);
    string prefix = "";
    char c;

    for(int i = 0; i < shortest; i++) {
        c = words[0][i];
        for(auto& w : words) {
            if(c != w[i]) {
                goto END;  // kill loops
            }
        }
        if(shortest != 0)
            prefix += c;
    }
  END:
    return prefix;
}

int main()
{
    vector<string> test1 { "colorado", "color", "cold" };
    vector<string> test2 { "a", "b", "c" };
    vector<string> test3 { "spot", "spotty", "spotted" };
    
    cout << "Test1: ";
    for (auto& word : test1) {
        cout << word << " ";
    }
    cout << endl << "  Prefix = " << GetCommonPrefix(test1) << endl;
    cout << "  PrefixC = " << GetCommonPrefixChar(test1) << endl;

    cout << "Test2: ";
    for (auto& word : test2) {
        cout << word << " ";
    }
    cout << endl << "  Prefix = " << GetCommonPrefix(test2) << endl;
    cout << "  PrefixC = " << GetCommonPrefixChar(test2) << endl;

    cout << "Test3: ";
    for (auto& word : test3) {
        cout << word << " ";
    }
    cout << endl << "  Prefix = " << GetCommonPrefix(test3) << endl;
    cout << "  PrefixC = " << GetCommonPrefixChar(test3) << endl;
}
