// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdlib.h>
#include "keymap_definitions.h"
#include QMK_KEYBOARD_H
#include "quantum.h"
// #include "gpio.h"
// #include "i2c.h"

#include "timer.h"



// #include "config.h"

enum custom_keycodes {
    KC_P00 = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Imagine cool ascii art of the keyboard here
     */
    [0] = LAYOUT_65(
        FR_A, FR_B , FR_C,
        FR_D, FR_E, FR_F
    )
    // [0] = LAYOUT_65(
    //     FR_A,   FR_A,  FR_A,   FR_A,  FR_A,   FR_A,  FR_A,   FR_A, FR_A, FR_A, FR_A,   FR_A,  FR_A, FR_A,
    //     // FR_B,   FR_B,  FR_B,   FR_B, FR_B, FR_B, FR_B,   FR_B,  FR_B,   FR_B,  FR_B,   FR_B,  FR_B,   FR_B, FR_B, FR_B, FR_B,   FR_B, FR_B,
    //     // FR_C,  FR_C,   FR_C,  FR_C,   FR_C, FR_C, FR_C, FR_C,   FR_C,  FR_C,   FR_C,  FR_C,   FR_C,  FR_C,   FR_C, FR_C, FR_C, FR_C, FR_C,
    //     // FR_D,  FR_D, FR_D,  FR_D,   FR_D,  FR_D,   FR_D, FR_D, FR_D, FR_D,   FR_D,  FR_D,   FR_D,  FR_D,   FR_D,  FR_D,   FR_D, FR_D,
    //     // FR_E, FR_E,   FR_E,  FR_E,   FR_E,  FR_E,   FR_E,  FR_E,   FR_E, FR_E, FR_E, FR_E,   FR_E,  FR_E,   FR_E,  FR_E,   FR_E,  FR_E,
    //     // FR_F, FR_F, FR_F, FR_F,   FR_F,  FR_F,   FR_F,  FR_F,   FR_F,  FR_F,   FR_F, FR_F, FR_F, FR_F,
    //     // FR_G,  FR_G,   FR_G,  FR_G,   FR_G

    // )
    // [0] = LAYOUT_65(
    //     TG(1),   KC_PSLS, KC_PAST, KC_PeMNS,
    //     KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
    //     KC_P4,   KC_P5,   KC_P6,   KC_PERC,
    //     KC_P1,   KC_P2,   KC_P3,   KC_EQL,
    //     KC_P0,   KC_P00,  KC_PDOT, KC_PENT
    // ),

    /*
     * ┌───┬───┬───┬───┐
     * │TG1│ / │ * │ - │
     * ┌───┬───┬───┐───┤
     * │Hom│ ↑ │PgU│ + │
     * ├───┼───┼───┤───┤
     * │ ← │   │ → │ % │
     * ├───┼───┼───┤───┤
     * │End│ ↓ │PgD│ = │
     * ├───┼───┼───┤───┤
     * │Ins│   │Del│Ent│
     * └───┴───┴───┘───┘
     */
    // [1] = LAYOUT_65(
    //     _______, _______, _______, _______,
    //     KC_HOME, KC_UP,   KC_PGUP, _______,
    //     KC_LEFT, XXXXXXX, KC_RGHT, _______,
    //     KC_END,  KC_DOWN, KC_PGDN, _______,
    //     KC_INS,  XXXXXXX, KC_DEL,  _______
    // )
};

// void matrix_init_user(void) {
//     // memset(oled_buffer, 0, sizeof(oled_buffer));
//     // Set the pin as an output
//     // setPinOutput(GP21);
// }

// bool led_update_kb(led_t led_state) {
//     bool res = led_update_user(led_state);
//     if(res) {
//         // gpio_write_pin sets the pin high for 1 and low for 0.
//         // In this example the pins are inverted, setting
//         // it low/0 turns it on, and high/1 turns the LED off.
//         // This behavior depends on whether the LED is between the pin
//         // and VCC or the pin and GND.
//         gpio_write_pin(GP21, led_state.caps_lock);

//     }
//     return res;
// }


// #if defined(ENCODER_MAP_ENABLE)
// const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
//     [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), // Encoder 0
//             },
// };
// #endif
// #define OLED_ENABLE
