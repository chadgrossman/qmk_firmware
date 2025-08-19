#include QMK_KEYBOARD_H

#define QWR 0
#define NAV 1
#define FUN 2
#define NUM 3
#define SYS 4

// Left-hand home row mods
#define ALT_A LALT_T(KC_A)
#define CTL_S LCTL_T(KC_S)
#define GUI_D LGUI_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define GUI_K RGUI_T(KC_K)
#define CTL_L LCTL_T(KC_L)
#define ALT_QUOT RALT_T(KC_QUOT)

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
#define NUM_BSP LT(NUM, KC_BSPC)

const key_override_t com_scl = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
const key_override_t dot_col = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);
const key_override_t excl_q = ko_make_basic(MOD_MASK_SHIFT, KC_EXLM, KC_QUES);
const key_override_t lprn_lt = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_LT);
const key_override_t rprn_gt = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_GT);

// Key Override declarations
const key_override_t *key_overrides[] = {
    &com_scl,
    &dot_col,
    &excl_q,
    &lprn_lt,
    &rprn_gt,
};

// Tap Dance declarations
enum {
    smrtsft,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [smrtsft] = ACTION_TAP_DANCE_DOUBLE(OS_LSFT, CW_TOGG),
};

const uint16_t PROGMEM esc[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM tab[] = {CTL_S, GUI_D, COMBO_END};
const uint16_t PROGMEM cut[] = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM copy[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM bspc[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM del[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM lprn[] = {SFT_J, GUI_K, COMBO_END};
const uint16_t PROGMEM rprn[] = {GUI_K, CTL_L, COMBO_END};
const uint16_t PROGMEM lbrc[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM rbrc[] = {KC_COMM, KC_DOT, COMBO_END};

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
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWR] = LAYOUT(
        QK_GESC, KC_1,  KC_2,  KC_3,  KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,   KC_0,     KC_BSPC,
        KC_TAB , KC_Q,  KC_W,  KC_E,  KC_R,    KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,     KC_BSLS,
        KC_LCTL, ALT_A, CTL_S, GUI_D, SFT_F,   KC_G,                      KC_H,    SFT_J,  GUI_K,   CTL_L,  ALT_QUOT, KC_QUOT,
        KC_LSFT, KC_Z,  KC_X,  KC_C,  KC_V,    KC_B,    NAV_SPC, KC_MEH,  KC_N,    KC_M,   KC_COMM, KC_DOT, KC_EXLM,  KC_SLSH,
                                      KC_LGUI, FUN_ENT, KC_TRNS, OS_LSFT, NUM_BSP, KC_RALT
    )
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
    case LT(0, KC_BSPC):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(A(KC_BSPC)); // Intercept hold function to send Alt-Backspace
        return false;
      }
      return true;              // Return true for normal processing of tap keycode
    case LT(0, KC_DEL):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(A(KC_DEL));  // Intercept hold function to send Alt-Delete
        return false;
      }
      return true;              // Return true for normal processing of tap keycode
  }
  return true;
}

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L', '*', '*', 'R', 'R', 'R', 'R', 'R', 'R', 
                            '*', '*', '*', '*', '*', '*'
    );