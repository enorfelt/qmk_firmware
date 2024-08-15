#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _SYMBOLS,
    _NAVIGATION,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_ESDF,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 *  ,-----------------------------------------.                    ,-----------------------------------------.
 *  |  §   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  +   |
 *  |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *  | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  Å   |
 *  |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *  | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ö  |  Ä   |
 *  |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 *  |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  | RSFT |
 *  `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LCTL | LALT | SYMB | /Enter  /       \Space \  | NAVI | BSPC |  DEL | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_LBRC,
    KC_ESC,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,   KC_MPLY,KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
                    KC_LGUI, KC_LCTL, KC_LALT, MO(_SYMBOLS), KC_ENT,    KC_SPC, MO(_NAVIGATION),  KC_BSPC,  KC_DEL, KC_RCTL
),
/*
 * SYMBOLS
 * ,-------fErikkggre----------------------------------.                    ,-----------------------------------------.
 * |  §   |   !  |   @  |   #  |   $  |   %  |                    |   &  |   /  |   `  |   ´  |   ^  |  ¨   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |      |   *  |   ~  |   {  |   }  |                    |      |   7  |   8  |   9  |   :  |  "   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   =  |   +  |   -  |   (  |   )  |-------.    ,-------|   ?  |   4  |   5  |   6  |   ;  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   |  |   <  |   >  |   [  |   ]  |-------|    |-------|   0  |   1  |   2  |   3  |   \  | RCTL |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LCTL | LALT | SYMB | /Enter  /       \Space \  | NAVI | BSPC |  DEL | RALT |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYMBOLS] = LAYOUT(
    KC_TRNS,  SE_EXLM,SE_AT,   SE_HASH, SE_DLR,  SE_PERC,                     SE_AMPR,SE_SLSH, SE_GRV,  SE_ACUT, SE_CIRC,   SE_DIAE,
    KC_TRNS,  KC_NO,  SE_ASTR, SE_TILD, SE_LCBR, SE_RCBR,                     KC_NO,  KC_P7,   KC_P8,   KC_P9,   SE_COLN,   SE_DQUO,
    KC_TRNS,  SE_EQL, SE_PLUS, SE_MINS, SE_LPRN, SE_RPRN,                     SE_QUES,KC_P4,   KC_P5,   KC_P6,   SE_SCLN,   SE_QUOT,
    KC_TRNS,  SE_PIPE,SE_LABK, SE_RABK, SE_LBRC, SE_RBRC, KC_TRNS,    KC_TRNS,KC_P0,  KC_P1,   KC_P2,   KC_P3,   SE_BSLS,   KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, _______, KC_TRNS,    KC_TRNS,_______,  KC_TRNS,  KC_TRNS, KC_TRNS
),
/*
 * NAVIGATION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  §   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |      |      |      |      |      |                    |NUMLK | HOME |  UP  | END  |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |      |      |      |      |      |-------.    ,-------| CAPS | LEFT | DOWN |RIGHT |      |      |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift| UNDO |  CUT | COPY |PASTE |      |-------|    |-------|PRTSC | PGUP |      | PGDN |      | RCTL |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LCTL | LALT | SYMB | /Enter  /       \Space \  | NAVI | BSPC |  DEL | RALT |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NAVIGATION] = LAYOUT(
    KC_TRNS,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_TRNS,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NUM,   KC_HOME,  KC_UP,   KC_END,  KC_NO,   KC_F12,
    KC_TRNS,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_CAPS,  KC_LEFT,  KC_DOWN, KC_RGHT, KC_NO,   KC_NO,
    KC_TRNS,  KC_UNDO,KC_CUT,  KC_COPY, KC_PASTE,KC_NO,    KC_TRNS,  KC_TRNS,KC_PSCR,  KC_PGUP,  KC_NO,   KC_PGDN, KC_NO,   KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS,_______, KC_TRNS,    KC_TRNS,_______,  KC_TRNS,  KC_TRNS, KC_TRNS
),
/*
 * ADJUSTJ
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  TOG |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | MOD+ |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | MOD- |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LCTL | LALT | SYMB | /Enter  /       \Space \  | NAVI | BSPC |  DEL | RALT |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
    RGB_TOG,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   EE_CLR,                     QK_RBT,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    RGB_MOD,  RGB_HUI,RGB_SAI, RGB_VAI, RGB_SPI, KC_NO,                      KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    RGB_RMOD, RGB_HUD,RGB_SAD, RGB_VAD, RGB_SPD, KC_NO,                      KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_TRNS,  KC_TRNS,KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, _______, KC_TRNS,    KC_TRNS,_______,  KC_TRNS,  KC_TRNS, KC_TRNS
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

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        // 'Monitor-product-logo-white', 128x32px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x70, 0x38, 0x18, 0x1c, 0x0c, 0x0c, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0e, 0x0c, 0x1c, 0x18, 0x38, 0x70, 0xe0, 0xc0, 0x80,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xf8, 0xfe, 0x0f, 0x03, 0x00, 0xf0, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0x7f, 0x1f,
        0xce, 0xe0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0x7f, 0x3f, 0x8f, 0xe6, 0xf0, 0xf0, 0x00, 0x01, 0x07,
        0x7e, 0xf8, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0x78, 0xf0, 0xc0, 0x00, 0x00, 0x80, 0xe0,
        0x78, 0xf8, 0xf8, 0x00, 0x00, 0xc0, 0xc0, 0x40, 0x40, 0xc0, 0xc0, 0x00, 0x00, 0xc0, 0xc0, 0xc0,
        0x40, 0x40, 0xc0, 0xc0, 0x00, 0x00, 0xcc, 0xcc, 0x00, 0xc0, 0xf0, 0xf0, 0x40, 0x40, 0x00, 0x80,
        0xc0, 0x40, 0x40, 0xc0, 0xc0, 0x80, 0x00, 0xc0, 0xc0, 0x80, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00,
        0xf8, 0xf8, 0x88, 0x88, 0x88, 0x88, 0x08, 0x00, 0xf8, 0xf8, 0x08, 0x08, 0x08, 0x98, 0xf8, 0x70,
        0x00, 0xf8, 0xf8, 0x08, 0x08, 0x08, 0x98, 0xf8, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x3f, 0xff, 0xe0, 0x80, 0x00, 0x7f, 0x3f, 0x0f, 0x67, 0x73, 0x7c, 0x7e, 0x7f,
        0x7f, 0x7f, 0x3f, 0x1f, 0x47, 0x73, 0x78, 0x7e, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0xc0,
        0xfc, 0x7f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x03, 0x0f, 0x0e, 0x07, 0x01,
        0x00, 0x1f, 0x1f, 0x00, 0x0f, 0x1f, 0x18, 0x10, 0x10, 0x18, 0x1f, 0x07, 0x00, 0x1f, 0x1f, 0x00,
        0x00, 0x00, 0x01, 0x1f, 0x1e, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x1f, 0x1f, 0x10, 0x10, 0x06, 0x0f,
        0x19, 0x10, 0x30, 0x18, 0x1f, 0x0f, 0x00, 0x1f, 0x1f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x1f, 0x1f, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x1f, 0x1f, 0x01, 0x01, 0x07, 0x1f, 0x1d, 0x10,
        0x00, 0x1f, 0x1f, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0e, 0x1c, 0x38, 0x30, 0x70, 0x60, 0xe0, 0xc0, 0xc0,
        0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x60, 0x60, 0x70, 0x38, 0x1c, 0x0e, 0x07, 0x03,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("Symb\n"), false);
            break;
        case _NAVIGATION:
            oled_write_P(PSTR("Navi\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj \n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_180;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYMBOLS, _NAVIGATION, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}
