#ifndef NUMA_NUMA_H
#define NUMA_NUMA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <time.h>

#ifdef _WIN32

#include <windows.h>
#define numaDisplayClear() system("cls")
#define numaSleep(ms) Sleep(ms)

#else

#include <unistd.h>
#define numaDisplayClear() system("clear")
#define numaSleep(ms) usleep(ms * 1000)

#endif

/**
 * @brief Structure to hold the configuration for the Numa display.
 *
 * @param start_address Starting memory address to display.
 * @param length Length of the memory to display in bytes.
 * @param width Number of bytes to display per line.
 * @param milliseconds Delay in milliseconds between updates.
 * @param update Flag to determine if the display should continuously update.
 * @param bytes_per_view Number of bytes to display together (1 for single byte, 2 for 2 bytes, etc.).
 */
__attribute__((unused)) typedef struct NumaDisplay {
     uint64_t start_address;
    uint32_t length;
    uint32_t width;
    uint32_t milliseconds;
    bool update;
    uint8_t bytes_per_view;
} NumaDisplay;


/**
 * @brief Displays the memory content in a formatted view.
 *
 * @param display Pointer to the NumaDisplay structure containing the display configuration.
 *
 * This function clears the screen, prints the header, and then displays the memory content
 * starting from `display->start_address` up to the specified `display->length` in a formatted view.
 * The display is updated continuously if `display->update` is true, with a delay specified by
 * `display->milliseconds`.
 */
__attribute__((unused)) void numaDisplay(NumaDisplay * display);

#endif /* NUMA_NUMA_H */
