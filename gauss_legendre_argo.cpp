#include <iostream>
#include <cmath>
#include <iomanip> 
using namespace std;

#define Num 15 //double型変数で表示する、少数点の桁数を指定。

double myfunc(double x,double n){ //元の関数は元の方程式の左辺が0のとき、xの値は√2となる。
    return x * x -n;
}

double myderivative(double x){ //x^2 - 2の導関数。
    return 2*x;
}

double mysqrt(double x){ //平方根を求める関数で、ニュートン法により数値を求めている。

    if(x == 0){
        return 0;
    }
    double x0 = x;
    double x1 = 0;

    while(true){
        x1 = x0 - myfunc(x0,x) / myderivative(x0);

        if(fabs(x0 - x1) < 1e-15){ //x0とx1の差が1e-15以下になった時に計算を打ち切る。
            break;
        }

        x0 = x1;
    }

    return x1;
}

double gauss_legendre_argo(){ //ガウス・ルジャンドルのアルゴリズムを実行する関数。
    double a0 = 1.0; //初期値を各変数に代入。　
    double a1;
    double b0 = 1.0 / mysqrt(2);
    double b1;
    double t0 = 1.0 / 4.0;
    double t1;
    double p0 = 1.0;
    double p1;
    double pi0 = 0.0;
    double pi1;
    int n =0;

    cout << "pi" << n << " = " << fixed << setprecision(Num) << pi0 << endl; //現項の円周率の数値を出力。


    while(true){
        pi1 = ((a0 + b0) * (a0 + b0)) / (4.0*t0);
        if(fabs(pi1 - pi0) < 1e-15){ //漸化式の差が1e-15以下ならば収束。
            break;
        }
        cout << "pi" << n+1<< " = " << fixed << setprecision(Num) << pi1 << endl;

        a1 = (a0 + b0) / 2.0;
        b1 = mysqrt(a0*b0);
        t1 = t0 - p0*(a0 - a1)*(a0 - a1);
        p1 = 2 * p0;

        a0 = a1;
        b0 = b1;
        t0 = t1;
        p0 = p1;
        pi0  = pi1;
        n += 1;
    }

    cout << "π  =  ";
    
    return pi1; //最終的な円周率の数値を出力。
}

int main(){
    //メイン関数でガウス・ルジャンドル関数を呼び出し、double型の有効桁数まで表示する。
    //小数点の14桁目まで正確に円周率の計算ができている。
    cout << fixed << setprecision(Num) << gauss_legendre_argo() << endl;
    return 0;
}
