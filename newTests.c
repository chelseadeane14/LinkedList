
#include <stdio.h>
#include "ldata.h"
#include "llist.h"

int
main(void)
{
    struct LData *d1 = create_data("DC", 38.9, 77.0);
    struct LData *d2 = create_data("New York", 40.7, 74.0);
    struct LData *d3 = create_data("Los Angeles", 34.1, 118.3);
    struct LData *d4 = create_data("Chicago", 41.8, 87.7);
    struct LData *d5;
    
    struct LList *s = create_empty_list();
    
    print_data(d1); printf("\n");   // expected: (DC, 38.9, 77.0)
    print_list(s); printf("\n");    // expected: [ ]
    add_first(s, d1);
    print_list(s); printf("\n");    // expected: [(DC, 38.9, 77.0)]
    add_first(s, d2);
    add_last(s, d3);
    print_list(s); printf("\n");    // expected: [(New York, 40.7, 74.0) (DC, 38.9, 77.0) (Los Angeles, 34.1, 118.3)]
    insertion_sort(s);
    printf("Insertion sort has been called. Expected is: [(DC, 38.9, 77.0) (Los Angeles, 34.1, 118.3) (New York, 40.7, 74.0)]\n");
    print_list(s); printf("\n");
    
    
    d5 = rem_last(s);
    print_list(s); printf("\n");    // expected: [(New York, 40.7, 74.0) (DC, 38.9, 77.0)]
    print_data(d5); printf("\n");   // expected: (Los Angeles, 34.1, 118.3)
    
    
    printf("\n\nStarting My Tests\n");
    
    
    printf("1. Expected Value = 1  Actual Value = %d\n", contains(s,d2)); //contains()
    printf("2. Expected Value = 2  Actual Value = %d\n", size(s)); // size()
    
    printf("Expected: (DC, 38.9, 77.0)\n");
    print_data(get_elem(s, 0)); printf("\n\n"); //expected: (New York, 40.7, 74.0)
    
    printf("Expected: (Los Angeles, 34.1, 118.3)\n");
    print_data(get_elem(s, 1)); printf("\n\n"); //expected: (DC, 38.9, 77.0)
    add_elem(s, d4, 1);
    printf("3. Expected Value = 3  Actual Value = %d\n", size(s)); // size()
    
    printf("Expected: [(DC, 38.9, 77.0) (Chicago, 41.8, 87.7) (Los Angeles, 34.1, 118.3)]\n");
    print_list(s); printf("\n\n"); //expected: expected: [(New York, 40.7, 74.0) (Chicago, 41.8, 87.7) (DC, 38.9, 77.0)]
    swap_elems(s,0,2);
    
    printf("Expected: [(Los Angeles, 34.1, 118.3) (Chicago, 41.8, 87.7) (DC, 38.9, 77.0)]\n");
    print_list(s); printf("\n\n");
    
    rem_first(s);
    printf("4. Expected Value = 2 Actual Value = %d\n", size(s)); // size()
    
    printf("Expected: [(Chicago, 41.8, 87.7) (DC, 38.9, 77.0)]\n");
    print_list(s); printf("\n\n"); //expected: [(Chicago, 41.8, 87.7) (DC, 38.9, 77.0)]
    rem_elem(s, 1);
    
    printf("Expected: [(Chicago, 41.8, 87.7)]\n");
    print_list(s); printf("\n\n"); //expected: [(DC, 38.9, 77.0)]
    printf("4. Expected Value = 1  Actual Value = %d\n", size(s)); // size()
    clear_list(s);
    printf("5. Expected Value = 0  Actual Value = %d\n", size(s)); // size()
    printf("6. Expected Value = 1  Actual Value = %d\n", is_empty(s)); //is_empty()
    
    printf("Expected: [ ]\n");
    print_list(s); printf("\n\n"); // expected: [ ]
}
