#pragma once

#include <stdint.h>

/**
 * @brief prints a hexadecimal dump of the given data
 *
 * This function prints offset, hexadecimal representation, and ASCII representation.
 *
 * @param data pointer to the input data buffer
 * @param length length of the input data in bytes
 * @param width number of bytes to display per row
 * @param bytes number of bytes to group together (1, 2, 4, or 8)
 *
 * @note The function supports grouping bytes in 1, 2, 4, or 8 byte chunks.
 *       For multi-byte groupings, the data is interpreted as little-endian.
 *
 * @warning if an unsupported byte width is provided, the function will print
 *          an error message to stderr and return without processing the data
*/
void numa(const uint8_t * data, uint32_t length, uint16_t width, uint8_t bytes);
