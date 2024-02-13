// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#define XXX KC_NO

// Redefine the base, extra and tap layers:
// * Add an app launcher key with tap dance guard

#if defined MIRYOKU_MAPPING_EXTENDED_THUMBS

    #if defined KEYBOARD_ymdk_id75

        #define MIRYOKU_LAYERMAPPING_BASE(\
        K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09,\
        K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19,\
        K20, K21, K22, K23, K24,                          K25, K26, K27, K28, K29,\
        N30, N31, K32, K33, K34,                          K35, K36, K37, N38, N39\
        )\
        LAYOUT_ortho_5x15(\
        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,       \
        K00,        K01,        K02,        K03,        K04,        XXX,        XXX,        XXX,        XXX,        XXX,        K05,        K06,        K07,        K08,        K09,       \
        K10,        K11,        K12,        K13,        K14,        XXX,        XXX,        XXX,        XXX,        XXX,        K15,        K16,        K17,        K18,        K19,       \
        K20,        K21,        K22,        K23,        K24,        XXX,        XXX,        XXX,        XXX,        XXX,        K25,        K26,        K27,        K28,        K29,       \
        TD(TD_APP), XXX,        XXX,        K32,        K33,        K34,        XXX,        XXX,        XXX,        K35,        K36,        K37,        XXX,        XXX,        TD(TD_APP) \
        )

        #define MIRYOKU_LAYERMAPPING_EXTRA(\
        K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09,\
        K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19,\
        K20, K21, K22, K23, K24,                          K25, K26, K27, K28, K29,\
        N30, N31, K32, K33, K34,                          K35, K36, K37, N38, N39\
        )\
        LAYOUT_ortho_5x15(\
        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,       \
        K00,        K01,        K02,        K03,        K04,        XXX,        XXX,        XXX,        XXX,        XXX,        K05,        K06,        K07,        K08,        K09,       \
        K10,        K11,        K12,        K13,        K14,        XXX,        XXX,        XXX,        XXX,        XXX,        K15,        K16,        K17,        K18,        K19,       \
        K20,        K21,        K22,        K23,        K24,        XXX,        XXX,        XXX,        XXX,        XXX,        K25,        K26,        K27,        K28,        K29,       \
        TD(TD_APP), XXX,        XXX,        K32,        K33,        K34,        XXX,        XXX,        XXX,        K35,        K36,        K37,        XXX,        XXX,        TD(TD_APP) \
        )

        #define MIRYOKU_LAYERMAPPING_TAP(\
        K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09,\
        K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19,\
        K20, K21, K22, K23, K24,                          K25, K26, K27, K28, K29,\
        N30, N31, K32, K33, K34,                          K35, K36, K37, N38, N39\
        )\
        LAYOUT_ortho_5x15(\
        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,       \
        K00,        K01,        K02,        K03,        K04,        XXX,        XXX,        XXX,        XXX,        XXX,        K05,        K06,        K07,        K08,        K09,       \
        K10,        K11,        K12,        K13,        K14,        XXX,        XXX,        XXX,        XXX,        XXX,        K15,        K16,        K17,        K18,        K19,       \
        K20,        K21,        K22,        K23,        K24,        XXX,        XXX,        XXX,        XXX,        XXX,        K25,        K26,        K27,        K28,        K29,       \
        TD(TD_APP), XXX,        XXX,        K32,        K33,        K34,        XXX,        XXX,        XXX,        K35,        K36,        K37,        XXX,        XXX,        TD(TD_APP) \
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
        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,       \
        K00,        K01,        K02,        K03,        K04,        XXX,        XXX,        XXX,        XXX,        XXX,        K05,        K06,        K07,        K08,        K09,       \
        K10,        K11,        K12,        K13,        K14,        XXX,        XXX,        XXX,        XXX,        XXX,        K15,        K16,        K17,        K18,        K19,       \
        K20,        K21,        K22,        K23,        K24,        XXX,        XXX,        XXX,        XXX,        XXX,        K25,        K26,        K27,        K28,        K29,       \
        TD(TD_APP), XXX,        K32,        K33,        K34,        XXX,        XXX,        XXX,        XXX,        XXX,        K35,        K36,        K37,        XXX,        TD(TD_APP) \
        )

        #define MIRYOKU_LAYERMAPPING_EXTRA(\
        K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09,\
        K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19,\
        K20, K21, K22, K23, K24,                          K25, K26, K27, K28, K29,\
        N30, N31, K32, K33, K34,                          K35, K36, K37, N38, N39\
        )\
        LAYOUT_ortho_5x15(\
        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,       \
        K00,        K01,        K02,        K03,        K04,        XXX,        XXX,        XXX,        XXX,        XXX,        K05,        K06,        K07,        K08,        K09,       \
        K10,        K11,        K12,        K13,        K14,        XXX,        XXX,        XXX,        XXX,        XXX,        K15,        K16,        K17,        K18,        K19,       \
        K20,        K21,        K22,        K23,        K24,        XXX,        XXX,        XXX,        XXX,        XXX,        K25,        K26,        K27,        K28,        K29,       \
        TD(TD_APP), XXX,        K32,        K33,        K34,        XXX,        XXX,        XXX,        XXX,        XXX,        K35,        K36,        K37,        XXX,        TD(TD_APP) \
        )

        #define MIRYOKU_LAYERMAPPING_TAP(\
        K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09,\
        K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19,\
        K20, K21, K22, K23, K24,                          K25, K26, K27, K28, K29,\
        N30, N31, K32, K33, K34,                          K35, K36, K37, N38, N39\
        )\
        LAYOUT_ortho_5x15(\
        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,        XXX,       \
        K00,        K01,        K02,        K03,        K04,        XXX,        XXX,        XXX,        XXX,        XXX,        K05,        K06,        K07,        K08,        K09,       \
        K10,        K11,        K12,        K13,        K14,        XXX,        XXX,        XXX,        XXX,        XXX,        K15,        K16,        K17,        K18,        K19,       \
        K20,        K21,        K22,        K23,        K24,        XXX,        XXX,        XXX,        XXX,        XXX,        K25,        K26,        K27,        K28,        K29,       \
        TD(TD_APP), XXX,        K32,        K33,        K34,        XXX,        XXX,        XXX,        XXX,        XXX,        K35,        K36,        K37,        XXX,        TD(TD_APP) \
        )

    #endif

