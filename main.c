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

newtonraphson(){
	const double PI=3.14159265;
	int tr,ttr,lg,us,i,j,N,stoppingcriterion,maxiteration,currentiteration,iterate;
	double x,temp,ttrfncoef[10],ttrbase[10],ttrxcoef[10],ttrxexp[10],ttrfnexp[10];
	double trfncoef[10],trbase[10],trxcoef[10],trxexp[10],trfnexp[10],lgfncoef[10];
	double lgbase[10],lgxcoef[10],lgxexp[10],lgfnexp[10],usfncoef[10],usbase[10];
	double usxcoef[10],usxexp[10],usfnexp[10],xn,xnew,toplam,xcoef[10],xexp[10],fxn,fturevxn,epsilon;

	system("cls");
	printf("How many polynomal value are you going to use?\n");
	scanf("%d",&N);

	for(i=0;i<N;i++){
		printf("\n%d. Polynom coefficient\n",i+1);
		scanf("%lf",&xcoef[i]);

		printf("%d. Polynom exponent\n",i+1);
		scanf("%lf",&xexp[i]);
	}

	printf("\nHow many exponential value are you going to use?\n");
	scanf("%d",&us);

	printf("usfncoef*(usbase^(usxcoef*x^usxexp))^usfnexp");

	for(i=0;i<us;i++){
		printf("\n\n%d. Element",i+1);

		printf("\nusfncoef: ");
		scanf("%lf",&usfncoef[i]);

		printf("\nusbase: ");
		scanf("%lf",&usbase[i]);

		printf("\nusxcoef: ");
		scanf("%lf",&usxcoef[i]);

		printf("\nusxexp: ");
		scanf("%lf",&usxexp[i]);

		printf("\nusfnexp: ");
		scanf("%lf",&usfnexp[i]);

	}
	printf("\nHow many logarithmic value are you going to use?\n");
	scanf("%d",&lg);

	printf("lgfncoef*(log_(logbase)(lgcoef*x^lgxexp)^lgfnexp");

	for(i=0;i<lg;i++){
		printf("\n\n%d. Element",i+1);
		printf("\nlgfncoef: ");
		scanf("%lf",&lgfncoef[i]);
		printf("\nlgbase: ");
		scanf("%lf",&lgbase[i]);
		printf("\nlgxcoef: ");
		scanf("%lf",&lgxcoef[i]);
		printf("\nlgxexp: ");
		scanf("%lf",&lgxexp[i]);
		printf("\nlgfnexp: ");
		scanf("%lf",&lgfnexp[i]);
	}
	printf("\nHow many trigonometric value are you going to use?\n");
	scanf("%d",&tr);

	printf("trfncoef*(trbase(trxcoef*x^trxexp))^trfnexp");

	for(i=0;i<tr;i++){
		printf("\n\n%d. Elements trigonomtric base (trbase): (1)sin  (2)cos  (3)tan  (4)cot: ",i+1);
		scanf("%lf",&trbase[i]);

		printf("\ntrfncoef: ");
		scanf("%lf",&trfncoef[i]);

		printf("\ntrxcoef: ");
		scanf("%lf",&trxcoef[i]);

		printf("\ntrxexp: ");
		scanf("%lf",&trxexp[i]);

		printf("\ntrfnexp: ");
		scanf("%lf",&trfnexp[i]);

	}
	printf("\nHow many inverse trigonometric value are you going to use?");
	scanf("%d",&ttr);

	printf("ttrfncoef*(ttrbase(ttrxcoef*x^ttrxexp))^ttrfnexp");

	for(i=0;i<ttr;i++){
		printf("\n\n%d. Elements inverse trigonometric base(ttrbase): (1)arcsin  (2)arccos  (3)arctan  (4)arccot: ",i+1);
		scanf("%lf",&ttrbase[i]);

		printf("\nttrfncoef: ");
		scanf("%lf",&ttrfncoef[i]);

		printf("\nttrxcoef: ");
		scanf("%lf",&ttrxcoef[i]);

		printf("\nttrxexp: ");
		scanf("%lf",&ttrxexp[i]);

		printf("\nttrfnexp: ");
		scanf("%lf",&ttrfnexp[i]);
		
	}
	system("cls");
	printf("Function:");

	for(i=0;i<N;i++){
		printf("+(%lf*x^%lf)",xcoef[i],xexp[i]);
	}
		
	for(i=0;i<us;i++){
		printf("+(%lf*(%lf^(%lf*x^%lf))^%lf)",usfncoef[i],usbase[i],usxcoef[i],usxexp[i],usfnexp[i]);
	}
	for(i=0;i<lg;i++){
		printf("+(%lf*(log(%lf*x^%lf)/log%lf)^%lf)",lgfncoef[i],lgxcoef[i],lgxexp[i],lgbase[i],lgfnexp[i]);
	}
	for(i=0;i<tr;i++){
		if(trbase[i]==1){
			printf("+%lf*(sin(%lf*x^%lf))^%lf",trfncoef[i],trxcoef[i],trxexp[i],trfnexp[i]);
		}
		else if(trbase[i]==2){
			printf("+%lf*(cos(%lf*x^%lf))^%lf",trfncoef[i],trxcoef[i],trxexp[i],trfnexp[i]);
		}
		else if(trbase[i]==3){
			printf("+%lf*(tan(%lf*x^%lf))^%lf",trfncoef[i],trxcoef[i],trxexp[i],trfnexp[i]);
		}
		else{
			printf("+%lf*(cot(%lf*x^%lf))^%lf",trfncoef[i],trxcoef[i],trxexp[i],trfnexp[i]);
		}
	}
	for(i=0;i<ttr;i++){
		if(ttrbase[i]==1){
			printf("+%lf*(arcsin(%lf*x^%lf))^%lf",ttrfncoef[i],ttrxcoef[i],ttrxexp[i],ttrfnexp[i]);
		}
		else if(ttrbase[i]==2){
			printf("+%lf*(arccos(%lf*x^%lf))^%lf",ttrfncoef[i],ttrxcoef[i],ttrxexp[i],ttrfnexp[i]);
		}
		else if(ttrbase[i]==3){
			printf("+%lf*(arctan(%lf*x^%lf))^%lf",ttrfncoef[i],ttrxcoef[i],ttrxexp[i],ttrfnexp[i]);
		}
		else{
		printf("+%lf*(arccot(%lf*x^%lf))^%lf",ttrfncoef[i],ttrxcoef[i],ttrxexp[i],ttrfnexp[i]);
		}
	}
	printf("\nx0; ");
	scanf("%lf",&xn);
	printf("\nepsilon: ");
	scanf("%lf",&epsilon);
	printf("\nMax iteration: ");
	scanf("%d",&maxiteration);
	currentiteration=1,iterate=1;
	while(currentiteration<=maxiteration && iterate==1){
		printf("\n\niteration: %d",currentiteration);
		printf("\nxn: %lf",xn);
		toplam=0;
		x=xn;
		for(i=0;i<N;i++){
			toplam=toplam+xcoef[i]*pow(x,xexp[i]);
		}
		for(i=0;i<us;i++){
			temp=usxcoef[i]*pow(x,usxexp[i]);
			toplam=toplam+usfncoef[i]*pow(pow(usbase[i],temp),usfnexp[i]);
		}
		for(i=0;i<lg;i++){
			toplam=toplam+lgfncoef[i]*pow(log10(lgxcoef[i]*pow(x,lgxexp[i]))/log10(lgbase[i]),lgfnexp[i]);
		}
		for(i=0;i<tr;i++){
			if(trbase[i]==1){
				toplam=toplam+trfncoef[i]*pow(sin((trxcoef[i]*pow(x,trxexp[i]))*PI/180),trfnexp[i]);
			}
			else if(trbase[i]==2){
				toplam=toplam+trfncoef[i]*pow(cos((trxcoef[i]*pow(x,trxexp[i]))*PI/180),trfnexp[i]);
			}
			else if(trbase[i]==3){
				toplam=toplam+trfncoef[i]*pow(tan((trxcoef[i]*pow(x,trxexp[i]))*PI/180),trfnexp[i]);
			}
			else{
				toplam=toplam+trfncoef[i]*pow(1/tan((trxcoef[i]*pow(x,trxexp[i]))*PI/180),trfnexp[i]);
			}
		}
		for(i=0;i<ttr;i++){
			if(ttrbase[i]==1){
				toplam=toplam+ttrfncoef[i]*(pow(asin(ttrxcoef[i]*pow(x,ttrxexp[i])),ttrfnexp[i]));
			}
			else if(ttrbase[i]==2){
				toplam=toplam+ttrfncoef[i]*(pow(acos(ttrxcoef[i]*pow(x,ttrxexp[i])),ttrfnexp[i]));
			}
			else if(ttrbase[i]==3){
				toplam=toplam+ttrfncoef[i]*(pow(atan(ttrxcoef[i]*pow(x,ttrxexp[i])),ttrfnexp[i]));
			}
			else{
				toplam=toplam+ttrfncoef[i]*(pow(PI/2-atan(ttrxcoef[i]*pow(x,ttrxexp[i])),ttrfnexp[i]));
			}
		}
		fxn=toplam;
		printf("\nf(xn): %lf",fxn);
		toplam=0;
		x=xn;
		for(i=0;i<N;i++){
			if(xexp[i]>0){
				toplam=toplam+(xcoef[i]*xexp[i]*pow(x,xexp[i]-1));
			}
		}
		for(i=0;i<us;i++){
			if(xexp[i]>0){
				toplam=toplam+(usfncoef[i])*(pow(usbase[i],usxcoef[i]*pow(x,usxexp[i])))*(usxcoef[i]*usxexp[i]*pow(x,usxexp[i]-1))*(log(usbase[i]))*(usfnexp[i])*(pow(pow(usbase[i],usxcoef[i]*pow(x,usxexp[i])),usfnexp[i]-1));
			}
		}
		for(i=0;i<lg;i++){
			if(xexp[i]>0){
				toplam=toplam+(lgfncoef[i])*(lgfnexp[i])*(pow(log10(lgxcoef[i]*pow(x,lgxexp[i]))/log10(lgbase[i]),lgfnexp[i]-1))*(lgxcoef[i]*lgxexp[i]*x/(log(lgbase[i])*lgxcoef[i]*pow(x,lgxexp[i])));
			}
		}
		for(i=0;i<tr;i++){
			if(xexp[i]>0){
				if(trbase[i]==1){
					toplam=toplam+((trfncoef[i])*(trfnexp[i])*(pow(sin((trxcoef[i]*pow(x,trxexp[i]))*PI/180),trfnexp[i]-1))*(cos((trxcoef[i]*pow(x,trxexp[i]))*PI/180))*(trxexp[i]*trxcoef[i]*pow(x,trxexp[i]-1)));
				}
				else if(trbase[i]==2){
					toplam=toplam+((trfncoef[i])*(trfnexp[i])*(pow(cos((trxcoef[i]*pow(x,trxexp[i]))*PI/180),trfnexp[i]-1))*(sin((trxcoef[i]*pow(x,trxexp[i]))*PI/180)*-1)*(trxexp[i]*trxcoef[i]*pow(x,trxexp[i]-1)));
				}
				else if(trbase[i]==3){
					toplam=toplam+((trfncoef[i])*(trfnexp[i])*(pow(tan((trxcoef[i]*pow(x,trxexp[i]))*PI/180),trfnexp[i]-1))*(1+pow(tan((trxcoef[i]*pow(x,trxexp[i]))*PI/180),2))*(trxexp[i]*trxcoef[i]*pow(x,trxexp[i]-1)));
				}
				else{
					toplam=toplam+((trfncoef[i])*(trfnexp[i])*(pow(1/tan((trxcoef[i]*pow(x,trxexp[i]))*PI/180),trfnexp[i]-1))*((1+pow(1/tan((trxcoef[i]*pow(x,trxexp[i]))*PI/180),2))*-1)*(trxexp[i]*trxcoef[i]*pow(x,trxexp[i]-1)));
				}
			}
		}
		for(i=0;i<ttr;i++){
			if(xexp[i]>0){
				if(ttrbase[i]==1){
					toplam=toplam+((ttrfncoef[i])*(ttrfnexp[i])*(ttrxexp[i])*(ttrxcoef[i])*(pow(x,ttrxexp[i]-1)))*(pow(asin(ttrxcoef[i]*pow(x,ttrxexp[i])),ttrfnexp[i]-1))/(sqrt(1-pow(ttrxcoef[i]*pow(x,ttrxexp[i]),2)));
				}
				else if(ttrbase[i]==2){
					toplam=toplam+((ttrfncoef[i])*(ttrfnexp[i])*(ttrxexp[i])*(ttrxcoef[i])*(pow(x,ttrxexp[i]-1)))*(pow(acos(ttrxcoef[i]*pow(x,ttrxexp[i])),ttrfnexp[i]-1))/(sqrt(1-pow(ttrxcoef[i]*pow(x,ttrxexp[i]),2)))*-1;
				}
				else if(ttrbase[i]==3){
					toplam=toplam+((ttrfncoef[i])*(ttrfnexp[i])*(ttrxexp[i])*(ttrxcoef[i])*(pow(x,ttrxexp[i]-1)))*(pow(atan(ttrxcoef[i]*pow(x,ttrxexp[i])),ttrfnexp[i]-1))/(1+pow(ttrxcoef[i]*pow(x,ttrxexp[i]),2));
				}
				else{
					toplam=toplam+((ttrfncoef[i])*(ttrfnexp[i])*(ttrxexp[i])*(ttrxcoef[i])*(pow(x,ttrxexp[i]-1)))*(pow(PI/2-atan(ttrxcoef[i]*pow(x,ttrxexp[i])),ttrfnexp[i]-1))/(1+pow(ttrxcoef[i]*pow(x,ttrxexp[i]),2))*-1;
				}
			}
		}
		fturevxn=toplam;
		printf("\nfturev(xn): %lf",fturevxn);
		toplam=0;
		xnew=xn-(fxn/fturevxn);
		printf("\nxn+1: %lf",xnew);
		if(fabs(fxn)<=epsilon){
			iterate=0;
		}
		currentiteration++;
		xn=xnew;
		}
	printf("\nResult: %lf\nPress any button to continue",xnew);
	getch();
	system("cls");
}




