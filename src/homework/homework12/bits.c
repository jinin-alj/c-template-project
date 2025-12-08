# include <stdio.h>

void print_bits32(int x){
    for (int i = 31; i >= 0; i--) {
        int bit = (x >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main(void){
    print_bits32(0xDEADBEEF);
    return 0;
}