#include QMK_KEYBOARD_H

enum layers {
	_BASE,
	_NAV,
	_MOD,
	_MEDIA,
	_NUM,
	_SYM,
	_FUN,
};

// clang-format off
#define MEDIA_ESC   LT(_MEDIA, KC_ESC)
#define NAV_SPC     LT(_NAV, KC_SPC)
#define FN_DEL      LT(_FUN, KC_DEL)
#define SYM_ENT     LT(_SYM, KC_ENT)
#define NUM_BSCP    LT(_NUM, KC_BSPC)
#define MOD_TAB     LT(_MOD, KC_TAB)
// clang-format on

#define O_LSFT OSM(MOD_LSFT)
#define O_LGUI OSM(MOD_LGUI)
#define O_RALT OSM(MOD_RALT)
#define O_LCTL OSM(MOD_LCTL)
#define O_LALT OSM(MOD_LALT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
        _______,   KC_Q,     KC_W,    KC_F,   KC_P,  KC_B,               KC_J,  KC_L,  KC_U,     KC_Y,      KC_QUOT,  _______,
        KC_LSFT,   KC_A,     KC_R,    KC_S,   KC_T,  KC_G,               KC_M,  KC_N,  KC_E,     KC_I,      KC_O,     KC_LSFT,
        _______, KC_Z,     KC_X,    KC_C,   KC_D,  KC_V,               KC_K,  KC_H,  KC_COMM,  KC_DOT,    KC_SLSH,  _______,
                             MEDIA_ESC, NAV_SPC, MOD_TAB,               SYM_ENT, NUM_BSCP, FN_DEL
    ),
    [_NAV] = LAYOUT_split_3x6_3(
        _______,  _______,  _______,  _______,  _______,  _______,       KC_AGIN,  KC_PSTE,  KC_COPY,  KC_CUT,   KC_UNDO,  _______,
        KC_LSFT,  KC_LGUI,  KC_LALT,  KC_LCTL,  _______,  _______,       KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  CW_TOGG,  KC_LSFT,
        _______,  _______,  KC_ALGR,  _______,  _______,  _______,       _______,   KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______,
                                      _______,  _______,  _______,       KC_ENT,   KC_BSPC,  KC_DEL
    ),
    [_MOD] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______,
        O_LSFT,  O_LGUI,  O_LALT,  O_LCTL,  _______, _______,            _______, _______, O_LCTL,  O_LALT,  O_LGUI,  O_LSFT,
        _______, _______, O_RALT,  _______, _______, _______,            _______, _______, _______, O_RALT,  _______,  _______,
                                   KC_ESC,  KC_SPC,  KC_TAB,             KC_ENT, KC_BSPC, KC_DEL
    ),
    [_MEDIA] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,            RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG, _______,
        KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, _______, _______,            _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_LSFT,
        _______, _______, KC_ALGR, _______, _______, _______,            _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______,            KC_MSTP, KC_MPLY, _______
    ),
    [_NUM] = LAYOUT_split_3x6_3(
        _______, KC_LBRC, KC_7,  KC_8, KC_9, KC_RBRC,                    _______, _______, _______, _______, _______, _______,
        KC_LSFT, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,                      _______, _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,
        _______, KC_GRV, KC_1, KC_2, KC_3, KC_BSLS,                      _______, _______, _______, KC_ALGR, _______, _______,
                             KC_DOT, KC_0, KC_MINS,                      _______, _______, _______
    ),
    [_SYM] = LAYOUT_split_3x6_3(
        _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,            _______, _______, _______, _______, _______, _______,
        KC_LSFT, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,            _______, _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,
        _______, KC_TILD, KC_EXLM, KC_AT, KC_HASH,   KC_PIPE,            _______, _______, _______, KC_ALGR, _______, _______,
                                   KC_LPRN, KC_RPRN, KC_UNDS,            _______, _______, _______
    ),
    [_FUN] = LAYOUT_split_3x6_3(
        _______, KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,                   _______, _______, _______, _______, _______, _______,
        KC_LSFT, KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,                   _______, _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,
        _______, KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,                   _______, _______, _______, KC_ALGR, _______, _______,
                               KC_APP, KC_SPC, KC_TAB,                   _______, _______, _______
    )
};
// clang-format on
const key_override_t capsword_key_override =
	ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);
