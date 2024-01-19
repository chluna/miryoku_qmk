// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

#include "manna-harbour_miryoku.h"

#include "process_dynamic_macro.h"
#include "os_detection.h"
#include "features/casemodes.h"
#include "features/achordion.h"


// Additional Features double tap guard

enum {
    U_TD_BOOT,
#define MIRYOKU_X(LAYER, STRING) U_TD_U_##LAYER,
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
    TD_DM1,
    TD_DM2,
    TD_CM,
    TD_CWI,
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

void td_dynamic_macro1(tap_dance_state_t *state, void *user_data) {
    keyrecord_t record;
    record.event.pressed = false;

    if (state->count == 1) {
        process_dynamic_macro(QK_DYNAMIC_MACRO_PLAY_1, &record);
    }
    else if (state->count == 2) {
        process_dynamic_macro(QK_DYNAMIC_MACRO_RECORD_START_1, &record);
    }
}

void td_dynamic_macro2(tap_dance_state_t *state, void *user_data) {
    keyrecord_t record;
    record.event.pressed = false;

    if (state->count == 1) {
        process_dynamic_macro(QK_DYNAMIC_MACRO_PLAY_2, &record);
    }
    else if (state->count == 2) {
        process_dynamic_macro(QK_DYNAMIC_MACRO_RECORD_START_2, &record);
    }
}

void td_case_modes(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        enable_xcase_with(OSM(MOD_LSFT));
    }
    else if (state->count == 2) {
        enable_xcase();
    }
}

void td_caps_word_insert(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        caps_word_toggle();
    }
    else if (state->count == 2) {
        tap_code16(KC_INS);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
#define MIRYOKU_X(LAYER, STRING) [U_TD_U_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_U_##LAYER),
    MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
    [TD_DM1] = ACTION_TAP_DANCE_FN(td_dynamic_macro1),
    [TD_DM2] = ACTION_TAP_DANCE_FN(td_dynamic_macro2),
    [TD_CM]  = ACTION_TAP_DANCE_FN(td_case_modes),
    [TD_CWI] = ACTION_TAP_DANCE_FN(td_caps_word_insert),
};


// Custom macros

enum custom_keycodes {
    LAUNCH = SAFE_RANGE
};


// Custom functions

void invoke_app_launcher(void) {
    os_variant_t os = detected_host_os();
    switch (os) {
        case OS_LINUX:
            SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_SPC) SS_UP(X_LGUI));
            break;
        case OS_WINDOWS:
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_SPC) SS_UP(X_LALT));
            break;
        case OS_MACOS:
        case OS_IOS:
            SEND_STRING(SS_DOWN(X_LCMD) SS_TAP(X_SPC) SS_UP(X_LCMD));
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

    if (!process_case_modes(keycode, record)) {
        return false;
    }

    if (record->event.pressed) {
        const uint8_t mods = get_mods();

        switch (keycode) {
            case LAUNCH:
                invoke_app_launcher();
                break;
            case TD(TD_CWI):
                if (mods & MOD_MASK_SHIFT) {
                    tap_code16(KC_CAPS);
                    return false;
                }
                break;
            case KC_MPRV:
                if (mods & MOD_MASK_SHIFT) {
                    g_tapping_term -= DYNAMIC_TAPPING_TERM_INCREMENT;
                    return false;
                }
                break;
            case KC_MNXT:
                if (mods & MOD_MASK_SHIFT) {
                    g_tapping_term += DYNAMIC_TAPPING_TERM_INCREMENT;
                    return false;
                }
                break;
            case ALGR_T(KC_DOT):
                if (mods & MOD_MASK_SHIFT) {
                    unregister_mods(mods);
                    tap_code16(KC_COLN);
                    register_mods(mods);
                    return false;
                }
                break;
            case LT(U_BUTTON, KC_SLSH):
                if (mods & MOD_MASK_SHIFT) {
                    unregister_mods(mods);
                    tap_code16(KC_BSLS);
                    register_mods(mods);
                    return false;
                }
                break;
        }
    }

    return true;
};

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

const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
const key_override_t volup_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_VOLU, KC_BRIU);
const key_override_t voldn_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_VOLD, KC_BRID);

const key_override_t **key_overrides = (const key_override_t *[]){
    &comma_key_override,
    &volup_key_override,
    &voldn_key_override,
    NULL
};


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
combo_t key_combos[COMBO_COUNT] = {
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
