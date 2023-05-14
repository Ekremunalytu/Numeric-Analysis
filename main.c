#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct  Polynom{
    double Coefficient;
    int Exponent;
};



double Structured_Polynom(double base ){
    struct Polynom p;
    printf("Enter coefficient: ");
    scanf("%lf" , &p.Coefficient);
    printf("Enter exponent");
    scanf("%d" , &p.Exponent);
    
}


double Polynom(double Base, double *Polynom_Coefficient, int *Polynom_Exponent, int Polynom_Degree) {
    double Sum = 0.0;
    int Polynom_I;
    for (Polynom_I = 0; Polynom_I <= Polynom_Degree; Polynom_I++) {
        Sum += Polynom_Coefficient[Polynom_I] * pow(Base, Polynom_Exponent[Polynom_I]);
    }
    return Sum;
}



double Bisection(double Bisection_Floor, double Bisection_Ceiling, double *Bisection_Coefficient, int *Bisection_Exponent, int Bisection_Degree, double Bisection_Tolerance, int Max_Iteration) {
    double Middle;
    double F_Floor;
    double F_Ceiling;
    double F_Middle;
    int Iteration = 0;

    F_Floor = Polynom(Bisection_Floor, Bisection_Coefficient, Bisection_Exponent, Bisection_Degree);
    F_Ceiling = Polynom(Bisection_Ceiling, Bisection_Coefficient, Bisection_Exponent, Bisection_Degree);

    printf("%lf",F_Ceiling); // Deneme amaçlı

    while ((Bisection_Ceiling-Bisection_Floor) > Bisection_Tolerance && Iteration < Max_Iteration) {
        Middle = (Bisection_Floor+Bisection_Ceiling) / 2.0;
        F_Middle = Polynom(Middle, Bisection_Coefficient, Bisection_Exponent, Bisection_Degree);

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

double Regula_Falsi(double Regula_Floor, double Regula_Ceiling, double *Regula_Coefficient, int *Regula_Exponent, int Regula_Degree, double Regula_Tolerance, double Regula_Max_Iteration) {
    double Regula_Floor_Value = Polynom(Regula_Floor, Regula_Coefficient, Regula_Exponent, Regula_Degree);
    double Regula_Ceiling_Value = Polynom(Regula_Ceiling, Regula_Coefficient, Regula_Exponent, Regula_Degree);
    double Regula_Middle, Regula_Middle_Value;
    int Regula_Iteration = 0;
    double Regula_Error = Regula_Tolerance + 1;

    while (Regula_Error > Regula_Tolerance && Regula_Iteration <= Regula_Max_Iteration) {
        if (fabs(Regula_Floor_Value) < 0.0001) {
            printf("Root: %lf\n", Regula_Floor_Value);
        }
        if (fabs(Regula_Ceiling_Value) < 0.0001) {
            printf("Root: %lf\n", Regula_Ceiling_Value);
        }

        Regula_Middle = (Regula_Ceiling * Regula_Floor_Value - Regula_Floor * Regula_Ceiling_Value) / (Regula_Floor_Value - Regula_Ceiling_Value);
        Regula_Middle_Value = Polynom(Regula_Middle, Regula_Coefficient, Regula_Exponent, Regula_Degree);

        if (fabs(Regula_Middle_Value) < 0.0001) {
            printf("Root: %lf\n", Regula_Middle);
        }

        if (Regula_Floor_Value * Regula_Middle_Value < 0.0) {
            Regula_Ceiling = Regula_Middle;
            Regula_Ceiling_Value = Regula_Middle_Value;
        }
        else {
            Regula_Floor = Regula_Middle;
            Regula_Floor_Value = Regula_Middle_Value;
        }

        Regula_Error = fabs(Regula_Ceiling_Value - Regula_Floor_Value);
        Regula_Iteration++;
    }

    if (Regula_Error <= Regula_Tolerance) {
        return Regula_Middle;
    }
    else {
        printf("Regula Falsi method failed!!!!\n");
        return 0;
    }
}




gaussseidel(){
int i,j,x,y,satir,A,egim,N,currentiteration,maxiteration,iterate;
double a,b,c,matris[10][10],maxmatris[10][10],value[10][1],temp,temp2,max,epsilon;
system("cls");
printf("NxN olan kare matrisin N degerini girin: ");
scanf("%d",&N);
for(i=0;i<N;i++){
	for(j=0;j<N;j++){
		printf("\n[%d][%d] :",i,j);
		scanf("%lf",&matris[i][j]);
	}
}
printf("\n\n Simdi ise Cevap matrisini giriniz.");
for(i=0;i<N;i++){
	printf("\n[%d][%d]",i,N);
	scanf("%lf",&matris[i][N]);
}
for(i=0;i<N-1;i++){
	x=i+N;
	for(j=0;j<N+1;j++){
		matris[x][j]=matris[i][j];
	}
}
printf("\nbaslangic degerleri: ");
for(i=0;i<N;i++){
	printf("\n[%d][0]: ",i);
	scanf("%lf",&value[i][0]);
}
printf("\nepsilon: ");
scanf("%lf",&epsilon);
printf("\nFind diagonally dominant matrix?'0'=no,'1'=yes");
scanf("%d",&A);
if(A!=1 && A!=0){
	printf("\ngirilen deger gecersiz.1 olarak ayarlaniyor.");
}
if(A==1){
	max=0;
	for(i=0;i<N;i++){
		for(x=0;x<N;x++){
			if(x==0){
				a=matris[x+i][x];
			}
			else a=a*matris[x+i][x];
		}
		if(a<0){
			a=a*-1;
		}
		if(a>max){
			max=a;
			satir=i;
			egim=-1;
		}
	}
	for(i=2*N-2;i>N-2;i--){
		for(x=0;x<N;x++){
			if(x==0){
				a=matris[i-x][x];
			}
			else a=a*matris[i-x][x];
		}
		if(a<0){
			a=a*-1;
		}
		if(a>max){
			max=a;
			satir=i;
			egim=1;
		}
	}
	if(egim==-1){
		for(i=0;i<N;i++){
			for(j=0;j<N+1;j++){
				maxmatris[i][j]=matris[satir+i][j];
			}
		}
	}
	else{
		for(i=0;i<N;i++){
			for(j=0;j<N+1;j++){
				maxmatris[i][j]=matris[satir-i][j];
			}
		}
	}
	printf("\nMaxMatris: ");
	for(i=0;i<N;i++){
		printf("\n");
		for(j=0;j<N+1;j++){
			printf("		%lf",maxmatris[i][j]);
		}
	}
}
else {
	for(i=0;i<N;i++){
		for(j=0;j<N+1;j++){
			maxmatris[i][j]=matris[i][j];
		}
	}
}
/*printf("\n\nmax:%lf,%d",max,satir);*/
printf("\nMax iteration: ");
scanf("%d",&maxiteration);
iterate=1;
currentiteration=1;
while(iterate==1 && currentiteration<maxiteration){
	temp=value[0][0];
	for(i=0;i<N;i++){
		temp2=0;
		for(j=0;j<N;j++){
			if(i!=j){
				temp2=temp2-maxmatris[i][j]*value[j][0];
			}
		}
		temp2=temp2+maxmatris[i][N];
		temp2=temp2/maxmatris[i][i];
		value[i][0]=temp2;
		printf("\nx%d: %lf",i,value[i][0]);
	}
	temp=temp-value[0][0];
	if(temp<0){
		temp=temp*-1;
	}
	if(epsilon>temp){
		iterate=0;
	}
	printf("\niteration: %d\n",currentiteration);
	currentiteration++;
}
printf("\nPress any button to continue");
getch();
system("cls");	
}



int main() {
    int operation;
    int in_program = 1;
    double Bisection_Floor, Bisection_Ceiling, Bisection_Tolerance;
    int Bisection_Degree;
    //int Bisection_Max_Iteration;
    double Regula_Floor , Regula_Ceiling , Regula_Tolerance;
    //double Regula_Max_Iteration;
    int Regula_Degree;
    int flag;

  
	
    
    while (in_program){
        printf("Welcome to numeric analysis program!!!\n");
        printf("Enter a designed number to make an matematical operation you wished for .\n");
        printf("Enter 1 to perform bisection method\n");
        printf("Enter 2 to perform regula-falsi method\n");
        printf("Enter 3  to perform gauss-seidel method");
        scanf("%d" , &operation);
      

        }

      switch (operation) {
        case 1:

            printf("Enter Polynom Degree: \n");
            scanf("%d", &Bisection_Degree);
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

            double *Bisection_Coefficient = (double*) malloc((Bisection_Degree+1) * sizeof(double));
            int *Bisection_Exponent = (int*) malloc((Bisection_Degree+1) * sizeof(int));

            for (int j = 0; j <= Bisection_Degree; j++) {
                printf("%d. Enter Coefficient: ", j);
                scanf("%lf", &Bisection_Coefficient[j]);

                printf("%d. Enter Exponent: ", j);
                scanf("%d", &Bisection_Exponent[j]);
               
            }

            int Max_Iteration;
            printf("Enter Max iteration\n");
            scanf("%d", &Max_Iteration);

            double Bisection_Root = Bisection(Bisection_Floor, Bisection_Ceiling, Bisection_Coefficient, Bisection_Exponent, Bisection_Degree, Bisection_Tolerance, Max_Iteration);

            printf("Bisection Root: %lf\n", Bisection_Root);

            free(Bisection_Coefficient);
            free(Bisection_Exponent);

            break;
            
        case 2:
        
            printf("Enter Polynom Degree: \n");
            scanf("%d", &Regula_Degree);
            printf("Enter tolerance value\n");
            scanf("%lf", &Regula_Tolerance);

            printf("Enter floor and ceiling for bisection method.\n");
            printf("For floor: ");
            scanf("%lf", &Regula_Floor);
            printf("For ceiling: ");
            scanf("%lf", &Regula_Ceiling);

            if (Regula_Floor > Regula_Ceiling) {
                printf("You entered wrong floor and ceiling value !!!!!\n");
                printf("Switching values.\n");
                double Regula_Switch_Temp = Regula_Floor;
                Regula_Floor = Regula_Ceiling;
                Regula_Ceiling = Regula_Switch_Temp;
                printf("[%lf,%lf]\n", Regula_Floor, Regula_Ceiling);
            }

            if (Regula_Floor == Regula_Ceiling) {
                printf("You entered same values.\n");
                printf("Aborting!!!\n");
                break;
            }

            double *Regula_Coefficient = (double*) malloc((Regula_Degree+1) * sizeof(double));
            int *Regula_Exponent = (int*) malloc((Regula_Degree+1) * sizeof(int));
            

            int Regula_Max_Iteration;
            printf("Enter Max iteration\n");
            scanf("%d", &Regula_Max_Iteration);

            for (int i = 0 ; i < Regula_Degree ; i++){
                printf("\nEnter coefficient:  ");
                scanf("%lf", &Regula_Coefficient[i]);

                printf("\nEnter exponent: ");
                scanf("%d" , &Regula_Exponent[i]);
		            
            }
   
            //double Regula_Root = Regula_Falsi(Regula_Floor , Regula_Ceiling , Regula_Coefficient , Regula_Exponent , Regula_Degree , Regula_Tolerance, Regula_Max_Iteration);

            //printf("Root:  %lf\n---", Regula_Root);

            free(Regula_Coefficient);
            free(Regula_Exponent);
            break;
    case 3:
        gaussseidel();

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


//commit change