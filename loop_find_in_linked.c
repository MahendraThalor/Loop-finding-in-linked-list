/* ----------------------------------------------------------------------------
 * Program to check loop in given linked list.
 * ----------------------------------------------------------------------------
 */

/* Header files. */
#include<stdio.h> /* To print the outputs. */
#include<stdlib.h> /* Used for malloc/calloc. */
#include<stdbool.h> /* To use bool. */

/* Structure of node. */
struct node
{
	int		data;
	struct	node * link;
};

/* Declarations of functions. */
struct node * createNode(int data);
bool isLoopInList(struct node * head);
void printList(struct node * head);

/* Main body. */
int main()
{
	struct node * head = NULL;

	/* Empty list. */

	/* Create the list. */
	head = createNode(1);
	return 0;
}

/*
 * This function creates a node and return the link of that node.
 */
struct node *
createNode(int data)
{
	struct node * temp = NULL;

	/* Allocate memory for 1 node. */
	temp = (struct node *) malloc (sizeof(struct node));

	/* Initiliaze the members. */
	temp->data = data;
	temp->link = NULL;

	/* Return adrres of new allocated node. */
	return temp;
}

/*
 * This will print the list but list should not contain loop.
 */
void printList(struct node * head)
{
	struct node * temp = head;

	/* If head is null, then list is empty. */
	if (head == NULL)
	{
		printf("\nList is empty.\n");
		return;
	}

	printf("List is as:");

	/* Print all the elements till NULL. */
	while (temp != NULL)
	{
		printf(" %d", temp->data);

		/* Move to next node. */
		temp = temp->link;
	}
}

/*
 * This function check that if any loop in the list or not, if loop, then it
 * will return true else false.
 */
bool isLoopInList(struct node * head)
{
	bool	is_loop = false;

	/*
	 * If head is pointing to null OR link of head is NULL, it means there is
	 * no loop in the list so return from here.
	 */
	if (head == NULL || head->link == NULL)
		return is_loop;

	/*
	 * To check loop, we will take 2 pointers and traverse the list.
	 * slow_pointer: increment by 1
	 * fast_pointer: increment by 2
	 *
	 * After each operation, check that if both the pointers are pointing to
	 * same node, it means, loop or if we reached to null, then there is no
	 * loop in the list.
	 */
	slow_ptr = head;
	fast_ptr = head->link;

	while (fast_ptr != NULL)
	{
		/*
		 * If slow_ptr and fast_ptr, both are pointing to same address, then
		 * we are done. Loop is in list.
		 */
		if (slow_ptr == fast_ptr)
		{
			is_loop = true;
			break;
		}

		/* Move the slow ptr to next node. */
		slow_ptr = slow_ptr->link;

		/*
		 * Move the fast ptr to 2 node.
		 *
		 * Note: 1st we move fast ptr to 1 node and based on next link, we will
		 * move.
		 */
		fast_ptr = fast_ptr->link;

		/* If fast ptr is not null, then move to next ptr. */
		if (fast_ptr)
			fast_ptr = fast_ptr->link;
		else
		{
			/* We reached to null, so break. */
			break;
		}
	}

	return is_loop;
}
