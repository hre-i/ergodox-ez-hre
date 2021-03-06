#include QMK_KEYBOARD_H

//#undef DEBOUNCE
//#define DEBOUNCE    20

#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols layer
#define WCTL 2 // window control layer
#define MDIA 3 // media / mouse control layer

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  WS_R,
  WS_L,
  WS_1, WS_2, WS_3, WS_4, WS_5,
  WS_6, WS_7, WS_8, WS_9, WS_0,
};

////

#define STAB ACTION_MODS_KEY(MOD_LSFT, KC_TAB)  // Shift+Tab

#define MOD_AS    MT((MOD_LALT|MOD_LSFT), KC_NO)
#define MOD_CS    MT((MOD_LCTL|MOD_LSFT), KC_NO)
#define MOD_AC    MT((MOD_LALT|MOD_LCTL), KC_NO)
#define MOD_CW    MT((MOD_LCTL|MOD_LGUI), KC_NO)
#define MOD_SW    MT((MOD_LSFT|MOD_LGUI), KC_NO)
#define MOD_AW    MT((MOD_LALT|MOD_LGUI), KC_NO)
#define MOD_ACS   MT((MOD_LALT|MOD_LCTL|MOD_LSFT), KC_NO)
#define MOD_ACW   MT((MOD_LALT|MOD_LCTL|MOD_LGUI), KC_NO)
#define MOD_ASW   MT((MOD_LALT|MOD_LSFT|MOD_LGUI), KC_NO)
#define MOD_CSW   MT((MOD_LCTL|MOD_LSFT|MOD_LGUI), KC_NO)
#define MOD_ACSW  MT((MOD_LALT|MOD_LCTL|MOD_LSFT|MOD_LGUI), KC_NO)

#define SF_LBRC  ACTION_MODS_KEY(MOD_LSFT, KC_LBRC)     // { (Shift + [)
#define SF_RBRC  ACTION_MODS_KEY(MOD_LSFT, KC_RBRC)     // } (Shift + ])

#define M_PASTE ACTION_MODS_KEY(MOD_LSFT, KC_INS)  // Mintty Paste(Shift+Ins)
#define M_COPY  ACTION_MODS_KEY(MOD_LCTL, KC_INS)  // Mintty Copy (Ctrl+Ins)

#define KC_BS  KC_BSPC  // Backspace
#define KC_ENT KC_ENTER // Enter

#define KC_LWIN KC_LGUI
#define KC_RWIN KC_RGUI
#define KC_LOPT KC_LALT
#define KC_ROPT KC_RALT

#define KNJ  ACTION_MODS_KEY(MOD_LALT, KC_GRAVE) // Alt+`

#define T_COPY   ACTION_MODS_KEY(MOD_LCTL, KC_INS)  // Ctrl+INS
#define T_PASTE  ACTION_MODS_KEY(MOD_LSFT, KC_INS)  // Shift+INS

#define TO_RIGHT_WS  ACTION_MODS_KEY(MOD_LGUI|MOD_LCTL, KC_RIGHT) // Ctrl+Win+Right
#define TO_LEFT_WS   ACTION_MODS_KEY(MOD_LGUI|MOD_LCTL, KC_LEFT)  // Ctrl+Win+Right

#define WIN_ML ACTION_MODS_KEY(MOD_LGUI|MOD_LSFT|MOD_LCTL, KC_Y) // Main Left
#define WIN_SR ACTION_MODS_KEY(MOD_LGUI|MOD_LSFT|MOD_LCTL, KC_U) // Sub Right
#define WIN_SL ACTION_MODS_KEY(MOD_LGUI|MOD_LSFT|MOD_LCTL, KC_I) // Sub Left
#define WIN_MR ACTION_MODS_KEY(MOD_LGUI|MOD_LSFT|MOD_LCTL, KC_O) // Main Right

