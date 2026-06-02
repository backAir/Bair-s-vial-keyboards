// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_definitions.h"
#include "raw_hid.h"

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
        FR_A,   FR_B,  FR_C,   FR_D,
        FR_E,   FR_F,  FR_G,   FR_H,
        FR_I,   FR_J,  FR_K,   FR_L,
        FR_M,   FR_N,  FR_O,   FR_P,
        FR_Q,   FR_R,  FR_S,   FR_T
    ),
    // [0] = LAYOUT_ortho_5x4(
    //     TG(1),   KC_PSLS, KC_PAST, KC_PMNS,
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
    [0] =   { ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP), // Encoder 0
              ENCODER_CCW_CW(KC_MS_WH_LEFT, KC_MS_WH_RIGHT), // Encoder 1
              ENCODER_CCW_CW(KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP), // Encoder 2
              ENCODER_CCW_CW(KC_VOLD, KC_VOLU) // Encoder 3
            },
    //                  Encoder 1                                     Encoder 2
};
#endif



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t reply[32] = {0,1,2,3,30,19};
    raw_hid_send(reply, 32);

    // if(record->event.pressed && keycode == 0x8999){
    //     led_state = !led_state;
    //     writePin(LED_PIN, led_state);
    //     return false;
    // }

    #include "../../../lib/process_record_user_HID.c"


    return true;
}

// void keyboard_post_init_user(void) {
//     setPinOutput(LED_PIN);
//     writePinHigh(LED_PIN);
// }

void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
// void raw_hid_receive(uint8_t *data, uint8_t length) {
    // Your Raw HID handler here
    // data[0..length-1]
    // uint8_t reply[32] = {0};
    led_state = !led_state;
    writePin(LED_PIN, led_state);
return;


    #include "../../../lib/HID_layer_change.c"

}