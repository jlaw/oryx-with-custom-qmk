// Copyright 2024 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file keymap.c
 * @brief Pascal's keymap for the ZSA Voyager.
 *
 * This file defines what keycode is performed by each key position. See also
 * getreuer.c for definitions of macros, etc. used in my keymap.
 */

#include QMK_KEYBOARD_H

#include "voyager.h"
#include "layout.h"
#include "getreuer_qwerty_jis.c"

#include "version.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_LR(  // Base layer: QWERTY.
    _______, _______, _______, KC_LEFT, KC_RGHT, _______,
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,
    LCTL_BS, LGUI_A , LALT_S , LSFT_D , LCTL_F , NUM_G  ,
    WIN_BSL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,
                                                 KC_UNDS, SYM_SPC,

                      _______, KC_DOWN, KC_UP  , KC_MINS, KC_CIRC, KC_MPLY,
                      KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_AT  ,
                      KC_H   , RCTL_J , RSFT_K , RALT_L , RGUI_SC, KC_COLN,
                      KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,
             QK_REP , NAV_ESC
  ),

  [SYM] = LAYOUT_LR(  // Symbol layer
    _______, _______, _______, _______, _______, _______,
    TMUXESC, MO(FUN), KC_DQUO, _______, _______, _______,
    KC_DEL , KC_EXLM, KC_HASH, KC_DLR , KC_PERC, KC_AMPR,
    G(KC_A), G(KC_Z), G(KC_X), G(KC_C), G(KC_V), SELLINE,
                                                 _______, _______,

                      _______, _______, _______, _______, _______, KC_MUTE,
                      _______, KC_QUOT, KC_LBRC, KC_RBRC, SRCHSEL, _______,
                      _______, _______, KC_LPRN, KC_RPRN, _______, _______,
                      _______, _______, KC_LCBR, KC_RCBR, _______, _______,
             _______, C(KC_C)
  ),

  [NUM] = LAYOUT_LR(  // Number layer.
    _______, _______, _______, _______, _______, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, KC_LCTL, XXXXXXX, XXXXXXX,
                                                 TO(BASE), _______,

                      _______, _______, _______, _______, _______, _______,
                      KC_TAB , KC_8   , KC_9   , KC_4   , KC_PPLS, KC_PSLS,
                      KC_COLN, KC_1   , KC_2   , KC_3   , KC_PMNS, KC_PAST,
                      KC_PCMM, KC_7   , KC_6   , KC_5   , KC_PDOT, _______,
             KC_0   , QK_LLCK
  ),

  [WIN] = LAYOUT_LR(  // Window management layer.
    RGB_TOG, RGB_DEF, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                 XXXXXXX, A(KC_SPC),

                      XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,
                      A(KC_TAB), A(KC_8), A(KC_9), A(KC_4), XXXXXXX, XXXXXXX,
                      A(S(KC_LEFT)), A(KC_1), A(KC_2), A(KC_3), A(S(KC_RGHT)), XXXXXXX,
                      XXXXXXX, A(KC_7), A(KC_6), A(KC_5), KC_VOLD, KC_VOLU,
             QK_REP , XXXXXXX
  ),

  [FUN] = LAYOUT_LR(  // Funky fun layer.
    _______, _______, _______, _______, _______, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                 TO(BASE), _______,

                      _______, _______, _______, _______, _______, QK_BOOT,
                      XXXXXXX, KC_F8  , KC_F9  , KC_F4  , KC_F10 , XXXXXXX,
                      XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F11 , XXXXXXX,
                      XXXXXXX, KC_F7  , KC_F6  , KC_F5  , KC_F12 , _______,
             XXXXXXX, QK_LLCK
  ),

  [NAV] = LAYOUT_LR(  // Navigation layer.
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                 XXXXXXX, _______,

                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, XXXXXXX,
                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
             XXXXXXX, XXXXXXX
  ),
};

