#include <iostream>
#include <cmath>
#include <iomanip> 
using namespace std;

#define Num 14

double myfunc(double x,double n){
    return x * x -n;
}

double myderivative(double x){
    return 2*x;
}

double mysqrt(double x){

    if(x == 0){
        return 0;
    }
    double x0 = x;
    double x1 = 0;

    while(true){
        x1 = x0 - myfunc(x0,x) / myderivative(x0);

        if(fabs(x0 - x1) < 0.000000000000001){
            break;
        }

        x0 = x1;
    }

    return x1;
}

double gauss_legendre_argo(){
    double a0 = 1.0;
    double a1;
    double b0 = 1.0 / mysqrt(2);
    double b1;
    double t0 = 1.0 / 4.0;
    double t1;
    double p0 = 1.0;
    double p1;
    double pi0;
    double pi1;
    int n =0;

    while(true){
        pi1 = ((a0 + b0) * (a0 + b0)) / (4.0*t0);
        cout << "pi" << n << " = " << fixed << setprecision(Num) << pi0 << endl;
        cout << "pi" << n+1<< " = " << fixed << setprecision(Num) << pi1 << endl;
        if(pi0 == pi1){
            break;
        }
        a1 = (a0 + b0) / 2.0;
        b1 = mysqrt(a0*b0);
        t1 = t0 - p0*(a0 - a1)*(a0 - a1);
        p1 = 2 * p0;

        a0 = a1;
        b0 = b1;
        t0 = t1;
        p0 = p1;
        pi0  = pi1;
        n += 2;
    }

    cout << "π  =  ";
    

    return pi1;
}

int main(){
    cout << fixed << setprecision(Num) << gauss_legendre_argo() << endl;
    return 0;
}
