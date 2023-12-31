/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

// clang-format off

enum layers {
    _BASE,
    _EXTRA,
};

#define EX_SPC LT(_EXTRA, KC_SPC)

#define SHIFT OSM(MOD_LSFT)
#define GUI OSM(MOD_LGUI)
#define CTRL OSM(MOD_LCTL)
#define ALT OSM(MOD_LALT)

#define SELECT S(KC_INS)
#define CUT G(KC_X)
#define COPY G(KC_C)
#define PASTE G(KC_V)
#define CTRL_A C(KC_A)
#define DELWORD G(KC_BSPC)

#define SCRNLCK G(KC_Z)

#define WM_TAG G(KC_R)

#define KPOPEN G(KC_O)
#define KPUSER C(KC_B)
#define PMENU G(KC_EQL)

/* reset one shot layer if one shot mod is pressed * /
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (IS_QK_ONE_SHOT_MOD(keycode) && is_oneshot_layer_active() && record->event.pressed) {
		clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
	}
	return;
}
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_60_ansi(
        KC_ESC,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_LCTL, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL, KC_LALT,  KC_LGUI,                            EX_SPC,                             KC_RGUI,  _______,  _______,  KC_RCTL),

    [_EXTRA] = LAYOUT_60_ansi(
        KC_TILD, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,
	_______, KC_TAB,   CTRL_A,  _______, WM_TAG,  CW_TOGG, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSPC,  _______,  _______,  _______,
	_______, KC_ESC,   ALT,     CTRL,    GUI,     KC_UNDS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,   _______,            _______,
	_______,           PMENU,   CUT,     COPY,    PASTE,   SELECT,  KC_DEL,  DELWORD, KC_SCLN, KC_COLN,  KC_PIPE,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    /*
    [MAC_BASE] = LAYOUT_60_ansi(
        KC_ESC,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_LCTL, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL, KC_LOPT,  KC_LCMD,                            KC_SPC,                             KC_RCMD,  MO(_FN1), MO(_FN3), KC_RCTL),

    [WIN_BASE] = LAYOUT_60_ansi(
        KC_ESC,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_CAPS, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL, KC_LWIN,  KC_LALT,                            KC_SPC,                             KC_RALT,  MO(_FN2), MO(_FN3), KC_RCTL),

    [_FN1] = LAYOUT_60_ansi(
        KC_GRV,  KC_BRID,  KC_BRIU, KC_NO,   KC_NO,   RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_MOD,
        RGB_TOG, RGB_MOD,  RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, KC_INS,   KC_PGUP,  KC_HOME,  _______,
        _______, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, KC_UP,   _______, KC_PGDN,  KC_END,             _______,
        _______,           _______, _______, _______, _______, _______, NK_TOGG, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL,             _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_FN2] = LAYOUT_60_ansi(
        KC_GRV,  KC_BRID,  KC_BRIU, KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_MOD,
        RGB_TOG, RGB_MOD,  RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, KC_APP,  KC_SCRL, KC_INS,   KC_PGUP,  KC_HOME,  _______,
        _______, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, KC_UP,   KC_PSCR, KC_PGDN,  KC_END,             _______,
        _______,           _______, _______, _______, _______, _______, NK_TOGG, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL,             _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_FN3] = LAYOUT_60_ansi(
        KC_TILD, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,
        RGB_TOG, RGB_MOD,  RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______,  _______,            _______,
        _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______)
	*/
};
