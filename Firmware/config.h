#pragma once

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 10

/* Custom matrix pins and port select array */
#define MATRIX_ROW_PINS \
    { B13, B14, B15, B12 }
#define MATRIX_COL_CHANNELS \
    { 2, 1, 0, 3, 4 }
#define MUX_SEL_PINS \
    { B5, B4, B3 }

/* Hardware peripherals pins */
#define APLEX_EN_PIN_0 B0
#define APLEX_EN_PIN_1 B1
#define DISCHARGE_PIN A4
#define ANALOG_PORT A3

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
//#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

