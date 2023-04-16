// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "quantum_keycodes.h"
#include <stdio.h>

enum custom_keycodes {
    REV_S_DOT = QK_USER,
    REV_S_COMM,
    REV_S_SLSH,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case REV_S_COMM:
        if (record->event.pressed) {
            if (get_mods() && MOD_BIT(KC_LSFT)) {
                unregister_code(KC_LSFT);
                register_code(KC_SLSH);
                unregister_code(KC_SLSH);
                register_code(KC_LSFT);
                return false;
            } else {
                register_code(KC_LSFT);
                register_code(KC_COMM);
                unregister_code(KC_COMM);
                unregister_code(KC_LSFT);
                return false;
            }
        }
        break;

    case REV_S_SLSH:
        if (record->event.pressed) {
            register_code(KC_COMM);
            unregister_code(KC_COMM);
            return false;
        }
        break;

    case REV_S_DOT:
        if (record->event.pressed) {
            register_code(KC_DOT);
            unregister_code(KC_DOT);
            return false;
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM tab[] = {REV_S_COMM,  KC_SCLN, COMBO_END};
// const uint16_t PROGMEM bsp[] = {KC_J,  KC_H, COMBO_END};
const uint16_t PROGMEM ent[] = {KC_X,  KC_C, COMBO_END};
const uint16_t PROGMEM quote[] = {KC_J,  KC_H, COMBO_END};
const uint16_t PROGMEM doublequote[] = {KC_J,  KC_H, COMBO_END};
const uint16_t PROGMEM esc[] = {REV_S_COMM, REV_S_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(tab, KC_TAB),
    // COMBO(bsp, KC_BSPC),
    COMBO(ent, KC_ENT),
    COMBO(quote, KC_4),
    COMBO(doublequote, KC_3),
    COMBO(esc, KC_ESC),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//   base layer
  [0] = LAYOUT_split_3x5_2(
       KC_A,    KC_Z,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_M,
        MT(MOD_LGUI, KC_Q),    MT(MOD_LALT, KC_R),    MT(MOD_LCTL, KC_S),    MT(MOD_LSFT, KC_T),   KC_D,
       KC_H,    MT(MOD_RSFT, KC_N),    MT(MOD_RCTL, KC_E),    MT(MOD_LALT, KC_I),  MT(MOD_LGUI, KC_O),
        KC_W,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    KC_SCLN, REV_S_COMM,  REV_S_DOT, REV_S_SLSH,
                              MO(1),  KC_SPC,            LT(4, KC_BSPC),   MO(2)

// LT(2, KC_ENT)
// LT(1, KC_ESC)
//   nav layer
  ), [1] = LAYOUT_split_3x5_2(
           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_QUOT,    KC_9,    KC_0,
           KC_Q,    KC_5,    KC_PERC,    KC_MINS,   KC_EQL,
                                 KC_ESC, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
      ALGR(KC_7), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, ALGR(KC_7), ALGR(KC_8), KC_4, KC_3,
                                           _______,  KC_SPC,     KC_BSPC, XXXXXXX
  ),

//   num layer
  [2] = LAYOUT_split_3x5_2(
       RALT(KC_5),   KC_AMPR, KC_ASTR,  KC_LPRN, RALT(KC_MINS),                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_Q,    KC_DLR,    KC_PERC,    KC_CIRC,   KC_EQL,
                                 KC_ESC, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
       KC_NUBS, KC_EXLM, KC_AT, KC_HASH, LSFT(KC_NUBS),                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                                             KC_RPRN,  KC_6,     KC_BSPC, _______
  ),

//   gaming layer
  [3] = LAYOUT_split_3x5_2(
           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
                                              TG(3),  KC_6,     KC_BSPC,   MO(2)
  ),

  // symboles layer
  [4] = LAYOUT_split_3x5_2(
        XXXXXXX,   KC_1, KC_BSLS,  KC_LPRN, KC_LBRC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_RBRC,    RALT(KC_4),    LSFT(KC_QUOT),    RALT(KC_EQL),   KC_PLUS,
                                                     KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
       RALT(KC_2), KC_SLSH, RALT(KC_0), RALT(KC_3), ALGR(KC_6),                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                                           KC_MINS,  KC_8,     KC_BSPC, _______
  ),

  // functions layer
  [5] = LAYOUT_split_3x5_2(
        KC_F12,  KC_F7, KC_F8, KC_F9, RALT(KC_EQL),                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_F11,   KC_F4,  KC_F5,  KC_F6,   KC_PLUS,
                                                     KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
       KC_F10, KC_F1, KC_F2, KC_F3, KC_F10,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                                             KC_MINS,  KC_8,     KC_BSPC, _______
  )
};

//Custom callback for caps words because colemak on software azerty
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
        case KC_SCLN:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

