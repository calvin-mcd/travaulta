#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "matrix.h"

typedef struct {
    uint16_t low_threshold_matrix[MATRIX_ROWS][MATRIX_COLS];  // threshold for key release
    uint16_t high_threshold_matrix[MATRIX_ROWS][MATRIX_COLS]; // threshold for key press
} ecsm_config_t;

int  ecsm_init(ecsm_config_t const* const ecsm_config);
bool ecsm_matrix_scan(matrix_row_t current_matrix[]);
void ecsm_print_matrix(void);
