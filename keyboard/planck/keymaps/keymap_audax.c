// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "backlight.h"
#include "keymap_extras/keymap_neo2.h"
#include "keymap_extras/keymap_german.h"
#include "keymap_common.h"
#include "timer.h"
#include "action.h"
#include "action_util.h"

// Max duration that counts as a tap (ms)
#ifndef TAPPING_TERM
#define TAPPING_TERM 200
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _NE 0
#define _RS 1

#define NEO_L1_Y 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_NE] = { /* Neo 2 Soft */
  {MEH_T(KC_TAB),NEO_X,   NEO_V,           NEO_L,   NEO_C,   NEO_W,        NEO_K,        NEO_H,   NEO_G,   NEO_F,   NEO_Q,   KC_BSPC},
  {NEO_L1_L,     NEO_U,   NEO_I,           NEO_A,   NEO_E,   NEO_O,        NEO_S,        NEO_N,   NEO_R,   NEO_T,   NEO_D,   F(1)},
  {KC_LSFT,      NEO_UE,  NEO_OE,          NEO_AE,  NEO_P,   NEO_Z,        NEO_B,        NEO_M,   KC_COMM, KC_DOT,  NEO_J,   SFT_T(KC_ESC)},
  {KC_LCTL,      KC_LALT, KC_LSFT|KC_LGUI, KC_ESC,  NEO_L1_R,GUI_T(KC_SPC),CTL_T(KC_ENT),NEO_L2_L,F(0),    KC_PGUP, KC_PGDN, S(KC_INS)}
},
[_RS] = { /* RAISE */
  {KC_GRV,       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,         KC_7,    KC_8,    KC_9,    KC_0,    NEO_SS},
  {KC_TRNS,      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,        KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {KC_TRNS,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,       KC_F12,       DF(_NE), KC_TRNS, DF(_RS), RESET,   KC_TRNS},
  {KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MPLY}
}
};


const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_TAP_TOGGLE(_RS),
  [1] = ACTION_FUNCTION_TAP(NEO_L1_Y)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            backlight_step();
          } else {
            unregister_code(KC_RSFT);
          }
        break;
	return MACRO_NONE;
      }
};


void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch (id) {
    case NEO_L1_Y:
    if (record->event.pressed) {
	register_code(NEO_L1_R);
    } else {
	unregister_code(NEO_L1_R);
	if (record->tap.count != 0) {
	    register_code(NEO_Y);
	    add_key(NEO_Y);
	    send_keyboard_report();
	    del_key(NEO_Y);
	    send_keyboard_report();
	}
    }
  break;
  }
}
