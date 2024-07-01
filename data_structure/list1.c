#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {

	element data;

	struct ListNode *link;

}ListNode;

ListNode * insert_first(ListNode *head, element value) {

	ListNode *p = (ListNode *) malloc(sizeof(ListNode));

	p->data = value;

	p->link = head; //100

	head = p;

	return head;

}

void print_list(ListNode *head) {

	for (ListNode *p = head; p != NULL; p = p->link)

		printf("%d->", p->data);

	printf("\n");

}

ListNode * delete_first(ListNode *head) {

	ListNode *removed;

	if (head == NULL) return NULL;

	removed = head;

	head = head->link;

	free(removed);

	return head;

}

int main() {

	ListNode *head = NULL;



	for (int i = 0; i < 5; i++) {

		head = insert_first(head, i);//head=100

		print_list(head); // 4->3->2->1->0

	}



	head = delete_first(head); //가장 먼저 4를 삭제함

	print_list(head);

}