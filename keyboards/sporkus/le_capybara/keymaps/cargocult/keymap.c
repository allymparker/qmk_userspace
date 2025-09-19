
// Copyright 2025 cargocult
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layer definitions
enum layers {
     BASE,
     NUMPAD,
     NAV,
     FKEY,
     SYM
};

// Thumb key definitions
#define TT_NUM LT(NUMPAD, KC_ENT)
#define TT_NAV LT(NAV, KC_ESC)
#define TT_FKEY LT(FKEY, KC_BSPC)
#define TT_SYM LT(SYM, KC_SPC)

// Keymap using LAYOUT_3thumb
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     // BASE LAYER (QWERTY)
          [BASE] = LAYOUT_3thumb(
               KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MPLY,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
               KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
               KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                               KC_TAB,  TT_NUM,  TT_NAV,                   TT_FKEY,  TT_SYM,    KC_DEL
          ),

     // NUMPAD LAYER
     [NUMPAD] = LAYOUT_3thumb(
          _______,  _______,  _______,  _______,  _______,    KC_MPLY,         KC_ASTR,   KC_7,   KC_8,   KC_9,   _______,
          _______,  _______,  _______,  _______,  _______,                     KC_PLUS,   KC_4,   KC_5,   KC_6,   _______,
          _______,  _______,  _______,  _______,  _______,                     KC_MINS,   KC_1,   KC_2,   KC_3,   KC_PERC,
                              _______,  _______,  _______,                     KC_EQL,    KC_0, _______
     ),

     // NAVIGATION LAYER (vim style)
     [NAV] = LAYOUT_3thumb(
           _______,  _______,  _______,  _______,  _______,   KC_MPLY,        _______,   _______,   _______,   _______,   _______,
           _______,  _______,  _______,  _______,  _______,                   KC_LEFT,     KC_UP,   KC_DOWN,   KC_RGHT,   _______,
           _______,  _______,  _______,  _______,  _______,                   _______,   _______,   _______,   _______,   _______,
                               _______,  _______,  _______,                   _______,   _______,   _______
     ),

     // FKEY LAYER
     [FKEY] = LAYOUT_3thumb(
           _______,  KC_F9,     KC_F10,   KC_F11,   KC_F12,     ______,       _______,   _______,   _______,   _______,
           _______,  KC_F5,      KC_F6,    KC_F7,    KC_F8,                   _______,   _______,   _______,   _______,   _______,
           _______,  KC_F1,      KC_F2,    KC_F3,    KC_F4,                   _______,   _______,   _______,   _______,   _______,
                               _______,  _______,  _______,                   _______,   _______,   _______
     ),


     // SYMBOL LAYER
     [SYM] = LAYOUT_3thumb(
          KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,         KC_MPLY,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
          KC_UNDS, KC_PLUS, KC_MINS, KC_EQL,  KC_GRV,                    KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_PIPE,
          KC_LT,   KC_GT,   KC_SCLN, KC_COLN, KC_QUES,                   KC_TILD, KC_BSLS, KC_SLSH, KC_DQUO, KC_QUOT,
                              _______, _______, _______,                     _______, _______, _______
     ),
     
     // // NAVIGATION LAYER (vim style)
     // [NAV] = LAYOUT_3thumb(
     //       _______,  _______,  _______,  _______,  _______,    _______,       _______,   _______,   _______,   _______,   _______,
     //       _______,  _______,  _______,  _______,  _______,                   _______,   _______,   _______,   _______,   _______,
     //       _______,  _______,  _______,  _______,  _______,                   _______,   _______,   _______,   _______,   _______,
     //                           _______,  _______,  _______,                   _______,   _______,   _______
     // ),

};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
     [BASE]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
     [NUMPAD] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
     [NAV]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
     [FKEY]   = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
     [SYM]    = { ENCODER_CCW_CW(KC_MPLY, KC_MUTE) }
};
#endif
