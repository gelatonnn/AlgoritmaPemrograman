#include <stdio.h>

int main() {
    int h1, m1, s1; 
    int h2, m2, s2; 
    int dh, dm, ds;

    scanf("%d %d %d", &h1, &m1, &s1);

       scanf("%d %d %d", &h2, &m2, &s2);

    if (s2 >= s1) {
        ds = s2 - s1;
    } else {
        ds = (s2 + 60) - s1;
        m2--;
    }


    if (m2 >= m1) {
        dm = m2 - m1;
    } else {
        dm = (m2 + 60) - m1;
        h2--;
    }

    dh = h2 - h1;

    printf("%d %d %d\n", dh, dm, ds);

    return 0;
}
