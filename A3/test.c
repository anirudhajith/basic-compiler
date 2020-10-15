#include<stdio.h>
int glob;
int main(){
    int a;
    int b;
    a = 50;
    b = 100;
    
    if (!(b > 3)) {
        b = 5;
    } else {
        b = 4;
    }
    printf("%d\n", a);
    printf("%d\n", b);
    
    while (a > 0) {
        b  = b + 2;
        a--;
    }
    
    //b = (((b*b) + (3/a)) - 6) * (7 - (b/8));
    //b = a;
    //b = (5 + b/50) * 3;
    //b = (-5)/3;
    printf("%d\n", a);
    printf("%d\n", b);
    
    return 0;
}