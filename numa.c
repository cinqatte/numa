#include "numa.h"
#include <stdio.h>
#include <ctype.h>

void numa(const uint8_t *data, uint32_t length, uint16_t width, uint8_t bytes) {
    uint32_t i, j;
    for (i = 0; i < length; i += width) {
        printf("%08x: ", i);
        
        for (j = 0; j < width; j += bytes) {
            if (i + j < length) {
                switch (bytes) {
                    case 1: printf("%02x ", data[i + j]); break;
                    case 2: 
                        if (i + j + 1 < length) 
                            printf("%04x ", *((uint16_t *)(data + i + j))); 
                        else 
                            printf("%02x   ", data[i + j]);
                        break;
                    case 4: 
                        if (i + j + 3 < length) 
                            printf("%08x ", *((uint32_t *)(data + i + j))); 
                        else {
                            for (int k = 0; k < 4 && i + j + k < length; k++)
                                printf("%02x", data[i + j + k]);
                            printf("%*s", 2 * (4 - (length - (i + j))), "");
                        }
                        break;
                    case 8: 
                        if (i + j + 7 < length) 
                            printf("%016lx ", *((uint64_t *)(data + i + j))); 
                        else {
                            for (int k = 0; k < 8 && i + j + k < length; k++)
                                printf("%02x", data[i + j + k]);
                            printf("%*s", 2 * (8 - (length - (i + j))), "");
                        }
                        break;
                    default: 
                        fprintf(stderr, "Unsupported byte width\n"); 
                        return;
                }
            } else {
                printf("%*s", bytes * 2 + 1, "");
            }
        }
        
        // Print ASCII representation
        printf(" | ");
        for (j = 0; j < width && i + j < length; ++j) {
            uint8_t byte = data[i + j];
            printf("%c", isprint(byte) ? byte : '.');
        }
        printf("\n");
    }
}