/* Copyright 2023 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
//#include "keymap_swedish.h"

#define _QWERTY 0
#define _SYMBOLS 1
#define _NAVIGATION 2
#define _ADJUST 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  §   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  +   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  Å   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ö  |  Ä   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  | RCTL |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LCTL | LALT | SYMB | /Enter  /       \Space \  | NAVI | BSPC |  DEL | RALT |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_LBRC,
    KC_ESC,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,   KC_MPLY,KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
                      KC_LGUI, KC_LCTL, KC_LALT, MO(_SYMBOLS), KC_ENT,    KC_SPC, MO(_NAVIGATION),  KC_BSPC,  KC_DEL, KC_RALT

),
/*
 * SYMBOLS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  §   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  +   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   7  |   8  |   9  |   P  |  Å   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   4  |   5  |   6  |   Ö  |  Ä   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   0  |   1  |   2  |   3  |   -  | RCTL |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LCTL | LALT | SYMB | /Enter  /       \Space \  | NAVI | BSPC |  DEL | RALT |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_SYMBOLS] = LAYOUT(
    KC_TRNS,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_TRNS,   KC_TRNS,KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,MO(_ADJUST),  KC_TRNS,  KC_TRNS, KC_TRNS

),
[_NAVIGATION] = LAYOUT(
    KC_TRNS,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_TRNS,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NUM,   KC_HOME,  KC_UP,   KC_END,  KC_NO,   KC_F12,
    KC_TRNS,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_CAPS,  KC_LEFT,  KC_DOWN, KC_RGHT, KC_NO,   KC_NO,
    KC_TRNS,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_TRNS,  KC_TRNS,KC_PSCR,  KC_PGUP,  KC_NO,   KC_PGDN, KC_NO,   KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS

),
[_ADJUST] = LAYOUT(
    RGB_TOG,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    RGB_MOD,  RGB_HUI,RGB_SAI, RGB_VAI, RGB_SPI, KC_NO,                      KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    RGB_RMOD, RGB_HUD,RGB_SAD, RGB_VAD, RGB_SPD, KC_NO,                      KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_TRNS,  KC_TRNS,KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS

),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] =     { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_SYMBOLS] =    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_NAVIGATION] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_ADJUST] =     { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif
