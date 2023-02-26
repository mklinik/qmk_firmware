/* Copyright 2015 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "analog.h"

static uint8_t aref = ADC_REF_POWER;

void analogReference(uint8_t mode) {
}

int16_t analogReadPin(pin_t pin) {
    return 0;
}

uint8_t pinToMux(pin_t pin) {
    return 0;
}

int16_t adc_read(uint8_t mux) {
    return 0;
}
