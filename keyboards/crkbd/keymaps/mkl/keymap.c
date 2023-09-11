/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

#define DEF 0 // default keyboardlayer
#define SYM 1 // symbols
#define NAV 2 // navigation
#define NUM 3 // numbers and some punctuation useful when typing numbers
#define FUN 4 // function keys, multimedia keys
#define GAM 5 // gaming layer, to be used as default
#define GA2 6 // gaming layer 2, to be used as temporary layer

// tab when tapped, SYM layer when held
#define TABSYM LT(SYM, KC_TAB)
// u when tapped, NAV layer when held
#define U_NAV LT(NAV, KC_U)
// space when tapped, NAV layer when held
#define SPCNAV LT(NAV, KC_SPC)
// esc when tapped, NUM layer when held
#define ESCNUM LT(NUM, KC_ESC)
// enter when tapped, FUN layer when held
#define ENTFUN LT(FUN, KC_ENT)

// home row mods, let's go
#define E_LSFT MT(MOD_LSFT, KC_E)
#define T_RSFT MT(MOD_RSFT, KC_T)
#define O_LCTL MT(MOD_LCTL, KC_O)
#define N_RCTL MT(MOD_RCTL, KC_N)
#define A_LALT MT(MOD_LALT, KC_A)
#define S_RALT MT(MOD_RALT, KC_S)

// for the gaming layer
#define S_LCTL MT(MOD_LCTL, KC_S)
#define D_LSFT MT(MOD_LSFT, KC_D)
#define ESC_SFT MT(MOD_LSFT, KC_ESC)
#define SPC_CTL MT(MOD_LCTL, KC_SPC)
#define TAB_ALT MT(MOD_LALT, KC_TAB)
#define TAB_GA2 LT(GA2, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEF] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   ,                      KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, A_LALT , O_LCTL , E_LSFT , U_NAV  , KC_I   ,                      KC_D   , KC_H   , T_RSFT , N_RCTL , S_RALT , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   ,                      KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, ESCNUM , TABSYM,     ENTFUN, SPCNAV , XXXXXXX
                                      //`--------------------------'  `--------------------------'

  ),

  [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_GRV , KC_LBRC, KC_RBRC, KC_EXLM, KC_QUES,                      XXXXXXX, KC_EQL , KC_LT  , KC_GT  , KC_BSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_TILD, KC_LPRN, KC_RPRN, KC_PIPE, KC_AMPR,                      KC_HASH, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_AT  , KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_CIRC, KC_UNDS, KC_PERC, KC_DLR , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,                      KC_BSPC, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, KC_COMM, KC_DOT , KC_SPC , XXXXXXX,                      XXXXXXX, XXXXXXX, KC_MINS, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, DF(GAM), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                      KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LALT, KC_LCTL, KC_DEL , XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_F12 , KC_F11 , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [GAM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(DEF), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                      XXXXXXX, XXXXXXX, KC_RSFT, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LALT , KC_SPC , KC_TAB ,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [GA2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_Y   , KC_U   , KC_J   , KC_O   , KC_P   ,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_H   , KC_I   , KC_K   , KC_L   , KC_SCLN,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

};
