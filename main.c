#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double polinom(double Base, double *Coefficient, int *Exponent, int Degree) {
    double Sum = 0.0;
    int Polynom_I;
    for (Polynom_I = 0; Polynom_I <= Degree; Polynom_I++) {
        Sum += Coefficient[Polynom_I] * pow(Base, Exponent[Polynom_I]);
    }
    return Sum;
}

double Bisection(double Bisection_Floor, double Bisection_Ceiling, double *Coefficient, int *Exponent, int Degree, double Bisection_Tolerance, int Max_Iteration) {
    double Middle, F_Floor, F_Ceiling, F_Middle;
    int Iteration = 0;

    F_Floor = polinom(Bisection_Floor, Coefficient, Exponent, Degree);
    F_Ceiling = polinom(Bisection_Ceiling, Coefficient, Exponent, Degree);

    while ((Bisection_Ceiling-Bisection_Floor) > Bisection_Tolerance && Iteration < Max_Iteration) {
        Middle = (Bisection_Floor+Bisection_Ceiling) / 2.0;
        F_Middle = polinom(Middle, Coefficient, Exponent, Degree);

        if (F_Middle == 0.0) {
            return Middle;
        } else if (F_Floor * F_Middle < 0.0) {
            Bisection_Ceiling = Middle;
            F_Ceiling = F_Middle;
        } else {
            Bisection_Floor = Middle;
            F_Floor = F_Middle;
        }

        Iteration++;
    }

    return (Bisection_Floor+Bisection_Ceiling) / 2.0;
}



int main() {
    int operation;
    int in_program = 1;
    double Bisection_Floor, Bisection_Ceiling, Bisection_Tolerance;
    int Degree, Max_Iteration;
    int flag;

    double *Coefficient;
    int *Exponent;
    
    while (in_program){
        printf("Welcome to numeric analysis program!!!\n");
        printf("Enter a designed number to make an matematical operation you wished for .\n");
        printf("Enter 1 to perform bisection method\n");
        scanf("%d" , &operation);

      switch (operation) {
        case 1:
        // Bisection method
        printf("Enter Polynom Degree: \n");
        scanf("%d", &Degree);
        printf("Enter tolerance value\n");
        scanf("%lf", &Bisection_Tolerance);

        printf("Enter floor and ceiling for bisection method.\n");
        printf("For floor: ");
        scanf("%lf", &Bisection_Floor);
        printf("For ceiling: ");
        scanf("%lf", &Bisection_Ceiling);

        if (Bisection_Floor > Bisection_Ceiling) {
            printf("You entered wrong floor and ceiling value !!!!!\n");
            printf("Switching values.\n");
            double Bisection_Switch_Temp = Bisection_Floor;
            Bisection_Floor = Bisection_Ceiling;
            Bisection_Ceiling = Bisection_Switch_Temp;
            printf("[%lf,%lf]\n", Bisection_Floor, Bisection_Ceiling);
        }

        if (Bisection_Floor == Bisection_Ceiling) {
            printf("You entered same values.\n");
            printf("Aborting!!!\n");
            break;
        }

        double *Coefficient = (double*) malloc((Degree+1) * sizeof(double));
        int *Exponent = (int*) malloc((Degree+1) * sizeof(int));

        for (int Polynom_I = 0; Polynom_I <= Degree; Polynom_I++) {
            printf("%d. Enter Coefficient: ", Polynom_I);
            scanf("%lf", &Coefficient[Polynom_I]);

            printf("%d. Enter Exponent: ", Polynom_I);
            scanf("%d", &Exponent[Polynom_I]);
        }

        int Max_Iteration;
        printf("Enter Max iteration\n");
        scanf("%d", &Max_Iteration);

        double Bisection_Root = Bisection(Bisection_Floor, Bisection_Ceiling, Coefficient, Exponent, Degree, Bisection_Tolerance, Max_Iteration);

        printf("Bisection Root: %lf\n", Bisection_Root);

        free(Coefficient);
        free(Exponent);

        break;

    default:
        printf("Invalid operation number. Please enter a valid number.\n");
        break;
    }
    printf("Please enter 0 to exit or any other key to perform another operation.\n");
    scanf("%d", &flag);

        if (flag == 0) {
             in_program = 0;
        }
    }

}
