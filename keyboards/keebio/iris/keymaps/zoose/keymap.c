#include QMK_KEYBOARD_H

#define ___ KC_TRNS
#define xxx KC_NO

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

// Mac spaces keys
#define D_PREV C(KC_LEFT)

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
enum td_keycodes {
    smrtsft,
    d_app,
    d_show,
    d_next,
    termnl,
};

// Tap Dance types
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_SINGLE_TAP
} td_state_t;

static td_state_t td_state;
td_state_t cur_dance(tap_dance_state_t *state);

void smrtsft_finished(tap_dance_state_t *state, void *user_data);
void smrtsft_reset(tap_dance_state_t *state, void *user_data);
void d_app_finished(tap_dance_state_t *state, void *user_data);
void d_app_reset(tap_dance_state_t *state, void *user_data);
void d_show_finished(tap_dance_state_t *state, void *user_data);
void d_show_reset(tap_dance_state_t *state, void *user_data);
void d_next_finished(tap_dance_state_t *state, void *user_data);
void d_next_reset(tap_dance_state_t *state, void *user_data);
void termnl_finished(tap_dance_state_t *state, void *user_data);
void termnl_reset(tap_dance_state_t *state, void *user_data);

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [smrtsft] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, smrtsft_finished, smrtsft_reset),
    [d_app] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, d_app_finished, d_app_reset),
    [d_show] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, d_show_finished, d_show_reset),
    [d_next] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, d_next_finished, d_next_reset),
    [termnl] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, termnl_finished, termnl_reset),
};

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}

void smrtsft_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            set_oneshot_mods(MOD_BIT(KC_LSFT));
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LSFT));
            break;
        case TD_DOUBLE_SINGLE_TAP:
            caps_word_on();
            break;
        default:
            break;
    }
}

void smrtsft_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LSFT));
            break;
        case TD_DOUBLE_SINGLE_TAP:
            break;
        default:
            break;
    }
}

void d_app_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(C(KC_DOWN));
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LSFT));
            break;
        default:
            break;
    }
}

void d_app_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(C(KC_DOWN));
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LSFT));
            break;
        default:
            break;
    }
}

void d_show_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(C(KC_UP));
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LGUI));
            break;
        default:
            break;
    }
}

void d_show_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(C(KC_UP));
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LGUI));
            break;
        default:
            break;
    }
}

void d_next_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(C(KC_RGHT));
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LCTL));
            break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code16(C(KC_RGHT));
            register_code16(C(KC_RGHT));
            break;
        default:
            break;
    }
}

void d_next_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(C(KC_RGHT));
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LCTL));
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code16(C(KC_RGHT));
            break;
        default:
            break;
    }
}

void termnl_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(C(KC_GRV));
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LALT));
            break;
        default:
            break;
    }
}

void termnl_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(C(KC_GRV));
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LALT));
            break;
        default:
            break;
    }
}

// Horizontal Combos
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

