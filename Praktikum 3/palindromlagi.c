#include <stdio.h>
#include <string.h>

int palindrom(char *s) { //fungsi buat nyimpen frekuensi huruf a-z
    int huruf[26] = {0}; 
    int len = strlen(s);
    int huruf_ganjil = 0;
    
    //itung frekuensi setiap huruf
    for (int i = 0; i < len; i++) {
        huruf[s[i] - 'a']++;
    }
    
    //itung jumlah huruf yg frekuensinya ganjil
    for (int i = 0; i < 26; i++) {
        if (huruf[i] % 2 != 0) {
            huruf_ganjil++;
        }
    }
    
    return (huruf_ganjil <= 1);
}

int main() {
    char s[1001];
    scanf("%s", s);
    
    if (palindrom(s)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
