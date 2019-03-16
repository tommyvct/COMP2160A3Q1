#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "table.h"

const int MAX = 50;

int main(int argc,char *argv[])
{
    FILE * instructionStream = stdin;
    bool readScript = false;

    if (argc > 1)
    {
        instructionStream = fopen(argv[1], "r");
        readScript = true;
        printf("Running script from \"%s\".\n", argv[1]);
    }
    else
    {
        fprintf(stdout,"Welcome to table.c test shell!\n");
    }
    

    while (true)
    // interal exit
    // exit condition: EOF or "exit" as instrucion
    {
        char * buffer = malloc(sizeof(char) * MAX);
        char * instruction = NULL;
        char * paramString;
        int param;

        printf("> ");
        fgets(buffer, MAX, instructionStream);

        // get instruction
        instruction = strtok(buffer, " ");
        // if pressed control-d or EOF
        if (instruction == NULL)
        {
            printf("\n");
            break;
        }
        // if pressed enter
        else if (!strcmp("\n", instruction))
        {
            if (readScript)
            {
                printf("\n");
            }
            
            continue;
        }

        // get parameter
        paramString = strtok(NULL, " ");
        // if there is a parameter after instruction
        if (paramString != NULL)
        {
            // is parameter legit?
            int paramStatus = sscanf(paramString, "%d", &param);
            // if legit
            if (paramStatus != EOF && paramStatus != 0)
            {
                if (!strcmp("insert", instruction))
                {
                    if (insertItem(param))
                    {
                        printf("Successfuly inserted %d.\n", param);
                    }
                    else
                    {
                        fprintf(stdout, "Failed to insert %d.\n", param);
                    }
                }
                else if (!strcmp("remove", instruction))
                {
                    if (removeItem(param))
                    {
                        printf("Successfuly removed %d.\n", param);
                    }
                    else
                    {
                        fprintf(stdout, "Failed to remove %d.\n", param);
                    }
                }
                else if (!strcmp("search", instruction))
                {
                    if (search(param))
                    {
                        printf("%d found.\n", param);
                    }
                    else
                    {
                        fprintf(stdout, "%d not found.\n", param);
                    }
                }
                else
                {
                    fprintf(stdout, "Command not found.\n");
                }

            }
            else
            {
                fprintf(stdout, "Invalid parameter. Integer expected.\n");
            }
        }
        else
        {
            if (!strcmp("clear\n", instruction))
            {
                clearTable();
                printf("Table cleard.\n");
            }
            else if (!strcmp("first\n", instruction))
            {
                int * const item = malloc(sizeof(int));
                
                if (firstItem(item))
                {
                    printf("First item is %d.\n", *item);
                }
                else
                {
                    fprintf(stdout, "List is empty.\n");
                }

                free(item);
            }
            else if (!strcmp("next\n", instruction))
            {
                int * const item = malloc(sizeof(int));
                
                if (nextItem(item))
                {
                    printf("Next item is %d.\n", *item);
                }
                else
                {
                    fprintf(stdout, "No more items.\n");
                }

                free(item);
            }
            else if (!strcmp("print\n", instruction))
            {
                printTable();
            }
            else if (!strcmp("exit\n", instruction))
            {
                break;
            }
            else
            {
                fprintf(stdout, "Command not found.\n");
            }
        }

        if (buffer != NULL)
        {
            free(buffer);
        }
    }

    if (readScript)
    {
        printf("End of script.\n");
    }
    else
    {
        printf("bye!\n");
    }

    return 0;
}