#define WIN_L ACTION_MODS_KEY(MOD_LGUI|MOD_LSFT|MOD_LCTL, KC_H) // Left Half
#define WIN_D ACTION_MODS_KEY(MOD_LGUI|MOD_LSFT|MOD_LCTL, KC_J) // Lower Half
#define WIN_U ACTION_MODS_KEY(MOD_LGUI|MOD_LSFT|MOD_LCTL, KC_K) // Upper Half
#define WIN_R ACTION_MODS_KEY(MOD_LGUI|MOD_LSFT|MOD_LCTL, KC_L) // Right Half

#define WIN_UL ACTION_MODS_KEY(MOD_LGUI|MOD_LSFT|MOD_LCTL, KC_Q)  // Upper-Left
#define WIN_DL ACTION_MODS_KEY(MOD_LGUI|MOD_LSFT|MOD_LCTL, KC_A)  // Lower-Left
#define WIN_UR ACTION_MODS_KEY(MOD_LGUI|MOD_LSFT|MOD_LCTL, KC_W)  // Upper-Right
#define WIN_DR ACTION_MODS_KEY(MOD_LGUI|MOD_LSFT|MOD_LCTL, KC_S)  // Lower-Right

#define APP_Q     ACTION_MODS_KEY(MOD_RGUI, KC_Q)     // RWIN+Q
#define APP_W     ACTION_MODS_KEY(MOD_RGUI, KC_W)     // RWIN+W
#define APP_E     ACTION_MODS_KEY(MOD_RGUI, KC_E)     // RWIN+E
#define APP_R     ACTION_MODS_KEY(MOD_RGUI, KC_R)     // RWIN+R
#define APP_T     ACTION_MODS_KEY(MOD_RGUI, KC_T)     // RWIN+T

#define APP_A     ACTION_MODS_KEY(MOD_RGUI, KC_A)     // RWIN+A
#define APP_S     ACTION_MODS_KEY(MOD_RGUI, KC_S)     // RWIN+S
#define APP_D     ACTION_MODS_KEY(MOD_RGUI, KC_D)     // RWIN+D
#define APP_F     ACTION_MODS_KEY(MOD_RGUI, KC_F)     // RWIN+F
#define APP_G     ACTION_MODS_KEY(MOD_RGUI, KC_G)     // RWIN+G

#define APP_Z     ACTION_MODS_KEY(MOD_RGUI, KC_Z)     // RWIN+Z
#define APP_X     ACTION_MODS_KEY(MOD_RGUI, KC_X)     // RWIN+X
#define APP_C     ACTION_MODS_KEY(MOD_RGUI, KC_C)     // RWIN+C
#define APP_V     ACTION_MODS_KEY(MOD_RGUI, KC_V)     // RWIN+V
#define APP_B     ACTION_MODS_KEY(MOD_RGUI, KC_B)     // RWIN+B

#define APP_Y     ACTION_MODS_KEY(MOD_RGUI, KC_Y)     // RWIN+Y
#define APP_U     ACTION_MODS_KEY(MOD_RGUI, KC_U)     // RWIN+U
#define APP_I     ACTION_MODS_KEY(MOD_RGUI, KC_I)     // RWIN+I
#define APP_O     ACTION_MODS_KEY(MOD_RGUI, KC_O)     // RWIN+O
#define APP_P     ACTION_MODS_KEY(MOD_RGUI, KC_P)     // RWIN+P

#define APP_H     ACTION_MODS_KEY(MOD_RGUI, KC_H)     // RWIN+H
#define APP_J     ACTION_MODS_KEY(MOD_RGUI, KC_J)     // RWIN+J
#define APP_K     ACTION_MODS_KEY(MOD_RGUI, KC_K)     // RWIN+K
#define APP_L     ACTION_MODS_KEY(MOD_RGUI, KC_L)     // RWIN+L
#define APP_SCLN  ACTION_MODS_KEY(MOD_RGUI, KC_SCLN)  // RWIN+;

