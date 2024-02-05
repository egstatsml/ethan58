/*
** got the bongo cat from https://github.com/Rwarcards762/lily58_bongocat
**
*/

#include QMK_KEYBOARD_H
#include "stdio.h"

// OLED setup
#define IDLE_FRAMES 4
#define IDLE_SPEED 30
#define TAP_FRAMES 2
#define TAP_SPEED 40
#define ANIM_FRAME_DURATION 200
#define ANIM_SIZE 512

/* char     wpm_str[10]; */
/* uint32_t anim_timer         = 0;
 * uint32_t anim_sleep         = 0;
 * uint8_t  current_idle_frame = 0;
 * uint8_t  current_tap_frame  = 0; */

/* static long int oled_timeout = 300000; // 5 minutes */
enum layer_number {
    _QWERTY = 0,
    _NUMB   = 1,
    _SYMB   = 2,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_QWERTY] = LAYOUT(
  KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,                     KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,     KC_NO,
  KC_ESC,LGUI_T(KC_Q),LALT_T(KC_W),LCTL_T(KC_E),LGUI_T(KC_R),KC_T,       KC_Y,RGUI_T(KC_U),LCTL_T(KC_I),RALT_T(KC_O),RGUI_T(KC_P),KC_GRV,
  KC_BSLS, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN,  KC_QUOT,
  KC_ESC,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_NO,     KC_NO,  KC_N,    KC_M, KC_COMM,    KC_DOT,KC_SLASH, KC_MINS,
  KC_NO,  KC_BSPC,  KC_TAB, CTL_T(KC_SPC), RSFT_T(KC_ENT),MO(_SYMB), LT(_NUMB, KC_BSPC), KC_NO
),

