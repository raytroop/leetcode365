#include <iostream>

int Fibonacci(int n){
    if(n < 2)
        return n;
    int f0 = 0;
    int f1 = 1;
    for(int i = 2; i <= n; ++i){
        int tmp = f0 + f1;
        f0 = f1;
        f1 = tmp;
    }

    return f1;
}

int main(){
    std::cout << Fibonacci(3) << std::endl;
    std::cout << Fibonacci(9) << std::endl;
}