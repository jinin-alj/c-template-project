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
    print_bits32(1);
    print_bits32(-1);
    return 0;
}

// the output is:
// 00000000000000000000000000000001
// 11111111111111111111111111111111

// thats because the representation of negative numbers is just the not of the positive number plus one
// this is two's complement from the notes