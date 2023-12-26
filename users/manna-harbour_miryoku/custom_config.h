// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#define XXX KC_NO

// Redefine the base and extra layers

#if defined MIRYOKU_MAPPING_EXTENDED_THUMBS

#if defined KEYBOARD_ymdk_id75
#define MIRYOKU_LAYERMAPPING_BASE(\
K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09,\
K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19,\
K20, K21, K22, K23, K24,                          K25, K26, K27, K28, K29,\
N30, N31, K32, K33, K34,                          K35, K36, K37, N38, N39\
)\
LAYOUT_ortho_5x15(\
KC_LPRN, KC_LCBR, KC_LBRC, KC_LABK, XXX,     XXX,     TD(TD_DM1), DM_RSTP,  TD(TD_DM2), XXX,     XXX,     KC_RABK, KC_RBRC, KC_RCBR, KC_RPRN,  \
K00,     K01,     K02,     K03,     K04,     XXX,     CD_EQEQ,    CD_EQGT,  CD_NTEQ,    XXX,     K05,     K06,     K07,     K08,     K09,      \
K10,     K11,     K12,     K13,     K14,     XXX,     CD_ADAD,    CD_MUEQ,  CD_SUSU,    XXX,     K15,     K16,     K17,     K18,     K19,      \
K20,     K21,     K22,     K23,     K24,     XXX,     CD_ADEQ,    CD_DIEQ,  CD_SUEQ,    XXX,     K25,     K26,     K27,     K28,     K29,      \
XXX,     XXX,     LNC_ALT, K32,     K33,     K34,     XXX,        XXX,      XXX,        K35,     K36,     K37,     LNC_GUI, XXX,     XXX       \
)
#define MIRYOKU_LAYERMAPPING_EXTRA(\
K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09,\
K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19,\
K20, K21, K22, K23, K24,                          K25, K26, K27, K28, K29,\
N30, N31, K32, K33, K34,                          K35, K36, K37, N38, N39\
)\
LAYOUT_ortho_5x15(\
KC_LPRN, KC_LCBR, KC_LBRC, KC_LABK, XXX,     XXX,     TD(TD_DM1), DM_RSTP,  TD(TD_DM2), XXX,     XXX,     KC_RABK, KC_RBRC, KC_RCBR, KC_RPRN,  \
K00,     K01,     K02,     K03,     K04,     XXX,     CD_EQEQ,    CD_EQGT,  CD_NTEQ,    XXX,     K05,     K06,     K07,     K08,     K09,      \
K10,     K11,     K12,     K13,     K14,     XXX,     CD_ADAD,    CD_MUEQ,  CD_SUSU,    XXX,     K15,     K16,     K17,     K18,     K19,      \
K20,     K21,     K22,     K23,     K24,     XXX,     CD_ADEQ,    CD_DIEQ,  CD_SUEQ,    XXX,     K25,     K26,     K27,     K28,     K29,      \
XXX,     XXX,     LNC_ALT, K32,     K33,     K34,     XXX,        XXX,      XXX,        K35,     K36,     K37,     LNC_GUI, XXX,     XXX       \
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
KC_LPRN, KC_LCBR, KC_LBRC, KC_LABK, XXX,     XXX,     TD(TD_DM1), DM_RSTP,  TD(TD_DM2), XXX,     XXX,     KC_RABK, KC_RBRC, KC_RCBR, KC_RPRN,  \
K00,     K01,     K02,     K03,     K04,     XXX,     CD_EQEQ,    CD_EQGT,  CD_NTEQ,    XXX,     K05,     K06,     K07,     K08,     K09,      \
K10,     K11,     K12,     K13,     K14,     XXX,     CD_ADAD,    CD_MUEQ,  CD_SUSU,    XXX,     K15,     K16,     K17,     K18,     K19,      \
K20,     K21,     K22,     K23,     K24,     XXX,     CD_ADEQ,    CD_DIEQ,  CD_SUEQ,    XXX,     K25,     K26,     K27,     K28,     K29,      \
XXX,     LNC_ALT, K32,     K33,     K34,     XXX,     XXX,        XXX,      XXX,        XXX,     K35,     K36,     K37,     LNC_GUI, XXX       \
)
#define MIRYOKU_LAYERMAPPING_EXTRA(\
K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09,\
K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19,\
K20, K21, K22, K23, K24,                          K25, K26, K27, K28, K29,\
N30, N31, K32, K33, K34,                          K35, K36, K37, N38, N39\
)\
LAYOUT_ortho_5x15(\
KC_LPRN, KC_LCBR, KC_LBRC, KC_LABK, XXX,     XXX,     TD(TD_DM1), DM_RSTP,  TD(TD_DM2), XXX,     XXX,     KC_RABK, KC_RBRC, KC_RCBR, KC_RPRN,  \
K00,     K01,     K02,     K03,     K04,     XXX,     CD_EQEQ,    CD_EQGT,  CD_NTEQ,    XXX,     K05,     K06,     K07,     K08,     K09,      \
K10,     K11,     K12,     K13,     K14,     XXX,     CD_ADAD,    CD_MUEQ,  CD_SUSU,    XXX,     K15,     K16,     K17,     K18,     K19,      \
K20,     K21,     K22,     K23,     K24,     XXX,     CD_ADEQ,    CD_DIEQ,  CD_SUEQ,    XXX,     K25,     K26,     K27,     K28,     K29,      \
XXX,     LNC_ALT, K32,     K33,     K34,     XXX,     XXX,        XXX,      XXX,        XXX,     K35,     K36,     K37,     LNC_GUI, XXX       \
)
#endif

#endif

// Redefine the media layer:
// * Swap around and add other RGB keys
// * Replace U_NU below RGB_TOG to DT_PRNT

#define MIRYOKU_LAYER_MEDIA \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              RGB_TOG,           RGB_VAI,           KC_VOLU,           RGB_SAI,           RGB_HUI,           \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              DT_PRNT,           KC_MPRV,           KC_VOLD,           KC_MNXT,           RGB_SPI,           \
U_NA,              KC_ALGR,           TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  U_NA,              RGB_MOD,           RGB_M_P,           RGB_M_B,           RGB_M_R,           RGB_M_SW,          \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE,           U_NP,              U_NP

// Redefine the nav layer:
// * Change KC_INS to TD(TD_CM)
// * Change CW_TOGG to TD(TD_CWI)

#define MIRYOKU_LAYER_NAV \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              TD(TD_CM),         KC_HOME,           KC_UP,             KC_END,            KC_PGUP,           \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              TD(TD_CWI),        KC_LEFT,           KC_DOWN,           KC_RGHT,           KC_PGDN,           \
U_NA,              KC_ALGR,           TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP

// Disable nesting of dynamic macros
#define DYNAMIC_MACRO_NO_NESTING

// Enable bilateral combinations
#define BILATERAL_COMBINATIONS 500

// Enable permissive hold
#define PERMISSIVE_HOLD
