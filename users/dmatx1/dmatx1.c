#include "dmatx1.h"

static bool secondary_layout_left_shift_down = false;

const uint16_t secondary_layout_keycodes[] =
{
  KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,
  KC_LBRC, KC_RBRC,
  KC_SCLN, KC_QUOT, KC_NUHS,
  KC_NUBS, KC_COMM, KC_DOT, KC_SLSH,
};

uint16_t secondary_layout_map_keycode(uint16_t keycode)
{
  return secondary_layout_keycodes[keycode - SL_FIRST - 1];
}

void secondary_layout_register_code(uint16_t keycode)
{
  keycode = secondary_layout_map_keycode(keycode);

  if (secondary_layout_left_shift_down)
    unregister_code(KC_LSFT);

  register_code(KC_LALT);
  register_code(KC_LSFT);
  unregister_code(KC_LALT);
  unregister_code(KC_LSFT);

  if (secondary_layout_left_shift_down)
    register_code(KC_LSFT);

  register_code(keycode);
}

void secondary_layout_unregister_code(uint16_t keycode)
{
  keycode = secondary_layout_map_keycode(keycode);

  unregister_code(keycode);

  if (secondary_layout_left_shift_down)
    unregister_code(KC_LSFT);

  register_code(KC_LALT);
  register_code(KC_LSFT);
  unregister_code(KC_LALT);
  unregister_code(KC_LSFT);

  if (secondary_layout_left_shift_down)
    register_code(KC_LSFT);
}

bool secondary_layout_process_record_user(uint16_t keycode, keyrecord_t *record)
{
  if (keycode == KC_LSFT)
  {
    secondary_layout_left_shift_down = record->event.pressed;
  }
  else if (keycode > SL_FIRST && keycode < SL_LAST)
  {
    if (record->event.pressed)
      secondary_layout_register_code(keycode);
    else
      secondary_layout_unregister_code(keycode);
    return false;
  }
  return true;
}
