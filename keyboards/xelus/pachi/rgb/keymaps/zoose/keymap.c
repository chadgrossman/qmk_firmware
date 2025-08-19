/* Copyright 2021 Harrison Chan (Xelus)
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

#define QWR 0
#define COL 1
#define NAV 2
#define FUN 3
#define SYS 4

#define D_PREV C(KC_LEFT)
#define D_APP  C(KC_DOWN)
#define D_SHOW C(KC_UP)
#define D_NEXT C(KC_RGHT)

#define MSK_HME LT(0, KC_LEFT) // Tap: left  | Long-tap: start of line.
#define MSK_BTM LT(0, KC_DOWN) // Tap: down  | Long-tap: end   of doc.
#define MSK_TOP LT(0, KC_UP)   // Tap: up    | Long-tap: start of doc.
#define MSK_END LT(0, KC_RGHT) // Tap: right | Long-tap: end   of line.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [QWR] = LAYOUT_tkl_ansi_tsangan(
        KC_ESC,                   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  /**/ KC_PSCR, KC_SCRL, KC_PAUS,
        KC_GRV,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, /**/ KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, /**/ KC_DEL,  KC_END,  KC_PGDN,
        LT(FUN, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,          /**/          KC_UP,
        KC_LCTL,         KC_LALT, KC_LGUI,                   LT(NAV, KC_SPC),                             KC_RGUI,          KC_RALT, KC_RCTL, /**/ KC_LEFT, KC_DOWN, KC_RGHT
      ),

      [COL] = LAYOUT_tkl_ansi_tsangan(
        KC_ESC,                   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  /**/ KC_PSCR, KC_SCRL, KC_PAUS,
        KC_GRV,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, /**/ KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,          KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSPC, /**/ KC_DEL,  KC_END,  KC_PGDN,
        LT(FUN, KC_ESC), KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,          KC_ENT,
        KC_LSFT,         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,          /**/          KC_UP,
        KC_LCTL,         KC_LALT, KC_LGUI,                   LT(NAV, KC_SPC),                             KC_RGUI,          KC_RALT, KC_RCTL, /**/ KC_LEFT, KC_DOWN, KC_RGHT
      ),

      [NAV] = LAYOUT_tkl_ansi_tsangan(
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    /**/ KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,    /**/ KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_LPRN, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_RPRN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, A(KC_BSPC), /**/ KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, D_PREV,  D_SHOW,  D_NEXT,  KC_TRNS, MSK_HME, MSK_BTM, MSK_TOP, MSK_END, KC_TRNS, KC_TRNS,          KC_PENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,             /**/          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                                     KC_TRNS,          KC_TRNS, KC_TRNS,    /**/ KC_TRNS, KC_TRNS, KC_TRNS
      ),
      
      [FUN] = LAYOUT_tkl_ansi_tsangan(
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,  /**/ KC_MPLY, KC_MUTE, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          /**/          KC_VOLU,
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                                     KC_TRNS,          KC_TRNS, KC_TRNS, /**/ KC_MPRV, KC_VOLD, KC_MNXT
      ),

      [SYS] = LAYOUT_tkl_ansi_tsangan(
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    /**/ KC_TRNS, KC_TRNS, QK_BOOT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    /**/ RM_TOGG, RM_HUEU, RM_SATU,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, G(KC_BSPC), /**/ RM_NEXT, RM_HUED, RM_SATD,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, D_PREV,  D_APP,   D_SHOW,  D_NEXT,  KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,             /**/          RM_VALU,
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                                     KC_TRNS,          KC_TRNS, KC_TRNS,    /**/ RM_PREV, RM_VALD, RM_NEXT
      )

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, NAV, FUN, SYS);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(0, KC_LEFT):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(G(KC_LEFT)); // Intercept hold function to send GUI-Left
        return false;
      }
      return true;              // Return true for normal processing of tap keycode
    case LT(0, KC_DOWN):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(G(KC_DOWN)); // Intercept hold function to send GUI-Down
        return false;
      }
      return true;              // Return true for normal processing of tap keycode
    case LT(0, KC_UP):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(G(KC_UP));   // Intercept hold function to send GUI-Up
        return false;
      }
      return true;              // Return true for normal processing of tap keycode
    case LT(0, KC_RGHT):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(G(KC_RGHT)); // Intercept hold function to send GUI-Right
        return false;
      }
      return true;              // Return true for normal processing of tap keycode
    }
    return true;
}