/* SYMB
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   !  |  *   |  =   |  [   |   ]  |  $   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  \/| |  @   |  +   |  (   |   )  | \/|  |-------.    ,-------| LEFT |  UP  | DOWN | RIGHT|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  &   | -/_  |  {   |   }  |  /   |-------|    |-------|   _  |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LALT | LCTRL|QWERTY| / ENTER /       \SPACE \  | SYMB |BackSP| RALT |
 *                   |      | LGUI |      |/LCTRL  /         \RSHIFT\ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SYMB] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  KC_EXLM, LGUI_T(KC_PAST),LALT_T(KC_EQL),LCTL_T(KC_LBRC),LGUI_T(KC_RBRC),KC_DLR, _______, _______, _______, _______, _______, _______,
  KC_BSLS, KC_AT,  KC_PLUS,  KC_LPRN,  KC_RPRN,  KC_BSLS,                     KC_LEFT, KC_DOWN,   KC_UP,   KC_RGHT, _______,  _______,
  _______, KC_AMPR,KC_MINS,  KC_LCBR,   KC_RCBR,  KC_NO,           KC_NO,     KC_UNDS,   KC_0,    KC_1,   KC_2,   KC_3, KC_EXLM, KC_NO,
  KC_NO,  KC_BSPC,  KC_TAB, CTL_T(KC_SPC), RSFT_T(KC_ENT), _______, MO(_NUMB), KC_NO
  /* _______, KC_ESC, TO(_QWERTY), LCTL_T(KC_SPC),   RSFT_T(KC_ENT),TO(_SYMB), KC_BSPC, KC_NO */
),
/* NUMB
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  7   |  8   |   9  |      |                    |  *   |  /   |QWERTY|  eql |  -   |  |   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  4   |  5   |   6  |      |-------.    ,-------| Left | Down |  Up  |Right |  ^   |  \   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  0   |  1   |  3   |   3  |      |-------|    |-------| PAUSE|  _   |  ^   |  )   |  ]   |  }   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LALT | LCTRL|QWERTY| / ENTER /       \SPACE \  |QWERTY|BackSP| RALT |
 *                   |      | LGUI |      |/LCTRL  /         \RSHIFT\ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_NUMB] = LAYOUT(
  _______, _______, _______, _______, _______,_______,                     _______, _______,_______, _______, _______,_______,
  _______,_______,LGUI_T(KC_7),LALT_T(KC_8),LCTL_T(KC_9), _______,                _______, _______, _______,_______, _______, _______,
  _______,_______, KC_4, KC_5, KC_6, _______,                          KC_LEFT, KC_DOWN,   KC_UP,   KC_RGHT, _______,  _______,
  _______,KC_0,  KC_1,  KC_2, KC_3, _______, _______,          _______, _______, _______, _______,_______, _______, _______,
  KC_NO,  KC_BSPC,  KC_TAB, CTL_T(KC_SPC), RSFT_T(KC_ENT),  MO(_SYMB), _______, KC_NO
           /* KC_LALT, LGUI_T(KC_MINS),  TO(_QWERTY),LCTL_T(KC_SPC), RCTL_T(KC_ENT),TO(_QWERTY), RGUI_T(KC_BSPC), KC_RALT */
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LALT | LCTRL|SPACE | / QWERTY/       \QWERTY\  |ENTER |BackSP| RALT |
 *                   |      | LGUI | CTRL |/       /         \      \ |      |      |      |
                     `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

/* function to handle processing of some custom hold functions Uses the LT(0, XX)
 * as a sort of placeholder. Since layer 0 is always active, the LT doesn't
 * actually do anything so I can intercept it for my own custom hold/tap methods
 * Currently Supported custom hold/tap methods are plus/minus on the NUMB and SYMB
 * layers asterix/divide on the NUMB and SYMB layers */
/* bool process_record_user(uint16_t keycode, keyrecord_t *record) {
 *     switch (keycode) {
 *         case LT(0, KC_MINS):
 *             if (!record->tap.count && record->event.pressed) {
 *                 tap_code16(KC_PLUS); // Intercept hold function to send -
 *                 return false;
 *             }
 *             return true; // Return true for normal processing of tap keycode
 *         case LT(0, KC_SLSH):
 *             if (!record->tap.count && record->event.pressed) {
 *                 tap_code16(KC_ASTR); // Intercept hold function to send /
 *                 return false;
 *             }
 *             return true; // Return true for normal processing of tap keycode
 *     }
 *     return true;
 * } */
/* I want most of the mod keys to be handled with a certain amount of care,
 *     in that for the mod keys that are assigned to the keys below the home row,
 *     I want the keys themselves to be prioritised. For those keys I am not really
 *     trying to work quikly, nor am I typically in the flow of typing, so I want the
 *     letters themselves to be treated as first class.
 *
 *     For the Shift/Ent key, I want shift the be  prioritised. If I am pressing
 *     the Shift/Ent key, I want Shift to be activated if I push another key, even
 *     if i push the next key before the tapping timeout. I can achieve this by
 *     ignoring the mod tap interrupt per keys. In particular, I want to ignore the
 *     mod tap interrupt for the letter keys, but I want it to be used for
 *     the Shift/Entkey. I can do that here.
 *     Other keys I want it to work for include the thumb clusters.
 *     I dont typically hit the thumb cluster keys by accident whilst using
 *     them in a chord with other keys, so I want those keys to be hadled as
 *     a modifier if another key is pressed at the same time, regardless of
 *     the timeout period.
 *     An exception to this at the moment is the left control/space key.
 *     Since I have this mapped to an extremely common key at the moment,
 *     If I ignore the mod tap interrupt here, I am often sending Ctrl+<letter>
 *     just in normal typing, so am going to exvlude it.
 *
 *     More info about this can be found at:
 *     https://docs.qmk.fm/#/tap_hold
 *     */
/* bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
 *     switch (keycode) {
 *         // Force the mod-tap key press to be handled as a modifier if any
 *         // other key was pressed while the mod-tap key is held down.
 *         // To achieve this, have the case return false for the key sequence of
 *         // interest
 *         case RSFT_T(KC_ENT):
 *             return false;
 *         case LGUI_T(KC_MINS):
 *             return false;
 *         case RGUI_T(KC_BSPC):
 *             return false;
 *         default:
 *             // Do not force the mod-tap key press to be handled as a modifier
 *             // if any other key was pressed while the mod-tap key is held down.
 *             return true;
 *     }
 * } */

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NUMB, _SYMB, _ADJUST);
}

