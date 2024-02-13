// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

#include "manna-harbour_miryoku.h"

#include "os_detection.h"

#include "features/achordion.h"
#include "features/custom_shift_keys.h"
#include "features/casemodes.h"


// Additional Features double tap guard

enum {
    U_TD_BOOT,
#define MIRYOKU_X(LAYER, STRING) U_TD_U_##LAYER,
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
    TD_RGB_MOD,
};

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    reset_keyboard();
  }
}

#define MIRYOKU_X(LAYER, STRING) \
void u_td_fn_U_##LAYER(tap_dance_state_t *state, void *user_data) { \
  if (state->count == 2) { \
    default_layer_set((layer_state_t)1 << U_##LAYER); \
  } \
}
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X

void td_rgb_modes(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
#           if defined (RGB_MATRIX_ENABLE)
                rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
#           endif
#           if defined (RGBLIGHT_ENABLE)
                rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
#           endif
            break;
        case 2:
#           if defined (RGB_MATRIX_ENABLE)
                rgb_matrix_mode(RGB_MATRIX_BREATHING);
#           endif
#           if defined (RGBLIGHT_ENABLE)
                rgblight_mode(RGBLIGHT_MODE_BREATHING);
#           endif
            break;
        case 3:
#           if defined (RGB_MATRIX_ENABLE)
                rgb_matrix_mode(RGB_MATRIX_CYCLE_LEFT_RIGHT);
#           endif
#           if defined (RGBLIGHT_ENABLE)
                rgblight_mode(RGBLIGHT_MODE_RAINBOW_MOOD);
#           endif
            break;
        case 4:
#           if defined (RGB_MATRIX_ENABLE)
                rgb_matrix_mode(RGB_MATRIX_CYCLE_PINWHEEL);
#           endif
#           if defined (RGBLIGHT_ENABLE)
                rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
#           endif
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
#define MIRYOKU_X(LAYER, STRING) [U_TD_U_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_U_##LAYER),
    MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
    [TD_RGB_MOD] = ACTION_TAP_DANCE_FN(td_rgb_modes),
};


// Custom macros

enum custom_keycodes {
    LAUNCH = SAFE_RANGE,
    XC_CUSTOM,
    XC_KC_UNDS,
    XC_KC_MINS,
    XC_KC_SLSH,
    XC_KC_BSLS,
};

// Custom functions

void invoke_app_launcher(void) {
    os_variant_t os = detected_host_os();
    switch (os) {
        case OS_LINUX:
            tap_code16(LGUI(KC_SPC));
            break;
        case OS_WINDOWS:
            tap_code16(LALT(KC_SPC));
            break;
        case OS_MACOS:
        case OS_IOS:
            tap_code16(LCMD(KC_SPC));
            break;
        default:
            // send nothing
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }

    if (!process_custom_shift_keys(keycode, record)) {
        return false;
    }

    if (!process_case_modes(keycode, record)) {
        return false;
    }

    if (record->event.pressed) {
        switch (keycode) {
            case LAUNCH:
                invoke_app_launcher();
                break;
            case XC_CUSTOM:
                enable_xcase();
                break;
            case XC_KC_UNDS:
                enable_xcase_with(KC_UNDS);
                break;
            case XC_KC_MINS:
                enable_xcase_with(KC_MINS);
                break;
            case XC_KC_SLSH:
                enable_xcase_with(KC_SLSH);
                break;
            case XC_KC_BSLS:
                enable_xcase_with(KC_BSLS);
                break;
        }
    }

    return true;
};

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    // https://getreuer.info/posts/keyboards/achordion/index.html#achordion_chord

    switch (tap_hold_keycode) {
        // Allow same-hand holds for Miryoku layer tap keys
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            return true;
    }

    // Otherwise, follow the opposite hands rule.
    return achordion_opposite_hands(tap_hold_record, other_record);
}

void matrix_scan_user(void) {
    achordion_task();
}

bool use_default_xcase_separator(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
            return true;
    }
    return false;
}


// Keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#define MIRYOKU_X(LAYER, STRING) [U_##LAYER] = U_MACRO_VA_ARGS(MIRYOKU_LAYERMAPPING_##LAYER, MIRYOKU_LAYER_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};


// Shift functions

const custom_shift_key_t custom_shift_keys[] = {
    {KC_COMM, KC_SCLN},
    {KC_DOT , KC_COLN},
    {KC_VOLU, KC_BRIU},
    {KC_VOLD, KC_BRID},
    {CW_TOGG, KC_CAPS},
    {LT(U_BUTTON, KC_SLSH), KC_BSLS}
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);


// Thumb combos

#if defined (MIRYOKU_KLUDGE_THUMBCOMBOS)
const uint16_t PROGMEM thumbcombos_base_right[] = {LT(U_SYM, KC_ENT), LT(U_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left[] = {LT(U_NAV, KC_SPC), LT(U_MOUSE, KC_TAB), COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[] = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_mouse[] = {KC_BTN2, KC_BTN1, COMBO_END};
const uint16_t PROGMEM thumbcombos_media[] = {KC_MSTP, KC_MPLY, COMBO_END};
const uint16_t PROGMEM thumbcombos_num[] = {KC_0, KC_MINS, COMBO_END};
  #if defined (MIRYOKU_LAYERS_FLIP)
const uint16_t PROGMEM thumbcombos_sym[] = {KC_UNDS, KC_LPRN, COMBO_END};
  #else
const uint16_t PROGMEM thumbcombos_sym[] = {KC_RPRN, KC_UNDS, COMBO_END};
  #endif
const uint16_t PROGMEM thumbcombos_fun[] = {KC_SPC, KC_TAB, COMBO_END};
combo_t key_combos[] = {
  COMBO(thumbcombos_base_right, LT(U_FUN, KC_DEL)),
  COMBO(thumbcombos_base_left, LT(U_MEDIA, KC_ESC)),
  COMBO(thumbcombos_nav, KC_DEL),
  COMBO(thumbcombos_mouse, KC_BTN3),
  COMBO(thumbcombos_media, KC_MUTE),
  COMBO(thumbcombos_num, KC_DOT),
  #if defined (MIRYOKU_LAYERS_FLIP)
  COMBO(thumbcombos_sym, KC_RPRN),
  #else
  COMBO(thumbcombos_sym, KC_LPRN),
  #endif
  COMBO(thumbcombos_fun, KC_APP)
};
#endif
