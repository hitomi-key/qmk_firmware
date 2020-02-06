/* Copyright 2019 Ryota Goto
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
#include "bootloader.h"
/*
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, \
    K300, K301, K302,     K304,       K306,       K308,   K309, K310, K311  \
*/

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes { 
    QWERTY = SAFE_RANGE,
    KC_LSPC,
    KC_RENT,
    ADJUST
};
#define KC_TCTL MT(MOD_LCTL,KC_TAB)
#define KC_SSLS MT(MOD_RSFT,KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* Base */
    KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,\
    KC_TCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,\
    KC_LSFT, KC_BSLS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SSLS,\
    KC_LALT, XXXXXXX, KC_LGUI,          KC_LSPC,        KC_LSPC,       KC_RENT,      KC_RALT, XXXXXXX, ADJUST\
  ),
  [_LOWER] = LAYOUT( /* Extra Keys */
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_NO,\
    _______, XXXXXXX, KC_INS,  KC_DEL,  KC_BTN3, KC_F11,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_BSPC,\
    _______, KC_BSPC, XXXXXXX, KC_BSPC, KC_APP,  KC_ENT,  KC_F12,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,\
    _______, XXXXXXX, _______,          _______,        _______,        _______,     _______, XXXXXXX, _______\
  ),
  [_RAISE] = LAYOUT( /* Num */
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,\
    _______, KC_4,    KC_5,    KC_6,    KC_DOT,  XXXXXXX, KC_LBRC, KC_MINS, KC_EQL,  KC_BSLS, KC_LPRN, KC_QUOT,\
    _______, KC_GRV,  KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_RBRC, KC_SLSH, XXXXXXX, XXXXXXX, KC_RSFT,\
    _______, XXXXXXX, _______,          KC_TAB,         KC_TAB,         _______,     _______, _______, _______\
  ),
  [_ADJUST] = LAYOUT( \
    RESET,DF(_QWERTY),XXXXXXX, EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_UP,   XXXXXXX, XXXXXXX,\
    KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_RGHT, XXXXXXX, XXXXXXX,\
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOWN, XXXXXXX, _______,\
    _______, XXXXXXX, _______,          _______,        XXXXXXX,        _______,     _______, XXXXXXX, _______\
  ), \
};

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