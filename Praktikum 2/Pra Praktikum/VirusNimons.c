#include <stdio.h>

int main(){
    int N,T,X;
    scanf("%d %d %d",&N,&T,&X);
    long long totalV = N, nextV = N;
    for(int i = 0; i < T; i++){
        nextV = nextV*X;
        totalV += nextV;
    }
    printf("Terdapat %lld Virus Nimons Gila pada jam ke-%d\n",totalV,T);
    return 0;
}