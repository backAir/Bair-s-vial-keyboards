// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "raw_hid.h"

#define LED_PIN GP0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐
     * │ A │
     * └───┘
     */
    [0] = LAYOUT_ortho_1x1(
        0x8001
    ),
        [1] = LAYOUT_ortho_1x1(
        KC_B
    ),
        [2] = LAYOUT_ortho_1x1(
        KC_C
    ),
        [3] = LAYOUT_ortho_1x1(
        KC_D
    )
};

// static uint32_t press_counter = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #include "../../../lib/process_record_user_HID.c"
    return true;
}



// static bool led_state = true;

void keyboard_post_init_user(void) {
    // setPinOutput(LED_PIN);
    // writePinHigh(LED_PIN); // LED off initially
}


void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
// void raw_hid_receive(uint8_t *data, uint8_t length) {
    // Your Raw HID handler here
    // data[0..length-1]
    // uint8_t reply[32] = {0};
    #include "../../../lib/HID_layer_change.c"

}

