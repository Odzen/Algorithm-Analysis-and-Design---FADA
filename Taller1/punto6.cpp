#include <iostream>
#include <math.h>
using namespace std;

int main() {
    float dia=0;
    int r=3;
    int n=10;
    
    float raiz= sqrt((1-(8*r)+(8*n)));
    
    dia= (((2*r)-1)+ raiz) /2;
    
    int diaAprox=ceil(dia);
    
    cout<<diaAprox<<"\n";
    return 0;
}
