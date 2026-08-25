// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdlib.h>
#include <string.h>
#include "keymap_definitions.h"
#include QMK_KEYBOARD_H
#include "quantum.h"
// #include "gpio.h"
// #include "i2c.h"

#include "timer.h"


#include "raw_hid.h"
#include "../../../lib/messages.h"

// enum layer_names
// {
//     Base,
//     Two,
//     Three,
//     RGB
// };

// #include "config.h"

enum custom_keycodes {
    KC_P00 = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │TG1│ / │ * │ - │
     * ├───┼───┼───┼───┤
     * │ 7 │ 8 │ 9 │ + │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ % │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ = │
     * ├───┼───┼───┼───┤
     * │ 0 │00 │ . │Ent│
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_5x4(
        FR_A,  FR_B,                FR_C, FR_D,
        FR_E, FR_F, FR_G, FR_H, FR_I,
        FR_J, FR_K, FR_L, FR_M, FR_N,
        FR_0, FR_P, FR_Q, FR_R, FR_S
    ),
    [3] = LAYOUT_ortho_5x4(
        FR_A,  FR_B,                FR_C, FR_D,
        FR_E, FR_F, FR_G, FR_H, FR_I,
        FR_J, FR_K, FR_L, FR_M, FR_N,
        FR_0, FR_P, FR_Q, FR_R, FR_S
    )
    // [0] = LAYOUT_ortho_5x4(
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
    // [1] = LAYOUT_ortho_5x4(
    //     _______, _______, _______, _______,
    //     KC_HOME, KC_UP,   KC_PGUP, _______,
    //     KC_LEFT, XXXXXXX, KC_RGHT, _______,
    //     KC_END,  KC_DOWN, KC_PGDN, _______,
    //     KC_INS,  XXXXXXX, KC_DEL,  _______
    // )
};






#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), // Encoder 0
         ENCODER_CCW_CW(KC_VOLD, KC_VOLU) // Encoder 0
            },
    [3] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), // Encoder 0
         ENCODER_CCW_CW(KC_VOLD, KC_VOLU) // Encoder 0
            },
};
#endif




void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
// void raw_hid_receive(uint8_t *data, uint8_t length) {
    #include "../../../lib/HID_layer_change.c"
}


void matrix_init_user(void) {
    // static const char PROGMEM atreus_logo[] = ACH_LOGO;



    // Set the pin as an output
    // setPinOutput(GP1);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record){
    #include "../../../lib/process_record_user_HID.c"
    return true;
}



void matrix_scan_user(void) {
/*     if (blinking) {
        if (timer_elapsed(blink_timer) > BLINK_INTERVAL) {
            blink_timer = timer_read();
            // if (readPin(GP1)) {
            //     writePinLow(GP1);
            // } else {
            //     writePinHigh(GP1);
            // }
        }
    } */
}






// bool oled_task_user(void) {
// // bool oled_task_kb(void) {

//     if (oled_update_required) {
//         oled_write_raw((char*)oled_buffer, sizeof(oled_buffer));
//         // oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
//         oled_update_required = false;
//     }
//     return false;
// }

// #endif
