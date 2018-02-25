#include <stdlib.h>
#include <math.h>

//Functions

double sinx_math(double x){
	return sin(x);
}



double CompTra(double a , double b , double n){
	double h = (b-a)/n;
		if(n==1){
			return (h/2) * (sinx_math(a)+sinx_math(b));
		}
}



int main(){
	int n[5] = {1 , 2 , 4 , 8 , 16};
	printf("%f" , CompTra(0,3.14,1));
}
