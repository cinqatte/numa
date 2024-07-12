#include "numa/numa.h"

__attribute__((unused)) static void printHeader(uint32_t width, uint8_t bytes_per_view) {
    printf("Address         ");
    for (uint32_t i = 0; i < width; i += bytes_per_view) {
        for (uint32_t j = 0; j < bytes_per_view; j++) {
            printf("%02X", j);
        }
        printf(" ");
        if ((i + bytes_per_view) % 8 == 0) {
            printf(" ");
        }
    }
    printf("   ASCII\n");
}

__attribute__((unused)) void numaDisplay(NumaDisplay *display) {
    uint64_t end_address = display->start_address + display->length;
    uint64_t padded_end_address = end_address;

    if (display->length % display->width != 0) {
        padded_end_address += display->width - (display->length % display->width);
    }

    do {
        numaDisplayClear();
        printHeader(display->width, display->bytes_per_view);

        for (uint64_t address = display->start_address; address < padded_end_address; address += display->width) {
            printf("%08lX    ", address);

            for (uint32_t i = 0; i < display->width; i += display->bytes_per_view) {
                if (address + i < end_address) {
                    for (uint32_t j = 0; j < display->bytes_per_view; j++) {
                        if (address + i + j < end_address) {
                            printf("%02X", *((uint8_t *)(address + i + j)));
                        } else {
                            printf("  ");
                        }
                    }
                    printf(" ");
                    if ((i + display->bytes_per_view) % 8 == 0 && i != 0) {
                        printf(" ");
                    }
                } else {
                    for (uint32_t j = 0; j < display->bytes_per_view; j++) {
                        printf("  ");
                    }
                    printf(" ");
                }
            }

            printf("   ");

            for (uint32_t i = 0; i < display->width; i++) {
                if (address + i < end_address) {
                    char c = *((char *)(address + i));
                    printf("%c", (c >= 32 && c <= 126) ? c : '.');
                } else {
                    printf(" ");
                }
                if ((i + 1) % 8 == 0 && i != 0) {
                    printf(" ");
                }
            }
            printf("\n");
        }

        if (display->milliseconds > 0) {
            numaSleep(display->milliseconds);
        }
    } while (display->update);
}