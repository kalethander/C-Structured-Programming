/*
I/O Assignment
Kyle Lethander
Aug. 19, 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

typedef struct list_of_int {
    int num_el;
    int data[];
} list_of_int;

typedef struct node {
    int d;
    struct node* left;
    struct node* right;
} NODE;

typedef NODE	*BTREE;

void print_file( FILE *fptr)
{
    int c;
    rewind(fptr);
    while((c = getc(fptr)) != EOF)
	putc(c, stdout);
}

void file_to_array( list_of_int* list, FILE *ifp)
{
    int c, element = 0, i = 0;

    rewind(ifp);
    list -> num_el = (getc(ifp) - '0');
    list -> data[list -> num_el];
    getc(ifp);    // removes the space

    while((c = getc(ifp)) != EOF) {
	if( c >= '0' && c <= '9') {
	    element *= 10;
	    element += ( c - '0');}
        else {
	    list -> data[i++] = element;
	    element = 0;}
    }	    
}

void inorder(BTREE node)
{
    if(node != NULL)
    {
	inorder(node -> left);
	printf("%d ", node -> d);
	inorder(node -> right);
    }
}

BTREE gen_node( void) { return(malloc(sizeof(NODE))); }

BTREE init_node( int data, BTREE p1, BTREE p2)
{
    BTREE new_node = gen_node();
    new_node -> d = data;
    new_node -> left = p1;
    new_node -> right = p2;
    return new_node;
}

BTREE build_tree( list_of_int* list, int i)
{
    int size = list -> num_el;
    if( i >= size)
	return NULL;
    else
	return( init_node(list -> data[i],
			build_tree(list, 2*i + 1),
			build_tree(list, 2*i + 2)));
}

int main(int argc, char* argv[])
{
    FILE *ifp;

    list_of_int* list = malloc(sizeof(list_of_int));
    BTREE tree;

    ifp = fopen(argv[1], "r+");
    printf("The numbers from the file %s are \n", argv[1]);
    print_file(ifp);
    printf("\n\n");

    file_to_array(list, ifp);
    tree = build_tree( list, 0);
    printf("Binary tree representation: \n");
    inorder(tree);
    printf("\n\n");    
    fclose(ifp);

    return 0;
}