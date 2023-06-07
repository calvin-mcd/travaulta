#include "switch_matrix.h"
#include "matrix.h"
#include "debug.h"

#ifndef LOW_THRESHOLD
#    define LOW_THRESHOLD 350
#endif

#ifndef HIGH_THRESHOLD
#    define HIGH_THRESHOLD 450
#endif

/* matrix state(1:on, 0:off) */
extern matrix_row_t raw_matrix[MATRIX_ROWS]; // raw values
extern matrix_row_t matrix[MATRIX_ROWS];     // debounced values

// clang-format off
const uint16_t low_threshold[MATRIX_ROWS][MATRIX_COLS] = {
    { 650, 650, 650, 650, 650, 650, 650, 650, 650, 650, 650 }, \
    { 650, 650, 650, 650, 650, 650, 650, 650, 650, 650, 650 }, \
    { 650, 650, 650, 650, 650, 650, 650, 650, 650, 650, 650 }, \
    { 650, 650, 650, 650, 650, 650, 650, 650, 650, 650, 650 }  \
};

const uint16_t high_threshold[MATRIX_ROWS][MATRIX_COLS] = {
    { 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500 }, \
    { 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500 }, \
    { 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500 }, \
    { 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500 }  \
};
// clang-format on

void matrix_init_custom(void) {
    ecsm_config_t ecsm_config;

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            ecsm_config.low_threshold_matrix[row][col]  = low_threshold[row][col];
            ecsm_config.high_threshold_matrix[row][col] = high_threshold[row][col];
        }
    }

    ecsm_init(&ecsm_config);
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool updated = ecsm_matrix_scan(current_matrix);

// RAW matrix values on console
#ifdef CONSOLE_ENABLE
    static int cnt = 0;
    if (cnt++ == 300) {
        cnt = 0;
        ecsm_print_matrix();
    }
#endif

    return updated;
}