const key_override_t *key_overrides[] = {&capsword_key_override};

// custom tapping term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	case MOD_TAB:
		return 115;
	default:
		return TAPPING_TERM;
	}
}

// clang-format off
#define LED_INTENSITY      0x08
#define RGB_DARK_CYAN      0x00, LED_INTENSITY, LED_INTENSITY
#define RGB_DARK_MAGENTA   LED_INTENSITY, 0x00, LED_INTENSITY
#define RGB_DARK_PURPLE    LED_INTENSITY, 0x00, 0x40
#define RGB_DARK_WHITE     LED_INTENSITY, LED_INTENSITY, LED_INTENSITY

/*
    SplitKB Aurora Corne schematic, under: ../../schematic/ (goto file)
*/

#define LED_SW21_LEFT      g_led_config.matrix_co[3][0]
#define LED_SW20_LEFT      g_led_config.matrix_co[3][1]
#define LED_SW19_LEFT      g_led_config.matrix_co[3][2]

#define LED_SW21_RIGHT     g_led_config.matrix_co[7][0]
#define LED_SW20_RIGHT     g_led_config.matrix_co[7][1]
#define LED_SW19_RIGHT     g_led_config.matrix_co[7][2]

#define LED_SW06_LEFT      g_led_config.matrix_co[0][0]
#define LED_SW12_LEFT      g_led_config.matrix_co[1][0]
#define LED_SW18_LEFT      g_led_config.matrix_co[2][0]

#define LED_SW06_RIGHT     g_led_config.matrix_co[4][0]
#define LED_SW12_RIGHT     g_led_config.matrix_co[5][0]
#define LED_SW18_RIGHT     g_led_config.matrix_co[6][0]

#define NON_THUMB_KEY_ROWS               3
// clang-format on

void set_thumb_keys(void) {
	rgb_matrix_set_color(LED_SW20_LEFT, RGB_DARK_WHITE);
	rgb_matrix_set_color(LED_SW20_RIGHT, RGB_DARK_WHITE);

	rgb_matrix_set_color(LED_SW21_RIGHT, RGB_DARK_WHITE);
	rgb_matrix_set_color(LED_SW21_LEFT, RGB_DARK_WHITE);

	if (get_highest_layer(layer_state) == _MOD) {
		rgb_matrix_set_color(LED_SW19_LEFT, RGB_DARK_PURPLE);
		rgb_matrix_set_color(LED_SW19_RIGHT, RGB_DARK_PURPLE);
	} else {
		rgb_matrix_set_color(LED_SW19_LEFT, RGB_DARK_MAGENTA);
		rgb_matrix_set_color(LED_SW19_RIGHT, RGB_DARK_MAGENTA);
	}
}

void set_underglow(uint8_t column) {
	rgb_matrix_set_color(column, RGB_DARK_CYAN); // UNDERGLOW LEDs
	rgb_matrix_set_color(column + 27, RGB_DARK_CYAN);
}


uint8_t matrix_config(uint8_t i, uint8_t j) {
	return g_led_config.matrix_co[i][j];
}

void set_keylight(uint8_t row, uint8_t column) {
	rgb_matrix_set_color(matrix_config(row, column), RGB_DARK_CYAN);
	rgb_matrix_set_color(matrix_config(row + 4, column), RGB_DARK_CYAN);
}

bool rgb_matrix_indicators_kb(void) {
	for (uint8_t i = 0; i < NON_THUMB_KEY_ROWS; i++) {
		for (uint8_t j = 0; j < MATRIX_COLS; j++) {
			set_underglow(j);
			set_keylight(i, j);
		}
	}
	set_thumb_keys();
	return true;
}
