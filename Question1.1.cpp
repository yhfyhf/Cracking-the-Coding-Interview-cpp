/*
 * Implement an algorithm to determine if a string has all unique characters. 
 * What if you can not use additional data structures?
 */

#include <iostream>
#include <cstring>
using namespace std;

bool isAllUnique1(string s) {
    int flag[256] = {0};
    int len = s.length();
    for (int i = 0; i < len; ++i) {
        int asciiPos = (int)s[i];   // the position in ASCII
        if (flag[asciiPos] == 1) return false;
        flag[asciiPos] = 1;
    }
    return true;
}

/* improvement */
bool isAllUnique2(string s) {
    int flag[8] = {0};
    int len = s.length();
    for (int i = 0; i < len; ++i) {
        int asciiPos = (int)s[i];
        int index = asciiPos/32;
        int shift = asciiPos%32;
        if(flag[index] & (1 << shift)) return false;
        flag[index] |= (1 << shift);
    }
    return true;
}

int main(int argc, char const *argv[]) {
    string s1 = "hello, how are you?";
    string s2 = "Myfirstcode!";
    cout  << isAllUnique1(s1) << isAllUnique1(s2) << endl;
    cout  << isAllUnique2(s1) << isAllUnique2(s2) << endl;
    return 0;
}
