#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void usage() {
    printf("ugen v0.2 by KryptoMagik\n");
    printf("------------------------\n\n");
    printf("ugen <password length>\n");
}

int main(int argc, char *argv[]) {
    FILE *randf;
    int stop = 0;
    int maxlen = 1000000;
    unsigned char buf;
    int i = 0;
    if (argc == 2) {
        int passlen = atoi(argv[1]);
	if (passlen > maxlen) {
            printf("You ask for too much!  Max password length exceeded.\n");
	    exit(1);
	}
        char password[passlen];
        randf = fopen("/dev/urandom", "rb");
	while (stop != 1) {
            fread(&buf, 1, 1, randf);
	    if (((int)buf >= 32) && ((int)buf <= 126)) {
	        password[i] = (char)buf;
		i += 1;
		if (i == passlen) {
		    stop = 1;
		}
	    }
	}
        fclose(randf);
        for (i = 0; i < passlen; i++) {
            printf("%c", password[i]);
        }
        printf("\n");
    }
    else {
        usage();
    }
}
