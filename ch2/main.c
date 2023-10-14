#include <stdio.h>
#include <sys/types.h>

void inplace_swap(int *x, int *y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

// 2.11 remove equality first<=last
void reverse_array(int a[], int cnt) {
    int first, last;
    for (first = 0, last = cnt -1;
         first < last; 
         first++, last--) {
        inplace_swap(&a[first],&a[last]);
    }
}

// 2.12 - How would I make it agnostic to word size?
// This was not the exercise, but interesting nontheless
void least_significant_byte(long int *a, uint word_size) {
    // char will always be one byte
    if (word_size % 8 != 0) {
        printf("invalid word size");
        return;
    }
    char *b = (char*)a;
    int size_bytes = word_size / 8;

    // Quite stupid 
    b[0] = b[0] & 0xFF;
    for (uint byte_nr = 1; byte_nr < size_bytes; byte_nr++) {
        b[byte_nr] = b[byte_nr] & 0x00;
    }
}

void print_array(int a[], int cnt) {
    for(int i = 0; i < cnt; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    // Unsure about my opinion on having length as argument to the funcs
    // rather than doing that check inside. More versatile this way parhaps, subarrays and so on
    int A[] = {1,2,3,4}; 
    int length_A = sizeof(A) / sizeof(int);
    int B[] = {1,2,3,4,5}; 
    int length_B = sizeof(B) / sizeof(int);

    print_array(A, length_A);
    reverse_array(A, length_A);
    print_array(A, length_A);

    print_array(B, length_B);
    reverse_array(B, length_B);
    print_array(B, length_B);

    // 2.12
    long int x = 0x8765432112345678;
    int word_size = 64;
    printf("char: 0x%.*lx\n", word_size / 4, x);
    least_significant_byte(&x, word_size);
    printf("char: 0x%.*lx\n", word_size / 4, x);




    return 0;
}
