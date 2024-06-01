// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#define XXX KC_NO

// Redefine the base, extra and tap layers:
// * Use function keys in the top row

#if defined MIRYOKU_MAPPING_EXTENDED_THUMBS

    #if defined KEYBOARD_ymdk_id75

        #define MIRYOKU_LAYERMAPPING_BASE(\
        K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09,\
        K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19,\
        K20, K21, K22, K23, K24,                          K25, K26, K27, K28, K29,\
        N30, N31, K32, K33, K34,                          K35, K36, K37, N38, N39\
        )\
        LAYOUT_ortho_5x15(\
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      TD(TD_DM1), DM_RSTP,    TD(TD_DM2), KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,    \
        K00,        K01,        K02,        K03,        K04,        KC_SLSH,    KC_7,       KC_8,       KC_9,       KC_ASTR,    K05,        K06,        K07,        K08,        K09,       \
        K10,        K11,        K12,        K13,        K14,        KC_MINS,    KC_4,       KC_5,       KC_6,       KC_PLUS,    K15,        K16,        K17,        K18,        K19,       \
        K20,        K21,        K22,        K23,        K24,        KC_MINS,    KC_1,       KC_2,       KC_3,       KC_PLUS,    K25,        K26,        K27,        K28,        K29,       \
        XXX,        XXX,        XXX,        K32,        K33,        K34,        KC_DOT,     KC_0,       KC_EQL,     K35,        K36,        K37,        XXX,        XXX,        XXX        \
        )

        #define MIRYOKU_LAYERMAPPING_EXTRA(\
        K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09,\
        K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19,\
        K20, K21, K22, K23, K24,                          K25, K26, K27, K28, K29,\
        N30, N31, K32, K33, K34,                          K35, K36, K37, N38, N39\
        )\
        LAYOUT_ortho_5x15(\
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      TD(TD_DM1), DM_RSTP,    TD(TD_DM2), KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,    \
        K00,        K01,        K02,        K03,        K04,        KC_SLSH,    KC_7,       KC_8,       KC_9,       KC_ASTR,    K05,        K06,        K07,        K08,        K09,       \
        K10,        K11,        K12,        K13,        K14,        KC_MINS,    KC_4,       KC_5,       KC_6,       KC_PLUS,    K15,        K16,        K17,        K18,        K19,       \
        K20,        K21,        K22,        K23,        K24,        KC_MINS,    KC_1,       KC_2,       KC_3,       KC_PLUS,    K25,        K26,        K27,        K28,        K29,       \
        XXX,        XXX,        XXX,        K32,        K33,        K34,        KC_DOT,     KC_0,       KC_EQL,     K35,        K36,        K37,        XXX,        XXX,        XXX        \
        )

        #define MIRYOKU_LAYERMAPPING_TAP(\
        K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09,\
        K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19,\
        K20, K21, K22, K23, K24,                          K25, K26, K27, K28, K29,\
        N30, N31, K32, K33, K34,                          K35, K36, K37, N38, N39\
        )\
        LAYOUT_ortho_5x15(\
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      TD(TD_DM1), DM_RSTP,    TD(TD_DM2), KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,    \
        K00,        K01,        K02,        K03,        K04,        KC_SLSH,    KC_7,       KC_8,       KC_9,       KC_ASTR,    K05,        K06,        K07,        K08,        K09,       \
        K10,        K11,        K12,        K13,        K14,        KC_MINS,    KC_4,       KC_5,       KC_6,       KC_PLUS,    K15,        K16,        K17,        K18,        K19,       \
        K20,        K21,        K22,        K23,        K24,        KC_MINS,    KC_1,       KC_2,       KC_3,       KC_PLUS,    K25,        K26,        K27,        K28,        K29,       \
        XXX,        XXX,        XXX,        K32,        K33,        K34,        KC_DOT,     KC_0,       KC_EQL,     K35,        K36,        K37,        XXX,        XXX,        XXX        \
        )

    #endif

