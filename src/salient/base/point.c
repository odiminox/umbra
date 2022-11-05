/* BSD 3-Clause License
 *
 * Copyright © 2008-2022, Jice, Odiminox and the salient contributors.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "point.h"

void SALIENT_point_set(int x, int y, SALIENT_points_data_t* data) {
  data->x = x;
  data->y = y;
}

bool SALIENT_point_is_xy(int x, int y, SALIENT_points_data_t* data) { return ((data->x == x) && (data->y == y)); }

bool SALIENT_point_is_point(SALIENT_points_data_t* point, SALIENT_points_data_t* data) { return &point == &data; }

void SALIENT_point_mouse_xy(int x, int y, TCOD_mouse_t* ms, SALIENT_points_data_t* data) {
  data->mouse_hover = SALIENT_point_is(x, y, data);
  data->mouse_down = data->mouse_hover & ms->lbutton;
}
void SALIENT_point_mouse_point(SALIENT_points_data_t* point, TCOD_mouse_t* ms, SALIENT_points_data_t* data) {
  data->mouse_hover = SALIENT_point_is(point);
  data->mouse_down = data->mouse_hover = ms->lbutton;
}
