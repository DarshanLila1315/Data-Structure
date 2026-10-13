#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *createNode(int data) {
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	return node;
}

void splitList(struct Node *head, struct Node *head1, struct Node *head2) {
	struct Node *slow = head, *fast = head;

	if (head == NULL || head->next == head) {
		head1 = head;
		head2 = NULL;
		return;
	}

	while (fast->next != head && fast->next->next != head) {
		slow = slow->next;
		fast = fast->next->next;
	}

	if (fast->next->next == head)
		fast = fast->next;

	head1 = head;
	head2 = slow->next;
	slow->next = head1;
	fast->next = head2;
}

void display(struct Node *head) {
	struct Node *current = head;

	if (head == NULL) {
		printf("Empty list\n");
		return;
	}

	do {
		printf("%d ", current->data);
		current = current->next;
	} while (current != head);
	printf("\n");
}

int main(void) {
	int n, value;
	struct Node *head = NULL, *tail = NULL;
	struct Node *head1, *head2;

	printf("Enter number of nodes: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &value);
		struct Node *node = createNode(value);
		if (head == NULL)
			head = node;
		else
			tail->next = node;
		tail = node;
	}

	if (tail != NULL)
		tail->next = head;

	splitList(head, &head1, &head2);
	printf("First half: ");
	display(head1);
	printf("Second half: ");
	display(head2);

	return 0;
}

