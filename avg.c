/*
Objectives
Re-familiarize yourself with the C programming language
Re-familiarize yourself with the shell / terminal / command-line of UNIX
Learn (as a side effect) how to use a proper code editor, such as cLion (or emacs or vi or...)
Learn a little about how UNIX utilities are implemented
While the project focuses upon writing simple C programs, you can see from the above that even that requires a bunch of other previous knowledge, including a basic idea of what a shell is and how to use the command line on some UNIX-based systems (e.g., Linux or macOS), how to use a code editor such as cLion or emacs or vi, and of course a basic understanding of C programming.

Before beginning: If you need a refresher on the Unix/C environment, read this tutorial (链接到外部网站。).

To start cLion you can type cLion in the VM that you installed.

Summary of what gets turned in:

A single .c file avg.c.
It should compile successfully in cLion on the VM given.
Each should (hopefully) pass the tests we supply to you.
avg
We are going to write a utility that is missing from linux: avg.  To create the avg binary, you'll be creating a single source file, avg.c, which will involve writing C code to implement it.
Sometimes you have a file full of numbers and you want to average them all up. You could write a complicated function with awk, but the syntax is hard to remember. Instead we want to write a program that does that for us.

For this assignment assume that you have a text file with numbers separated by newlines. You want to read the numbers in and add them up ; then divide by the line count to get the average. Since we want to be flexible on the type and size of numbers we can handle, we will use double floating point.

You must be able to handle a file with any number of numbers (including no numbers). You can assume that the files are well formed: it will contain only valid numbers separated by newlines.

For example, numbers.txt contains a list of numbers.

*/


#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    double n;
    double sum = 0;
    int count = 0;
    double avg;

    FILE *fp = fopen("./numbers.txt", "r");
    if (fp == NULL){
        printf("avg: cannot open file\n");
        exit(1);
    }
    
    while (fscanf(fp, "%lf", &n) == 1){
        sum += n;
        count++;
    }
        
    avg = (double) sum / count;
    
    printf("%-8s= %f\n", "Average", avg);

    fclose(fp);
    
    return 0;
}
