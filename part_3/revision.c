//code by atharva patwe
#include <stdio.h>
#include <string.h>

    struct Elements       //declaring the data type
    {
        char name[50];
        char symbol[50];
        float atomic_weight;
    };
    void printElement( struct Elements element);
    int main (){
        struct Elements no1;  // declaring the number of elements to be used
        struct Elements no2;
        struct Elements no3;
        struct Elements no4;
        struct Elements no5;
        struct Elements no6;
        struct Elements no7;
        struct Elements no8;
        struct Elements no9;
        struct Elements no10;

    strcpy ( no1.name, "Hydrogen"); // inserting each element name, symbol and their weight
    strcpy ( no1.symbol, "H");
    no1.atomic_weight = 1.008;

    strcpy ( no2.name, "Helium");
    strcpy (no2.symbol, "He");
    no2.atomic_weight = 4.003;

    strcpy ( no3.name, "Lithium");
    strcpy ( no3.symbol, "Li");
    no3.atomic_weight = 6.941;

    strcpy ( no4.name, "Beryllium");
    strcpy ( no4.symbol, "Be");
    no4.atomic_weight = 9.012;

    strcpy ( no5.name, "Boron");
    strcpy ( no5.symbol, "B");
    no5.atomic_weight = 10.811;

    strcpy ( no6.name, "Carbon");
    strcpy ( no6.symbol, "C");
    no6.atomic_weight = 12.011;

    strcpy ( no7.name, "Nitrogen");
    strcpy ( no7.symbol, "N");
    no7.atomic_weight = 14.007;

    strcpy ( no8.name, "Oxygen");
    strcpy ( no8.symbol, "O");
    no8.atomic_weight = 15.999;

    strcpy ( no9.name, "Fluorine");
    strcpy ( no9.symbol, "F");
    no9.atomic_weight = 18.998;

    strcpy ( no10.name, "Neon");
    strcpy ( no10.symbol, "Ne");
    no10.atomic_weight = 20.180;

    printElement( no1);   // print out the elements name symbol and weight
    printElement( no2);
    printElement( no3);
    printElement( no4);
    printElement( no5);
    printElement( no6);
    printElement( no7);
    printElement( no8);
    printElement( no9);
    printElement( no10);

    return 0;
    }
void printElement( struct Elements element){
    printf( "Element: %s\n", element.name);  // when printed it will display Element:, Symbol: , and Atomic weight: next to the appropriate element information
    printf( "Symbol: %s\n", element.symbol);
    printf( "Atomic Weight: %f\n", element.atomic_weight);
    printf("\n\n");
}