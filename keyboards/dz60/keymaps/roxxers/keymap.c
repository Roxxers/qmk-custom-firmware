#include QMK_KEYBOARD_H
#include "keymap_uk.h"
#include "sendstring_uk.h"

// Define layer consts
#define RALT_UP 1
#define FN_UP 2
#define SETTING 3

enum my_keycodes {
    PIPE = SAFE_RANGE,
    BKSLSH
};

bool process_record_user(uint16_t kc, keyrecord_t *rec) {
    // Detect altgr keypress and dont process as normal if PIPE or BKSLSH are pressed
    // uint8_t layer;
    // layer = biton32(layer_state);  // get the current layer
    // if (layer == RALT_UP) {        // if it is your shift layer, then...
    //      if (kc >= KC_A && kc <= KC_EXSEL && !(  
    //      // if your keycode is in this range, shift will be enabled, unless you exclude it below
    //      // in my example, you don't want shift if 1 or 2 is pressed while on this layer
    //      // just add whichever keycodes you want to exclude
    //              kc == PIPE ||
    //              kc == BKSLSH
    //         )) {
    //           if (rec->event.pressed) {
    //               register_mods(MOD_RALT);
    //           } else {
    //               unregister_mods(MOD_RALT);
    //           }
    //      }
    // }
    switch (kc) {
        case PIPE:
            if (rec->event.pressed) {
                SEND_STRING("|");
            }
            return false; // Skip all further processing of this key
        case BKSLSH:
            if (rec->event.pressed) {
                SEND_STRING("\\");
            }
            return false; // Skip all further processing of this key
        default:
            return true;
    };
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_60_iso_4th_row_all_1u(
        KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,
        LT(FN_UP, KC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(SETTING), KC_DEL,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(RALT_UP), _______, MO(FN_UP), KC_RCTL
    ),
    [RALT_UP] = LAYOUT_60_iso_4th_row_all_1u(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NO,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, PIPE, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, BKSLSH, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
	[FN_UP] = LAYOUT_60_iso_4th_row_all_1u(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLCK, KC_PSCR, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_MSTP, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, KC_UP, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_MSEL, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_LEFT, KC_DOWN, KC_RGHT,
        _______, _______, _______, _______, _______, _______, _______, KC_TRNS, _______
    ),
	[SETTING] = LAYOUT_60_iso_4th_row_all_1u(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

