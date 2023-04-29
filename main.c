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
int Polynom_Base;

void Create (struct Polynom *p){
    int i;
    printf("Enter Number of Terms.\n");
    scanf("%d", &p -> n);

    p -> Terms = (struct Term  *) malloc((p->n) * sizeof(struct Term));
    printf("Enter base: ");
    scanf("%d" , &Polynom_Base);


    printf("Enter Terms\n");
    for (i = 0  ; i < p -> n ; i++){
        p -> Terms[i].Coefficient = Polynom_Base;
        scanf("%d" ,  &p->Terms[i].Exponent);   
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

int Calculate_Polynom_Value(struct Polynom p , int Base_Value){
    int sum = 0;
    for (int i = 0 ; i < p.n ; i++){
        sum += pow( Base_Value , p.Terms[i].Exponent);
        };
    return sum;
};





int main() {


    
    int operation;
    int in_program = 1;
    int Bisection_Floor,Bisection_Ceiling;
    

    

    
    
    while (in_program){


    printf("Welcome to numeric analysis program!!!\n");
    printf("Enter a designed number to make an matematical operation you wished for .\n");
    printf("Enter 1 to perform bisection method\n");
    scanf("%d" , &operation);

    if(operation == 1){ //switch case içerisinde scanf çalışmadığı için harici olarak aldım.
        printf("Enter floor and ceiling for bisection method.\n");
        
        printf("For floor: ");
        scanf("%d" , &Bisection_Floor);
        printf("\nFor ceiling: ");
        scanf("%d" , &Bisection_Ceiling);
        if(Bisection_Floor > Bisection_Ceiling){
            printf("You entered wrong floor and ceiling value !!!!!\n");
            printf("Switching values.\n");
            int Bisection_Switch_Temp = Bisection_Floor;
            Bisection_Floor = Bisection_Ceiling;
            Bisection_Ceiling = Bisection_Switch_Temp;
            printf("[%d,%d]" ,Bisection_Floor,Bisection_Ceiling);
        }
        if(Bisection_Floor == Bisection_Ceiling){
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
            printf("First enter Polynom_Base then enter explonent.\n");
            Create(&p1);
            Print_Polynom(p1);
            for(int i = 0 ; i < p1.n; i++){
                p1.Terms[i].Coefficient = Bisection_Floor;
            };
            int Bisection_Floor_value = Calculate_Polynom_Value(p1 , Bisection_Floor);
            Print_Polynom(p1);
            Calculate_Polynom_Value(p1 , Bisection_Floor);
            for(int i = 0 ; i < p1.n; i++){
                p1.Terms[i].Coefficient = Bisection_Ceiling;
            };
            int Bisection_Ceiling_Value = Calculate_Polynom_Value(p1 , Bisection_Ceiling);
            if(Bisection_Ceiling_Value*Bisection_Floor_value >  0){
                printf("Root not found");
                return 0;
            }

            
            
            

          


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