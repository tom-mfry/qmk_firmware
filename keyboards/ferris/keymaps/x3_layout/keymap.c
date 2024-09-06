#include QMK_KEYBOARD_H

#define xx KC_NO
const uint16_t PROGMEM bootLoaderCombo1[] = {KC_Q, KC_E, KC_T, COMBO_END};
const uint16_t PROGMEM bootLoaderCombo2[] = {KC_Y, KC_I, KC_P, COMBO_END};
const uint16_t PROGMEM spotlight[] = {KC_BSPC, KC_SPC, COMBO_END};
const uint16_t PROGMEM tabCombo[] = {KC_BSPC, KC_T, COMBO_END};
const uint16_t PROGMEM navLayer[] = {KC_BSPC, KC_S, COMBO_END};
const uint16_t PROGMEM symLayer[] = {KC_BSPC, KC_D, COMBO_END};
const uint16_t PROGMEM numLayer[] = {KC_BSPC, KC_F, COMBO_END};
const uint16_t PROGMEM mouseLayer[] = {KC_BSPC, KC_G, COMBO_END};
const uint16_t PROGMEM capsWord[] = {KC_SPC, KC_W, COMBO_END};
const uint16_t PROGMEM enter[] = {KC_SPC, KC_E, COMBO_END};

enum layers
{
  _BASE,
  _NUM,
  _SYM,
  _NAV,
  _MOUSE
};

enum custom_keycodes {
  DOUBLE_COLON = SAFE_RANGE,
  PWD
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case DOUBLE_COLON:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING("::");
        } else {
            // when keycode is released
        }
        break;
    
    case PWD:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING("`~wtS0tLitiF;/\\");
        } else {
            // when keycode is released
        }
        break;
    }
    return true;
};


combo_t key_combos[] = {
    COMBO(bootLoaderCombo1, QK_BOOTLOADER),
    COMBO(bootLoaderCombo2, QK_BOOTLOADER),
    COMBO(spotlight, LGUI(KC_SPC)),
    COMBO(tabCombo, KC_TAB),
    COMBO(navLayer, TO(_NAV)),
    COMBO(symLayer, TO(_SYM)),
    COMBO(numLayer, TO(_NUM)),
    COMBO(mouseLayer, TO(_MOUSE)),
    COMBO(capsWord, QK_CAPS_WORD_TOGGLE),
    COMBO(enter, KC_ENT),
};

