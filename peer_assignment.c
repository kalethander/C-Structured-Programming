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

void print_file( FILE *fptr)
{
    int c;
    rewind(fptr);
    while((c = getc(fptr)) != EOF)
	putc(c, stdout);
}

void print_output( int maximum, double average, FILE *ofp)
{
    int c;
    while((c = getc(stdout)) != EOF)
	putc(c, ofp);
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

double compute_average( list_of_int* list)
{
    int i;
    double sum = 0.0;
    for( i = 0; i < (list -> num_el); i++) {
	sum += (list -> data[i]);
	printf("sum is %lf\n", sum); }
    return (sum / (list -> num_el));
}

int compute_max( list_of_int* list)
{
    int i = 1;
    int* maximum;
    while(i < (list -> num_el)) {
	maximum = (list -> data[i - 1] > list -> data[i]) ? &(list->data[i-1]) : &(list->data[i]);
	i++; }
    return *maximum;
}

int main(int argc, char* argv[])
{
    FILE *ifp, *ofp;

    int maximum, num_el;
    double average;
    list_of_int* list = malloc(sizeof(list_of_int));

    ifp = fopen(argv[1], "r+");
    ofp = fopen(argv[2], "w+");
    printf("The numbers from the file %s are \n", argv[1]);
    print_file(ifp);
    printf("\n\n");

    file_to_array(list, ifp);
    maximum = compute_max( list);
    average = compute_average( list);

    printf("The average of these integers is %lf\n", average);
    printf("The maximum of these integers is %d\n", maximum);
    print_output(maximum, average, ofp);
    printf("\n\n");
    fclose(ifp);
    fclose(ofp);

    return 0;
}