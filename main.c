#include <stdio.h>
#include <math.h>






int main() {


    
    int operation;
    int in_program = 1;
    
    

    

    
    
    while (in_program){


    printf("Welcome to numeric analysis program!!!\n");
    printf("Enter a designed number to make an matematical operation you wished for .\n");
    printf("Enter 1 to reverse a matrix\n");
    scanf("%d" , &operation);
    

    int flag;
        
            switch (operation)
        {
        case 1:
            printf("it works\n");

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