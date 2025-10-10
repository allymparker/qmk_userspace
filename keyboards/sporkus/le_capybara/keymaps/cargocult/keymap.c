
// Copyright 2025 cargocult
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "../../rgb.c"
#include "kc_jetbrains.h"
#include "kc_mac.h"
#include "../../../features/swapper.h"

enum custom_keycodes {
  NUMWORD = SAFE_RANGE,
  CTL_TAB,
  GUI_TAB,
  KC_MCPY,  // Custom keycode for copy (used in MC_CPY mod-tap)
  KC_MPST,  // Custom keycode for paste (used in MC_PST mod-tap)
  KB_SAFE_RANGE  //use "KB_SAFE_RANGE" for keyboard specific codes
};

// Layer definitions
enum layers {
     BASE,
     NUMPAD,
     NAV,
     FKEY,
     SYM,
     FWD,
     BCK,
     JB,
     JBR,
     JBN,
     LAYER_COUNT
};

#include "combos.h"

#define LT_NUM LT(NUMPAD, KC_ENT)
#define LT_NAV LT(NAV, KC_ESC)
#define LT_FKEY LT(FKEY, KC_BSPC)
#define LT_SYM LT(SYM, KC_SPC)

#define LT_V LT(FWD, KC_V)
#define LT_M LT(BCK, KC_M)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
          [BASE] = LAYOUT_3thumb(
               KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_MPLY,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
               MC_A,    MC_S,    MC_D,    MC_F,    KC_G,                      KC_H,    MC_J,    MC_K,    MC_L,    MC_SEMI,
               KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                               KC_TAB,  LT_NUM,  LT_NAV,                      LT_FKEY, LT_SYM,  KC_DEL
          ),

     [NUMPAD] = LAYOUT_3thumb(
          QK_BOOT,  _______,  _______,  _______,  _______,      _______,       KC_ASTR,   KC_7,   KC_8,   KC_9,   _______,
          _______,  _______,  _______,  _______,  _______,                     KC_PLUS,   KC_4,   KC_5,   KC_6,   _______,
          _______,  _______,  _______,  _______,  _______,                     KC_MINS,   KC_1,   KC_2,   KC_3,   KC_PERC,
                              _______,  _______,  _______,                     KC_EQL,    KC_0, _______
     ),

     [NAV] = LAYOUT_3thumb(
           _______,  _______,  _______,  _______,  _______,     _______,       GUI_TAB,    MC_PWD,    MC_NWD,   _______,   _______,
            MC_UND,   MC_CUT,   MC_CPY,   MC_PST,  _______,                    KC_LEFT,     KC_DOWN,   KC_UP,   KC_RGHT,   _______,
           _______,  _______,  _______,  _______,  _______,                    CTL_TAB,    MC_HME,    MC_END,   _______,   _______,
                               _______,  _______,  _______,                    MC_DWD,    MC_SPT,   _______
     ),

     [FKEY] = LAYOUT_3thumb(
           _______,  KC_F9,     KC_F10,   KC_F11,   KC_F12,     _______,      _______,   _______,   _______,   _______,   _______,
           _______,  KC_F5,      KC_F6,    KC_F7,    KC_F8,                   _______,   _______,   _______,   _______,   _______,
           _______,  KC_F1,      KC_F2,    KC_F3,    KC_F4,                   _______,   _______,   _______,   _______,   _______,
                               _______,  _______,  _______,                   _______,   _______,   _______
     ),

     [SYM] = LAYOUT_3thumb(
          KC_CIRC, KC_AMPR, KC_HASH, KC_TILD, KC_LPRN,          _______,      KC_RPRN, _______, _______, _______, _______,
          KC_GRV,  KC_PIPE, KC_EXLM, KC_QUOT, KC_LCBR,                        KC_RCBR, _______, _______, _______, _______,
          KC_BSLS, KC_AT,   KC_DLR,   MC_PND, KC_LBRC,                        KC_RBRC, _______, _______, _______, _______,
                            KC_UNDS, KC_MINS, KC_DQUO,                        _______, _______, _______
     ),
     
     [FWD] = LAYOUT_3thumb(
           _______,  _______,  _______,  _______,  _______,     _______,       _______,     JB_NU,   _______,   _______,   _______,
           _______,  _______,  _______,  _______,  _______,                    _______,   _______,   _______,   _______,   _______,
           _______,  _______,  _______,  _______,  _______,                    _______,    MC_FWD,   _______,   _______,   _______,
                               _______,  _______,  _______,                    _______,   _______,   _______
     ),

     
     [BCK] = LAYOUT_3thumb(
           _______,  _______,  _______,   JB_RR,   _______,     _______,       _______,   _______,   _______,   _______,   _______,
           _______,  _______,  _______,  _______,  _______,                    _______,   _______,   _______,   _______,   _______,
           _______,  _______,  _______,   MC_BCK,  _______,                    _______,   _______,   _______,   _______,   _______,
                               _______,  _______,  _______,                    _______,   _______,   _______
     ),

     
     [JB] = LAYOUT_3thumb(
           _______,  _______,  _______,  OSL(JBR), _______,     _______,       _______,   _______,   _______,   _______,   _______,
           _______,  _______,  _______,  _______,  _______,                    _______,   _______,   _______,   _______,   _______,
           _______,  _______,  _______,  _______,  _______,                    _______,   OSL(JBN),  _______,   _______,   _______,
                               _______,  _______,  TO(BASE),                   _______,   _______,   _______
     ),

     
     
     
     [JBR] = LAYOUT_3thumb(
           _______,  _______,  _______,    JB_RR,    JB_RT,     _______,       _______,   _______,   _______,   _______,   JB_RP,
           _______,    JB_RS,    JB_RD,    JB_RF,  _______,                    _______,   _______,   _______,   _______,   _______,
           _______,  _______,    JB_RC,    JB_RV,  _______,                      JB_RN,     JB_RM,   _______,   _______,   _______,
                               _______,  _______,  TO(BASE),                   _______,   _______,   _______
     ),

     
     
     
     [JBN] = LAYOUT_3thumb(
           _______,  _______,  _______,  _______,  _______,     _______,       _______,   _______,   _______,   _______,   _______,
           _______,  _______,  _______,  _______,  _______,                    _______,   _______,   _______,   _______,   _______,
           _______,  _______,  _______,  _______,  _______,                    _______,   _______,   _______,   _______,   _______,
                               _______,  _______,  TO(BASE),                   _______,   _______,   _______
     ),

     
     
     // // NAVIGATION LAYER (vim style)
     // [NAV] = LAYOUT_3thumb(
     //       _______,  _______,  _______,  _______,  _______,     _______,       _______,   _______,   _______,   _______,   _______,
     //       _______,  _______,  _______,  _______,  _______,                    _______,   _______,   _______,   _______,   _______,
     //       _______,  _______,  _______,  _______,  _______,                    _______,   _______,   _______,   _______,   _______,
     //                           _______,  _______,  _______,                    _______,   _______,   _______
     // ),

};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    // Default volume control for all layers
    [0 ... (LAYER_COUNT - 1)] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    // Override specific layers
    [NUMPAD] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) }
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

    switch (keycode) {
        case KC_MCPY:
            if (record->tap.count && record->event.pressed) {
                tap_code16(LGUI(KC_C)); // Send Cmd+C on tap
                return false;
            }
            break;
        case KC_MPST:
            if (record->tap.count && record->event.pressed) {
                tap_code16(LGUI(KC_V)); // Send Cmd+V on tap
                return false;
            }
            break;
    }

    return true;
}