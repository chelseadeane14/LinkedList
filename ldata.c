//
//  ldata.c
//  
//
//  Created by Chelsea Deane on 12/17/15.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ldata.h"

// Creates and returns an empty data record, where
// city = "", lat = 0.0, lon = 0.0
struct LData *create_empty_data() {
    struct LData *data = malloc(sizeof(struct LData));
    data->city = "";
    data->lat = 0.0;
    data->lon = 0.0;
    return data;
}

// Creates and returns a data record with the specified values
struct LData *create_data(char* city, double lat, double lon){
    struct LData *data = malloc(sizeof(struct LData));
    data->city = city;
    data->lat = lat;
    data->lon = lon;
    return data;
}

// Returns true if and only if the city of data1 comes
// alphanumerically before or is the same as the city of data2
int are_ordered(struct LData *data1, struct LData *data2){
    if(strcmp(data1->city,data2->city) < 0) {
        return 1;
    }
    else if(strcmp(data1->city,data2->city) == 0){        //1 - true
        return 1;                                          //0 - false
    }
    else if(strcmp(data1->city,data2->city) > 0){
        return 0;
    }
    return 0;

}

// Returns true if and only if the city of data1 equals the city of data2
int are_equal(struct LData *data1, struct LData *data2){
    if(strcmp(data1->city, data2->city) == 0){
        return 1;
    }
    else{
        return 0;
    }
    return 0;
}

// Swaps the contents of data1 and data2
void swap_data(struct LData *data1, struct LData *data2){
    struct LData temp;
    temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}

// Resets the information in data to default values (see create_empty_data)
void clear_data(struct LData *data){
    data -> city = "";
    data -> lat = 0.0;
    data -> lon = 0.0;
    free(data);
}

// Prints the data in the format: (city, lat, lon)
// where lat and lon are printed to one decimal place
void print_data(struct LData *data){
    printf("(");
    printf("%s", data->city);
    printf(",");
    printf("%.1f", data->lat);
    printf(",");
    printf("%.1f", data->lon);
    printf(")");
}

