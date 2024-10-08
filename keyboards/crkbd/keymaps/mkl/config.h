/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

//#define MASTER_LEFT
#define MASTER_RIGHT
// take handedness from an EEPROM setting
// #define EE_HANDS
// someone said this might help with boot hang problem, but for some reason it swaps sides, the left
// side is always the right side and vice versa
//#define SPLIT_USB_DETECT
// Trying again to fix the boot hang problem
#define NO_USB_STARTUP_CHECK

// https://precondition.github.io/home-row-mods

// don't auto-repeat when tap-holding a home row mod
#define TAPPING_FORCE_HOLD

#define TAPPING_TERM 180

//#define PERMISSIVE_HOLD

// only activate the hold action after the TAPPING_TERM, never on interrupt
#define IGNORE_MOD_TAP_INTERRUPT

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// for gaming
#define TAP_CODE_DELAY 20
