#if defined(KEYBOARD_janus)

#define LED_RED   GP17
#define LED_GREEN GP16
#define LED_BLUE  GP25

/* LED Layer indicators */
void led_toggle(uint8_t id, bool on) {
	switch (id) {
		case 0:
			writePin(LED_RED, on);
			break;
		case 1:
			writePin(LED_GREEN, on);
			break;
		case 2:
			writePin(LED_BLUE, on);
			break;
		default:
			break;
	}
}

void set_layer_indicators(uint8_t layer) {
	switch (layer) {
		case _QWERTY:
			/* black */
			led_toggle(0, true);
			led_toggle(1, true);
			led_toggle(2, true);
			break;
		case _NUMBER:
			/* red */
			led_toggle(0, false);
			led_toggle(1, true);
			led_toggle(2, true);
			break;
		case _MOUSE:
			/* blue */
			led_toggle(0, true);
			led_toggle(1, true);
			led_toggle(2, false);
			break;
		case _NAV:
			/* green */
			led_toggle(0, true);
			led_toggle(1, false);
			led_toggle(2, true);
			break;
		case _FUNCT:
			/* yellow */
			led_toggle(0, false);
			led_toggle(1, false);
			led_toggle(2, true);
			break;
		case _MOD:
			/* cyan */
			led_toggle(0, true);
			led_toggle(1, false);
			led_toggle(2, false);
			break;
		default:
			/* white, should not happen */
			led_toggle(0, false);
			led_toggle(1, false);
			led_toggle(2, false);
			break;
	}
}

void led_init_ports(void) {
	// Initialize indicator LEDs to output
	setPinOutput(LED_RED);
	setPinOutput(LED_GREEN);
	setPinOutput(LED_BLUE);

	set_layer_indicators(0);
}

bool led_update_kb(led_t led_state) {
	bool res = led_update_user(led_state);
	return res;
}

layer_state_t layer_state_set_kb(layer_state_t state) {
	set_layer_indicators(get_highest_layer(state));

	return layer_state_set_user(state);
}

#endif
