/*
 * Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and
 * s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring.
 * i.e., "waterbottle" is a rotation of "erbottlewat".
 */

#include <iostream>
#include <string>
using namespace std;

bool isSubstring(string s1, string s2) {
	if (s1.find(s2) == string::npos)
		return false;
	return true;
}

bool isRotation(string s1, string s2) {
	if(s1.length() != s2.length())
		return false;
	return isSubstring(s1 + s1, s2);
}

int main(int argc, char const *argv[]) {
	string s1 = "waterbottle";
	string s2 = "erbottlewat";
	cout << isRotation(s1, s2) << endl;
	return 0;
}
