#include <stdio.h>
#include <math.h>
#include <stdlib.h>



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


double Regula_Falsi(double Regula_Floor , double Regula_Ceiling ,double *Regula_Coefficient , int *Regula_Exponent , int Regula_Degree , double Regula_Tolerance , double Regula_Max_Iteration ){
    double Regula_Floor_Value = Polynom(Regula_Floor, Regula_Coefficient ,Regula_Exponent , Regula_Degree );
    double Regula_Ceiling_Value = Polynom(Regula_Ceiling , Regula_Coefficient , Regula_Exponent , Regula_Degree);
    double Regula_Middle , Regula_Middle_Value;
    int Regula_Iteration = 0;
    double Regula_Error = Regula_Tolerance + 1;
    
    if(fabs(Regula_Floor_Value) == 0){
        printf("Root:  %lf" , Regula_Floor_Value );
    };
    if(fabs(Regula_Ceiling_Value) == 0 ){
        printf("Root:  %lf" , Regula_Ceiling_Value);
    };

    while(Regula_Error > Regula_Tolerance && Regula_Iteration <  Regula_Max_Iteration){
        Regula_Middle = (Regula_Ceiling*Regula_Floor_Value - Regula_Floor*Regula_Ceiling_Value)/(Regula_Floor_Value - Regula_Ceiling_Value);
        Regula_Middle_Value = Polynom(Regula_Middle , Regula_Coefficient , Regula_Exponent , Regula_Degree);

        if(Regula_Middle_Value == 0.0){
            printf("Root: %lf" , Regula_Middle);
        }
        if( Regula_Floor_Value * Regula_Middle_Value < 0.0 ){
            Regula_Ceiling = Regula_Middle;
            Regula_Ceiling_Value = Regula_Middle_Value;
        }
        else {
            Regula_Floor = Regula_Middle;
            Regula_Floor_Value = Regula_Middle_Value;
        }
        Regula_Error = fabs(Regula_Ceiling - Regula_Floor);
        Regula_Iteration++;
    }

    if (Regula_Error <= Regula_Tolerance){
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
printf(" \nbaslangic degerleri: ");
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

//gauss eliminasyon ve bir matrisin tersi metot fonksiyonları eklendi, -sinem
void gauss_elimination(float userMatrix[MAX_SIZE][MAX_SIZE], int N, float results[MAX_SIZE])
{
    int i,j,k;
    float demoMatrix[MAX_SIZE][MAX_SIZE],temp, answers[N];
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            demoMatrix[i][j]=userMatrix[i][j];
        }
        demoMatrix[i][j]=results[i];
    }

    for(k=0; k<N; k++)
    {
        for(i=k; i<N; i++)
        {
            temp=demoMatrix[i][k];
            for(j=k; j<N+1; j++)
            {
                demoMatrix[i][j]=demoMatrix[i][j]/temp;
            }

        }
        for(i=k+1; i<N; i++)
        {
            for(j=0; j<N+1; j++)
            {
                demoMatrix[i][j]=demoMatrix[i][j]-demoMatrix[k][j];
            }
        }
    }

    printf("\nHere is your matrix:\n\n");
    for(i=0; i<N; i++)
    {
        for(j=0; j<N+1; j++)
        {
            printf("%f ", demoMatrix[i][j]);
        }
        printf("\n");
    }
    answers[N-1] = demoMatrix[N-1][N] / demoMatrix[N-1][N-1];
    for(i=N-2; i>=0; i--)
    {
        temp = 0;
        for(j=N-1; j>=i+1; j--)
        {
            temp = temp + (answers[j] * demoMatrix[i][j]);
        }
        answers[i] = (demoMatrix[i][N] - temp) / demoMatrix[i][i];
    }

    printf("The result vektor is: (");
    for(i=0; i<N-1; i++)
    {
        printf("%f, ",answers[i]);
    }
    printf("%f)\n", answers[N-1]);
}




float determinant(float userMatrix[MAX_SIZE][MAX_SIZE], int N)
{
    int i,j,k,subI,subJ;
    float det;
    det=0;
    float subMatrix[MAX_SIZE][MAX_SIZE] = {0};
    if (N == 1){
        return userMatrix[0][0];
    }
    else if (N == 2){
        return userMatrix[0][0] * userMatrix[1][1] - userMatrix[1][0] * userMatrix[0][1];
    }
    else
    {
        for (k = 0; k < N; k++){
            subI = 0;
            for (i = 1; i < N; i++){
                subJ = 0;
                for (j = 0; j < N; j++){
                    if (j != k){
                        subMatrix[subI][subJ] = userMatrix[i][j];
                        subJ++;
                    }
                }
                subI++;
            }
            float a = userMatrix[0][k] * determinant(subMatrix, N - 1);
            if (k % 2 == 1){
                a *= -1;
            }
            det += a;
        }
    }
    return det;
}
void inverse_matris_function(float userMatrix[MAX_SIZE][MAX_SIZE], int N)
{
    int i,j,k,t;
    float adjointMatrix[MAX_SIZE][MAX_SIZE], demoMatrix[MAX_SIZE][MAX_SIZE],demoinMatrix[MAX_SIZE][MAX_SIZE];
    float inverseMatrix[MAX_SIZE][MAX_SIZE];


    float det2;
    //first calculate the determinant of function:
    det2 = determinant(userMatrix,N);
    printf("Determinant of matris is: %f \n", det2);
    //second, we need adjoint matrix:
    if(det2==0){
        printf("\nDeterminant of the matris you gave is 0. Inverse matrix can not be calculated.");
    }
    else
    {

        for(i=0; i<N; i++)
        {
            for (k = 0; k < N; k++)
            {
                if (k != i)
                {
                    if (k < i)
                    {
                        for (j=0; j<N ; j++)
                        {

                            demoMatrix[k][j] = userMatrix[k][j];
                        }
                    }
                    else
                    {
                        for (j=0; j<N; j++)
                        {

                            demoMatrix[k-1][j] = userMatrix[k][j];
                        }
                    }
                }
            }
            for(j=0; j<N; j++)
            {
                for (k = 0; k < N; k++)
                {

                    if (k != j)
                    {
                        if (k < j)
                        {
                            for (t=0; t<N-1; t++)
                            {

                                demoinMatrix[t][k] = demoMatrix[t][k];
                            }
                        }
                        else
                        {
                            for(t=0; t<N-1; t++)
                            {

                                demoinMatrix[t][k-1] = demoMatrix[t][k];
                            }
                        }
                    }

                }
                adjointMatrix[j][i]= determinant(demoinMatrix, N - 1)* pow(-1, i+j);
            }
        }
        //now, all we need to do is dividing adjoint matrix to determinant:
        for(i=0; i<N ; i++)
        {
            for (j=0; j<N; j++)
            {
                inverseMatrix[i][j]=adjointMatrix[i][j]/det2;
            }
        }
        printf("\nHere is your inverse matrix: \n");
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
            {
                printf("%.3f ", inverseMatrix[i][j]);
            }
            printf("\n");
        }
    }
}
//---------------------//



