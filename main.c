#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "table.h"

const int MAX = 50;

int main()
{
    bool exit = false;
    fprintf(stdout,"Welcome to table.c test shell!\n");

    while (!exit)
    {
        char buffer[MAX];
        char instruction[MAX];
        int param = -99;

        fprintf(stdin, "> ");
        fgets(buffer, MAX, stdin);
        instruction[0] = *strtok(&buffer[0], " ");
        sscanf(strtok(NULL, " "), "%d", &param);

        if (strcmp("insert", instruction))
        {
            if (insertItem(param))
            {
                printf("Successfuly inserted %d.\n", param);
            }
            else
            {
                fprintf(stderr, "Failed to insert %d.\n", param);
            }
        }
        else if (strcmp("remove", instruction))
        {
            if (removeItem(param))
            {
                printf("Successfuly removed %d.\n", param);
            }
            else
            {
                fprintf(stderr, "Failed to remove %d.\n", param);
            }
        }
        else if (strcmp("search", instruction))
        {
            if (search(param))
            {
                printf("%d found.\n", param);
            }
            else
            {
                fprintf(stderr, "%d not found.\n", param);
            }
        }
        else if (strcmp("first", instruction))
        {
            int * const item = malloc(sizeof(int));
            
            if (firstItem(item))
            {
                printf("First item is %d.\n", *item);
            }
            else
            {
                fprintf(stderr, "List is empty.\n");
            }

            free(item);
        }
        else if (strcmp("next", instruction))
        {
            int * const item = malloc(sizeof(int));
            
            if (nextItem(item))
            {
                printf("Next item is %d.\n", *item);
            }
            else
            {
                fprintf(stderr, "No more items.\n");
            }

            free(item);
        }
        else if (strcmp("clear", instruction))
        {
            clearTable();
            printf("Table cleard.\n");
        }
        else if (strcmp("print", instruction))
        {
            printTable();
        }
        else if (strcmp("exit", instruction))
        {
            exit = true;
        }
        else
        {
            fprintf(stderr, "Command not found.\n");
        }
    }

    printf("bye!\n");
}