// Vertical Combos
const uint16_t PROGMEM at[] = {KC_W, CTL_S, COMBO_END};
const uint16_t PROGMEM hash[] = {KC_E, GUI_D, COMBO_END};
const uint16_t PROGMEM dlr[] = {KC_R, SFT_F, COMBO_END};
const uint16_t PROGMEM perc[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM grv[] = {CTL_S, KC_X, COMBO_END};
const uint16_t PROGMEM bsls[] = {GUI_D, KC_C, COMBO_END};
const uint16_t PROGMEM eqp[] = {SFT_F, KC_V, COMBO_END};
const uint16_t PROGMEM tild[] = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM circ[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM plus[] = {KC_U, SFT_J, COMBO_END};
const uint16_t PROGMEM astr[] = {KC_I, GUI_K, COMBO_END};
const uint16_t PROGMEM ampr[] = {KC_O, CTL_L, COMBO_END};
const uint16_t PROGMEM unds[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM mins[] = {SFT_J, KC_M, COMBO_END};
const uint16_t PROGMEM slsh[] = {GUI_K, KC_COMM, COMBO_END};
const uint16_t PROGMEM pipe[] = {CTL_L, KC_DOT, COMBO_END};

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
    COMBO(at, KC_AT),
    COMBO(hash, KC_HASH),
    COMBO(dlr, KC_DLR),
    COMBO(perc, KC_PERC),
    COMBO(grv, KC_GRV),
    COMBO(bsls, KC_BSLS),
    COMBO(eqp, KC_EQL),
    COMBO(tild, KC_TILD),
    COMBO(circ, KC_CIRC),
    COMBO(plus, KC_PLUS),
    COMBO(astr, KC_ASTR),
    COMBO(ampr, KC_AMPR),
    COMBO(unds, KC_UNDS),
    COMBO(mins, KC_MINS),
    COMBO(slsh, KC_SLSH),
    COMBO(pipe, KC_PIPE),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWR] = LAYOUT(
        KC_GRV,  KC_1,  KC_2,  KC_3,  KC_4,    KC_5,                          KC_6,    KC_7,   KC_8,    KC_9,   KC_0,     KC_MINS,
        KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,    KC_T,                          KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,     KC_BSLS,
        KC_ESC,  ALT_A, CTL_S, GUI_D, SFT_F,   KC_G,                          KC_H,    SFT_J,  GUI_K,   CTL_L,  ALT_QUOT, KC_SCLN,
        KC_LSFT, KC_Z,  KC_X,  KC_C,  KC_V,    KC_B,    NAV_SPC, KC_MEH,      KC_N,    KC_M,   KC_COMM, KC_DOT, KC_EXLM,  KC_SLSH,
                                      KC_LGUI, FUN_ENT, xxx,     TD(smrtsft), NUM_BSP, KC_RALT
    ),
    [NAV] = LAYOUT(
        ___, ___,     ___,     ___,     ___,     ___,            ___,     ___,     ___,     ___,     ___,     ___,
        ___, G(KC_Q), ___,     ___,     ___,     ___,            ___,     MSK_BSP, KC_TAB,  MSK_DEL, ___,     ___,
        ___, OS_LALT, OS_LCTL, OS_LGUI, OS_LSFT, ___,            MSK_HME, MSK_BTM, MSK_TOP, MSK_END, KC_PENT, ___,
        ___, ___,     ___,     ___,     ___,     ___,  ___, ___, KC_INS,  KC_PGDN, KC_PGUP, ___,     ___,     ___,
                                        ___,     ___,  xxx, ___, ___, ___
    ),
    [FUN] = LAYOUT(
        ___, ___,     ___,    ___,    ___,    ___,                ___,     ___,       ___,        ___,        ___,        ___,
        ___, KC_F12,  KC_F7,  KC_F8,  KC_F9,  ___,                ___,     KC_MPRV,   KC_MNXT,    ___,        ___,        ___,
        ___, ALT_F11, CTL_F4, GUI_F5, SFT_F6, ___,                D_PREV,  TD(d_app), TD(d_show), TD(d_next), TD(termnl), ___,
        ___, KC_F10,  KC_F1,  KC_F2,  KC_F3,  ___,  ___, ___,     ___,     KC_VOLD,   KC_VOLU,    ___,        ___,        ___,
                                      ___,    ___,  xxx, KC_MPLY, KC_MUTE, ___
    ),
    [NUM] = LAYOUT(
        ___, ___,   ___,   ___,   ___,   ___,            ___, ___,     ___,     ___,     ___,     ___,
        ___, ___,   KC_7,  KC_8,  KC_9,  ___,            ___, ___,     ___,     ___,     ___,     ___,
        ___, ALT_0, CTL_4, GUI_5, SFT_6, ___,            ___, OS_LSFT, OS_LGUI, OS_LCTL, OS_LALT, ___,
        ___, ___,   KC_1,  KC_2,  KC_3,  ___,  ___, ___, ___, ___,     ___,     ___,     ___,     ___,
                                  ___,   ___,  xxx, ___, ___, ___
    ),
    [SYS] = LAYOUT(
        ___, ___, ___, ___, ___, ___,            ___,     ___, ___, ___, ___, ___,
        ___, ___, ___, ___, ___, ___,            ___,     ___, ___, ___, ___, ___,
        ___, ___, ___, ___, ___, QK_BOOT,        QK_BOOT, ___, ___, ___, ___, ___,
        ___, ___, ___, ___, ___, ___,  ___, ___, ___,     ___, ___, ___, ___, ___,
                            ___, ___,  xxx, ___, ___,     ___
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

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, FUN, NUM, SYS);
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