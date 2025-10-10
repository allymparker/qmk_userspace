
// Tap Dance declarations
enum {
    TD_MAX_KEYS,
    TD_WIN_RIGHT
};

// Tap Dance definitions
void tapdance_maximise(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(KC_F18);
            break;
        case 2:
            tap_code16(KC_F20);
            break;
        case 3:
            tap_code16(KC_F21);
            reset_tap_dance(state);
            break;
        default:
            reset_tap_dance(state);
            break;
    }
}

void tapdance_win_right(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(KC_F19);
            break;
        case 2:
            tap_code16(MEH(KC_F19));
            break;
        default:
            reset_tap_dance(state);
            break;
    }
}


tap_dance_action_t tap_dance_actions[] = {
    [TD_MAX_KEYS] = ACTION_TAP_DANCE_FN(tapdance_maximise),
    [TD_WIN_RIGHT] = ACTION_TAP_DANCE_FN(tapdance_win_right),
};

#define TD_MAX TD(TD_MAX_KEYS)
#define TD_WIN_RIGHT TD(TD_WIN_RIGHT)