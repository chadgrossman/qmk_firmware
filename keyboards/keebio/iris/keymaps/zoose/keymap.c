#include QMK_KEYBOARD_H

#define ___ KC_TRNS
#define xxx KC_NO

#define QWR 0
#define NAV 1
#define FUN 2
#define NUM 3
#define SYM 4
#define SYS 5

// Left-hand home row mods
#define ALT_L LALT_T(KC_A)
#define CTL_L LCTL_T(KC_S)
#define GUI_L LGUI_T(KC_D)
#define SFT_L LSFT_T(KC_F)

// Left-hand function home row mods
#define ALT_F11 LALT_T(KC_F11)
#define CTL_F4 LCTL_T(KC_F4)
#define GUI_F5 LGUI_T(KC_F5)
#define SFT_F6 LSFT_T(KC_F6)

// Left-hand number home row mods
#define ALT_0 LALT_T(KC_0)
#define CTL_4 LCTL_T(KC_4)
#define GUI_5 LGUI_T(KC_5)
#define SFT_6 LSFT_T(KC_6)

// Right-hand home row mods
#define SFT_R RSFT_T(KC_J)
#define GUI_R RGUI_T(KC_K)
#define CTL_R LCTL_T(KC_L)
#define ALT_R RALT_T(KC_SCLN)

// Navigation tap-holds
#define MSK_HME LT(0, KC_LEFT) // Tap: left  | Long-tap: start of line.
#define MSK_BTM LT(0, KC_DOWN) // Tap: down  | Long-tap: end   of doc.
#define MSK_TOP LT(0, KC_UP)   // Tap: up    | Long-tap: start of doc.
#define MSK_END LT(0, KC_RGHT) // Tap: right | Long-tap: end   of line.
#define MSK_BSP LT(0, KC_BSPC) // Tap: bspc  | Long-tap: backspace word.
#define MSK_DEL LT(0, KC_DEL)  // Tap: del   | Long-tap: delete    word.

// Layer-tap keys
#define NAV_SPC LT(NAV, KC_SPC)
#define FUN_ENT LT(FUN, KC_ENT)
#define SYM_BSP LT(SYM, KC_BSPC)
#define NUM_TAB LT(NUM, KC_TAB)

// Mod-tap keys
#define MEH_DEL MEH_T(KC_DEL)

// Mac spaces keys
#define D_PREV C(KC_LEFT)
#define D_APP  C(KC_DOWN)
#define D_SHOW C(KC_UP)
#define D_NEXT C(KC_RGHT)

// const key_override_t com_scl = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
// const key_override_t dot_col = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);
const key_override_t excl_q = ko_make_basic(MOD_MASK_SHIFT, KC_EXLM, KC_QUES);
const key_override_t lprn_lt = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_LT);
const key_override_t rprn_gt = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_GT);

// Key Override declarations
const key_override_t *key_overrides[] = {
    // &com_scl,
    // &dot_col,
    &excl_q,
    &lprn_lt,
    &rprn_gt,
};

