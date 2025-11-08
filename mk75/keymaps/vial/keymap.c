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
    [0] = LAYOUT_75(
                                    KC_ESCAPE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DELETE,
        KC_B, KC_B, KC_B, KC_B,     KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, KC_EQUAL, KC_BSPC, KC_PSCR,
        KC_C, KC_C, KC_C, KC_C,     KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BACKSLASH, KC_PGUP,
        KC_D, KC_D, KC_D, KC_D,     KC_CAPS_LOCK, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SEMICOLON, KC_QUOTE , KC_ENTER, KC_PAGE_DOWN,
        KC_E, KC_E, KC_E, KC_E,     KC_LEFT_SHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RIGHT_SHIFT, KC_UP, KC_END,
        KC_F, KC_F, KC_F, KC_F,     KC_LEFT_CTRL, KC_LGUI, KC_LALT, KC_SPACE, KC_RALT, KC_RGUI, KC_RIGHT_CTRL, KC_LEFT, KC_DOWN, KC_RIGHT,
        KC_UP, KC_DOWN, KC_SPACE, KC_LEFT, KC_RIGHT
    )
    // [0] = LAYOUT_75(
    //     FR_A,   FR_A,  FR_A,   FR_A,  FR_A,   FR_A,  FR_A,   FR_A, FR_A, FR_A, FR_A,   FR_A,  FR_A, FR_A,
    //     // FR_B,   FR_B,  FR_B,   FR_B, FR_B, FR_B, FR_B,   FR_B,  FR_B,   FR_B,  FR_B,   FR_B,  FR_B,   FR_B, FR_B, FR_B, FR_B,   FR_B, FR_B,
    //     // FR_C,  FR_C,   FR_C,  FR_C,   FR_C, FR_C, FR_C, FR_C,   FR_C,  FR_C,   FR_C,  FR_C,   FR_C,  FR_C,   FR_C, FR_C, FR_C, FR_C, FR_C,
    //     // FR_D,  FR_D, FR_D,  FR_D,   FR_D,  FR_D,   FR_D, FR_D, FR_D, FR_D,   FR_D,  FR_D,   FR_D,  FR_D,   FR_D,  FR_D,   FR_D, FR_D,
    //     // FR_E, FR_E,   FR_E,  FR_E,   FR_E,  FR_E,   FR_E,  FR_E,   FR_E, FR_E, FR_E, FR_E,   FR_E,  FR_E,   FR_E,  FR_E,   FR_E,  FR_E,
    //     // FR_F, FR_F, FR_F, FR_F,   FR_F,  FR_F,   FR_F,  FR_F,   FR_F,  FR_F,   FR_F, FR_F, FR_F, FR_F,
    //     // FR_G,  FR_G,   FR_G,  FR_G,   FR_G

    // )
    // [0] = LAYOUT_75(
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
    // [1] = LAYOUT_75(
    //     _______, _______, _______, _______,
    //     KC_HOME, KC_UP,   KC_PGUP, _______,
    //     KC_LEFT, XXXXXXX, KC_RGHT, _______,
    //     KC_END,  KC_DOWN, KC_PGDN, _______,
    //     KC_INS,  XXXXXXX, KC_DEL,  _______
    // )
};




// #if defined(ENCODER_MAP_ENABLE)
// const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
//     [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), // Encoder 0
//             },
// };
// #endif
// #define OLED_ENABLE
#if defined(OLED_ENABLE)
#include "oled.h"
static uint8_t oled_buffer[128 * 64 / 8] = {0};
static bool oled_update_required = false;


void matrix_init_user(void) {
    memset(oled_buffer, 0, sizeof(oled_buffer));
    // Set the pin as an output
    setPinOutput(GP1);
}

bool toggled = false;
bool blinking = false;
uint16_t blink_timer = 0;
const uint16_t BLINK_INTERVAL = 500; // Blink interval in milliseconds
int stupid_logo = false;
int x = 0;
int y = 0;


// if returns true then the keypress registers
bool process_record_user(uint16_t keycode, keyrecord_t *record){
    // if(!record->event.pressed){
    //     return false;
    // }
    // switch (keycode) {
    //     case FR_A:
    //         oled_buffer[0] = 0xFF;
    //         oled_buffer[10] = 0x00;
    //         oled_update_required = true;
    //     break;
    //     case FR_B:
    //         oled_buffer[0] = 0x00;
    //         oled_buffer[10] = 0xFF;
    //         oled_update_required = true;
    //     break;
    //     case FR_C:
            // for (size_t i = 0; i < 10; i++)
            // {
            //     bool in_bound = y < 128;
            //     if(in_bound){
            //         write_to_oled_buffer(x,y,true);
            //         oled_update_required = true;
            //         x++;
            //         if (x >= OLED_WIDTH) {
            //             x = 0;
            //             y++;
            //         }
            //     }
            // }
    //     break;
    //     case QK_BOOTLOADER:
    //         return true;
    // }
    return true;
    write_to_oled_buffer(x,y,true);

}

void matrix_scan_user(void) {
    if (blinking) {
        if (timer_elapsed(blink_timer) > BLINK_INTERVAL) {
            blink_timer = timer_read();
            if (readPin(GP1)) {
                writePinLow(GP1);
            } else {
                writePinHigh(GP1);
            }
        }
    }
}


static void write_to_oled_buffer(uint8_t x, uint8_t y, bool on){
    if (x >= OLED_WIDTH || y >= OLED_HEIGHT) {
        return; // Out of bounds
    }

    uint16_t index = (y / 8) * OLED_WIDTH + x;
    uint8_t bit = 1 << (y % 8);

    if (on) {
        oled_buffer[index] |= bit; // Set the bit to turn the pixel on
    } else {
        oled_buffer[index] &= ~bit; // Clear the bit to turn the pixel off
    }
}





oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}




bool oled_task_kb(void) {
    for (size_t i = 0; i < 10; i++)
    {
        oled_buffer[i] = 0xFF;
    }
    const char *text = PSTR("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789!@#$%^&*()[]{}-=_+?/,.|abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789!@#$%^&*()[]{}-=_+?/,.|");
    oled_write_P(text, false);

    // oled_write_raw((char*)oled_buffer, sizeof(oled_buffer));
    if (oled_update_required) {
        oled_update_required = false;
    }
    return false;
}

#endif
