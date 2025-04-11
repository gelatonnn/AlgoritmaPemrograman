//Credit to : Athalla Ananda STI'24

#include <stdio.h>
#include <string.h>

int TimeConversion(char *time){
    int hh = (time[0] - '0') * 10 + (time[1] - '0');
    int mm = (time[3] - '0') * 10 + (time[4] - '0');
    return hh * 60 + mm;
}

int PalindromeChecker(int num){
    if (num < 10) return 0;
    int reversed = 0;
    int temp = num;
    while (temp > 0){
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }
    return reversed == num;
}

int main(){
    int N;
    scanf("%d", &N);
    char times[N][6];
    int minutes[N];
    for (int i = 0; i < N; i++){
        scanf("%s", times[i]);
        minutes[i] = TimeConversion(times[i]);
    } 
    int isFirst = 1;
    int count = 0;
    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            int start = minutes[i] < minutes[j] ? minutes[i] : minutes[j];
            int end = minutes [i] > minutes[j] ? minutes[i] : minutes[j];
            int durasi = end - start;
            
            if (PalindromeChecker(durasi)){
                if (count == 0) printf("[");
                if (!isFirst) printf(", ");
                printf("[%s - %s], %d menit]", minutes[i] < minutes[j] ? times[i] : times[j], minutes[i] > minutes[j] ? times[i] : times[j], durasi);
                isFirst = 0;
                count += 1;
            }
        }   
    }
    if (count == 0) printf("Mungkin bukan hari ini. Jadi, Gro akan melamar Luiy pekan depan.\n");
    else printf("]\n");
    return 0;
}