// Horizontal Combos
const uint16_t PROGMEM esc[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM tab[] = {CTL_L, GUI_L, COMBO_END};
const uint16_t PROGMEM cut[] = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM copy[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM bspc[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM del[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM lprn[] = {SFT_R, GUI_R, COMBO_END};
const uint16_t PROGMEM rprn[] = {GUI_R, CTL_R, COMBO_END};
const uint16_t PROGMEM lbrc[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM rbrc[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM lcbr[] = {KC_PGDN, KC_PGUP, COMBO_END};

combo_t key_combos[] = {
    COMBO(esc, KC_ESC),
    COMBO(tab, KC_TAB),
    COMBO(cut, G(KC_X)),
    COMBO(copy, G(KC_C)),
    COMBO(paste, G(KC_V)),
    COMBO(bspc, KC_BSPC),
    COMBO(del, KC_DEL),
    COMBO(lprn, KC_LPRN),
    COMBO(rprn, KC_RPRN),
    COMBO(lbrc, KC_LBRC),
    COMBO(rbrc, KC_RBRC),
    COMBO(lcbr, KC_LCBR),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWR] = LAYOUT(
        KC_GRV,  KC_1,  KC_2,  KC_3,  KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS,
        KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,    KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,    KC_MINS,
        KC_ESC,  ALT_L, CTL_L, GUI_L, SFT_L,   KC_G,                      KC_H,    SFT_R,  GUI_R,   CTL_R,  ALT_R,   KC_QUOT,
        KC_LSFT, KC_Z,  KC_X,  KC_C,  KC_V,    KC_B,    NAV_SPC, KC_MEH,  KC_N,    KC_M,   KC_COMM, KC_DOT, KC_EXLM, KC_SLSH,
                                      NUM_TAB, FUN_ENT, xxx,     OS_LSFT, SYM_BSP, MEH_DEL
    ),
    [NAV] = LAYOUT(
        ___, ___,     ___,     ___,     ___,     ___,            ___,     ___,     ___,     ___,     ___,     ___,
        ___, ___,     ___,     ___,     ___,     ___,            ___,     MSK_BSP, KC_TAB,  MSK_DEL, ___,     ___,
        ___, OS_LALT, OS_LCTL, OS_LGUI, OS_LSFT, ___,            MSK_HME, MSK_BTM, MSK_TOP, MSK_END, KC_PENT, ___,
        ___, ___,     ___,     ___,     ___,     ___,  ___, ___, KC_INS,  KC_PGDN, KC_PGUP, ___,     ___,     ___,
                                        ___,     ___,  xxx, ___, ___,     ___
    ),
    [FUN] = LAYOUT(
        ___, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  ___,
        ___, ___,     ___,     ___,     ___,     ___,            KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR,  ___,     KC_F11,
        ___, OS_LALT, OS_LCTL, OS_LGUI, OS_LSFT, ___,            KC_HASH, KC_LPRN, KC_RPRN, KC_SCLN, KC_DQUO, KC_F12,
        ___, ___,     ___,     ___,     ___,     ___,  ___, ___, KC_AT,   KC_COLN, KC_COMM, KC_DOT,  KC_QUOT, ___,
                                        ___,     ___,  xxx, ___, ___,     ___
    ),
    [SYM] = LAYOUT(
        ___, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,             KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  ___,
        ___, KC_GRV,  KC_LT,   KC_GT,   KC_MINS, KC_PIPE,           ___,   ___,     ___,     ___,     ___,     KC_F11,
        ___, KC_EXLM, KC_ASTR, KC_SLSH, KC_EQL,  KC_AMPR,           ___,   OS_LSFT, OS_LGUI, OS_LCTL, OS_LALT, KC_F12,
        ___, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC, ___, ___, ___,   ___,     ___,     ___,     ___,     ___,
                                        ___,     ___,     xxx, ___, ___,   ___
    ),
    [NUM] = LAYOUT(
        ___, ___,     ___,     ___,     ___,     ___,           ___,     ___,   ___,  ___,  ___,     ___,
        ___, ___,     ___,     ___,     ___,     ___,           KC_PLUS, KC_7,  KC_8, KC_9, ___,     ___,
        ___, OS_LALT, OS_LCTL, OS_LGUI, OS_LSFT, ___,           KC_MINS, KC_4,  KC_5, KC_6, KC_ASTR, ___,
        ___, ___,     ___,     ___,     ___,     ___, ___, ___, KC_EQL,  KC_1,  KC_2, KC_3, KC_SLSH, ___,
                                        ___,     ___, xxx, ___, KC_0,    KC_DOT
    ),
    [SYS] = LAYOUT(
        QK_BOOT, ___, ___, ___, ___, ___,            ___,    ___,     ___,     ___,     ___, ___,
        ___,     ___, ___, ___, ___, ___,            ___,    KC_MPRV, KC_MNXT, KC_MPLY, ___, ___,
        ___,     ___, ___, ___, ___, ___,            D_PREV, D_APP,   D_SHOW,  D_NEXT,  ___, ___,
        ___,     ___, ___, ___, ___, ___,  ___, ___, ___,    KC_VOLD, KC_VOLU, KC_MUTE, ___, ___,
                                ___, ___,  xxx, ___, ___,    ___
    ),
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MSK_HME:
        case MSK_BTM:
        case MSK_TOP:
        case MSK_END:
        case MSK_BSP:
        case MSK_DEL:
            // Do not select the hold action when another key is tapped.
            return false;
        default:
            // Immediately select the hold action when another key is tapped.
            return true;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(0, KC_LEFT):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(G(KC_LEFT)); // Incept hold function to send GUI-Left
        return false;
      }
      return true;
    case LT(0, KC_DOWN):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(G(KC_DOWN)); // Intercept hold function to send GUI-Down
        return false;
      }
      return true;
    case LT(0, KC_UP):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(G(KC_UP));   // Intercept hold function to send GUI-Up
        return false;
      }
      return true;
    case LT(0, KC_RGHT):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(G(KC_RGHT)); // Intercept hold function to send GUI-Right
        return false;
      }
      return true;
    case LT(0, KC_BSPC):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(A(KC_BSPC)); // Intercept hold function to send Alt-Backspace
        return false;
      }
      return true;
    case LT(0, KC_DEL):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(A(KC_DEL));  // Intercept hold function to send Alt-Delete
        return false;
      }
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, FUN, SYM, SYS);
  return state;
}

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L', '*', '*', 'R', 'R', 'R', 'R', 'R', 'R', 
                            '*', '*', '*', '*', '*', '*'
    );