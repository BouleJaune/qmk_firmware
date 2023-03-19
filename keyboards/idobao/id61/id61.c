// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "id61.h"

#define __ NO_LED

#if defined(RGB_MATRIX_ENABLE)

/* Pre-key
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │60 │59 │58 │57 │56 │55 │54 │53 │52 │51 │50 │49 │48 │  47   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │ 46  │45 │44 │43 │42 │41 │40 │39 │38 │37 │36 │35 │34 │ 33  │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │  32  │31 │30 │29 │28 │27 │26 │25 │24 │23 │22 │21 │   20   │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
 * │   19   │18 │17 │16 │15 │14 │13 │12 │11 │10 │ 9 │    8     │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │ 7  │ 6  │ 5  │            4           │ 3  │ 2  │ 1  │ 0  │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 *
 * Underglow (from top / [Esc] = top left)
 * ┌────┬────┬────┬────┬────┐
 * │ 61 │ 62 │ 63 │ 64 │ 65 │
 * ├────┴────┴────┴────┴────┤
 * ├────┬────┬────┬────┬────┤
 * │ 70 │ 69 │ 68 │ 67 │ 66 │
 * └────┴────┴────┴────┴────┘
 */

led_config_t g_led_config = { {
    // Key Matrix to LED Index
    { 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47 },
    { 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33 },
    { 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, __ },
    { 19, __, 18, 17, 16, 15, 14, 13, 12, 11, 10,  9,  8, __ },
    {  7,  6,  5, __, __, __,  4, __, __, __,  3,  2,  1,  0 },
}, {
    // LED Index to Physical Position
    // generated from: https://xelus.netlify.app/guides/KLE_to_RGB_parser
    /* NB: Reverse order! */
    {224,64 }, {204,64 }, {184,64 }, {163,64 },                                  {103,64 },                                  { 42,64 }, { 22,64 }, {  2,64 },
    {212,48 },            {182,48 }, {165,48 }, {149,48 }, {133,48 }, {117,48 }, {101,48 }, { 85,48 }, { 69,48 }, { 52,48 }, { 36,48 }, { 10,48 },
    {216,32 }, {190,32 }, {174,32 }, {157,32 }, {141,32 }, {125,32 }, {109,32 }, { 93,32 }, { 77,32 }, { 61,32 }, { 44,32 }, { 28,32 }, {  6,32 },
    {222,16 }, {202,16 }, {186,16 }, {170,16 }, {153,16 }, {137,16 }, {121,16 }, {105,16 }, { 89,16 }, { 73,16 }, { 57,16 }, { 40,16 }, { 24,16 }, {  4,16 },
    {218,0  }, {194,0  }, {178,0  }, {161,0  }, {145,0  }, {129,0  }, {113,0  }, { 97,0  }, { 81,0  }, { 65,0  }, { 48,0  }, { 32,0  }, { 16,0  }, {  0,0  }
    // underglow LEDs (positions pushed to nearest edge to match edge key colors)
    #ifndef ID61_DISABLE_UNDERGLOW
    , {  0,0  }, { 56,0  }, { 112,0  }, {168,0  }, {224,0  },
    {224,64 }, {168,64 }, {112,64 }, { 56,64 }, { 0,64 }
    #endif
}, {
    // LED Index to Flag
    /* NB: Reverse order! */
    1, 1, 1, 1,          4,          1, 1, 1,
    1,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 9,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
    // underglow LEDs
    #ifndef ID61_DISABLE_UNDERGLOW
    , 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2
    #endif
} };

#endif  // RGB_MATRIX_ENABLE