#endif

// Redefine the num layer:
// * Rearrange symbols to fit my use case

#define MIRYOKU_LAYER_NUM \
KC_PERC,           KC_7,              KC_8,              KC_9,              KC_HASH,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_GRV,            KC_4,              KC_5,              KC_6,              KC_PLUS,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_QUES,           KC_1,              KC_2,              KC_3,              KC_ASTR,           U_NA,              TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    KC_ALGR,           U_NA,              \
U_NP,              U_NP,              KC_DOT,            KC_0,              KC_MINS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

// Redefine the sym layer:
// * Rearrange symbols to fit my use case

#define MIRYOKU_LAYER_SYM \
KC_CIRC,           KC_LBRC,           KC_AMPR,           KC_PIPE,           KC_RBRC,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_TILD,           KC_LCBR,           KC_LPRN,           KC_RPRN,           KC_RCBR,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_EXLM,           KC_LABK,           KC_MINS,           KC_EQL,            KC_RABK,           U_NA,              TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  KC_ALGR,           U_NA,              \
U_NP,              U_NP,              KC_AT,             KC_DLR,            KC_UNDS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

// Redefine the nav layer:
// * Replace the clipboard keys in the lower third row to xcase macro keys

#define MIRYOKU_LAYER_NAV \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              KC_INS,            KC_HOME,           KC_UP,             KC_END,            KC_PGUP,           \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              CW_TOGG,           KC_LEFT,           KC_DOWN,           KC_RGHT,           KC_PGDN,           \
U_NA,              KC_ALGR,           TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    U_NA,              XC_CUSTOM,         XC_KC_UNDS,        XC_KC_MINS,        XC_KC_SLSH,        XC_KC_BSLS,        \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP

// Redefine the media layer:
// * Swap around RGB keys and use a tap dance for specific RGB modes
// * Replace U_NU keys in the lower third row to dynamic tapping term keys

#define MIRYOKU_LAYER_MEDIA \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              RGB_TOG,           RGB_VAI,           KC_VOLU,           RGB_HUI,           RGB_SPI,           \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              TD(TD_RGB_MOD),    KC_MPRV,           KC_VOLD,           KC_MNXT,           RGB_SAI,           \
U_NA,              KC_ALGR,           TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  U_NA,              RGB_MOD,           DT_DOWN,           DT_PRNT,           DT_UP,             U_NU,              \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE,           U_NP,              U_NP

// Enable permissive hold
#define PERMISSIVE_HOLD

// Enable typing streak detection
#define ACHORDION_STREAK

// Set the default xcase separator
#define DEFAULT_XCASE_SEPARATOR OSM(MOD_LSFT)
