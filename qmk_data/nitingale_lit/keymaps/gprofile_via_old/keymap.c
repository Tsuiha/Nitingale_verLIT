/* Copyright 2023 Tsuiha
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

static bool x_pressed = false;
static bool c_pressed = false;
static bool v_pressed = false;
static bool b_pressed = false;

static int lay0 = 0;
static int lay1 = 0;
static int lay2 = 0;
static int lay3 = 0;

static bool wkeep = false;
static bool akeep = false;
static bool skeep = false;
static bool dkeep = false;
/*
enum custom_keycodes {
    USER00 = SAFE_RANGE,
	USER01,USER02,USER03
};
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
	
/*
judge layer command
 */
	case KC_X:
        if (record->event.pressed) {
            x_pressed = true;
        } else {
            x_pressed = false;
			lay0 = 0;
			lay1 = 0;
			lay2 = 0;
			lay3 = 0;
        }
        break;
	
	case KC_C:
        if (record->event.pressed) {
            c_pressed = true;
        } else {
            c_pressed = false;
			lay0 = 0;
			lay1 = 0;
			lay2 = 0;
			lay3 = 0;
        }
        break;

	case KC_V:
        if (record->event.pressed) {
            v_pressed = true;
        } else {
            v_pressed = false;
			lay0 = 0;
			lay1 = 0;
			lay2 = 0;
			lay3 = 0;
        }
        break;

	case KC_B:
        if (record->event.pressed) {
            b_pressed = true;
        } else {
            b_pressed = false;
			lay0 = 0;
			lay1 = 0;
			lay2 = 0;
			lay3 = 0;
        }
        break;

/*
switch layer command
 */
	case KC_1:
		if (record->event.pressed) {
			if (x_pressed && c_pressed && v_pressed && b_pressed) {
				lay0 ++;
				if (lay0 == 5) {
					set_single_persistent_default_layer(0);
				}
			}
		}
		return true;
		break;
		
	case KC_2:
		if (record->event.pressed) {
			if (x_pressed && c_pressed && v_pressed && b_pressed) {
				lay1 ++;
				if (lay1 == 5) {
					set_single_persistent_default_layer(1);
				}
			}
		}
		return true;
		break;

	case KC_3:
		if (record->event.pressed) {
			if (x_pressed && c_pressed && v_pressed && b_pressed) {
				lay2 ++;
				if (lay2 == 5) {
					set_single_persistent_default_layer(2);
				}
			}
		}
		return true;
		break;

	case KC_4:
		if (record->event.pressed) {
			if (x_pressed && c_pressed && v_pressed && b_pressed) {
				lay3 ++;
				if (lay3 == 5) {
					set_single_persistent_default_layer(3);
				}
			}
		}
		return true;
		break;

/*
judge killswitch

	case QK_KB_0:
        if (record->event.pressed) {
            wkeep = true;
        } else {
            wkeep = false;
        }
        break;

	case QK_KB_1:
        if (record->event.pressed) {
            akeep = true;
        } else {
			akeep = false;
        }
        break;

	case QK_KB_2:
        if (record->event.pressed) {
            skeep = true;
        } else {
            skeep = false;
        }
        break;

	case QK_KB_3:
        if (record->event.pressed) {
            dkeep = true;
        } else {
            dkeep = false;
        }
        break;
 */

/*
aka killswitch
 */

    case QK_KB_0:
        if (record->event.pressed) {
			wkeep = true;
			if (skeep) {
				unregister_code(KC_S);
			}
            register_code(KC_W);
        } else {
			wkeep = false;
//            unregister_code(KC_W);
//			if (skeep) {
//				register_code(KC_S);
//			}
        }
        break;

    case QK_KB_1:
        if (record->event.pressed) {
			akeep = true;
			if (dkeep) {
				unregister_code(KC_D);
			}
            register_code(KC_A);
        } else {
			akeep = false;
            unregister_code(KC_A);
//			if (dkeep) {
//				register_code(KC_D);
//			}
        }
        break;

    case QK_KB_2:
        if (record->event.pressed) {
			skeep = true;
			if (wkeep) {
				unregister_code(KC_W);
			}
            register_code(KC_S);
        } else {
			skeep = false;
            unregister_code(KC_S);
//			if (wkeep) {
//				register_code(KC_W);
//			}
        }
        break;

    case QK_KB_3:
        if (record->event.pressed) {
			dkeep = true;
			if (akeep) {
				unregister_code(KC_A);
			}
            register_code(KC_D);
        } else {
			dkeep = false;
            unregister_code(KC_D);
//			if (akeep) {
//				register_code(KC_A);
//			}
        }
        break;


    }
    return true;
};





const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
  KC_0, KC_1, KC_2, KC_3, KC_4, KC_5,
  KC_TAB, KC_Q, QK_KB_0, KC_E, KC_R, KC_T,
  KC_J,  QK_KB_1, QK_KB_2, QK_KB_3, KC_F, KC_G,KC_H,
  KC_LSFT, KC_Z,    KC_X, KC_C, KC_V, KC_B,
  KC_LCTL, 		    KC_ESC, KC_LALT, KC_SPC, KC_N
  ),

[1] = LAYOUT(
  KC_0, KC_1, KC_2, KC_3, KC_4, KC_5,
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
  KC_J,  KC_A, KC_S, KC_D, KC_F, KC_G,KC_H,
  KC_LSFT, KC_Z,    KC_X, KC_C, KC_V, KC_B,
  KC_LCTL, 		    KC_ESC, KC_LALT, KC_SPC, KC_N
  ),

[2] = LAYOUT(
  KC_0, KC_1, KC_2, KC_3, KC_4, KC_5,
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
  KC_J,  KC_A, KC_S, KC_D, KC_F, KC_G,KC_H,
  KC_LSFT, KC_Z,    KC_X, KC_C, KC_V, KC_B,
  KC_LCTL, 		    KC_ESC, KC_LALT, KC_SPC, KC_N
  ),

[3] = LAYOUT(
  KC_0, KC_1, KC_2, KC_3, KC_4, KC_5,
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
  KC_J,  KC_A, KC_S, KC_D, KC_F, KC_G,KC_H,
  KC_LSFT, KC_Z,    KC_X, KC_C, KC_V, KC_B,
  KC_LCTL, 		    KC_ESC, KC_LALT, KC_SPC, KC_N
  )
  
};