int main() {
    int operation;
    int in_program = 1;
    double Bisection_Floor, Bisection_Ceiling, Bisection_Tolerance;
    int Bisection_Degree;
    //int Bisection_Max_Iteration;
    double Regula_Floor , Regula_Ceiling , Regula_Tolerance;
    //double Regula_Max_Iteration;
    double Regula_Degree;
    int flag;
    //eliminasyon ve ters matris için tanımladığım değişkenler: -sinem
    int i,j,mainmenu,N,k,t;
    float userMatrix[MAX_SIZE][MAX_SIZE], results[MAX_SIZE];
    //-------------------//
  
	
    
    while (in_program){
        printf("Welcome to numeric analysis program!!!\n");
        printf("Enter a designed number to make an matematical operation you wished for .\n");
        printf("Enter 1 to perform bisection method\n");
        printf("Enter 2 to perform regula-false method\n");
        scanf("%d" , &operation);
        if(operation == 2){
            printf("Enter Polynom Degree: \n");
            scanf("%lf", &Regula_Degree);
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
	    printf("%d",Regula_Max_Iteration); // Deneme amaçlı

            for (int i = 0 ; i <= Regula_Degree ; i++){
                printf("\nEnter coefficient:  ");
                scanf("%lf", &Regula_Coefficient[i]);

                printf("\nEnter exponent: ");
                scanf("%d" , &Regula_Exponent[i]);
		printf("%d",Regula_Exponent[i]); // Deneme amaçlı
            }

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
            scanf("%lf", &Regula_Degree);
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

            for (int i = 1 ; i < Regula_Degree ; i++){
                printf("\nEnter coefficient:  ");
                scanf("%lf", &Regula_Coefficient[i]);

                printf("\nEnter exponent: ");
                scanf("%d" , &Regula_Exponent[i]);
		            printf("--%d--",i); // Deneme amaçlı
            }
   
            double Regula_Root = Regula_Falsi(Regula_Floor , Regula_Ceiling , Regula_Coefficient , Regula_Exponent , Regula_Degree , Regula_Tolerance, Regula_Max_Iteration);

            printf("Root:  %lf\n---", Regula_Root);

            free(Regula_Coefficient);
            free(Regula_Exponent);
            break;
    case 3:
        gaussseidel();
    break;
    case 4:
    printf("Welcome to inverse matris, please enter dimension of the square matrix, you want to get inverse: ");
            scanf("%d", &N);
            printf("Please enter the elements of the matrix: \n");
            for(i=0; i<N; i++){
                for(j=0; j<N; j++){
                    printf("Please enter the %d. row and %d. coloumn element of the matrix: ", i+1,j+1);
                    scanf("%f", &userMatrix[i][j]);
                }
            }
            printf("\nHere is your matrix:\n\n");
            for(i=0; i<N; i++){
            	for(j=0; j<N; j++){
                    printf("%f ", userMatrix[i][j]);
                }
                printf("\n");
            }

            inverse_matris_function(userMatrix, N);
    break;
    case 5:
    printf("Welcome to Gauss elimination method, please enter the number of equations:  ");
            scanf("%d", &N);
            printf("Please enter the matrix of the coefficients: \n");
            for(i=0; i<N; i++)
            {
                for(j=0; j<N; j++)
                {
                    printf("Please enter the %d. row and %d. coloumn element of the matrix: ", i+1,j+1);
                    scanf("%f", &userMatrix[i][j]);
                }
            }
            printf("\nHere is your matrix:\n\n");
            for(i=0; i<N; i++)
            {
                for(j=0; j<N; j++)
                {
                    printf("%f ", userMatrix[i][j]);
                }
                printf("\n");
            }
            printf("Please enter the results of equations: ");
            for(i=0; i<N; i++)
            {
                printf("\nPlease enter the result of %d. equation: ",i+1);
                scanf("%f", &results[i]);
        	}
            gauss_elimination(userMatrix, N, results);

            printf("Your operation is done. Do you want to go to main menu? \n(Yes,go to main menu: 1 No,exit the program: 0 ) ");
            scanf("%d", &mainmenu);
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
