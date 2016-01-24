//
//  listtest.c
//  
//
//  Created by Chelsea Deane on 12/17/15.
//
//

#include <stdio.h>
#include "ldata.h"
#include "llist.h"

int main() {
    
    struct LData *d1 = create_data("DC", 38.9, 77.0);
    struct LData *d2 = create_data("New York", 40.7, 74.0);
    struct LData *d3 = create_data("Los Angeles", 34.1, 118.3);
    struct LData *d4 = create_data("Chicago", 41.8, 87.7);
    struct LData *d5;
    
    struct LList *s = create_empty_list();
    printf("Test 1: expected: (DC, 38.9, 77.0)\n");
    print_data(d1); printf("\n");	// expected: (DC, 38.9, 77.0)
    printf("End of Test 1\n");
    printf("\n");
    
    printf("Test 2: expected: [ ]\n");
    print_list(s); printf("\n"); 	// expected: [ ]
    printf("End of Test 2\n");
    printf("\n");
    
    printf("Test 3: expected: [(DC, 38.9, 77.0)]\n");
    add_first(s, d1);
    print_list(s); printf("\n");	// expected: [(DC, 38.9, 77.0)]
    printf("End of Test 3\n");
    printf("\n");
    
    add_first(s, d2);
    add_last(s, d3);
    
    printf("Test 4: [(New York, 40.7, 74.0) (DC, 38.9, 77.0) (Los Angeles, 34.1, 118.3)]\n");
    print_list(s); printf("\n");	// expected: [(New York, 40.7, 74.0) (DC, 38.9, 77.0) (Los Angeles, 34.1, 118.3)]
    printf("End of Test 4\n");
    printf("\n");
    
    printf("Test 8: expected: [(New York, 40.7, 74.0)(Los Angeles, 34.1, 118.3)]\n");
    rem_elem(s, 1);
    print_list(s);
    printf("End of Test 8\n");
    printf("\n");
    
    d5 = rem_last(s);
    printf ("Test 5: expected: [(New York, 40.7, 74.0) (DC, 38.9, 77.0)]\n");
    print_list(s); printf("\n");	// expected: [(New York, 40.7, 74.0) (DC, 38.9, 77.0)]
    printf("End of Test 5\n");
    printf("\n");
    
    printf("Test 7: expected: (DC, 38.9, 77.0)\n");
    print_data(get_elem(s, 1));
    printf("End of Test 7\n");
    printf("\n");
    
    printf("Test 6: expected: (Los Angeles, 34.1, 118.3)\n");
    print_data(d5); printf("\n");	// expected: (Los Angeles, 34.1, 118.3)
    printf("End of Test 6\n");
    printf("\n");
    
}