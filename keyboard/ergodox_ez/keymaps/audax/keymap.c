#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "action_util.h"
#include "action.h"
#include "timer.h"
#include "keymap_extras/keymap_neo2.h"
#include "keymap_extras/keymap_german.h"

// Layer names
#define BASE 0 // default layer
#define _GA 1
#define _UP 2
#define MDIA 3 // media keys

#define NEO_L1_SS 1
#define NEO_L2_ENT 2

// Max duration that counts as a tap (ms)
#ifndef TAPPING_TERM
#define TAPPING_TERM 200
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_CIRC,         KC_1,          KC_2,          KC_3,          KC_4,    KC_5,    KC_MPLY,
        KC_TAB,          NEO_X,         NEO_V,         NEO_L,         NEO_C,   NEO_W,   MO(MDIA),
        KC_CAPS,         NEO_U,        NEO_I,         NEO_A,         NEO_E,   NEO_O,
        KC_LSFT,         CTL_T(NEO_UE), ALT_T(NEO_OE), GUI_T(NEO_AE), NEO_P,   NEO_Z,   MO(_UP),
        MT(_GA, KC_HOME), KC_PGDN,        KC_PGUP,        KC_END, KC_LGUI,
						LALT(KC_TAB),KC_LALT,
							    LSFT(KC_INS),
						    KC_SPC,KC_BSPC,KC_INS,
        // right hand
        KC_MNXT,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        TG(_GA),       NEO_K,   NEO_H,   NEO_G,   NEO_F,   NEO_Q,   NEO_Y,
	    NEO_S,   NEO_N,   NEO_R,   NEO_T,   NEO_D,   F(NEO_L1_SS),
        MEH_T(KC_NO),NEO_B,   NEO_M,   KC_COMM, KC_DOT,  MT(MOD_LGUI|MOD_LCTL, NEO_J),   SFT_T(KC_ESC),
				    CTL_T(KC_LEFT), KC_DOWN, KC_UP,   KC_RGHT, KC_LALT,
        LALT(KC_LEFT),LALT(KC_RGHT),
        LCTL(KC_TAB),
        LCTL(LALT(KC_TAB)),KC_TAB, F(3)
    ),
[_GA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12,
       KC_TRNS, NEO_U, NEO_I, KC_TRNS, KC_TRNS,KC_TRNS,
       KC_TRNS, NEO_UE, NEO_OE, NEO_AE, KC_TRNS, KC_TRNS, KC_F5,
       KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
                                           KC_F1, KC_F2,
                                                    KC_F3,
                                  KC_TRNS, KC_TRNS, KC_F4,
    // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
[_UP] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_DEL,  KC_PGDN, KC_UP,   KC_PGUP, KC_BSPC, KC_TRNS,
       KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT,KC_END,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_DEL, KC_TRNS,
    // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_TRNS,
       KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_TRNS, NEO_SS,
                KC_COMM, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_DOT, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_TRNS,
       KC_TRNS, KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5,
       KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_BTN3, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2,
                                           KC_TRNS, RESET,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN2, KC_TRNS,
    // right hand
       KC_TRNS, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11,
       KC_TRNS, KC_TRNS, KC_WHOM, KC_WREF, KC_WFWD, KC_TRNS, KC_F12,
                KC_TRNS, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_TRNS,
       KC_TRNS, KC_WSCH, KC_WBAK, KC_VOLD, KC_MUTE, KC_VOLU, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_WBAK, KC_WFWD
),
};

const uint16_t PROGMEM fn_actions[] = {
    /* [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols) */
  [1] = ACTION_FUNCTION_TAP(NEO_L1_SS),
  [2] = ACTION_FUNCTION_TAP(NEO_L2_ENT),
  [3] = ACTION_LAYER_TAP_KEY(_UP, KC_ENT)
};
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch (id) {
    case NEO_L1_SS:
    if (record->event.pressed) {
	register_code(NEO_L1_R);
    } else {
	unregister_code(NEO_L1_R);
	if (record->tap.count != 0) {
	    add_key(NEO_SS);
	    send_keyboard_report();
	    del_key(NEO_SS);
	    send_keyboard_report();
	}
    }
  break;
    case NEO_L2_ENT:
    if (record->event.pressed) {
	register_code(NEO_L2_R);
    } else {
	unregister_code(NEO_L2_R);
	if (record->tap.count != 0) {
	    add_key(KC_ENT);
	    send_keyboard_report();
	    del_key(KC_ENT);
	    send_keyboard_report();
	}
    }
  }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
    }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void  matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
    case _GA:
      ergodox_right_led_3_on();
      break;
    case MDIA:
	ergodox_right_led_2_on();
	break;
    default:
	ergodox_board_led_off();
	break;
    }

};
