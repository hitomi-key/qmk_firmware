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

    [0] = LAYOUT(
        KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,
        KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	
        KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_RSLS,	
                        KC_NO,	KC_NO,	KC_NO,	KC_LSPC,    KC_RENT,KC_NO,	KC_NO,	KC_NO
        )
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