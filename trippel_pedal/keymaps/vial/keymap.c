// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "raw_hid.h"
#include "messages.h"
#define LED_PIN GP0


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐
     * │ A │
     * └───┘
     */
    [0] = LAYOUT_pedals(
        KC_A, KC_B , KC_C,
        KC_D, KC_E, KC_F
    ),
    [1] = LAYOUT_pedals(
        KC_B, KC_B , KC_C,
        KC_D, KC_E, KC_F
    ),
    [2] = LAYOUT_pedals(
        KC_C, KC_B , KC_C,
        KC_D, KC_E, KC_F
    ),
    [3] = LAYOUT_pedals(
        KC_D, KC_B , KC_C,
        KC_D, KC_E, KC_F
    )
};

// static uint32_t press_counter = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed && keycode >= 0x8000) {
        uint8_t reply[32] = {0};

        if (keycode < 0x8100)
        {
            reply[0] = LAUNCH_PROGRAM;
            reply[1] =  keycode - 0x8000;
            raw_hid_send(reply, 32);
        }
        return false;
    }

    return true;
}


// #define TEST_LED
#ifndef TEST_LED

void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
// void raw_hid_receive(uint8_t *data, uint8_t length) {
    // Your Raw HID handler here
    // data[0..length-1]

    uint8_t reply[32] = {0};
    switch (data[0]) {
        case LAYER_CHANGE:
            layer_move(data[1]);
            break;
    }
    // layer_move(3);

    raw_hid_send(reply, 32);
}

#else
static bool led_state = true;

void keyboard_post_init_user(void) {
    setPinOutput(LED_PIN);
    writePinHigh(LED_PIN); // LED off initially
}


void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
// void raw_hid_receive(uint8_t *data, uint8_t length) {
    // Your Raw HID handler here
    // data[0..length-1]
    led_state = !led_state;
    writePin(LED_PIN, data[0] == 0xAA);
    // writePin(LED_PIN, led_state);

    // uint8_t reply[32] = {0};

    // reply[0] = 0xAA;        // response ID
    // reply[1] = data[0];    // echo command

    // raw_hid_send(reply, 32);
    // for (size_t i = 0; i < 32; i++)
    // {
    //     data[i] = i;
    // }
    raw_hid_send(data, 32);
}
#endif
