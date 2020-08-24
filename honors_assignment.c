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


int_list* to_front( int_list* list)
{
    while( list -> prev != NULL)
	list = list -> prev;
    return list;
}

int_list* to_back( int_list* list)
{
    while( list -> next != NULL)
	list = list -> next;
    return list;
}

void print_forward( int_list* list)
{
    int i = 0;
    list = to_front( list);
    while(list != NULL) {
	printf("Element %d is %d\n", i++, list -> d);
	list = list -> next;
    }
}

int_list* rm_node( int_list* node)
{
    int_list* p1 = node -> prev;
    int_list* p2 = node -> next;
    if (p1 == NULL) { p2 -> prev = NULL;}
    else if (p2 == NULL) { p1 -> next = NULL;}
    else {
	p1 -> next = p2;
	p2 -> prev = p1;
    }
    free(node);
    return p2;
}

int_list* access_element( int_list* list, int n)
{
    list = to_front( list);
    for( int i = 0; i < (n - 1); i++)
	list = list -> next;
    return list;
}

int_list* rm_duplicates( int_list* list, int n)
{
    for( int i = 1; i < n; i++) 
    {
	for( int j = i + 1; j < n; j++)
	{
	    if( access_element( list, i)->d == access_element( list, j)->d) {
		list = rm_node(access_element( list, j)); n--;}
	}
    }
    return list;
}

int_list* create_node( int data)
{
    int_list* node = malloc(sizeof(int_list));
    node -> d = data;
    node -> prev = NULL;
    node -> next = NULL;
    return node;
}

int_list* add_to_front( int data, int_list* list)
{
    int_list* new_node = create_node( data);
    list = to_front( list);
    list -> prev = new_node;
    new_node -> next = list;
    return new_node;
}

int_list* generate_list( int n)
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





/*


int_list* rm_duplicates( int_list* list)
{
    int* data;
    int j = 0;
    list = to_front( list);
    while( list -> next != NULL) {
	j++;
	data = &(list -> d);
	list = list -> next;
	while( list -> next != NULL) {
	    if( list -> d == *data)
		list = rm_node( list);
	    list = list -> next;    
	}
	list = to_front( list);
	for( int i = 0; i < j; i++)
	    list = list -> next;
    }
    list = to_front(list);
    return list;
}


*/




/*
list = to_back(list);
    if( (list -> prev) -> d == list -> d)
	list = rm_node( list);
 */





/* int_list* add_to_back( int data, int_list* list)
{
    int_list* new_node = create_node( data);
    list = to_back( list);
    list -> next = new_node;
    new_node -> prev = list;
    list = to_front(new_node);
    return list;
} */

/*  
void print_backward(int_list* list)
{
    int i = 0;
    list = to_back( list);
    while(list != NULL) {
	printf("Element %d is %d\n", i++, list -> d);
	list = list -> prev;
    }
} */