Gauss_Seidel(){
    int i,j,x,y,Column,Dominant_Finder,Slope,N,Current_Iteration,Max_Iteration,Iterate;
    double a,b,c,Matrix[10][10],Max_Matrix[10][10],Values[10][1],Temp1,Temp2,Max,Epsilon;

    system("cls");
    printf("Enter square matrix size:  ");
    scanf("%d",&N);

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("\n[%d][%d] :",i,j);
            scanf("%lf",&Matrix[i][j]);
        }
    }

    printf("\n\n Enter answer matrix");

    for(i=0;i<N;i++){
        printf("\n[%d][%d]",i,N);
        scanf("%lf",&Matrix[i][N]);
    }

    for(i=0;i<N-1;i++){
        x=i+N;
        for(j=0;j<N+1;j++){
            Matrix[x][j]=Matrix[i][j];
        }
    }

    printf("\nEnter beggining values:  ");

    for(i=0;i<N;i++){
        printf("\n[%d][0]: ",i);
        scanf("%lf",&Values[i][0]);
    }

    printf("\nEnter epsilon value:   ");
    scanf("%lf",&Epsilon);

    printf("\nFind diagonally dominant matrix?'0'=no,'1'=yes");
    scanf("%d",&Dominant_Finder);
    if(Dominant_Finder!=1 && Dominant_Finder!=0){
        printf("\nInvalid input. Value set to 1 !!!!!!!!!!!!!");
    }
    if(Dominant_Finder==1){

        Max=0;
        for(i=0;i<N;i++){
            for(x=0;x<N;x++){
                if(x==0){
                    a=Matrix[x+i][x];
                    }
                else a=a*Matrix[x+i][x];
            }

            if(a<0){
                a=a*-1;
            }

            if(a>Max){
                Max=a;
                Column=i;
                Slope=-1;
            }

        }

        for(i=2*N-2;i>N-2;i--){
            for(x=0;x<N;x++){
                if(x==0){
                    a=Matrix[i-x][x];
                }

                else{
                     a=a*Matrix[i-x][x];
                }

            }

            if(a<0){
                a=a*-1;
            }

            if(a>Max){
                Max=a;
                Column=i;
                Slope=1;
            }
        }
        if(Slope==-1){

            for(i=0;i<N;i++){
                for(j=0;j<N+1;j++){
                    Max_Matrix[i][j]=Matrix[Column+i][j];
                }
            }
        }

        else{
            for(i=0;i<N;i++){
                for(j=0;j<N+1;j++){
                    Max_Matrix[i][j]=Matrix[Column-i][j];
                }
            }
        }

        printf("\nMax matrix: ");

        for(i=0;i<N;i++){
            printf("\n");
            for(j=0;j<N+1;j++){
                printf("		%lf",Max_Matrix[i][j]);
            }
        }
    }

    else {

        for(i=0;i<N;i++){
            for(j=0;j<N+1;j++){
                Max_Matrix[i][j]=Matrix[i][j];
            }
        }
    }
   
    printf("\nMax iteration: ");
    scanf("%d",&Max_Iteration);

    Iterate=1;
    Current_Iteration=1;

    while(Iterate==1 && Current_Iteration<Max_Iteration){

        Temp1=Values[0][0];

        for(i=0;i<N;i++){

            Temp2=0;
            for(j=0;j<N;j++){

                if(i!=j){
                    Temp2=Temp2-Max_Matrix[i][j]*Values[j][0];
                }
            }

            Temp2=Temp2+Max_Matrix[i][N];
            Temp2=Temp2/Max_Matrix[i][i];
            Values[i][0]=Temp2;

            printf("\nx%d: %lf",i,Values[i][0]);

        }

        Temp1=Temp1-Values[0][0];

        if(Temp1<0){
            Temp1=Temp1*-1;
        }

        if(Epsilon>Temp1){
            Iterate=0;
        }

        printf("\niteration: %d\n",Current_Iteration);
        Current_Iteration++;
    }
    printf("\nPress any button to continue");
    getch();

    system("cls");	
}