#define APP_N     ACTION_MODS_KEY(MOD_RGUI, KC_N)     // RWIN+N
#define APP_M     ACTION_MODS_KEY(MOD_RGUI, KC_M)     // RWIN+M
#define APP_COMM  ACTION_MODS_KEY(MOD_RGUI, KC_COMM)  // RWIN+,
#define APP_DOT   ACTION_MODS_KEY(MOD_RGUI, KC_DOT)   // RWIN+.
#define APP_SLSH  ACTION_MODS_KEY(MOD_RGUI, KC_SLSH)  // RWIN+/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.       ,------------------------------------------.
 * | INS   |  1  |  2  |  3  |  4  |  5  | DEL |       |  6  |  7  |  8  |  9  |  0  |  -  | =/+   |
 * |-------+-----+-----+-----+-----+-----------|       |-----+-----+-----+-----+-----+-----+-------|
 * |Alt/Tab|  Q  |  W  |  E  |  R  |  T  |  [  |       |  ]  |  Y  |  U  |  I  |  O  |  P  |LAlt/\ |
 * |-------+-----+-----+-----+-----+-----|     |       |     |-----+-----+-----+-----+-----+-------|
 * | LCtl  |  A  |  S  |  D  |  F  |  G  |-----|       |-----|  H  |  J  |  K  |  L  | ;:  |LCtl/' |
 * |-------+-----+-----+-----+-----+-----|  `  |       | BS  |-----+-----+-----+-----+-----+-------|
 * | LSft  |  Z  |  X  |  C  |  V  |  B  |     |       |     |  N  |  M  |  ,  |  .  | /?  | RSft  |
 * `-------+-----+-----+-----+-----+-----------'       `-----------+-----+-----+-----+-----+-------'
 *  | WS_L | WS_R|     | L2  | LALT|                               |LALT | L2  |     | RAlt| RCtl |
 *  `------------------------------'                               `------------------------------'
 *                                 ,-------------.   ,-------------.
 *                                 | WIN_L|WIN_UL|   |WIN_UR|WIN_R |
 *                          ,------|------|------|   |------+------+------.
 *                          |      |      |WIN_DL|   |WIN_DR|      |      |
 *                          | Ent  | ESC  |------|   |------| L1   | SPC  |
 *                          |      |      | LWIN |   | RWIN |      |      |
 *                          `--------------------'   `--------------------'
 *
 */
    [BASE] = LAYOUT_ergodox(  // layer 0 : default
            // left hand
            //--+----* ----+----* ----+----* ----+----* ----+----* ----+----* ----+----*
            KC_INS,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_DEL,
            KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_LBRC,
            KC_LCTRL,  KC_A,      KC_S,      KC_D,      KC_F,      KC_G,
            KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_GRAVE,
            WS_L,      WS_R,      KC_INS,    MO(WCTL),  KC_LALT,
                       WIN_L,     WIN_UL,
                                  WIN_DL,
            KC_ENT,    KC_ESC,    KC_LWIN,
            // right hand
            //--+----* ----+----* ----+----* ----+----* ----+----* ----+----* ----+----*
            KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,   KC_EQL,
            KC_RBRC,   KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      LALT_T(KC_BSLS),
                       KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   LCTL_T(KC_QUOT),
            KC_BS,     KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSFT,
                                  KC_RALT,   MO(WCTL),  KC_TRNS,   KC_RALT,   KC_RCTL,
            WIN_UR,    WIN_R,
            WIN_DR,
            KC_RWIN,   MO(SYMB),  KC_SPACE
        ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.      ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
 * |---------+------+------+------+------+------+------|      |------+------+------+------+------+------+--------|
 * |         |      |      |  {   |   }  | PScr |      |      |      |      | App  | PgUp | PgDn |      |        |
 * |---------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
 * |         | WS_L | WS_R |  [   |   ]  | ScLk |------|      |------| Left | Down |  Up  |Right |      |        |
 * |---------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |      |      | BS   | Del  | Home | End  |      |        |
 * `---------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                  |      |      |      |      |RESET |
 *   `-----------------------------------'                                  `----------------------------------'
 *                                        ,-------------.   ,-------------.
 *                                        |      |      |   |      |      |
 *                                 ,------|------|------|   |------+------+------.
 *                                 |      |      |      |   |      |      |      |
 *                                 |      |      |------|   |------|      |      |
 *                                 |      |      |      |   |      |      |      |
 *                                 `--------------------'   `--------------------'
 */
// SYMBOLS
    [SYMB] = LAYOUT_ergodox(
            // left hand
            //--+----* ----+----* ----+----* ----+----* ----+----* ----+----* ----+----*
            KC_TRNS,   KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_TRNS,
            KC_TRNS,   KC_TRNS,   KC_TRNS,   SF_LBRC,   SF_RBRC,   KC_PSCR,   KC_TRNS,
            KC_TRNS,   WS_L,      WS_R,      KC_LBRC,   KC_RBRC,   KC_SLCK,
            KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
            KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
                                                                   KC_TRNS,   KC_TRNS,
                                                                              KC_TRNS,
                                                        KC_TRNS,   KC_TRNS,   KC_TRNS,
            // right hand
            //--+----* ----+----* ----+----* ----+----* ----+----* ----+----* ----+----*
            KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,
            KC_TRNS,   KC_TRNS,   KC_APP,    KC_PGUP,   KC_PGDN,   KC_TRNS,   KC_TRNS,
                       KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  KC_BS,     KC_TRNS,
            KC_TRNS,   KC_TRNS,   KC_DELETE, KC_HOME,   KC_END,    KC_TRNS,   KC_TRNS,
                                  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   RESET,
            KC_TRNS,   KC_TRNS,
            KC_TRNS,
            KC_TRNS,   KC_TRNS,   KC_TRNS
        ),
/* Keymap 2: Window Control Layer
 *
 * ,-------------------------------------------.       ,------------------------------------------.
 * |       |WS_1 |WS_2 |WS_3 |WS_4 |WS_5 |     |       |WS_6 |WS_7 |WS_8 |WS_9 |WS_0 |     |       |
 * |-------+-----+-----+-----+-----+-----------|       |-----+-----+-----+-----+-----+-----+-------|
 * |       |APP_Q|APP_W|APP_E|APP_R|APP_T|WIN_D|       |WIN_U|APP_Y|APP_U|APP_I|APP_O|APP_P|       |
 * |-------+-----+-----+-----+-----+-----|     |       |     |-----+-----+-----+-----+-----+-------|
 * |       |APP_A|APP_S|APP_D|APP_F|APP_G|-----|       |-----|APP_H|APP_J|APP_K|APP_L|APP_;|       |
 * |-------+-----+-----+-----+-----+-----|WIN_L|       |WIN_R|-----+-----+-----+-----+-----+-------|
 * |       |APP_Z|APP_X|APP_C|APP_V|APP_B|     |       |     |APP_N|APP_M|APP_,|APP_.|APP_/|       |
 * `-------+-----+-----+-----+-----+-----------'       `-----------+-----+-----+-----+-----+-------'
 *  |      |     |     |     |     |                               |     |     |     |     |      |
 *  `------------------------------'                               `------------------------------'
 *                                 ,-------------.   ,-------------.
 *                                 |WIN_L |WIN_UL|   |WIN_UR|WIN_R |
 *                          ,------|------|------|   |------+------+------.
 *                          |      |      |WIN_DL|   |WIN_DR|      |      |
 *                          |      |      |------|   |------|      |      |
 *                          |      |      |      |   |      |      |      |
 *                          `--------------------'   `--------------------'
 *
 */
    [WCTL] = LAYOUT_ergodox(
            // left hand
            KC_TRNS,   WS_1,       WS_2,       WS_3,       WS_4,       WS_5,       KC_TRNS,
            KC_TRNS,   APP_Q,      APP_W,      APP_E,      APP_R,      APP_T,      WIN_D,
            KC_TRNS,   APP_A,      APP_S,      APP_D,      APP_F,      APP_G,
            KC_TRNS,   APP_Z,      APP_X,      APP_C,      APP_V,      APP_B,      WIN_L,
            KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                                       WIN_SL,     WIN_UL,
                                                                                   WIN_DL,
                                                           KC_TRNS,    KC_TRNS,    KC_TRNS,
            // right hand
            WS_6,      WS_7,       WS_8,       WS_9,       WS_0,       KC_TRNS,    KC_TRNS,
            WIN_U,     APP_Y,      APP_U,      APP_I,      APP_O,      APP_P,      KC_TRNS,
                       APP_H,      APP_J,      APP_K,      APP_L,      APP_SCLN,   KC_TRNS,
            WIN_R,     APP_N,      APP_M,      APP_COMM,   APP_DOT,    APP_SLSH,   KC_TRNS,
                                   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
            WIN_UR,    WIN_MR,
            WIN_DR,
            KC_TRNS,   KC_TRNS,    KC_TRNS
        ),
/* Keymap 3: Mouse Control Layer
 *
 * ,---------------------------------------------------.      ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |      |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|      |------+------+------+------+------+------+--------|
 * |         |      |      | MS_U |      |      |      |      |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
 * |         |      | MS_L | MS_D | MS_R |      |------|      |------|      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
 * |         |      | BTN1 | WH_U | BTN2 |      |      |      |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
 *   |       |      | WH_L | WH_D | WH_R |                                  | VOLU | VOLD | MUTE |      |      |
 *   `-----------------------------------'                                  `----------------------------------'
 *                                        ,-------------.   ,-------------.
 *                                        |      |      |   |      |      |
 *                                 ,------|------|------|   |------+------+------.
 *                                 |      |      |      |   |      |      |      |
 *                                 | BTN1 | BTN2 |------|   |------|      |      |
 *                                 |      |      |      |   |      |      |      |
 *                                 `--------------------'   `--------------------'
 */
// Media/Mouse Control Layer
    [MDIA] = LAYOUT_ergodox(
            // left hand
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_BTN1, KC_WH_U, KC_BTN2, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_R,
                                                         KC_TRNS, KC_TRNS,
                                                                  KC_TRNS,
                                                KC_BTN1, KC_BTN2, KC_TRNS,
            // right hand
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                              KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS,
            KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS
        ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;

  case WS_L:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RCTRL)SS_DOWN(X_LGUI)SS_DOWN(X_LCTRL)SS_TAP(X_LEFT)SS_UP(X_LCTRL)SS_UP(X_LGUI));
    }
    return false;
    break;

  case WS_R:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RCTRL)SS_DOWN(X_LGUI)SS_DOWN(X_LCTRL)SS_TAP(X_RIGHT)SS_UP(X_LCTRL)SS_UP(X_LGUI));
    }
    return false;
    break;

