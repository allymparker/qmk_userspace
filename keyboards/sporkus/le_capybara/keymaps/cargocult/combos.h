enum combos {
  CB_SCRSHT,
  CB_JETBRAINS,
};

const uint16_t PROGMEM scrsht_combo[] = {MC_L, MC_SEMI, COMBO_END};
const uint16_t PROGMEM jetbrains_combo[] = {KC_V, KC_M, COMBO_END};

combo_t key_combos[] = {
  [CB_SCRSHT] = COMBO(scrsht_combo, MC_PSC),
  [CB_JETBRAINS] = COMBO(jetbrains_combo, OSL(JB)),
};