/*
 * Write code to reverse a C-Style String. (C-String means that "abcd" is 
 * represented as five characters, including the null character).
 *
 * NOTE
 * the string ends with a null charactor '\0'.
 */

#include <iostream>
using namespace std;

void swap(char *x, char *y){
    char *temp = x;
    x = y;
    y = temp;
}

void reverse(char *s) {
	if (!s) return;
	int len = strlen(s);
	char *front = s;
	char *end = &s[len-1];
	while(front != end) {
		swap(*front++, *end--);
	}
}

int main(int argc, char const *argv[]) {
	char s[] = "hello, how are you?";
	reverse(s);
	cout << s << endl;
	return 0;
}

