#include <stdio.h>
#include <math.h>

int main(){
    int N;
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        double x, suhu;
        char a, b;
        scanf("%lf %c %c",&x,&a,&b);
        if(a == 'C'){
            if(b == 'F'){
                suhu = x*9/5 + 32;
            } else {
                suhu = x + 273.15;
            }
        } else if(a == 'F'){
            if(b == 'C'){
                suhu = (x-32)*5/9;
            }else {
                suhu = (x-32)*5/9 + 273.15;
            }
        } else {
            if(b == 'C'){
                suhu = x - 273.15;
            } else {
                suhu = (x-273.15)*9/5 + 32;
            }

        }
        suhu = floor(suhu);
        printf("%.2lf\n",suhu);
    }
    return 0;
}