#else

    #if defined KEYBOARD_ymdk_id75

        #define MIRYOKU_LAYERMAPPING_BASE(\
        K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09,\
        K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19,\
        K20, K21, K22, K23, K24,                          K25, K26, K27, K28, K29,\
        N30, N31, K32, K33, K34,                          K35, K36, K37, N38, N39\
        )\
        LAYOUT_ortho_5x15(\
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      TD(TD_DM1), DM_RSTP,    TD(TD_DM2), KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,    \
        K00,        K01,        K02,        K03,        K04,        KC_SLSH,    KC_7,       KC_8,       KC_9,       KC_ASTR,    K05,        K06,        K07,        K08,        K09,       \
        K10,        K11,        K12,        K13,        K14,        KC_MINS,    KC_4,       KC_5,       KC_6,       KC_PLUS,    K15,        K16,        K17,        K18,        K19,       \
        K20,        K21,        K22,        K23,        K24,        KC_MINS,    KC_1,       KC_2,       KC_3,       KC_PLUS,    K25,        K26,        K27,        K28,        K29,       \
        XXX,        XXX,        K32,        K33,        K34,        XXX,        KC_DOT,     KC_0,       KC_EQL,     XXX,        K35,        K36,        K37,        XXX,        XXX        \
        )

        #define MIRYOKU_LAYERMAPPING_EXTRA(\
        K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09,\
        K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19,\
        K20, K21, K22, K23, K24,                          K25, K26, K27, K28, K29,\
        N30, N31, K32, K33, K34,                          K35, K36, K37, N38, N39\
        )\
        LAYOUT_ortho_5x15(\
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      TD(TD_DM1), DM_RSTP,    TD(TD_DM2), KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,    \
        K00,        K01,        K02,        K03,        K04,        KC_SLSH,    KC_7,       KC_8,       KC_9,       KC_ASTR,    K05,        K06,        K07,        K08,        K09,       \
        K10,        K11,        K12,        K13,        K14,        KC_MINS,    KC_4,       KC_5,       KC_6,       KC_PLUS,    K15,        K16,        K17,        K18,        K19,       \
        K20,        K21,        K22,        K23,        K24,        KC_MINS,    KC_1,       KC_2,       KC_3,       KC_PLUS,    K25,        K26,        K27,        K28,        K29,       \
        XXX,        XXX,        K32,        K33,        K34,        XXX,        KC_DOT,     KC_0,       KC_EQL,     XXX,        K35,        K36,        K37,        XXX,        XXX        \
        )

        #define MIRYOKU_LAYERMAPPING_TAP(\
        K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09,\
        K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19,\
        K20, K21, K22, K23, K24,                          K25, K26, K27, K28, K29,\
        N30, N31, K32, K33, K34,                          K35, K36, K37, N38, N39\
        )\
        LAYOUT_ortho_5x15(\
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      TD(TD_DM1), DM_RSTP,    TD(TD_DM2), KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,    \
        K00,        K01,        K02,        K03,        K04,        KC_SLSH,    KC_7,       KC_8,       KC_9,       KC_ASTR,    K05,        K06,        K07,        K08,        K09,       \
        K10,        K11,        K12,        K13,        K14,        KC_MINS,    KC_4,       KC_5,       KC_6,       KC_PLUS,    K15,        K16,        K17,        K18,        K19,       \
        K20,        K21,        K22,        K23,        K24,        KC_MINS,    KC_1,       KC_2,       KC_3,       KC_PLUS,    K25,        K26,        K27,        K28,        K29,       \
        XXX,        XXX,        K32,        K33,        K34,        XXX,        KC_DOT,     KC_0,       KC_EQL,     XXX,        K35,        K36,        K37,        XXX,        XXX        \
        )

    #endif

#endif

// Redefine the base and extra layers
// - Remove the mod/layer tap keys in the home and bottom rows

#define MIRYOKU_LAYER_BASE \
KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              \
KC_A,              KC_S,              KC_D,              KC_F,              KC_G,              KC_H,              KC_J,              KC_K,              KC_L,              KC_QUOT,           \
KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,           \
U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,              U_NP

