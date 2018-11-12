#include "ugen.c"

void usage() {
    printf("ugen v0.1 by KryptoMagik\n");
    printf("------------------------\n\n");
    printf("ugen <password length>\n");
}

int main(int argc, char *argv[]) {
    int iterations = 10000;
    int seedlen = 16;
    int maxlen = 1000000;
    unsigned char *seed[seedlen];
    unsigned char buf[seedlen];
    FILE *randf;
    if (argc == 2) {
        int passlen = atoi(argv[1]);
	if (passlen > maxlen) {
	    printf("You ask for too much!  Password length exceeded.\n");
	    exit(1);
	}
        char password[passlen];
        randf= fopen("/dev/urandom", "rb");
        fread(buf, 1, seedlen, randf);
        fclose(randf);
        ugen(buf, seedlen, password, iterations, passlen);
	for (int i = 0; i < passlen; i++) {
            printf("%c", password[i]);
	}
        printf("\n");
    }
    else {
        usage();
    }
}
