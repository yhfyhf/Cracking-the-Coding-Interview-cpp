/*
 * Implement an algorithm to find the nth to last element of a singly linked list.
 */

#include <iostream>
using namespace std;

typedef struct node {
	int data;
	struct node *next;
}LinkList;

LinkList* createLinkList(int a[], int n) {
	LinkList *head, *p, *q;
    for(int i = 0; i < n; ++i){
        q = new LinkList;
        q->data = a[i];
        if(i==0){
            p = q;
            head = p;
            continue;
        }
        p->next = q;
        p = q;
    }
    return head;
}

LinkList* findNthToLast(LinkList *head, int n) {
	LinkList *fast = head, *slow = head;
	for (int i = 0; i < n; ++i)
		fast = fast->next;
	while (fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

int main(int argc, char const *argv[]) {
	int a[] = {1, 2, 4, 5, 4, 4, 9};
	int length = 7;
	LinkList *head = createLinkList(a, length);
	int n = 4;
	LinkList *nthToLast = findNthToLast(head, n);
	cout << nthToLast->data << endl;
	return 0;
}
