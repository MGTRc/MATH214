#include <stdlib.h>
#include <math.h>


double calc(double x , double y , int n){
	double t_top;
	double t = (x-y)/n;
	int i;
	for(i=1; i<=(n-1); i++){
		t_top = t_top + sin(x + (i*t));
	}
    return (t/2)*(sin(x) + 2*t_top + sin(y));

}

int main(){
	double a = 0; double b = M_PI;
	int i,j,m,n,k,stepper;
	stepper = 1;
	double table[5][5];
	
	for(i=0; i<=4; i++){
		table[i][0] = calc(a , b , pow(2,i));
	}
	
	for(j=1; j<5; j++){
		for(m=stepper; m<5; m++){
			double div = pow(4,j)-1;
			table[m][j] = (table[m][j-1]) + (table[m][j-1] - table[m-1][j-1])/(div);
			if(m==4){
				stepper++;
			}
		}
	}
	for(n=0; n<5; n++){
		for(k=0; k<5; k++){
			printf("%f  " , table[n][k]);
		}
		printf("\n");
	}
	return 0;
}
	
