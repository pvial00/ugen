#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ugen (unsigned char *seed, int seedlen, char *key, int iterations, int keylen) {
    int modulus = 95;
    for (int x = 0; x < keylen; x++) {
        key[x] = 0;
    }
    int n = 0;
    for (int x = 0; x < seedlen; x++) {
        key[n] = (key[n] + seed[x]) % modulus;
        n = (n + 1) % keylen;
    }
    int s[modulus];
    for (int x = 0; x < modulus; x++) {
        s[x] = 0;
    }
    int t = 0;
    int r = 0;
    int d = modulus - keylen;
    int y = modulus / 2;
    int out;
    for (n=0; n < keylen; n++) {
        s[n % modulus] = (s[n % modulus] + key[n % keylen]) % modulus;
        t = (t + s[n % modulus]) % modulus; }
    for (n = 0; n < modulus; n++) {
        s[n % modulus] = (s[n % modulus] + t) % modulus;
        t = (t + s[n % keylen]) % modulus; }
    for (n = 0; n < d; n++) {
        s[n+keylen] = (s[n] + s[(n + 1) % d] + t) % modulus;
        t = (t + s[n] + n) % modulus; }
    for (n = 0; n < modulus; n++) {
        s[n % modulus] = (s[n % modulus] + t) % modulus;
        t = (t + s[n % modulus]) % modulus; }
    for (n = 0; n < modulus; n++) {
        s[n] = (s[n] + s[(n + y) % modulus] + t) % modulus;
        t = (t + s[n] + n) & 0xff; }

    n = 0;
    for (int x = 0; x < (keylen * iterations); x++) {
       s[n] = (s[n] + s[(n + 1) % modulus] + t) % modulus;
       t = (t + s[n] + n) % modulus;
       out = (((t + s[n]) % modulus) + s[n]) % modulus;
       key[r] = (char)(((key[r] + out) % modulus) + 32);
       n = (n + 1) % modulus;
       r = (r + 1) % keylen;
    }
}
