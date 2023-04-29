#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Term{
    int Coefficient;
    int Exponent;
};
struct Polynom{
    int n;
    struct Term *Terms;
}; 

void Create (struct Polynom *p){
    int i;
    printf("Enter Number of Terms.\n");
    scanf("%d", &p -> n);

    p -> Terms = (struct Term  *) malloc((p->n) * sizeof(struct Term));

    printf("Enter Terms\n");
    for (i = 0  ; i < p -> n ; i++){
        scanf("%d%d" , &p->Terms[i].Coefficient , &p->Terms[i].Exponent);
    }
}

void Print_Polynom (struct Polynom p){
    int i;
    for (i = 0 ; i < p.n ; i++){
        printf("%d^%d" , p.Terms[i].Coefficient , p.Terms[i].Exponent);
        if (i + 1 < p.n){
            printf(" + ");
        }
    };
    printf("\n");
};







int main() {


    
    int operation;
    int in_program = 1;
    
    

    

    
    
    while (in_program){


    printf("Welcome to numeric analysis program!!!\n");
    printf("Enter a designed number to make an matematical operation you wished for .\n");
    printf("Enter 1 to perform bisection method\n");
    scanf("%d" , &operation);
    if(operation == 1){ //switch case içerisinde scanf çalışmadığı için harici olarak aldım.
        printf("Enter floor and ceiling for bisection method.\n");
        int floor,ceiling;
        printf("For floor: ");
        scanf("%d" , &floor);
        printf("\nFor ceiling: ");
        scanf("%d" , &ceiling);
        if(floor > ceiling){
            printf("You entered wrong floor and ceiling value !!!!!\n");
            printf("Switching values.\n");
            int Bisection_Switch_Temp = floor;
            floor = ceiling;
            ceiling = Bisection_Switch_Temp;
            printf("[%d,%d]" ,floor,ceiling);
        }
        if(floor == ceiling){
            printf("You entered same values.\n");
            printf("Aborting!!!");
            return 0;
        }
    };
    

    int flag;
        
            switch (operation)
        {
        case 1:
            struct Polynom p1;
            printf("Enter polynom to find roots.\n");
            printf("First enter base then enter explonent.\n");
            Create(&p1);
            Print_Polynom(p1);
            

          


        default:
            break;
        }
        
        printf("Please enter 0 for exit\n");
        scanf("%d" , &flag);

        
        
        if(flag == 0 ){
            in_program = 0;
        }

        };










    
}