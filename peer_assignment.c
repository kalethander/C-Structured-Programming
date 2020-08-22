/*
    Week 3 Peer Assignment
    Kyle Lethander
    Aug. 17, 2020
*/

#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN_MAX 15
#define SYM_LEN_MAX 3

typedef struct element{
    char name[NAME_LEN_MAX];
    char symbol[SYM_LEN_MAX]; 
    double atomic_weight;
    struct element *next;
} element;

void print_elements( element* e)  // note elements printed "bottom to top"
{
    while( e != NULL) {
	printf("%-12s%-10s%-10.3lf\n", e -> name, e -> symbol, e -> atomic_weight);
	e = e -> next;
    }
}

void print_header( char* title, char* h1, char* h2, char* h3)
{
    printf("%-27s\n", title);
    printf("%-12s%-10s%-10s\n", h1, h2, h3);
}

element* create_element( void)  // makes a new element
{
    element* el = (element*)malloc(sizeof(element));
    printf("Enter name of element: ");
    scanf("%s", el -> name);
    printf("Enter element symbol: ");
    scanf("%s", el -> symbol);
    printf("Enter atomic weight: ");
    scanf("%lf", &(el -> atomic_weight)); 
    el -> next = NULL;
    return el;
}

element* add_element( element* curr_list)  // adding a new element to the list
{
    element* head = create_element( );
    head -> next = curr_list;
    return head;
}

element* generate_list( element* el_list, int n)  // generating the element list
{
    int i;
    el_list = create_element( );
    for (i = 1; i < n; i++)
	el_list = add_element( el_list);
    return el_list;
}

int main(void)
{
    int n;
    printf("How many elements would you like to enter? ");
    scanf("%d", &n);
    element* el_list = (element*)malloc(sizeof(element));
    el_list = generate_list( el_list, n);

    print_header("List of the Elements", "Name", "Symbol", "Weight");
    print_elements( el_list);
    printf("\n\n");

    return 0;
}