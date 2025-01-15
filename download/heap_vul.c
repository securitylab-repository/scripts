#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>

struct data {
    char name[64]; // Premier objet dans le tas (heap)
};

struct fp {
    int (*fp)();  // Second objet dans le tas : fp (contient un pointeur)
};

void winner() {
    printf("level passed\n");  // winner() -- nous voulons executer cette fonction
}

void nowinner() {
    printf("level has not been passed\n");
}


int main(int argc, char **argv) {
    struct data *d;
    struct fp *f;

    d = malloc(sizeof(struct data));  // Allocates storage on the heap
    f = malloc(sizeof(struct fp)); // fp pointe vers nowinner()
    f->fp = nowinner;

    printf("data is at %p, fp is at %p\n", d, f);

    strcpy(d->name, argv[1]);  // Copies argv[1] into a 64-byte array, no length check

    f->fp();  // Calls function pointer
}
