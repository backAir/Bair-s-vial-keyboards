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
    [0] = LAYOUT_ortho_3x3(
        KC_KP_7,KC_KP_8,0x8999,
        KC_KP_4,KC_KP_5,KC_KP_6,
        KC_KP_1,KC_KP_2,KC_KP_3
    )
    //     [1] = LAYOUT_ortho_3x3(
    //     KC_B
    // ),
    //     [2] = LAYOUT_ortho_3x3(
    //     KC_C
    // ),
    //     [3] = LAYOUT_ortho_3x3(
    //     KC_D
    // )
};

// static uint32_t press_counter = 0;
static bool led_state = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
            uint8_t reply[32] = {0,1,2,3,30,19};
                raw_hid_send(reply, 32);

    if(record->event.pressed && keycode == 0x8999){
        led_state = !led_state;
        writePin(LED_PIN, led_state);
        return false;
    }

    #include "../../../lib/process_record_user_HID.c"


    return true;
}




void keyboard_post_init_user(void) {
    setPinOutput(LED_PIN);
    writePinHigh(LED_PIN);
}


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

