// /////////////////////////////////////////////////////////
// 
// File:   hw5_2_William_Moon.c
// Author: Hesham Elshafey
// Date:   2/25/2022
//
// This program uses the Selection Sort algorithm to
// sort a list of people
// 
// /////////////////////////////////////////////////////////
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    char name[25];
    int age;
} Person;

int get_num_people(void);
int get_sort_type(void);
void get_people_info(Person [], int);
void sort_list(Person [], int, int);
int get_sort_value(const Person *, int);
void print_list(Person* order[], int num_people);

int main(void)
{
    int num_people = get_num_people();
    Person people[num_people];

    get_people_info(people, num_people);
    int sort_type = get_sort_type();

    sort_list(people, num_people, sort_type);
    
    return 0;
}

int get_num_people(void)
{
    int num_people = 0;
    printf("How many people would you like to enter? ");
    scanf("%d", &num_people);
    return num_people;
}

void get_people_info(Person person[], int num_people)
{
    for (int i=0; i < num_people; i++, person++)
    {
        printf("Please enter person %d's first name and age: ", i+1);
        scanf("%24s %d", person->name, &(person->age));
    }
}

int get_sort_type(void)
{
    int sort_type = -1;
    printf("Would you like to sort by age or alphabetical order?\n");
    do
    {
        printf("Enter 0 for age, 1 for alphabetical order (first letter only): ");
        scanf("%d", &sort_type);
    } while (sort_type < 0 || sort_type > 1);

    return sort_type;
}

void sort_list(Person people[], int num_people, int sort_type)
{
    Person *this_person = people;
    Person * sort_order[num_people];
    Person **sort_idx = sort_order;
    int x = 0 ;
    int y = 0 ;
   

    
    
    for (int i=0; i < num_people; i++)
    {
        *sort_idx++ = this_person++;
    }
     if(sort_type == 0)
     {
      for( x =0; x<num_people ; x++)
      {
          for ( y=x+1; y<num_people; y++)
          {
               if( (*(sort_order + x))->age > (*(sort_order + y))->age){
                    Person *temp =  (*(sort_order + y));
                    ((*(sort_order + y))) = (*(sort_order+x));
                    (*(sort_order + x)) = temp; 
               }
          }
      }
     }
     if(sort_type == 1)
     {
        
      for( x = 0; x<num_people ; x++)
      {
          for ( y=x+1; y<num_people; y++)
          {
               if( (*(sort_order + x))->name[0] > (*(sort_order + y))->name[0]){
                    Person *temp =  (*(sort_order + y));
                    ((*(sort_order + y))) = (*(sort_order+x));
                    (*(sort_order + x)) = temp; 
               }
          }
      }
     }
    

    print_list(sort_order, num_people);
}


void print_list( Person* sort_order[], int num_people)
{
    printf("The sorted list:\n");
    for (int i=0; i < num_people; i++)
    {
         Person *person = *(sort_order + i);
        printf("%s, %d\n", person->name, person->age);
    }
}


int get_sort_value(const Person * person, int sort_type)
{
    return sort_type ? (int)person->name[0]: person->age;
}    