int main() {
    int operation;
    int in_program = 1;
    int Bisection_I;
    double Bisection_Floor, Bisection_Ceiling, Bisection_Tolerance;
    int Bisection_Degree;
    //int Bisection_Max_Iteration;
    int Regula_I;
    double Regula_Floor , Regula_Ceiling , Regula_Tolerance;
    //double Regula_Max_Iteration;
    double Regula_Degree;
    int flag;

  
	
    
    while (in_program){
        printf("Welcome to numeric analysis program!!!\n");
        printf("Enter a designed number to make an matematical operation you wished for .\n");
        printf("Enter 1 to perform bisection method\n");
        printf("Enter 2 to perform regula-falsi method\n");
        printf("Enter 3 to perform newton ralphson method\n");
        printf("Enter 6 to perform  Gauss seidel method\n");
        scanf("%d" , &operation);
        

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

            for (Bisection_I = 0; Bisection_I <= Bisection_Degree; Bisection_I++) {
                printf("%d. Enter Coefficient: ", Bisection_I);
                scanf("%lf", &Bisection_Coefficient[Bisection_I]);

                printf("%d. Enter Exponent: ", Bisection_I);
                scanf("%d", &Bisection_Exponent[Bisection_I]);
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

            for (Regula_I = 1 ; Regula_I < Regula_Degree ; Regula_I++){
                printf("\nEnter coefficient:  ");
                scanf("%lf", &Regula_Coefficient[Regula_I]);

                printf("\nEnter exponent: ");
                scanf("%d" , &Regula_Exponent[Regula_I]);
		            printf("--%d--",Regula_I); // Deneme amaçlı
            }
   
            double Regula_Root = Regula_Falsi(Regula_Floor , Regula_Ceiling , Regula_Coefficient , Regula_Exponent , Regula_Degree , Regula_Tolerance, Regula_Max_Iteration);

            printf("Root:  %lf\n---", Regula_Root);

            free(Regula_Coefficient);
            free(Regula_Exponent);
            break;

    case 3:
        newtonraphson();
        break;

    case 6:
        Gauss_Seidel();
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
