# Coursera: C Structured Programming

Start: 11/08/2023
End: 

Sessions:
- 11/08/2023
- 11/10/2023
- 11/11/2023
- 11/16/2023

## User Defined Types 

C has multiple types and stuff, but there's a lot to do 
when it comes to data, and not only raw binary blob data.

There's some ways to define and create new Types in order to 
have more stuff to do and limit what should and what shouldn't the code do
with it's types.

## Enum

Enum is a way to create a custom data type which will enumerate a sequence, 
the days of the week: 

enum Days { mon, tue, wed, thu, fri };

That way, the compiler and C will take, by example, tuesday as it's index which is 1.
But we can understand them more easily without using only the indexes.

In order to use the enum will need to use the 'type'. We can change it with typedef
enum Day var\_name = val;

These work wonderfully with switches, you can just pass the name value of the index, and
it'll process it normaly.

These can be casted to ints, obviously.

## typedef

We can use type def to define some customs types.

With enums we can just
typdef enum EnumName enumName;
So in order to use EnumName we can only do it by using enumName as the type.

## PreProcesor
It's a way to do some imports, definitions and others. 

Some are : #includes <lib>
Which are a way to add header files whom define generally functions, 
constants and others.

They are generally stored in /usr/include

#define NAME value: are used to define constants, 
but their types are not verified on the compiling, only at run time

#define MACRO() function: can be also used to define macros, 
which are just fast and easy functions, can accept args if they're defined inside the parenthesis.
These could be mutliple lines by using \\ as a \\n

But macros are not recommended, so we shouldn't use them that much or at all. 
We can preprocess the script and only leave the code before the compilation by using the flag -E in gcc
$ gcc -E -o a.out a.c

But idk what to do with the remaining file.

There's a GNU Manual for this, so if anything, go there!

## Asserts IN C

Asserts are a way to mathematically or a logically way to test our code. 
They are included in assert.h, and they will abort the code if a conditional passed as arg
is 0.

But if we define in the preprocesor NDEBUG, as a flag, whitout value. The code will ignore the 
asserts and run normally, generaly used, like the name implies, to debug the code in development.

This could be defined inside the code file with:
#define NDEBUG
or in while executing the compiler with:
$ gcc -o a.out a.c -DNDEBUG

## Structs and ADTs

Structs are a way to implement Abstract Data Types, which behave like a simple python dict, or like an object
which only has properties.

It's defined like:

struct foo {
	type property1;
	type property2;
	...
	type propertyn;
} bar;

We can use typedef so we can use the foo type everywhere

typedef struct foo { 
	... 
} bar;

Then we can use the variable like this using the operator point  .  :
bar.property1 = value;

Or by using pointers by the member accesing operator  ->  :
\*bar\-\>property = value;

If we try to use the struct type recursively, inside the same struct, we have to use the struct NAME
as the type even if we have used typedef.

typedef struct foo {
	type property1;
	struct foo property2;
	...
} foo;

## Stacks

An Abstract Data Type which let us 'stack' data, just like a stack or pile of hot cakes, 
the first on top goes first, and the last one goes at last place.

LIFO: Last In First Out.

There's a nice implementation of it in C. Great.

## Linked List

Is a List wich is a series of nodes connected each other by using pointers.
