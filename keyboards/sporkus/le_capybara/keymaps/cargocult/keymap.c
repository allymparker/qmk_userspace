
// Copyright 2025 cargocult
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "../../rgb.c"
#include "kc_mac.h"
#include "../../../features/swapper.h"

enum custom_keycodes {
  NUMWORD = SAFE_RANGE,
  CTL_TAB,
  GUI_TAB,
  KB_SAFE_RANGE  //use "KB_SAFE_RANGE" for keyboard specific codes
};

// Layer definitions
enum layers {
     BASE,
     NUMPAD,
     NAV,
     FKEY,
     SYM
};

#include "combos.h"


// Keymap using LAYOUT_3thumb
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     // BASE LAYER (QWERTY)
          [BASE] = LAYOUT_3thumb(
               KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MPLY,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
               MC_A,    MC_S,    MC_D,    MC_F,    KC_G,                      KC_H,    MC_J,    MC_K,    MC_L,    MC_SEMI,
               KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                               KC_TAB,  TT_NUM,  TT_NAV,                   TT_FKEY,  TT_SYM,    KC_DEL
          ),

     // NUMPAD LAYER
     [NUMPAD] = LAYOUT_3thumb(
          _______,  _______,  _______,  _______,  _______,    _______,         KC_ASTR,   KC_7,   KC_8,   KC_9,   _______,
          _______,  _______,  _______,  _______,  _______,                     KC_PLUS,   KC_4,   KC_5,   KC_6,   _______,
          _______,  _______,  _______,  _______,  _______,                     KC_MINS,   KC_1,   KC_2,   KC_3,   KC_PERC,
                              _______,  _______,  _______,                     KC_EQL,    KC_0, _______
     ),

     // NAVIGATION LAYER (vim style)
     [NAV] = LAYOUT_3thumb(
           _______,  _______,  _______,  _______,  _______,   _______,        GUI_TAB,    MC_PWD,    MC_NWD,   _______,   _______,
            MC_UND,   MC_CUT,   MC_CPY,   MC_PST,  _______,                   KC_LEFT,     KC_UP,   KC_DOWN,   KC_RGHT,   _______,
           _______,  _______,  _______,  _______,  _______,                   CTL_TAB,    MC_HME,    MC_END,   _______,   _______,
                               _______,  _______,  _______,                    MC_DWD,    MC_SPT,   _______
     ),

     // FKEY LAYER
     [FKEY] = LAYOUT_3thumb(
           _______,  KC_F9,     KC_F10,   KC_F11,   KC_F12,     _______,      _______,   _______,   _______,   _______,   _______,
           _______,  KC_F5,      KC_F6,    KC_F7,    KC_F8,                   _______,   _______,   _______,   _______,   _______,
           _______,  KC_F1,      KC_F2,    KC_F3,    KC_F4,                   _______,   _______,   _______,   _______,   _______,
                               _______,  _______,  _______,                   _______,   _______,   _______
     ),


     // SYMBOL LAYER
     [SYM] = LAYOUT_3thumb(
          KC_CIRC, KC_AMPR, KC_HASH, KC_TILD, KC_LPRN,         _______,      KC_RPRN, _______, _______, _______, _______,
          KC_GRV,  KC_PIPE, KC_EXLM, KC_QUOT, KC_LCBR,                       KC_RCBR, _______, _______, _______, _______,
          KC_BSLS, KC_AT,   KC_DLR,   MC_PND, KC_LBRC,                       KC_RBRC, _______, _______, _______, _______,
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


bool swapper_ctl_tab_active = false;
bool swapper_gui_tab_active = false;

// return false to interrupt normal processing
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &swapper_gui_tab_active, KC_LGUI, KC_TAB, GUI_TAB,
        keycode, record
    );

    update_swapper(
        &swapper_ctl_tab_active, KC_LCTL, KC_TAB, CTL_TAB,
        keycode, record
    );

    return true;
}