/* NOTES

CHORDING
  BACKSPC + S: Toggle _NAV Layer
  BACKSPC + D: Toggle _SYM Layer
  BACKSPC + F: Toggle _NUM Layer
  BACKSPC + G: Toggle _MOUSE Layer
  SPC + W: Caps word


*  BASE LAYER
* ┌────────┬────────┬────────┬────────┬────────┐       ┌────----────┬────────┬────────┬────────┬────────┐
* │   Q    │   W    │   E    │   R    │   T    │       │   Y        │   U    │   I    │   O    │   P    │
* ├────────┼────────┼────────┼────────┼────────┤       ├──────----──┼────────┼────────┼────────┼────────┤
* │   A    │   S    │   D    │   F    │   G    │       │   H        │   J    │   K    │   L    │   ;    │
* ├────────┼────────┼────────┼────────┼────────┤       ├─────----───┼────────┼────────┼────────┼────────┤
* │   Z    │   X    │   C    │   V    │   B    │       │   N        │   M    │   ,    │   .    │   /    │
* └────────┴────────┴────────┼────────┼────────┤       ├──────----──┼────────┤────────┴────────┴────────┘
*                            │  SYMB  │  BKSPC │       │ SPACE/CAG  │  NAV   │
*                            └────────┴────────┘       └─────----───┴────────┘
*
*  NAV LAYER
* ┌────────┬────────┬────────┬────────┬────────┐       ┌────────┬────────┬────────┬────────┬────────┐
* │  ESC   │  CSG   │  CAG   │  DEL   │ BKSPC  │       │  END   │ PG_DWN │ PG_UP  │  HOME  │  CAPS  │
* ├────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┤
* │ LSHFT  │ LCTRL  │  LALT  │  LGUI  │  TAB   │       │   ←    │   ↓    │   ↑    │   →    │  CAPSW │
* ├────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┤
* │        │  CUT   │  COPY  │ PASTE  │  FIND  │       │   <    │   -    │   +    │   >    │        │
* └────────┴────────┴────────┼────────┼────────┤       ├────────┼────────┤────────┴────────┴────────┘
*                            │  SYMB  │ ENTER  │       │  BASE  │        │
*                            └────────┴────────┘       └────────┴────────┘
*
*  SYMBOL LAYER
* ┌────────┬────────┬────────┬────────┬────────┐       ┌────────┬────────┬────────┬────────┬────────┐
* │   .    │   "    │   <    │   >    │   '    │       │   ::   │   (    │    )   │   %    │   &    │
* ├────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┤
* │   !    │   +    │   -    │   =    │   #    │       │   :    │   [    │    ]   │   ?    │   |    │
* ├────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┤
* │   *    │    /   │   _    │    \   │   `    │       │   ~    │   {    │    }   │   @    │   ^    │
* └────────┴────────┴────────┼────────┼────────┤       ├────────┼────────┤────────┴────────┴────────┘
*                            │  NUM   │ BKSPC  │       │  BASE  │  NAV   │
*                            └────────┴────────┘       └────────┴────────┘
*
*  NUMBER LAYER
* ┌────────┬────────┬────────┬────────┬────────┐       ┌────────┬────────┬────────┬────────┬────────┐
* │  BASE  │   1    │   2    │   3    │ ENTER  │       │        │        │        │        │        │
* ├────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┤
* │        │   4    │   5    │   6    │   0    │       │        │        │        │        │        │
* ├────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┤
* │        │   7    │   8    │   9    │        │       │        │        │        │        │        │
* └────────┴────────┴────────┼────────┼────────┤       ├────────┼────────┤────────┴────────┴────────┘
*                            │        │ BKSPC  │       │  BASE  │ MOUSE  │
*                            └────────┴────────┘       └────────┴────────┘
*
* MOUSE LAYER
* ┌────────┬────────┬────────┬────────┬────────┐       ┌────────┬────────┬────────┬────────┬────────┐
* │        │        │SCRL_UP │        │  PWD   │       │        │        │ MSE_UP │        │        │
* ├────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┤
* │ LSHFT  │RGT_CLCK│SCRL_DWN│LFT_CLCK│        │       │        │MSE_LFT │MSE_DWN │MSE_RGT │        │
* ├────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┤
* │        │        │MDL_CLCK│        │        │       │        │        │        │        │        │
* └────────┴────────┴────────┼────────┼────────┤       ├────────┼────────┤────────┴────────┴────────┘
*                            │  LGUI  │  BASE  │       │  BASE  │        │
*                            └────────┴────────┘       └────────┴────────┘
*
*   */



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_BASE] = LAYOUT_split_3x5_2(
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                  TT(_SYM), KC_BSPC,            KC_SPC, TT(_NAV)),

        [_NAV] = LAYOUT_split_3x5_2(
          KC_ESC, OSM(MOD_LCTL|MOD_LSFT|MOD_LGUI), OSM(MOD_LCTL|MOD_LALT|MOD_LGUI), KC_DEL, KC_BSPC, KC_END, KC_PGDN, KC_PGUP, KC_HOME, KC_CAPS,
          OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), KC_TAB, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, QK_CAPS_WORD_TOGGLE,
          xx, LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), LGUI(KC_F), KC_COMM, KC_MINS, KC_EQL, KC_DOT, xx,
          xx, KC_ENT, TO(_BASE), xx),

        [_SYM] = LAYOUT_split_3x5_2(
          KC_DOT, KC_DQUO, KC_LT, KC_GT, KC_QUOT, DOUBLE_COLON, KC_LPRN, KC_RPRN, KC_PERC, KC_AMPR, 
          KC_EXLM, KC_PLUS, KC_MINS, KC_EQL, KC_HASH, KC_COLN, KC_LBRC, KC_RBRC, KC_QUES, KC_PIPE, 
          KC_ASTR, KC_SLSH, KC_UNDS, KC_BSLS, KC_GRV, KC_TILD, KC_LCBR, KC_RCBR, KC_AT, KC_CIRC,
          xx, KC_BSPC, TO(_BASE), xx),

        [_NUM] = LAYOUT_split_3x5_2(
          TO(_BASE), KC_1, KC_2, KC_3, KC_ENT, xx, xx, xx, xx, xx,
          xx, KC_4, KC_5, KC_6, KC_0, xx, xx, xx, xx, xx,
          xx, KC_7, KC_8, KC_9, xx, xx, xx, xx, xx, xx,
          xx, KC_BSPC, TO(_BASE), xx)),

        [_MOUSE] = LAYOUT_split_3x5_2(
          xx, xx, MS_WHLD, xx, PWD,                       xx, xx, QK_MOUSE_CURSOR_UP, xx, xx,
          MOD_LSFT, MS_BTN2, MS_WHLU, MS_BTN1, xx,    xx, QK_MOUSE_CURSOR_LEFT, QK_MOUSE_CURSOR_DOWN, QK_MOUSE_CURSOR_RIGHT, xx,
          xx, xx, MS_BTN3, xx, xx,                     xx, xx, xx, xx, xx,
          MOD_LGUI, TO(_BASE),                                     TO(_BASE), xx),
};

