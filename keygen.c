#include <stdio.h>
#include <string.h>
//made by PSVIta-Dev on github
int main(int argc, char **argv) {
    if(argc != 2) {
        printf("Usage: %s IMEI\n", argv[0]);
        return -1;
    }
    
    char *imei = argv[1];
    char result[30];
    
    if(strlen(imei) != 15) {
        printf("Not a valid IMEI\n");
        return -1;
    }
    
    int v4_1 = 0;
    while(v4_1 < 30) {
        result[v4_1] = (imei[(v4_1 + 7 ^ 4) % 15] - 41 ^ 1) % 10;
        ++v4_1;
    }

    for(int i = 0; i < 30; i++) {
        printf("%d", result[i]);
    }
    
    printf("\n");
    return 0;
}
