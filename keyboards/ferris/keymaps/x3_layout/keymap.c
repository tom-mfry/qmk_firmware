#include QMK_KEYBOARD_H

#define xx KC_NO

const uint16_t PROGMEM bootLoaderCombo1[] = {KC_Q, KC_E, KC_T, COMBO_END};
const uint16_t PROGMEM bootLoaderCombo2[] = {KC_Y, KC_I, KC_P, COMBO_END};
const uint16_t PROGMEM enterCombo[] = {KC_BSPC, KC_SPC, COMBO_END};
const uint16_t PROGMEM tabCombo[] = {KC_BSPC, KC_T, COMBO_END};
const uint16_t PROGMEM mouseLayer[] = {KC_ESC, KC_CAPS, COMBO_END};

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
    }
    return true;
};


combo_t key_combos[] = {
    COMBO(bootLoaderCombo1, QK_BOOTLOADER),
    COMBO(bootLoaderCombo2, QK_BOOTLOADER),
    COMBO(enterCombo, KC_ENT),
    COMBO(tabCombo, KC_TAB),
    COMBO(mouseLayer, TO(_MOUSE)),
};

/*
*  BASE LAYER
* ┌────────┬────────┬────────┬────────┬────────┐       ┌────────┬────────┬────────┬────────┬────────┐
* │   Q    │   W    │   E    │   R    │   T    │       │   Y    │   U    │   I    │   O    │   P    │
* ├────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┤
* │   A    │   S    │   D    │   F    │   G    │       │   H    │   J    │   K    │   L    │   ;    │
* ├────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┤
* │   Z    │   X    │   C    │   V    │   B    │       │   N    │   M    │   ,    │   .    │   /    │
* └────────┴────────┴────────┼────────┼────────┤       ├────────┼────────┤────────┴────────┴────────┘
*                            │  LSFT  │  BKSPC │       │ SPACE  │  NAV   │
*                            └────────┴────────┘       └────────┴────────┘
*
*  NAV LAYER
* ┌────────┬────────┬────────┬────────┬────────┐       ┌────────┬────────┬────────┬────────┬────────┐
* │  ESC   │  TAB   │        │  DEL   │ BKSPC  │       │  END   │ PG_DWN │ PG_UP  │  HOME  │  CAPS  │
* ├────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┤
* │ LSHFT  │ LCTRL  │  LALT  │  LGUI  │        │       │   ←    │   ↓    │   ↑    │   →    │        │
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
* │   ^    │    /   │   *    │    \   │   `    │       │   ~    │   {    │    }   │   @    │        │
* └────────┴────────┴────────┼────────┼────────┤       ├────────┼────────┤────────┴────────┴────────┘
*                            │  NUM   │ BKSPC  │       │  BASE  │  NAV   │
*                            └────────┴────────┘       └────────┴────────┘
*
*  NUMBER LAYER
* ┌────────┬────────┬────────┬────────┬────────┐       ┌────────┬────────┬────────┬────────┬────────┐
* │        │   1    │   2    │   3    │ ENTER  │       │        │        │        │        │        │
* ├────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┤
* │        │   4    │   5    │   6    │        │       │        │        │        │        │        │
* ├────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┤
* │        │   7    │   8    │   9    │   0    │       │        │        │        │        │        │
* └────────┴────────┴────────┼────────┼────────┤       ├────────┼────────┤────────┴────────┴────────┘
*                            │ SPACE  │  BKSPC │       │  BASE  │ MOUSE  │
*                            └────────┴────────┘       └────────┴────────┘
*
* MOUSE LAYER
* ┌────────┬────────┬────────┬────────┬────────┐       ┌────────┬────────┬────────┬────────┬────────┐
* │        │        │SCRL_UP │        │        │       │        │        │ MSE_UP │        │        │
* ├────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┤
* │ LSHFT  │RGT_CLCK│MDL_CLCK│LFT_CLCK│        │       │        │MSE_LFT │MSE_DWN │MSE_RGT │        │
* ├────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┤
* │        │        │SCRL_DWN│        │        │       │        │        │        │        │        │
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
                                  KC_LSFT, KC_BSPC,            KC_SPC, TT(_NAV)),

        [_NAV] = LAYOUT_split_3x5_2(
          KC_ESC, KC_TAB, xx, KC_DEL, KC_BSPC, KC_END, KC_PGDN, KC_PGUP, KC_HOME, KC_CAPS,
          OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_MEH), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, xx,
          xx, LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), LGUI(KC_F), KC_LT, KC_MINS, KC_PLUS, KC_GT, xx,
          TO(_SYM), KC_ENT, TO(_BASE), xx),

        [_SYM] = LAYOUT_split_3x5_2(
          KC_DOT, KC_DQUO, KC_LT, KC_GT, KC_QUOT, DOUBLE_COLON, KC_LPRN, KC_RPRN, KC_PERC, KC_AMPR, 
          KC_EXLM, KC_PLUS, KC_MINS, KC_EQL, KC_HASH, KC_COLN, KC_LBRC, KC_RBRC, KC_QUES, KC_PIPE, 
          KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, KC_GRV, KC_TILD, KC_LCBR, KC_RCBR, KC_AT, KC_NO,
          TO(_NUM), KC_BSPC, TO(_BASE), TO(_NAV)),

        [_NUM] = LAYOUT_split_3x5_2(
          xx, KC_1, KC_2, KC_3, KC_ENT, xx, xx, xx, xx, xx,
          xx, KC_4, KC_5, KC_6, xx, xx, xx, xx, xx, xx,
          xx, KC_7, KC_8, KC_9, KC_0, xx, xx, xx, xx, xx,
          KC_SPC, KC_BSPC, TO(_BASE), TO(_MOUSE)),

        [_MOUSE] = LAYOUT_split_3x5_2(
          xx, xx, KC_MS_WH_UP, xx, xx,                       xx, xx, KC_MS_UP, xx, xx,
          xx, xx, KC_MS_BTN2, KC_MS_BTN3, KC_MS_BTN1, xx,    xx, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,
          xx, xx, KC_MS_WH_DOWN, xx, xx,                     xx, xx, xx, xx, xx,
          xx, TO(_BASE),                                     TO(_BASE), xx),
};

