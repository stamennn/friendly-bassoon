#include <stdio.h>

// Dichiarazione della funzione stoub
int stoub(char *s, unsigned short b, int *r);

struct Test {
    char *s;
    unsigned short b;
    int res;
    int num;
};

int main() {
    struct Test tests[1000];
    int i, j;

    // Test 0: Numero base 10
    tests[0].s = "0";
    tests[0].b = 10;
    tests[0].res = 1;
    tests[0].num = 0;

    // Test 1: Numero positivo base 10
    tests[1].s = "25";
    tests[1].b = 10;
    tests[1].res = 1;
    tests[1].num = 25;

    // Test 2: Numero negativo base 10
    tests[2].s = "-25";
    tests[2].b = 10;
    tests[2].res = 1;
    tests[2].num = -25;

    // Test 3: Spazi bianchi all'inizio
    tests[3].s = "   42";
    tests[3].b = 10;
    tests[3].res = 1;
    tests[3].num = 42;

    // Test 4: Carattere non valido base 10
    tests[4].s = "42a";
    tests[4].b = 10;
    tests[4].res = 1;
    tests[4].num = 42;

    // Test 5: Base non valida (troppo piccola)
    tests[5].s = "101";
    tests[5].b = 1;
    tests[5].res = 0;

    // Test 6: Base non valida (troppo grande)
    tests[6].s = "101";
    tests[6].b = 37;
    tests[6].res = 0;

    // Test 7: Base 2 (binario)
    tests[7].s = "101";
    tests[7].b = 2;
    tests[7].res = 1;
    tests[7].num = 5;

    // Test 8: Base 16 (esadecimale)
    tests[8].s = "1A";
    tests[8].b = 16;
    tests[8].res = 1;
    tests[8].num = 26;

    // Test 9: Base 36 (massima base)
    tests[9].s = "Z";
    tests[9].b = 36;
    tests[9].res = 1;
    tests[9].num = 35;

    for (int k = 0; k < 10; k++) {
        i = stoub(tests[k].s, tests[k].b, &j);
        if (i != tests[k].res || (i == 1 && j != tests[k].num)) {
            printf("TEST %d FAILED! Expecting (%d,%d), got (%d,%d)\n", k, tests[k].res, tests[k].num, i, j);
        } else {
            printf("TEST %d PASSED!\n", k);
        }
    }
    return 0;
}
