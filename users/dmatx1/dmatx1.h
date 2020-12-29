#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

#define KC_LMON SGUI(KC_LEFT)
#define KC_RMON SGUI(KC_RGHT)
#define KC_CPUP LCTL(KC_PGUP)
#define KC_CPDN RCTL(KC_PGDN)
#define KC_SDEL LSFT(KC_DEL)
#define KC_ALFT LALT(KC_LEFT)
#define KC_ARGH LALT(KC_RGHT)

enum custom_keycodes
{
  SL_FIRST = SAFE_RANGE,
  SL_GRV, SL_1, SL_2, SL_3, SL_4, SL_5, SL_6, SL_7, SL_8, SL_9, SL_0, SL_MINS, SL_EQL,
  SL_LBRC, SL_RBRC,
  SL_SCLN, SL_QUOT, SL_NUHS,
  SL_NUBS, SL_COMM, SL_DOT, SL_SLSH,

  SL_LAST,
};

bool secondary_layout_process_record_user(uint16_t keycode, keyrecord_t *record);

#endif
