#include <stdio.h>
#include <stdint.h>

uint32_t read_number(FILE *file) {
    uint8_t bytes[4];
    fread(bytes, sizeof(uint8_t), 4, file);

    uint32_t number = 0;
    for (int i = 0; i < 4; i++) {
        number = (number << 8) + bytes[i];
    }

    return number;
}

int main(int argc, char *argv[]) {
    FILE *file1 = fopen(argv[1], "rb");
    FILE *file2 = fopen(argv[2], "rb");

    uint32_t number1 = read_number(file1);
    uint32_t number2 = read_number(file2);

    fclose(file1);
    fclose(file2);

    uint32_t sum = number1 + number2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", number1, number1, number2, number2, sum, sum);

    return 0;
}

