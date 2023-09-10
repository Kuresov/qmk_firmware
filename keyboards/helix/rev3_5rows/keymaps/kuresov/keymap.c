/* Copyright 2021 Kuresov
 * Credit to yushakobo (2020)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H


// Define layer names
enum layer_names {
  _QWERTY = 0,
  _L_1,
  _L_2,
};

// Alias layer switch
#define L_1 MO(_L_1)
#define L_2 MO(_L_2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  -   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | L_1  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   N  |   M  |   ,  |   .  |   /  |  =   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl |      |      |  GUI |  Alt | Space| Ctrl | Entr | Shft | Ctrl |      |      | L_1  | L_2  |
   * `-------------------------------------------------------------------------------------------------'
   * L_1: Press-and-hold for Layer 1
   * L_2: Press-and-hold for Layer 2
   */
  [_QWERTY] = LAYOUT( \
      KC_ESC,   KC_1,       KC_2, KC_3,    KC_4,    KC_5,                     KC_6,   KC_7,     KC_8,      KC_9,    KC_0,    KC_BSPC, \
      KC_TAB,   KC_Q,       KC_W, KC_E,    KC_R,    KC_T,                     KC_Y,   KC_U,     KC_I,      KC_O,    KC_P,    KC_MINS, \
      L_1   ,   KC_A,       KC_S, KC_D,    KC_F,    KC_G,                     KC_H,   KC_J,     KC_K,      KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT,  KC_Z,       KC_X, KC_C,    KC_V,    KC_B,   KC_LBRC, KC_RBRC, KC_N,   KC_M,     KC_COMM,   KC_DOT,  KC_SLSH,  KC_EQL, \
      KC_LCTL,  _______, _______, KC_LGUI, KC_LALT, KC_SPC, KC_LCTL, KC_ENT,  KC_LSFT, KC_RCTL,  _______,   _______, L_1,     KC_RCTL \
    ),

  /* Layer 1
   * ,----------------------------------------------.                ,------------------------------------------------.
   * |   `   |  F1   |  F2   |  F3   |  F4   |  F5   |               |  F6   |  F7   |  F8   |  F9   |  F10  |  Del  |
   * |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
   * |       |RGB_TOG|RGB_MOD|RGBRMOD|       |       |               |       | Bri Up| Bri Dn|  F11  |  F12  |   \   |
   * |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
   * |       |RGB_VAD|RGB_VAI|       |       |       |               |  Left | Down  |  Up   | Rght  | VOL-  | VOL+  |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |       |RGB_SAD|RGB_SAI|       |       |       |       |       |       |       | PREV  | NEXT  | PLAY  |       |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |       |RGB_HUD|RGB_HUI|       |       |       |       |       |       |       |       |       |       |PrntScr|
   * `---------------------------------------------------------------------------------------------------------------'
   * RGB_TOG: Toggle RGB
   * RGB_MOD/RGBRMOD: Next/previous RGB
   * RGB_VAI/RGB_VAD: Increase/decrease value (brightness)
   * RGB_SAI/RGB_SAD: Increase/decrease saturation
   * RGB_HAI/RGB_HAD: Increase/decrease hue
   * RGB_RST: Reset RGB
   * EH_LEFT: Set left side as master
   * EH_RGHT: Set right side as master
   */
  [_L_1] = LAYOUT( \
      KC_GRV, KC_F1,    KC_F2,   KC_F3,    KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
      _______, RGB_TOG, RGB_MOD, RGB_RMOD, _______, _______,                   _______, KC_BRIU, KC_BRID, KC_F11,  KC_F12,  KC_BSLS,
      _______, RGB_VAD, RGB_VAI, _______,  _______, _______,                   KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_VOLD, KC_VOLU,
      _______, RGB_SAD, RGB_SAI, _______,  _______, _______, _______, _______, _______, KC_BRIU, KC_MPRV, KC_MNXT, KC_MPLY, _______,
      _______, RGB_HUD, RGB_HUI, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR
      ),

  /* Layer 2
   * ,----------------------------------------------.                ,------------------------------------------------.
   * | RESET |       |       |       |       |       |               |       |       |       |       |       | RESET |
   * |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |               |       |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |   [   |               |   ]   |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
   * `---------------------------------------------------------------------------------------------------------------'
   */
  [_L_2] = LAYOUT( \
        RESET, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,   RESET,
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, KC_LBRC,                   KC_RBRC, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),
};
