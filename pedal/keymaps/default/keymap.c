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

static uint32_t press_counter = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        press_counter++;

        uint8_t report[32] = {0};   // 33 bytes = report ID + 32 data

        report[1] = 0x10; // Message type: key press
        report[2] = (press_counter >> 0) & 0xFF;
        report[3] = (press_counter >> 8) & 0xFF;
        report[4] = (press_counter >> 16) & 0xFF;
        report[5] = (press_counter >> 24) & 0xFF;

        report[6] = keycode & 0xFF;
        report[7] = keycode >> 8;

        raw_hid_send(report, 32);
    }

    return true;
}

// static bool led_state = true;

// void keyboard_post_init_user(void) {
//     setPinOutput(LED_PIN);
//     writePinHigh(LED_PIN); // LED off initially
// }


void raw_hid_receive(uint8_t *data, uint8_t length) {
    // Your Raw HID handler here
    // data[0..length-1]
    // led_state = !led_state;
    // writePin(LED_PIN, led_state);

    // uint8_t reply[32] = {0};

    // reply[0] = 0xAA;        // response ID
    // reply[1] = data[0];    // echo command
    #include "../../../lib/HID_layer_change.c"

    raw_hid_send(data, 32);
}

