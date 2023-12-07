# Coursera: C Structured Programming

Start: 11/08/2023
End: 12/06/2023

Sessions:
- 11/08/2023
- 11/10/2023
- 11/11/2023
- 11/16/2023
- 11/20/2023
- 11/22/2023
- 12/06/2023

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

## FILE I/O

There's a bunch of internal C stdio.h functions which let us read, write and process files in C.

The main usage is using a FILE variable, then create or open, read, write in a file, with the functions available.

## Command line Args

Generraly in C, you can pass args to the main function by defining two args in it.

int argc, char \*arg[]

The first will take the number of args passed and the seccond, a array of the strings or args passed.
If you need another type of kind of arg other than a string you should cast it.

## Advanced I/O

The most avanced I/O in C is stdin and stdout, which are a way to recieve input and send output.
But more than that, it's an industry standard, one which all commandline programs MUST have.

Using this I/O will let the user send a file as an input or ouput using the shell standard input and output
operators.

In bash

$ ./program.out < inputfile
$ ./program.out > outputfile
$ ./program.out >> rewriteInOutputFile

Although this sounds extreamly important and rather difficult to make from scratch. We can make our 
scripts stdin and stdout compatible by just changing printf and scanf with 

fprintf(where to print, "format", ...values);

fscanf(where to scan, "format", ...values references);

These are generally file functions, but if we pass in the first arg of the function

stin or stout. 

We would be using the stdinput and stdoutput standard.
It also works normally if we need to use it just like a normal printf or scanf.

## C++

C is a subset of C++, huh?

Yeah. Everything that you can do in C you can do it in C++.
The only thing is that C++ has more functionalities, stuff and such.

There's a lot of new stuff:
- addons, new stuff and changes to the libc standard library.
- auto, for declaring a automatic type for a value, so the compiler
	gets to choose the type of a variable acording to their current value
	usage and such
- STL: New classes which has mainly data structures available, more 
	complex than the simple allocated-array, but with way more functionalities.
	for example, the vector is a array look alike, but a little bit better.

That and in general terms, the OOP implemtation of C.
Which by classes you can create more complex objects, which are not a total abstraction of an object 
but and object that we can actively use.

And that was it...

One more done.
