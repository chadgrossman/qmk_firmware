// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define QWR 0
#define HHK 1
#define NAV 2
#define FUN 3
#define SYS 4

#define D_PREV C(KC_LEFT)
#define D_APP  C(KC_DOWN)
#define D_SHOW C(KC_UP)
#define D_NEXT C(KC_RGHT)

#define MSK_HME LT(QWR, KC_LEFT) // Tap: left  | Long-tap: start of line.
#define MSK_BTM LT(QWR, KC_DOWN) // Tap: down  | Long-tap: end   of doc.
#define MSK_TOP LT(QWR, KC_UP)   // Tap: up    | Long-tap: start of doc.
#define MSK_END LT(QWR, KC_RGHT) // Tap: right | Long-tap: end   of line.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ \ │Del│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ <-- │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │ CEsc │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
     * │  Shft  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shft │ 1 │
     * ├─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─┴───┤
     * │ Ctl │Alt│ Gui │                           │ Gui │ 2 │ Ctl │
     * └─────┴───┴─────┴───────────────────────────┴─────┴───┴─────┘
     */
    [QWR] = LAYOUT_60_ansi_tsangan_split_bs_rshift(
        KC_GRV,          KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,   KC_0,           KC_MINS,          KC_EQL,  KC_BSLS, KC_DEL,
        KC_TAB,          KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,           KC_LBRC,          KC_RBRC, KC_BSPC,
        LT(FUN, KC_ESC), KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,        KC_QUOT,          KC_ENT,
        KC_LSFT,         KC_Z,    KC_X,    KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,        RSFT_T(KC_UP),    MO(HHK),
        KC_LCTL,         KC_LALT, KC_LGUI,                   LT(NAV, KC_SPC),             GUI_T(KC_LEFT), LT(FUN, KC_DOWN), CTL_T(KC_RGHT)
    ),
    [HHK] = LAYOUT_60_ansi_tsangan_split_bs_rshift(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PAUS, KC_SCRL, KC_PSCR, KC_UP,   KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_PENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [NAV] = LAYOUT_60_ansi_tsangan_split_bs_rshift(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, A(KC_BSPC),
        KC_TRNS, KC_TRNS, D_PREV,  D_SHOW,  D_NEXT,  KC_TRNS, MSK_HME, MSK_BTM, MSK_TOP, MSK_END, KC_TRNS, KC_TRNS, KC_PENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [FUN] = LAYOUT_60_ansi_tsangan_split_bs_rshift(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,  KC_DEL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_LCBR, KC_TRNS, KC_TRNS, KC_RCBR, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_LPRN, KC_TRNS, KC_TRNS, KC_TRNS, KC_RPRN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [SYS] = LAYOUT_60_ansi_tsangan_split_bs_rshift(
        QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS
    ),

};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFT_T(KC_UP):
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFT_T(KC_UP):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, HHK, FUN, SYS);
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(QWR, KC_LEFT):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(G(KC_LEFT)); // Intercept hold function to send GUI-Left
        return false;
      }
      return true;              // Return true for normal processing of tap keycode
    case LT(QWR, KC_DOWN):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(G(KC_DOWN)); // Intercept hold function to send GUI-Down
        return false;
      }
      return true;              // Return true for normal processing of tap keycode
    case LT(QWR, KC_UP):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(G(KC_UP));   // Intercept hold function to send GUI-Up
        return false;
      }
      return true;              // Return true for normal processing of tap keycode
    case LT(QWR, KC_RGHT):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(G(KC_RGHT)); // Intercept hold function to send GUI-Right
        return false;
      }
      return true;              // Return true for normal processing of tap keycode
    }
    return true;
}