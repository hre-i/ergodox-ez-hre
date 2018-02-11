#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  WS_R,
  WS_L
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

// LT(SYMB, KC_SPACE)

#define KNJ  ACTION_MODS_KEY(MOD_LALT, KC_GRAVE) // Alt+`

#define TO_RIGHT_WS  ACTION_MODS_KEY(MOD_LGUI|MOD_LCTL, KC_RIGHT) // Ctrl+Win+Right
#define TO_LEFT_WS   ACTION_MODS_KEY(MOD_LGUI|MOD_LCTL, KC_LEFT)  // Ctrl+Win+Right

#define WIN_L  ACTION_MODS_KEY(MOD_LGUI, KC_LEFT)  // Left Half
#define WIN_R  ACTION_MODS_KEY(MOD_LGUI, KC_RIGHT) // Right Half
#define WIN_U  ACTION_MODS_KEY(MOD_LGUI, KC_UP   ) // Upper Half
#define WIN_D  ACTION_MODS_KEY(MOD_LGUI, KC_DOWN)  // Lower Half

#define WIN_UL ACTION_MODS_KEY(MOD_LGUI|MOD_LSFT, KC_UP)    // Upper-Left
#define WIN_DL ACTION_MODS_KEY(MOD_LGUI|MOD_LSFT, KC_LEFT)  // Lower-Left
#define WIN_UR ACTION_MODS_KEY(MOD_LGUI|MOD_LSFT, KC_RIGHT) // Upper-Right
#define WIN_DR ACTION_MODS_KEY(MOD_LGUI|MOD_LSFT, KC_DOWN)  // Lower-Right


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.       ,------------------------------------------.
 * |  `    |  1  |  2  |  3  |  4  |  5  | INS |       |  6  |  7  |  8  |  9  |  0  |  -  |  =    |
 * |-------+-----+-----+-----+-----+-----------|       |-----+-----+-----+-----+-----+-----+-------|
 * |Alt/Tab|  Q  |  W  |  E  |  R  |  T  | WS_L|       | WS_R|  Y  |  U  |  I  |  O  |  P  |LAlt/\ |
 * |-------+-----+-----+-----+-----+-----|     |       |     |-----+-----+-----+-----+-----+-------|
 * | LCtl  |  A  |  S  |  D  |  F  |  G  |-----|       |-----|  H  |  J  |  K  |  L  | ;:  |LCtl/' |
 * |-------+-----+-----+-----+-----+-----| DEL |       | BS  |-----+-----+-----+-----+-----+-------|
 * | LSft  |  Z  |  X  |  C  |  V  |  B  |     |       |     |  N  |  M  |  ,  |  .  | /?  | RSft  |
 * `-------+-----+-----+-----+-----+-----------'       `-----------+-----+-----+-----+-----+-------'
 *  | WS_L | WS_R| INS | LWIN| LALT|                               |LALT |RWIN |[   |  ]   | L2   |
 *  `------------------------------'                               `------------------------------'
 *                                 ,-------------.   ,-------------.
 *                                 | HELP | PgUp |   | Home | RALT |
 *                          ,------|------|------|   |------+------+------.
 *                          |      |      | PgDn |   | End  |      |      |
 *                          | Ent  | ESC  |------|   |------| L1   | SPC  |
 *                          |      |      | LWIN |   | RWIN |      |      |
 *                          `--------------------'   `--------------------'
 *
 * WS_L/WS_R ... Move to Workspace Left/Right from VBox Guest.
 * 
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
    [BASE] = KEYMAP(  // layer 0 : default
            // left hand
            //--+----*---+----* ----+----* ----+----* ----+----* ----+----* ----+----* ----+----*
            KC_GRAVE,           KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_INS,
            LT(SYMB, KC_TAB),   KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      WS_L,
            KC_LCTRL,           KC_A,      KC_S,      KC_D,      KC_F,      KC_G,
            KC_LSFT,            KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_DELETE,
            //
            WS_L, WS_R, KC_INS, KC_LWIN, KC_LALT, 
            //
            /*     */ KC_HELP, KC_PGUP,
            /*               */  KC_PGDN,
            KC_ENT,   KC_ESC,    KC_LWIN,
            // right hand
            //--+----* ----+----* ----+----* ----+----* ----+----* ----+----* ----+----*----+----*
            KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,   KC_EQL,
            WS_R,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      LALT_T(KC_BSLS),
                       KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   LCTL_T(KC_QUOT),
            KC_BS,     KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSFT,
            //
            KC_LALT, KC_RWIN, KC_LBRC, KC_RBRC, MO(MDIA),
            //
            KC_HOME,   KC_RALT,
            KC_END,
            KC_RWIN,   MO(SYMB),  KC_SPACE
        ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.      ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
 * |---------+------+------+------+------+------+------|      |------+------+------+------+------+------+--------|
 * |         |      |      |      |      | PScr | WinU |      | WinD |      | App  | PgUp | PgDn |      |        |
 * |---------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
 * |         |      |      |      |      | ScLk |------|      |------| Left | Down |  Up  |Right |      |        |
 * |---------+------+------+------+------+------| WinL |      | WinR |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |      |      | BS   | Del  | Home | End  |      |        |
 * `---------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                  |      |      |      |      |RESET |
 *   `-----------------------------------'                                  `----------------------------------'
 *                                        ,-------------.   ,-------------.
 *                                        |      |WinUL |   | WinUR|      |
 *                                 ,------|------|------|   |------+------+------.
 *                                 |      |      |WinDL |   | WinDR|      |      |
 *                                 |      |      |------|   |------|      |      |
 *                                 |      |      |      |   |      |      |      |
 *                                 `--------------------'   `--------------------'
 *
 * - WinUL/WinUR/WinDL/WinDR ... Tiling window (1/4)
 * - WinU/WinD/WinL/WinR     ... Tiling window (1/2)
 */
// SYMBOLS
    [SYMB] = KEYMAP(
            // left hand
            //--+----* ----+----* ----+----* ----+----* ----+----* ----+----* ----+----*
            KC_TRNS,   KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_TRNS,
            KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_PSCR,   WIN_D,
            KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_SLCK,
            KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   WIN_L,
            KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
            /*                                                  */ KC_TRNS,  WIN_UL,
            /*                                                            */ WIN_DL,
            /*                                      */ KC_TRNS,   KC_TRNS,   KC_TRNS,
            // right hand
            //--+----* ----+----* ----+----* ----+----* ----+----* ----+----* ----+----*
            KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,
            WIN_U,     KC_TRNS,   KC_APP,    KC_PGUP,   KC_PGDN,   KC_TRNS,   KC_TRNS,
            /*      */ KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  KC_BS,     KC_TRNS,
            WIN_R,     KC_TRNS,   KC_DELETE, KC_HOME,   KC_END,    KC_TRNS,   KC_TRNS,
            /*                 */ KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   RESET,
            WIN_UR,   KC_TRNS,
            WIN_DR,
            KC_TRNS,   KC_TRNS,  KC_TRNS
        ),
/* Keymap 2: Media Layer
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
// MEDIA
    [MDIA] = KEYMAP(
            // left hand
            //--+----* ----+----* ----+----* ----+----* ----+----* ----+----* ----+----*
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_BTN1, KC_WH_U, KC_BTN2, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_R,
            /*                                        */ KC_TRNS, KC_TRNS,
            /*                                                 */ KC_TRNS,
            /*                               */ KC_BTN1, KC_BTN2, KC_TRNS,
            // right hand
            KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            /*     */ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            /*              */ KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
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
      SEND_STRING(SS_TAP(X_RALT)SS_DOWN(X_LGUI)SS_DOWN(X_LCTRL)SS_DOWN(X_LEFT)SS_UP(X_LEFT)SS_UP(X_LCTRL)SS_UP(X_LGUI));;
    }
    return false;
    break;
  case WS_R:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RALT)SS_DOWN(X_LGUI)SS_DOWN(X_LCTRL)SS_DOWN(X_RIGHT)SS_UP(X_RIGHT)SS_UP(X_LCTRL)SS_UP(X_LGUI));;
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
