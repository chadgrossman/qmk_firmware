/* Copyright 2021 miruberegarden
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _DEF,
	_NAV,
    _FUN,
	_MED,
	_SYS,
	_BLN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_DEF] = LAYOUT(
	KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS,
	KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
	CTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_DEL,
	OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP), MO(_FUN),
	KC_LCTL, KC_LALT, KC_LGUI, LT(_NAV, KC_SPC), GUI_T(KC_LEFT), LT(_MED, KC_DOWN), CTL_T(KC_RGHT)
    ),
	[_NAV] = LAYOUT(
	_______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13,
	_______, _______, _______, _______, _______, _______, G(KC_Z), G(KC_V), G(KC_C), G(KC_X), G(S(KC_Z)), _______, _______, _______,
	_______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS, _______, _______,
	_______, _______, _______, _______, _______, _______, _______
    ),
    [_FUN] = LAYOUT(
	KC_TILDE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS,
	KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_UP, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_PENT, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, KC_END, KC_PGDN, KC_DOWN, _______, _______,
	_______, _______, _______, _______, _______, MO(_SYS), _______
    ),
	[_MED] = LAYOUT(
	_______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13,
	_______, KC_MPRV, KC_MNXT, KC_MPLY, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(_SYS),
	_______, _______, _______, _______, _______, _______, _______
    ),
	[_SYS] = LAYOUT(
	QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	EC_NORM, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, CG_TOGG, AG_TOGG, _______, _______, _______, _______
    ),
	[_BLN] = LAYOUT(
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______
    )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_T(KC_LEFT):
		case LT(_MED, KC_DOWN):
		case CTL_T(KC_RGHT):
		case RSFT_T(KC_UP):
			return TAPPING_TERM - 50;
        default:
            return TAPPING_TERM;
    }
}


bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_T(KC_LEFT):
		case LT(_MED, KC_DOWN):
		case CTL_T(KC_RGHT):
		case RSFT_T(KC_UP):
            return true;
        default:
            return false;
    }
}