#define DN_ALL SS_DOWN(X_LGUI)SS_DOWN(X_LALT)SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)
#define UP_ALL SS_UP(X_LSHIFT)SS_UP(X_LCTRL)SS_UP(X_LALT)SS_UP(X_LGUI)

  case WS_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RCTRL)DN_ALL/**/SS_TAP(X_1)UP_ALL/**/);;
    }
    return false;
    break;
  case WS_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RCTRL)DN_ALL/**/SS_TAP(X_2)UP_ALL/**/);;
    }
    return false;
    break;
  case WS_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RCTRL)DN_ALL/**/SS_TAP(X_3)UP_ALL/**/);;
    }
    return false;
    break;
  case WS_4:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RCTRL)DN_ALL/**/SS_TAP(X_4)UP_ALL/**/);;
    }
    return false;
    break;
  case WS_5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RCTRL)DN_ALL/**/SS_TAP(X_5)UP_ALL/**/);;
    }
    return false;
    break;
  case WS_6:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RCTRL)DN_ALL/**/SS_TAP(X_6)UP_ALL/**/);;
    }
    return false;
    break;
  case WS_7:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RCTRL)DN_ALL/**/SS_TAP(X_7)UP_ALL/**/);;
    }
    return false;
    break;
  case WS_8:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RCTRL)DN_ALL/**/SS_TAP(X_8)UP_ALL/**/);;
    }
    return false;
    break;
  case WS_9:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RCTRL)DN_ALL/**/SS_TAP(X_9)UP_ALL/**/);;
    }
    return false;
    break;
  case WS_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RCTRL)DN_ALL/**/SS_TAP(X_0)UP_ALL/**/);;
    }
    return false;
    break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
