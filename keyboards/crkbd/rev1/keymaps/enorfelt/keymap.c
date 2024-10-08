#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  SS_LOCK = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SS_LOCK:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_TAP(X_L)));
      }
      break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_split_3x6_3(
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, 		KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
		KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G,			KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,		KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RALT,
									KC_LCTL, MO(1), KC_ENT,		KC_SPC, KC_BSPC, MO(2)
		),

	[_LOWER] = LAYOUT_split_3x6_3(
		KC_TAB, KC_EXLM, KC_P7, KC_P8, KC_P9, SE_DLR,			KC_RBRC, KC_CIRC, KC_PIPE, KC_ASTR, KC_LPRN, SE_BSLS,
		KC_ESC, SE_DQUO, KC_P4, KC_P5, KC_P6, KC_PERC,								KC_NUBS, KC_RPRN, KC_MINS, SE_LBRC, SE_RBRC, SE_QUOT,
		KC_LSFT, KC_HASH, KC_P1, KC_P2, KC_P3, KC_P0,								SE_SLSH, SE_AT, SE_PIPE, SE_LCBR, SE_RCBR, KC_EQL,
														KC_RALT, KC_TRNS, KC_ENT, KC_SPC, KC_BSPC, MO(3)
		),

	[_RAISE] = LAYOUT_split_3x6_3(
		KC_TAB, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,					KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
		KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, SS_LOCK,					KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_PGUP, KC_F12,
		KC_LSFT, KC_NO, KC_LCTL, KC_LALT, KC_DEL, KC_NO,					KC_PSCR, KC_HOME, KC_END, KC_CAPS, KC_PGDN, KC_RALT,
													KC_LGUI, MO(3), KC_ENT, KC_SPC, KC_TRNS, KC_NO
		),
	[_ADJUST] = LAYOUT_split_3x6_3(
		QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,					KC_NO, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO,
		RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, KC_NO,		KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, KC_NO, KC_NO,
		RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO, KC_NO,		KC_NO, KC_VOLD, KC_NO, KC_NO, KC_NO, KC_NO,
													KC_NO, KC_TRNS, KC_ENT, KC_SPC, KC_TRNS, KC_NO
		)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)




