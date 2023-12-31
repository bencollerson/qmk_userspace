#include QMK_KEYBOARD_H

#define BASE TO(0)

#define NUMBER OSL(_NUMBER)
#define NAV OSL(_NAV)
#define FUNCT OSL(_FUNCT)
#define MOUSE OSL(_MOUSE)
#define MOD OSL(_MOD)
#define TOGMOUS TO(_MOUSE)

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

#define CTL_SPC CTL_T(KC_SPC)

enum layers {
	_QWERTY,
	_NUMBER,
	_MOUSE,
	_NAV,
	_FUNCT,
	_MOD,
};

#include "janus.h"

/* custom caps word behaviour - don't shift dash */
bool caps_word_press_user(uint16_t keycode) {
	switch (keycode) {
		// Keycodes that continue Caps Word, with shift applied.
		case KC_A ... KC_Z:
			add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
			return true;

		// Keycodes that continue Caps Word, without shifting.
		case KC_1 ... KC_0:
		case KC_BSPC:
		case KC_DEL:
		case KC_UNDS:
			return true;

		default:
			return false; // Deactivate Caps Word.
	}
}

/* reset one shot layer if one shot mod is pressed */
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (IS_QK_ONE_SHOT_MOD(keycode) && is_oneshot_layer_active() && record->event.pressed) {
		clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
	}
	return;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_34(
		KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
		KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,
		KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
		                           NUMBER,  SHIFT,        CTL_SPC, NAV
	),

	[_NUMBER] = LAYOUT_34(
		KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS,
		KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
		KC_GRV,  KC_TILD, KC_LBRC, KC_LPRN, KC_LCBR,      KC_RCBR, KC_RPRN, KC_RBRC, KC_EQL,  KC_BSLS,
		                           _______, MOUSE,        _______, _______
	),

	[_MOUSE] = LAYOUT_34(
		KC_TAB,  CTRL_A,  KPOPEN,  KPUSER,  KC_BSPC,      KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,
		KC_ESC,  ALT,     CTRL,    GUI,     KC_ENT,       KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, TOGMOUS,
		KC_SPC,  CUT,     COPY,    PASTE,   SELECT,       KC_BTN2, XXXXXXX, XXXXXXX, QK_BOOT, QK_RBT,
		                           BASE,    _______,      KC_BTN1, KC_BTN3
	),

	[_NAV] = LAYOUT_34(
		KC_TAB,  CTRL_A,  MOD,     WM_TAG,  CW_TOGG,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSPC,
		KC_ESC,  ALT,     CTRL,    GUI,     KC_UNDS,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
		PMENU,   CUT,     COPY,    PASTE,   SELECT,       KC_DEL,  DELWORD, KC_SCLN, KC_COLN, KC_PIPE,
		                           BASE,    _______,      FUNCT,   _______
	),

	[_FUNCT] = LAYOUT_34(
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
		KC_CAPS, ALT,     CTRL,    GUI,     KC_INS,       KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY,
		KC_F11,  KC_F12,  KC_PSCR, KC_SCRL, KC_PAUS,      KC_BRID, KC_MUTE, KC_BRIU, KC_APP,  SCRNLCK,
		                           BASE,    _______,      _______, _______
	),

	[_MOD] = LAYOUT_34(
		_______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______,      _______, GUI,     CTRL,    ALT,     _______,
		_______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
		                           BASE,    _______,      ALT,     GUI
	),
};

