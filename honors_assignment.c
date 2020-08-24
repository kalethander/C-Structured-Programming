/*
    Week 3 Peer Assignment
    Kyle Lethander
    Aug. 17, 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_RANGE 50
#define RANDOM_NUM (rand() % NUM_RANGE)

typedef struct int_list{
    int d;
    struct int_list *prev;
    struct int_list *next;
} int_list;


int_list* to_front( int_list* list)	// direct to list head
{
    while( list -> prev != NULL)
	list = list -> prev;
    return list;
}

int_list* to_back( int_list* list)	// direct to list tail
{
    while( list -> next != NULL)
	list = list -> next;
    return list;
}

void print_forward( int_list* list)	// print list in order
{
    int i = 0;
    list = to_front( list);
    while(list != NULL) {
	printf("Element %d is %d\n", i++, list -> d);
	list = list -> next;
    }
}

int_list* rm_node( int_list* node)	// remove a node
{
    int_list* p1 = node -> prev;
    int_list* p2 = node -> next;
    if (p1 == NULL) { p2 -> prev = NULL; return p2;}
    else if (p2 == NULL) { p1 -> next = NULL; return p1;}
    else {
	p1 -> next = p2;
	p2 -> prev = p1;
	free(node);
	return p2;
    }
}

int_list* access_element( int_list* list, int n)	// access element n
{
    list = to_front( list);
    for( int i = 0; i < (n - 1); i++)
	list = list -> next;
    return list;
}

int_list* rm_duplicates( int_list* list, int n)		// remove integer duplicates
{
    for( int i = 1; i < n; i++) 
    {
	for( int j = i + 1; j <= n; j++)
	{
	    if( access_element( list, i)->d == access_element( list, j)->d) {
		list = rm_node(access_element( list, j)); 
		n--;
	    }
	}
    }
    return list;
}

int_list* create_node( int data)	// creates new node instance
{
    int_list* node = malloc(sizeof(int_list));
    node -> d = data;
    node -> prev = NULL;
    node -> next = NULL;
    return node;
}

int_list* add_to_front( int data, int_list* list)	// append node to front of list
{
    int_list* new_node = create_node( data);
    list = to_front( list);
    list -> prev = new_node;
    new_node -> next = list;
    return new_node;
}

int_list* generate_list( int n)		// generates a list of nodes
{
    int i;
    srand(clock());
    int_list* list = create_node( RANDOM_NUM);    // create first element

    while( i < n) {list = add_to_front( RANDOM_NUM, list); i++;}
    
    return list;
}

int main(void)
{
    int n = 200;
    int_list* list = generate_list( n);
    printf("\nOriginal list: \n");
    print_forward( list);

    list = rm_duplicates( list, n);
    printf("\nMutated list: \n");
    print_forward( list); 

    return 0;
}