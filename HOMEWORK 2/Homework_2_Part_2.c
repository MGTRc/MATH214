/*
Project 2 - BiSection Method
Student Name 	: Mete Can GAZÝ
Student No		: 141024020
Deparment 		: Electronic Engineering
*/

#include <stdio.h>
#include <math.h>

//Variables
float a_n = 1.25;
float b_n = 1.50;
float error_rate = 0.01;
float f_root ;
float matrix[200][10];
int count=1;

float func(float x){
	return pow(x,3) + 4*pow(x,2) - 10;
}

float pn(float a_n , float b_n){
	return a_n + ((b_n - a_n)/2);
}

int main(){
	printf("Function 	= x^3 + 4x^2 - 10 \n");
	printf("Separation 	= [%f , %f]\n" , a_n , b_n);
	printf("Error Rate 	= %f\n\n" , error_rate);
	int i;
	for(i=0; ; i++){
		if(func(pn(a_n,b_n))*func(a_n)>0){
			float holder = pn(a_n , b_n);
			matrix[i][0] = a_n;
			matrix[i][1] = b_n;
			matrix[i][2] = pn(a_n , b_n);
			matrix[i][3] = func(holder);
			matrix[i-1][4] = fabs(b_n - a_n);
			if(matrix[i-1][4]<error_rate){
				break;
			}
			a_n = holder;	 
		}else if(func(pn(a_n,b_n))*func(a_n)<0){
			float holder_2 = pn(a_n , b_n);
			matrix[i][0] = a_n;
			matrix[i][1] = b_n;
			matrix[i][2] = pn(a_n , b_n);
			matrix[i][3] = func(holder_2);
			matrix[i-1][4] = matrix[i][4] = fabs(b_n - a_n);
			if(matrix[i-1][4]<error_rate){
				break;
			}
			b_n = holder_2;
		}
		count = count + 1;
	}
	
	printf("Ite:       an              bn              pn             f(pn)           Error\n");
	printf("____  ____________    ____________    ____________   ______________    _________\n");
	int j;
	for(j=0; j<count-2; j++){
		
			printf("%d.\t%f  \t%f  \t%f  \t%f  \t%f\n" , j+1 , matrix[j][0] , matrix[j][1] , matrix[j][2] , matrix[j][3] , matrix[j][4]);	
		
	}
	printf("--------------------------\n");
	printf("| Root = %f\t |\n" , matrix[count-3][2]);
	printf("--------------------------\n");
	system("pause");
	return 0;
}
