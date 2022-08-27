// /////////////////////////////////////////////////////////
// 
// File:   HW5_1 TEMPLATE
// Author: Hesham Elshafey
// Date:   2/25/2022
//
// This program reimplements strcat, strcpy, strcmp, 
// and strlen using pointer arithmetic.
// 
// User inputs what operation they want to perform,
// and the strings 
// /////////////////////////////////////////////////////////
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* my_strcat(char *dest, const char *src);
int my_strcmp(const char *str1, const char *str2);
size_t my_strlen(const char *str);
char* my_strrev(char *dest);
void usage(void);

int main(void)
{
    char buffer[100];
    char command[21];
    char str1[81];
    char str2[41];
    char extra[41];
    int done = 0;

    usage();
    do
    {
        printf("? ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            
            break;
        }
        int args = sscanf(buffer, "%20s %40s %40s %40s", command, str1, str2, extra);
        switch (args)
        {
            case 0:
                usage();
                break;
            case 1:
                if (strcmp(command, "quit") == 0)
                {
                    done = 1;
                    break;
                }
                usage();
                break;
            case 2:
                if (strcmp(command, "strlen") == 0)
                {
                    
                    printf("Result: %ld\n" , my_strlen(str1));
                    break;
                } 
                else if (strcmp(command, "strrev") == 0)
                {
                    
                   my_strrev(str1);
                   break;
                } else
                {
                    usage();
                }
                break;
            case 3:
                if(strcmp(command, "strcmp")==0)
                {
                    printf("Result: %d\n", my_strcmp(str1,str2));
                }
                else if (strcmp(command, "strcat")==0)
                {
                    my_strcat(str1,str2);
                }
                else
                {
                    usage();
                }
                
                break;
            default:
                usage();
                break;
        }
    } while (!done);

    printf("Bye!\n");
    return 0;
}

void usage(void)
{
    printf("Input an operation and up to two strings\n");
    printf("Usage:\n");
    printf("  strcat dest_string src_string\n");
    printf("  strcmp string1 string2\n");
    printf("  strlen string\n");
    printf("  strrev src_string\n");
    printf("  quit\n");
}

char* my_strcat(char *dest, const char *src)
{
    char string[100];
    int i = 0;
    for(; *dest != '\0'; *dest++)
    {
        string[i]= *dest;
        i++;
    }
    for(; *src !='\0'; *src++)
    {
        string[i] = *src;
        i++;
    }
    printf("Result : %s\n", string);
    return 0;
    
}

int my_strcmp(const char *str1, const char *str2)
{ 
   int sum1 = 0;
   int sum2 = 0;

    for(; *str1 != '\0'; *str1++ )
    {
        sum1 += *str1;
    }
    for(; *str2 != '\0'; *str2++ )
    {
        sum2 += *str2;
    }
     if ( sum2 == sum1)
     return 0;
     if ( sum2 > sum1)
     return -1;
     if ( sum2 < sum1)
     return 1;
}


size_t my_strlen(const char *str)
{   int number = 0;
    for(; *str != '\0'; *str++ )
    {
          number ++;
         
    }
    return (number);
}

char* my_strrev(char *dest)
{
    char string2[100];
    char string3[100];
    int y = 0;
    int z = 0;

    for(; *dest != '\0'; *dest++)
    {
        string2[y] = *dest;
        y++;
    }
    while ( y > 0 )
    {
        string3[z] = string2[y-1];
        y--;
        z++;
    }
     string2[z] = '\0';
     printf("Result: %s\n", string3);
}  