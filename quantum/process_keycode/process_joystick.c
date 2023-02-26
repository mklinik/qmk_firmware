#include "joystick.h"
#include "process_joystick.h"

#include "analog.h"

#include <string.h>
#include <math.h>

bool process_joystick(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case JS_BUTTON0 ... JS_BUTTON_MAX:
            if (record->event.pressed) {
                register_joystick_button(keycode - JS_BUTTON0);
            } else {
                unregister_joystick_button(keycode - JS_BUTTON0);
            }
            return false;
    }
    return true;
}

__attribute__((weak)) void joystick_task(void) {
    if (process_joystick_analogread()) {
        joystick_flush();
    }
}

uint16_t savePinState(pin_t pin) {
    return 0;
}

void restorePinState(pin_t pin, uint16_t restoreState) {
    return;
}

__attribute__((weak)) bool process_joystick_analogread() {
    return process_joystick_analogread_quantum();
}

bool process_joystick_analogread_quantum() {
#if JOYSTICK_AXES_COUNT > 0
    for (int axis_index = 0; axis_index < JOYSTICK_AXES_COUNT; ++axis_index) {
        if (joystick_axes[axis_index].input_pin == JS_VIRTUAL_AXIS) {
            continue;
        }

        // save previous input pin status as well
        uint16_t inputSavedState = savePinState(joystick_axes[axis_index].input_pin);

        // disable pull-up resistor
        writePinLow(joystick_axes[axis_index].input_pin);

        // if pin was a pull-up input, we need to uncharge it by turning it low
        // before making it a low input
        setPinOutput(joystick_axes[axis_index].input_pin);

        wait_us(10);

        // save and apply output pin status
        uint16_t outputSavedState = 0;
        if (joystick_axes[axis_index].output_pin != JS_VIRTUAL_AXIS) {
            // save previous output pin status
            outputSavedState = savePinState(joystick_axes[axis_index].output_pin);

            setPinOutput(joystick_axes[axis_index].output_pin);
            writePinHigh(joystick_axes[axis_index].output_pin);
        }

        uint16_t groundSavedState = 0;
        if (joystick_axes[axis_index].ground_pin != JS_VIRTUAL_AXIS) {
            // save previous output pin status
            groundSavedState = savePinState(joystick_axes[axis_index].ground_pin);

            setPinOutput(joystick_axes[axis_index].ground_pin);
            writePinLow(joystick_axes[axis_index].ground_pin);
        }

        wait_us(10);

        setPinInput(joystick_axes[axis_index].input_pin);

        wait_us(10);

#    if defined(ANALOG_JOYSTICK_ENABLE) && (defined(__AVR__) || defined(PROTOCOL_CHIBIOS))
        int16_t axis_val = analogReadPin(joystick_axes[axis_index].input_pin);
#    else
        // default to resting position
        int16_t axis_val = joystick_axes[axis_index].mid_digit;
#    endif

        // test the converted value against the lower range
        int32_t ref        = joystick_axes[axis_index].mid_digit;
        int32_t range      = joystick_axes[axis_index].min_digit;
        int32_t ranged_val = ((axis_val - ref) * -JOYSTICK_RESOLUTION) / (range - ref);

        if (ranged_val > 0) {
            // the value is in the higher range
            range      = joystick_axes[axis_index].max_digit;
            ranged_val = ((axis_val - ref) * JOYSTICK_RESOLUTION) / (range - ref);
        }

        // clamp the result in the valid range
        ranged_val = ranged_val < -JOYSTICK_RESOLUTION ? -JOYSTICK_RESOLUTION : ranged_val;
        ranged_val = ranged_val > JOYSTICK_RESOLUTION ? JOYSTICK_RESOLUTION : ranged_val;

        if (ranged_val != joystick_status.axes[axis_index]) {
            joystick_status.axes[axis_index] = ranged_val;
            joystick_status.status |= JS_UPDATED;
        }

        // restore output, ground and input status
        if (joystick_axes[axis_index].output_pin != JS_VIRTUAL_AXIS) {
            restorePinState(joystick_axes[axis_index].output_pin, outputSavedState);
        }
        if (joystick_axes[axis_index].ground_pin != JS_VIRTUAL_AXIS) {
            restorePinState(joystick_axes[axis_index].ground_pin, groundSavedState);
        }

        restorePinState(joystick_axes[axis_index].input_pin, inputSavedState);
    }

#endif
    return true;
}
