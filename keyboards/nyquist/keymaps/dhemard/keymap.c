#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _FN3 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base Layer
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Esc(2)|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Ent(2)|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | FN3  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Power| GUI  | Alt  | Ctrl |  FN1 | Shift| Space| FN1  | Ctrl | Alt  |      | Caps |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT( \
  KC_GRV,           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  LT(_FN2, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LT(_FN2, KC_ENT), \
  MO(_FN3),         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  KC_POWER,         KC_LGUI, KC_LALT, KC_LCTL, MO(_FN1),KC_LSFT, KC_SPC,  MO(_FN1),KC_RCTL, KC_RALT, XXXXXXX,  KC_CAPS \
),

/* Function Layer 1 (Symbols and Movement)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   -  |  =   |   {  |   }  |   '  | Home |      |      | End  |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   [  |   ]  |   (  |   )  |   `  | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   \  |      |   <  |   >  |      |      | PgDn | PgUp |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | xxxx |      |      | xxxx |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN1] = LAYOUT( \
  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
  _______,   KC_MINS,   KC_EQL,    S(KC_LBRC),S(KC_RBRC),KC_QUOT,   KC_HOME,   _______,   _______,   KC_END,    _______,   KC_DEL, \
  _______,   KC_LBRC,   KC_RBRC,   S(KC_9),   S(KC_0),   KC_GRV,    KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,   _______,   _______, \
  _______,   KC_BSLS,   _______,   S(KC_COMM),S(KC_DOT), _______,   _______,   KC_PGDN,   KC_PGUP,   _______,   _______,   _______, \
  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______ \
),

/* Function Layer 2 (Media and Numpad)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   /  |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | xxxx | Prev | Vol- | Vol+ | Mute | Next |   -  |   4  |   5  |   6  |   +  | xxxx |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      | Pause|      |   .  |   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |Shift |   0  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN2] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_PSLS, KC_7,    KC_8,    KC_9,    KC_PAST, _______, \
  _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MUTE, KC_MNXT, KC_PMNS, KC_4,    KC_5,    KC_6,    KC_PPLS, _______, \
  _______, _______, _______, _______, KC_MPLY, _______, KC_PDOT, KC_1,    KC_2,    KC_3,    KC_Z,    KC_ENT , \
  _______, _______, _______, _______, _______, _______, KC_LSFT, KC_0,    _______, _______, _______, _______ \
),

/* Function Layer 3 (Function Keys)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  F4  |  F5  |  F6  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | xxxx |      |  F1  |  F2  |  F3  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  F10 |  F11 |  F12 |      |      |      |      |      | pwr-w|      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN3] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_F7,   KC_F8,   KC_F9,   _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_F1,   KC_F2,   KC_F3,   _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, KC_PWR,  _______ \
)

};