#include QMK_KEYBOARD_H

const uint16_t PROGMEM bootLoaderCombo1[] = {KC_Q, KC_E, KC_T, COMBO_END};
const uint16_t PROGMEM bootLoaderCombo2[] = {KC_Y, KC_I, KC_P, COMBO_END};
combo_t key_combos[] = {
    COMBO(bootLoaderCombo1, QK_BOOTLOADER),
    COMBO(bootLoaderCombo2, QK_BOOTLOADER),
};

enum layers
{
  _BASE,
  _NUM,
  _SYM,
  _NAV,
  _FUNC,
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT_split_3x5_2(
          KC_Q, KC_W, KC_E, KC_R, KC_T,       KC_Y, KC_U, KC_I, KC_O, KC_P, 
          LSFT_T(KC_A), LCTL_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F), KC_G,       KC_H, LGUI_T(KC_J), LALT_T(KC_K), LCTL_T(KC_L), LSFT_T(KC_SCLN),
          KC_Z, KC_X, KC_C, KC_V, KC_B,       KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, 
          KC_LSFT, KC_BSPC, LT(2, KC_SPC), TO(1)),

        [1] = LAYOUT_split_3x5_2(
          KC_1, KC_2, KC_3, KC_4, KC_5,                 KC_6, KC_7, KC_8, KC_9, KC_0, 
          KC_COMM, KC_PERC, KC_LPRN, KC_LCBR, KC_LBRC,  KC_EQL, KC_QUES, KC_QUOT, KC_PLUS, KC_ASTR, 
          KC_DOT, KC_DLR, KC_RPRN, KC_RCBR, KC_RBRC,    KC_AT, KC_EXLM, KC_DQUO, KC_MINS, KC_SLSH, 
          KC_NO, KC_BSPC, TO(0), TO(2)),

        [2] = LAYOUT_split_3x5_2(
          KC_ESC, KC_NO, KC_NO, KC_TAB, QK_BOOTLOADER,      KC_PGUP, KC_HOME, KC_UP, KC_END, KC_CAPS, 
          OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_RGUI),      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, 
          KC_NO, LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), LGUI(KC_F),      KC_LGUI, KC_NO, KC_BSPC, KC_NO, QK_BOOTLOADER, 
          KC_NO, KC_ENT, TO(0), KC_NO),
          
        [_NUM] = LAYOUT_split_3x5_2(
          KC_NO, KC_1, KC_2, KC_3, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
          KC_NO, KC_NO,                           KC_NO, KC_NO,
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)