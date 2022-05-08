#include QMK_KEYBOARD_H
#include "config.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_Y)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_Y)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL
#define _RAISE 1
#define _LOWER 2
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)


enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
  DANCE_Q,
  DANCE_ESC,
  DANCE_CLN,
  DANCE_LBRC,
  DANCE_RBRC,
  DANCE_BSLASH,
  DANCE_SLASH,
  DANCE_QT,
  DANCE_LANG,
  DANCE_RANG,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_5x6( // QWERTY
        TD(DANCE_ESC) , TD(DANCE_1)  , TD(DANCE_2)  , TD(DANCE_3), TD(DANCE_4)  , TD(DANCE_5),                         TD(DANCE_6), TD(DANCE_7) , TD(DANCE_8)   , TD(DANCE_9)    , TD(DANCE_0)    , KC_BSPC,
        KC_TAB        , KC_Q         , KC_W         , KC_E       , KC_R         , KC_T,                                KC_Y       , KC_U        , KC_I          , KC_O           , KC_P           , TD(DANCE_BSLASH),
        KC_LSFT       , KC_A         , KC_S         , KC_D       , KC_F         , KC_G,                                KC_H       , KC_J        , KC_K          , KC_L           , TD(DANCE_CLN)  , TD(DANCE_QT),
        KC_LCTL       , KC_Z         , KC_X         , KC_C       , KC_V         , KC_B,                                KC_N       , KC_M        , TD(DANCE_LANG), TD(DANCE_RANG) , TD(DANCE_SLASH), KC_RSHIFT,

                                                    TD(DANCE_LBRC),TD(DANCE_RBRC),                                                                              KC_PLUS, KC_EQL,
                                                                RAISE, KC_ENTER,                                                     KC_BSPC, KC_SPC,
                                                                    KC_TAB,KC_HOME,                                            KC_END,  KC_DEL,
                                                                    KC_RALT, KC_LGUI,                                          KC_RGUI, KC_LALT
  ),

  [_RAISE] = LAYOUT_5x6(
        KC_TILDE,_______,_______,_______,_______,_______,                        KC_MPRV,KC_MPLY,KC_MNXT,KC_VOLD,KC_VOLU,KC_DEL,
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                        KC_LEFT,KC_DOWN,KC_UP  ,KC_RIGHT,_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______

    ),
  [_LOWER] = LAYOUT_5x6(
      KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,         KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
      _______,_______,_______,_______,_______,_______,         _______,KC_KP_7,KC_KP_8,KC_KP_9,_______,_______,
      _______,_______,_______,_______,_______,_______,         _______,KC_KP_4,KC_KP_5,KC_KP_6,_______,_______,
      _______,_______,_______,_______,_______,_______,         _______,KC_KP_1,KC_KP_2,KC_KP_3,_______,_______,
                      _______,_______,                                         _______,_______,
                                      _______,_______,         _______,_______,
                                      _______,_______,         _______,_______,
                                      _______,_______,         _______,_______
    ),

