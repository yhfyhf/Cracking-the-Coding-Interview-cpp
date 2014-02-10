/*
 * Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.
 *
 * EXAMPLE
 * Input: the node 'c' from the linked list a->b->c->d->e. iter 
 * Result: nothing is returned, but the new linked list looks like a->b->d->e.
 *
 * ALGORITHM
 * The solution to this is to simply copy the data from the next node into this node and then delete the next node.
 *
 * NOTE
 * Be care if the node to be delete is the last node, just point that out and discuss with your interviewer.
 */

#include <iostream>
using namespace std;

typedef struct node {
	int data;
	struct node *next;
}LinkList;

LinkList* createLinkList(int a[], int n) {
	LinkList *head, *p, *q;
	for (int i = 0; i < n; ++i) {
		q = new LinkList;
		q->data = a[i];
		if (i == 0) {
			p = q;
			head = p;
			continue;
		}
		p->next = q;
		p = q;
	}
	return head;
}

void printLinkList(LinkList *head) {
	while (head) {
		cout << head->data << ' ';
		head = head->next;
	}
	cout << endl;
}

void deleteANode(LinkList *node) {
	LinkList *temp = node->next;
	node->data = temp->data;
	node->next = temp->next;
	delete temp;
}

int main(int argc, char const *argv[]) {
	int a[] = {1, 2, 4, 5, 4, 4, 9};
	int length = 7;
	LinkList *head = createLinkList(a, length);
	printLinkList(head);
	LinkList *p = head->next->next->next;
	deleteANode(p);
	printLinkList(head);
	return 0;
}
