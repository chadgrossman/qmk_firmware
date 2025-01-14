#include QMK_KEYBOARD_H

#define HOME_Z LALT_T(KC_Z)
#define HOME_X LCTL_T(KC_X)
#define HOME_C LGUI_T(KC_C)
#define HOME_V LSFT_T(KC_V)

#define HOME_M   RSFT_T(KC_M)
#define HOME_COM LGUI_T(KC_COMM)
#define HOME_DOT LCTL_T(KC_DOT)
#define HOME_EXC LALT_T(S(KC_1))

enum layers {
    DEF,  // default layer
    NAV,  // navigation layer
    FUN,  // function layer
    NUM,  // number layer
    MED   // media keys
};

enum combos {
    combo_esc,
    combo_ret,
    combo_bspc,
    combo_del,
    combo_tab,
    combo_lpar,
    combo_rpar,
    combo_copy,
    combo_cut,
    combo_paste,
    combo_lbkt,
    combo_rbkt,
    combo_at,
    combo_hash,
    combo_dllr,
    combo_prcnt,
    combo_caret,
    combo_plus,
    combo_star,
    combo_amps,
    combo_grave,
    combo_bslh,
    combo_equal,
    combo_tilde,
    combo_under,
    combo_dash,
    combo_fslh,
    combo_pip
};

uint16_t get_combo_term(uint16_t index, combo_t *combo) {

    // or with combo index, i.e. its name from enum.
    switch (index) {
        case combo_ret:
            return 10;

        case combo_tab:
            return 10;
    }

    return COMBO_TERM;
}

#ifdef COMBO_MUST_TAP_PER_COMBO
bool get_combo_must_tap(uint16_t index, combo_t *combo) {

    // or with combo index, i.e. its name from enum.
    switch (index) {
        case combo_copy:
            return true;

        case combo_cut:
            return true;

        case combo_paste:
            return true;
            
        case combo_lbkt:
            return true;
            
        case combo_rbkt:
            return true;
    }

    return false;

}
#endif

