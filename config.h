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

/* Select hand configuration */

#define MASTER_LEFT
// following is required to make sure the oleds work properly
#define SPLIT_WPM_ENABLE
// #define MASTER_RIGHT
// #define EE_HANDS

/* Defines for my tapping terms.  For the mods below the home row I am going to use
 * the default tapping term and set it a bit higher. Everything else will be
 * custom. */


/* The HOLD_ON_OTHER_KEY_PRESS option specifies it such that if one of my mod keys is held down
 * and I press another key, the hold function is selected, even if I haven't been holding it for
 * longer than the TAPPING_TERM. Can get more info at the documentation,
 *     https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md */

/* #define IGNORE_MOD_TAP_INTERRUPT */
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200

/* #define TAPPING_FORCE_HOLD */
/*#define HOLD_ON_OTHER_KEY_PRESS*/
/* #define IGNORE_MOD_TAP_INTERRUPT_PER_KEY */
