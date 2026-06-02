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
        KC_A
    )
};

static bool led_state = true;

void keyboard_post_init_user(void) {
    setPinOutput(LED_PIN);
    writePinHigh(LED_PIN); // LED off initially
}


void raw_hid_receive_user(uint8_t *data, uint8_t length) {
    // Your Raw HID handler here
    // data[0..length-1]
    led_state = !led_state;
    writePin(LED_PIN, led_state);
}
