// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


//#ifdef NONE
enum layer_number {
    _QWERTY = 0,
    _GAME,
    _LOWER,
    _RAISE,
    _G_RAISE,
    _ADJUST
};

enum custom_keycodes { 
    QWERTY = SAFE_RANGE,
    LOWER,
    KC_LSPC,
    RAISE,
    G_RAISE,
    KC_RSLS,
    KC_RENT,
    ADJUST
};

#define KC_TCTL MT(MOD_LCTL,KC_TAB)
//#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
imported keymap from current equinox
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( //Base 
    KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,\
    KC_TCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,\
    KC_LSFT, KC_BSPC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSLS,\
    KC_LALT, XXXXXXX, KC_LGUI,          XXXXXXX,        KC_LSPC,       XXXXXXX,      KC_RALT, XXXXXXX, ADJUST\
  ),
  [_LOWER] = LAYOUT( //Extra Keys
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,\
    _______, XXXXXXX, KC_INS,  KC_DEL,  KC_BTN3, KC_F11,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______,\
    _______, KC_BSPC, XXXXXXX, KC_BSPC, KC_APP,  KC_ENT,  KC_F12,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,\
    _______, XXXXXXX, _______,          XXXXXXX,        _______,        XXXXXXX,     _______, XXXXXXX, ADJUST\
  ),
  [_RAISE] = LAYOUT( // Num
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,\
    _______, KC_4,    KC_5,    KC_6,    KC_DOT,  XXXXXXX, KC_LBRC, KC_MINS, KC_EQL,  KC_BSLS, KC_LPRN, KC_QUOT,\
    _______, KC_GRV,  KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_RBRC, KC_SCLN, XXXXXXX, XXXXXXX, KC_RSFT,\
    _______, XXXXXXX, _______,          XXXXXXX,         KC_ATAB,         XXXXXXX,     _______, _______, ADJUST\
  ),
  [_ADJUST] = LAYOUT( \
    RESET,DF(_QWERTY),XXXXXXX, EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_UP,   XXXXXXX, XXXXXXX,\
    KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_RGHT, XXXXXXX, XXXXXXX,\
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOWN, XXXXXXX, _______,\
    _______, XXXXXXX, _______,          XXXXXXX,        XXXXXXX,        XXXXXXX,     _______, XXXXXXX, _______\
  ), \
};
*/
    [_QWERTY] = LAYOUT(\
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,\
    KC_TCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_H,    KC_J,    KC_K,    KC_L,     KC_ENT,\
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSLS, \
         KC_LALT,      LOWER,   KC_LGUI, KC_LSPC,               KC_RENT, KC_RALT, RAISE,      ADJUST \
),
    [_GAME] = LAYOUT(\
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,\
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_H,    KC_J,    KC_K,    KC_L,       KC_ENT,\
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_LGUI, \
                KC_NO,       LOWER,   KC_ENT,  KC_SPC,          G_RAISE, KC_RALT, RAISE,       ADJUST \
),
  [_LOWER] = LAYOUT( \
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_DEL,\
    _______, MS_BTN1, KC_INS,  KC_DEL,  MS_BTN3,  KC_F11,       KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, MS_WHLU, \
    _______, MS_BTN2, KC_BSPC, KC_APP,  KC_ENT, KC_F12,         KC_HOME, KC_PGDN, KC_PGUP, KC_END,  MS_WHLD, \
         _______,    LOWER,   _______, KC_TAB,                  KC_TAB, _______,RAISE,      ADJUST\
   ),
  [_RAISE] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,      KC_9,      KC_0,    KC_GRV,\
    _______, KC_4,    KC_5,    KC_6,    KC_DOT,  XXXXXXX,       KC_LBRC, KC_MINS, KC_EQL,    KC_BSLS,   KC_QUOT,\
    _______, KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,       KC_RBRC, KC_SCLN, MS_WHLU,   MS_WHLD, _______,\
         _______,      LOWER,   _______, KC_TAB,                XXXXXXX, _______, RAISE,     _______\
  ),
  [_G_RAISE] = LAYOUT( \
    KC_ESC,   KC_1,    KC_2,   KC_3,    KC_4,    KC_5,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,\
    _______, XXXXXXX,  KC_6,   KC_7,    KC_8,    KC_9,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT,\
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_0,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,\
         KC_NO,      LOWER,   _______, KC_TAB,                  XXXXXXX, _______, RAISE,      _______\
  ),
  [_ADJUST] = LAYOUT( \
    QK_BOOT,DF(_QWERTY),XXXXXXX, EE_CLR, XXXXXXX, XXXXXXX,      EE_CLR, XXXXXXX, KC_PSCR, KC_UP,   XXXXXXX, QK_BOOT,\
    KC_CAPS, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, DF(_GAME),     BL_STEP, BL_UP,   KC_LEFT, KC_RGHT, XXXXXXX,\
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,BL_TOGG,        BL_BRTG, BL_DOWN,  KC_DOWN,  XXXXXXX, _______,\
         _______,    LOWER,   _______, XXXXXXX,                 XXXXXXX, _______, RAISE,      _______\
  ), \
};

//#ifdef NONE
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
	if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
		layer_on(layer3);
	} else {
		layer_off(layer3);
	}
}

static bool lower_pressed = false;
static bool raise_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_LSPC:
            if (record->event.pressed) {
                lower_pressed = 1;

                layer_on(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);

                if(lower_pressed){
                    register_code(KC_SPC);
                    unregister_code(KC_SPC);
                }
                lower_pressed = 0;
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RENT:
            if (record->event.pressed) {
                raise_pressed = 1;

                layer_on(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
                
                if(raise_pressed){
                    register_code(KC_ENT);
                    unregister_code(KC_ENT);
                }
                raise_pressed = 0;
            }
            return false;
        case KC_RSLS:
            if (record->event.pressed) {
                raise_pressed = 1;

                layer_on(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
                
                if(raise_pressed){
                    register_code(KC_SLSH);
                    unregister_code(KC_SLSH);
                }
                raise_pressed = 0;
            }
            return false;
        case G_RAISE:
            if (record->event.pressed) {
                layer_on(_G_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_G_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        default:
            if (record->event.pressed) {
                lower_pressed = 0;
                raise_pressed = 0;
            }
            break;
            
    }

    return true;
}
//#endif