#define MIRYOKU_LAYER_EXTRA \
KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
KC_A,              KC_R,              KC_S,              KC_T,              KC_G,              KC_M,              KC_N,              KC_E,              KC_I,              KC_O,              \
KC_Z,              KC_X,              KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           KC_DOT,            KC_SLSH,           \
U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,              U_NP

// Redefine all non-alpha layers:
// - Replace the KC_ALGR on the next outermost column of the bottom row to U_NA

// Redefine the num layer:
// - Rearrange symbols to fit my use case

#define MIRYOKU_LAYER_NUM \
KC_PERC,           KC_7,              KC_8,              KC_9,              KC_HASH,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_GRV,            KC_4,              KC_5,              KC_6,              KC_PLUS,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_QUES,           KC_1,              KC_2,              KC_3,              KC_ASTR,           U_NA,              TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    U_NA,              U_NA,              \
U_NP,              U_NP,              KC_DOT,            KC_0,              KC_MINS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

// Redefine the sym layer:
// - Rearrange symbols to fit my use case

#define MIRYOKU_LAYER_SYM \
KC_CIRC,           KC_LBRC,           KC_AMPR,           KC_PIPE,           KC_RBRC,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_TILD,           KC_LCBR,           KC_LPRN,           KC_RPRN,           KC_RCBR,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_EXLM,           KC_LABK,           KC_MINS,           KC_EQL,            KC_RABK,           U_NA,              TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  U_NA,              U_NA,              \
U_NP,              U_NP,              KC_AT,             KC_DLR,            KC_UNDS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

// Redefine the function layer:

#define MIRYOKU_LAYER_FUN \
KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,           U_NA,              TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  U_NA,              U_NA,              \
U_NP,              U_NP,              KC_APP,            KC_SPC,            KC_TAB,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP

// Redefine the nav layer:
// - Replace the clipboard keys on the bottom row with xcase macro keys

#define MIRYOKU_LAYER_NAV \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              KC_INS,            KC_HOME,           KC_UP,             KC_END,            KC_PGUP,           \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              CW_TOGG,           KC_LEFT,           KC_DOWN,           KC_RGHT,           KC_PGDN,           \
U_NA,              U_NA,              TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    U_NA,              XC_CUSTOM,         XC_KC_UNDS,        XC_KC_MINS,        XC_KC_SLSH,        XC_KC_BSLS,        \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP

// Redefine the mouse layer:

#define MIRYOKU_LAYER_MOUSE \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_NU,              KC_WH_L,           KC_MS_U,           KC_WH_R,           KC_WH_U,           \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              U_NU,              KC_MS_L,           KC_MS_D,           KC_MS_R,           KC_WH_D,           \
U_NA,              U_NA,              TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP

// Redefine the media layer:
// - Swap around RGB keys and use a tap dance for specific RGB modes
// - Replace U_NU keys on the bottom row with dynamic tapping term keys

#define MIRYOKU_LAYER_MEDIA \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              RGB_TOG,           RGB_VAI,           KC_VOLU,           RGB_HUI,           RGB_SPI,           \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              TD(TD_RGB_MOD),    KC_MPRV,           KC_VOLD,           KC_MNXT,           RGB_SAI,           \
U_NA,              U_NA,              TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  U_NA,              RGB_MOD,           DT_DOWN,           DT_PRNT,           DT_UP,             U_NU,              \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE,           U_NP,              U_NP

// Enable hold on other key press
#define HOLD_ON_OTHER_KEY_PRESS

// Enable custom tapping term per key
#define TAPPING_TERM_PER_KEY

// Disable nesting of dynamic macros
#define DYNAMIC_MACRO_NO_NESTING

// Set the default xcase separator
#define DEFAULT_XCASE_SEPARATOR OSM(MOD_LSFT)

// Configure settings for Dalius-style one shot keys
#define FLOW_COUNT 16
#define FLOW_ONESHOT_WAIT_TERM 1000
#define FLOW_ONESHOT_TERM 2000

// Configure settings for custom shift keys
#define CUSTOM_SHIFT_KEYS_NEGMODS ~MOD_MASK_SHIFT