const uint16_t PROGMEM cmb_esc[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM cmb_ret[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_bspc[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM cmb_del[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_tab[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM cmb_lpar[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM cmb_rpar[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_copy[] = {HOME_X, HOME_C, COMBO_END};
const uint16_t PROGMEM cmb_cut[] = {HOME_X, HOME_V, COMBO_END};
const uint16_t PROGMEM cmb_paste[] = {HOME_C, HOME_V, COMBO_END};
const uint16_t PROGMEM cmb_lbkt[] = {HOME_M, HOME_COM, COMBO_END};
const uint16_t PROGMEM cmb_rbkt[] = {HOME_COM, HOME_DOT, COMBO_END};
const uint16_t PROGMEM cmb_at[] = {KC_W, KC_S, COMBO_END};
const uint16_t PROGMEM cmb_hash[] = {KC_E, KC_D, COMBO_END};
const uint16_t PROGMEM cmb_dllr[] = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_prcnt[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM cmb_caret[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM cmb_plus[] = {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM cmb_star[] = {KC_I, KC_K, COMBO_END};
const uint16_t PROGMEM cmb_amps[] = {KC_O, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_grave[] = {KC_S, HOME_X, COMBO_END};
const uint16_t PROGMEM cmb_bslh[] = {KC_D, HOME_C, COMBO_END};
const uint16_t PROGMEM cmb_equal[] = {KC_F, HOME_V, COMBO_END};
const uint16_t PROGMEM cmb_tilde[] = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM cmb_under[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM cmb_dash[] = {KC_J, HOME_M, COMBO_END};
const uint16_t PROGMEM cmb_fslh[] = {KC_K, HOME_COM, COMBO_END};
const uint16_t PROGMEM cmb_pip[] = {KC_L, HOME_DOT, COMBO_END};

combo_t key_combos[] = {
    [combo_esc] = COMBO(cmb_esc, KC_ESC),
    [combo_ret] = COMBO(cmb_ret, KC_ENT),
    [combo_bspc] = COMBO(cmb_bspc, KC_BSPC),
    [combo_del] = COMBO(cmb_del, KC_DEL),
    [combo_tab] = COMBO(cmb_tab, KC_TAB),
    [combo_lpar] = COMBO(cmb_lpar, S(KC_9)),
    [combo_rpar] = COMBO(cmb_rpar, S(KC_0)),
    [combo_copy] = COMBO(cmb_copy, G(KC_C)),
    [combo_cut] = COMBO(cmb_cut, G(KC_X)),
    [combo_paste] = COMBO(cmb_paste, G(KC_V)),
    [combo_lbkt] = COMBO(cmb_lbkt, KC_LBRC),
    [combo_rbkt] = COMBO(cmb_rbkt, KC_RBRC),
    [combo_at] = COMBO(cmb_at, S(KC_2)),
    [combo_hash] = COMBO(cmb_hash, S(KC_3)),
    [combo_dllr] = COMBO(cmb_dllr, S(KC_4)),
    [combo_prcnt] = COMBO(cmb_prcnt, S(KC_5)),
    [combo_caret] = COMBO(cmb_caret, S(KC_6)),
    [combo_plus] = COMBO(cmb_plus, S(KC_EQL)),
    [combo_star] = COMBO(cmb_star, S(KC_8)),
    [combo_amps] = COMBO(cmb_amps, S(KC_7)),
    [combo_grave] = COMBO(cmb_grave, KC_GRV),
    [combo_bslh] = COMBO(cmb_bslh, KC_BSLS),
    [combo_equal] = COMBO(cmb_equal, KC_EQL),
    [combo_tilde] = COMBO(cmb_tilde, S(KC_GRV)),
    [combo_under] = COMBO(cmb_under, S(KC_MINS)),
    [combo_dash] = COMBO(cmb_dash, KC_MINS),
    [combo_fslh] = COMBO(cmb_fslh, KC_SLSH),
    [combo_pip] = COMBO(cmb_pip, S(KC_SLSH))
};

const key_override_t comma_override = ko_make_basic(MOD_MASK_SHIFT, HOME_COM, KC_SCLN);
const key_override_t dot_override = ko_make_basic(MOD_MASK_SHIFT, HOME_DOT, S(KC_SCLN));

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&comma_override,
    &dot_override
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[DEF] = LAYOUT(
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_GRAVE, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                            KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                            KC_H,     KC_J,    KC_K,     KC_L,     KC_QUOT,  KC_SCLN, 
    KC_TRNS,  HOME_Z,  HOME_X,  HOME_C,  HOME_V,  KC_B,            LT(NAV, KC_SPC), KC_TRNS,       KC_N,     HOME_M,  HOME_COM, HOME_DOT, HOME_EXC, S(KC_SLSH),
                                         MO(MED), LT(FUN, KC_ENT), KC_TRNS,         OSM(MOD_LSFT), OSL(NUM), MO(MED)
),

[NAV] = LAYOUT(
    KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,
    KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,       G(KC_TAB),     KC_TRNS,                   G(KC_Z), G(KC_V), G(KC_C), G(KC_X), S(G(KC_Z)), KC_TRNS,
    KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PENT,    KC_TRNS,
    KC_TRNS, OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LGUI), OSM(MOD_LSFT), KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,     KC_TRNS,
                                                          KC_TRNS,       KC_TRNS, KC_TRNS, CW_TOGG, KC_BSPC, KC_DEL
),
[FUN] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                   KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                   C(KC_LEFT), C(KC_DOWN), C(KC_UP), C(KC_RGHT), KC_TRNS, KC_TRNS,
    KC_TRNS, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS
),
[NUM] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_GRV,  KC_LBRC, KC_P7,   KC_P8,   KC_P9,   KC_RBRC,                   KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS, KC_SCLN, KC_P4,   KC_P5,   KC_P6,   KC_EQL,                    KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS, KC_MINS, KC_P1,   KC_P2,   KC_P3,   KC_SLSH, KC_TRNS, KC_TRNS, KC_TRNS, OSM(MOD_RSFT), OSM(MOD_LGUI), OSM(MOD_LCTL), OSM(MOD_LALT), KC_TRNS,
                                        KC_DOT,  KC_P0,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[MED] = LAYOUT(
    QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_MUTE, KC_TRNS
),
};
