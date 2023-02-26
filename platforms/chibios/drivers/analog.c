/* Copyright 2019 Drew Mills
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
#include <ch.h>
#include <hal.h>

// clang-format off
__attribute__((weak)) adc_mux pinToMux(pin_t pin) {
    // return an adc that would never be used so intToADCDriver will bail out
    return TO_MUX(0, 0xFF);
}

int16_t analogReadPin(pin_t pin) {
    return 0;
}

int16_t analogReadPinAdc(pin_t pin, uint8_t adc) {
    return 0;
}

int16_t adc_read(adc_mux mux) {
    return 0;
}
