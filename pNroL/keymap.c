#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MINUS,       KC_QUOTE,       KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_DQUO,        KC_CIRC,        KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_AT,          
    KC_BSPC,        KC_A,           MT(MOD_LALT, KC_S),MT(MOD_LSFT, KC_D),MT(MOD_LCTL, KC_F),KC_G,                                           KC_H,           MT(MOD_RCTL, KC_J),MT(MOD_RSFT, KC_K),MT(MOD_RALT, KC_L),KC_SCLN,        KC_COLN,        
    KC_BSLS,        MT(MOD_LGUI, KC_Z),KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         MT(MOD_RGUI, KC_SLASH),KC_ENTER,       
                                                    KC_UNDS,        KC_SPACE,                                       KC_NO,          LT(5,KC_ESCAPE)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, LGUI(KC_Z),     LGUI(KC_V),     LGUI(KC_A),     LGUI(KC_C),     LGUI(KC_X),                                     RCTL(KC_PAGE_UP),KC_PGDN,        KC_PAGE_UP,     RCTL(KC_PGDN),  KC_TRANSPARENT, KC_AUDIO_MUTE,  
    KC_NO,          MO(4),          KC_LABK,        KC_RABK,        KC_BSLS,        KC_GRAVE,                                       KC_AMPR,        KC_NO,          KC_LBRC,        KC_RBRC,        KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_EXLM,        KC_MINUS,       KC_PLUS,        KC_EQUAL,       KC_HASH,                                        KC_PIPE,        KC_COLN,        KC_LPRN,        KC_RPRN,        KC_PERC,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_SLASH,       KC_ASTR,        KC_CIRC,        KC_NO,                                          KC_TILD,        KC_DLR,         KC_LCBR,        KC_RCBR,        KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_TAB,         KC_8,           KC_9,           KC_4,           KC_KP_PLUS,     KC_KP_SLASH,    
    KC_TRANSPARENT, KC_NO,          KC_LEFT_ALT,    KC_LEFT_SHIFT,  KC_LEFT_CTRL,   KC_NO,                                          KC_COLN,        KC_1,           KC_2,           KC_3,           KC_KP_MINUS,    KC_KP_ASTERISK, 
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_NO,          KC_LEFT_CTRL,   KC_NO,          KC_NO,                                          KC_KP_COMMA,    KC_7,           KC_6,           KC_5,           KC_KP_DOT,      KC_TRANSPARENT, 
                                                    TO(0),          KC_TRANSPARENT,                                 KC_0,           QK_LLCK
  ),
  [3] = LAYOUT_voyager(
    RGB_TOG,        KC_NO,          RGB_MODE_FORWARD,RGB_HUI,        RGB_SAI,        RGB_VAI,                                        KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          RGUI(KC_TAB),   RGUI(KC_8),     RGUI(KC_9),     RGUI(KC_4),     KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_LEFT_ALT,    KC_LEFT_SHIFT,  KC_LEFT_CTRL,   KC_NO,                                          RGUI(RSFT(KC_LEFT)),RGUI(KC_1),     RGUI(KC_2),     RGUI(KC_3),     RGUI(RSFT(KC_RIGHT)),KC_NO,          
    KC_NO,          KC_LEFT_GUI,    KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          RGUI(KC_7),     RGUI(KC_6),     RGUI(KC_5),     KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,
                                                    KC_NO,          LGUI(KC_SPACE),                                 KC_NO,          KC_NO
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,        
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_F8,          KC_F9,          KC_F4,          KC_F10,         KC_NO,          
    KC_TRANSPARENT, KC_NO,          KC_LEFT_ALT,    KC_LEFT_SHIFT,  KC_LEFT_CTRL,   KC_NO,                                          KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F11,         KC_NO,          
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_F7,          KC_F6,          KC_F5,          KC_F12,         KC_TRANSPARENT, 
                                                    TO(0),          KC_TRANSPARENT,                                 KC_NO,          QK_LLCK
  ),
  [5] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_UP,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}



