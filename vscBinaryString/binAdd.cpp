#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

/* Given two binary strings (strings containing only 1s and 0s)
   return their sum (also as a binary string).

   Note: neither binary string will contain leading 0s unless the
   string itself is 0 */
string binaryAdd(string s1, string s2) {
    int i1 = 0, i2 = 0;
    for(auto& c: s1) {
        i1 <<= 1;
        if('1' == c)
            i1++;
    }
    for(auto& c: s2) {
        i2 <<= 1;
        if('1' == c)
            i2++;
    }
    i1 += i2;

    // return bitset<8>(i1).to_string();  // prints leading zeros...

    string oStr = "";
    do {
        string tmp;
        if(i1 & 1) {
            tmp = "1";
        } else tmp = "0";
        oStr = tmp + oStr;
        i1 >>= 1;
    } while(i1 > 0);
    return oStr;
}

int main()
{
    vector<string> s1 { "100", "11", "1", "0"};
    vector<string> s2 { "1", "1", "0", "0" };
    
    //for(auto& x : s1; auto& y: s2) {
    //for(auto& [a, b] : zip(s1, s2))
    for(int i = 0; i < s1.size(); i++) {
        cout << s1[i] << " + " << s2[i] << " = " << binaryAdd(s1[i], s2[i]) << endl;
    }
    cout << endl;
}