//   [0] = LAYOUT_5x6(
//     KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,
//     KC_TAB,         TD(DANCE_0),    TD(DANCE_1),    TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),    KC_AUDIO_VOL_UP,                                KC_MEDIA_NEXT_TRACK,TD(DANCE_I),   TD(DANCE_O),   TD(DANCE_P),   KC_P,           KC_QUOTE,       TD(DANCE_A),
//     TD(DANCE_5),    TD(DANCE_6),    TD(DANCE_7),    TD(DANCE_8),    TD(DANCE_9),    TD(DANCE_Q),   KC_AUDIO_VOL_DOWN,                                                                KC_MEDIA_PLAY_PAUSE,KC_Y,           TD(DANCE_S),   TD(DANCE_D),   TD(DANCE_F),   TD(DANCE_G),   KC_ENTER,
//     KC_LSHIFT,      TD(DANCE_W),   TD(DANCE_E),   TD(DANCE_R),   TD(DANCE_T),   TD(DANCE_Y),                                   KC_K,           TD(DANCE_H),   TD(DANCE_J),   KC_DOT,         KC_SLASH,       KC_RSHIFT,
//     KC_NO,          KC_NO,          KC_NO,          KC_LALT,        MO(1),          LCTL(LGUI(LSFT(KC_4))),                                                                                                LCTL(LGUI(KC_F)),MO(2),          KC_RCTRL,       KC_NO,          KC_NO,          KC_NO,
//     TD(DANCE_U),   LGUI(KC_TAB),   LCTL(LGUI(KC_Q)),                MO(1),          MO(3),          TD(DANCE_K)
//   ),
//   [1] = LAYOUT_5x6(
//     KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
//     TD(DANCE_L),   KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_SCOLON,      LSFT(KC_SCOLON),KC_TRANSPARENT,
//     KC_DELETE,      LALT(LCTL(LGUI(LSFT(KC_1)))),KC_DLR,         ST_MACRO_0,     ST_MACRO_1,     ST_MACRO_2,     KC_TRANSPARENT,                                                                 KC_TRANSPARENT, TD(DANCE_Z),   KC_DOWN,        KC_UP,          TD(DANCE_X),   ST_MACRO_6,     KC_TRANSPARENT,
//     KC_LGUI,        LALT(LSFT(KC_2)),LALT(KC_3),     ST_MACRO_3,     ST_MACRO_4,     ST_MACRO_5,                                     KC_HOME,        KC_END,         ST_MACRO_7,     ST_MACRO_8,     KC_NO,          KC_TRANSPARENT,
//     KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, MO(3),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
//     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
//   ),
//   [2] = LAYOUT_5x6(
//     LALT(LCTL(LGUI(LSFT(KC_0)))),LALT(LCTL(LGUI(LSFT(KC_S)))),LALT(LCTL(LGUI(LSFT(KC_N)))),LALT(LCTL(LGUI(LSFT(KC_M)))),LALT(LCTL(LGUI(LSFT(KC_C)))),LALT(LCTL(LGUI(LSFT(KC_I)))),LALT(LCTL(LGUI(LSFT(KC_F)))),                                LALT(LCTL(LGUI(LSFT(KC_2)))),LALT(LCTL(LGUI(LSFT(KC_T)))),LALT(LCTL(LGUI(LSFT(KC_3)))),LALT(LCTL(LGUI(LSFT(KC_Z)))),LALT(LCTL(LGUI(LSFT(KC_4)))),LALT(LCTL(LGUI(LSFT(KC_5)))),KC_6,
//     KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_LPRN,        KC_RPRN,        KC_UNDS,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MINUS,       KC_7,           KC_8,           KC_9,           KC_DOT,         KC_TRANSPARENT,
//     KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_LCBR,        KC_RCBR,        KC_MINUS,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_PLUS,        KC_4,           KC_5,           KC_6,           KC_SLASH,       KC_ASTR,
//     KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_LBRACKET,    KC_RBRACKET,    KC_BSLASH,                                      KC_0,           KC_1,           KC_2,           KC_3,           KC_EQUAL,       KC_TRANSPARENT,
//     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LGUI,        MO(3),          KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
//     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
//   ),
//   [3] = LAYOUT_5x6(
//     WEBUSB_PAIR,    RGB_VAD,        RGB_VAI,        RGB_HUD,        RGB_HUI,        RGB_MOD,        TOGGLE_LAYER_COLOR,                                RGB_TOG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,
//     KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_WH_RIGHT, KC_MS_UP,       KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_NO,          KC_BRIGHTNESS_UP,RESET,
//     KC_TRANSPARENT, KC_NO,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_NO,          KC_MS_BTN1,     KC_MS_BTN2,     KC_NO,          KC_BRIGHTNESS_DOWN,KC_TRANSPARENT,
//     KC_TRANSPARENT, KC_NO,          KC_NO,          KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_TRANSPARENT,                                 KC_NO,          KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_TRANSPARENT, KC_NO,
//     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,
//     KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
//   ),
};


qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_RPRN),
        [DANCE_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_EXLM),
        [DANCE_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_AT),
        [DANCE_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_HASH),
        [DANCE_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_DLR),
        [DANCE_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_PERC),
        [DANCE_6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_CIRC),
        [DANCE_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_AMPR),
        [DANCE_8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_ASTR),
        [DANCE_9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_LPRN),
        [DANCE_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRV),
        [DANCE_CLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
        [DANCE_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
        [DANCE_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
        [DANCE_BSLASH] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_PIPE),
        [DANCE_SLASH] = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_QUES),
        [DANCE_QT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQT),
        [DANCE_LANG] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_LABK),
        [DANCE_RANG] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_RABK),
};



// // MACROS

// enum {
//   RIGHT_SPACE,
// }

// bool process