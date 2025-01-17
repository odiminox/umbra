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
#pragma once
#include "base/point.hpp"
#include "base/rect.hpp"
#include "events/events.hpp"
#include "events/signal.hpp"
#include "module/module.hpp"
#include "widget/stylesheet.hpp"

namespace widget {
class Widget : public module::Module {
  friend class Checkbox;
  friend class StyleSheetSet;

 public:
  Widget() = default;
  /**
   * Custom, widget-specific code interpreting the mouse input.
   * @param ms reference to the mouse object
   */
  void mouse(TCOD_mouse_t&) override {}
  void onEvent(const SDL_Event&) override;

  /**
   * Signal launched when the mouse cursor enters the widget.
   */
  Signal2<Widget*, events::Event> onMouseEnter{};
  /**
   * Signal launched when the mouse cursor leaves the widget.
   */
  Signal2<Widget*, events::Event> onMouseLeave{};
  /**
   * Signal lauched when the mouse cursor moves inside the widget.
   */
  Signal2<Widget*, events::Event> onMouseMove{};
  /**
   * Signal launched when the mouse button is pressed when hovering over the widget. Corresponds to JavaScript's
   * <code>onmousedown</code> event.
   */
  Signal2<Widget*, events::Event> onMousePress{};
  /**
   * Signal launched when the mouse button is released when hovering over the widget. Corresponds to JavaScript's
   * <code>onmouseup</code> event.
   */
  Signal2<Widget*, events::Event> onMouseRelease{};
  /**
   * Signal launched when the mouse button is clicked when hovering over the widget. Corresponds to JavaScript's
   * <code>onclick</code> event. <strong>TODO:</strong> With the current implementation, this signal behaves identically
   * to <code>onMouseRelease</code>.
   */
  Signal2<Widget*, events::Event> onMouseClick{};

  /**
   * Part of the screen where the widget is
   */
  base::Rect rect{};
  /**
   * The style sheet containing information about the widget's appearance
   */
  widget::StyleSheet style{};

 protected:
  /**
   * Sets the widget's active zone reacting to dragging.
   * @param x the drag zone's top left corner's <i>x</i> coordinate
   * @param y the drag zone's top left corner's <i>y</i> coordinate
   * @param w the drag zone's width
   * @param h the drag zone's height
   */
  void setDragZone(int x, int y, int w, int h);
  /**
   * Custom code that is executed when the user release the mouse button
   * after dragging the widget
   */
  virtual void onDragEnd() {}
  /**
   * Pointer to the containing (parent) widget
   */
  Widget* parent{nullptr};  // reference to the widget that contains the object
  /**
   * The drag zone: the are within the widget that can be clicked in order to drag it
   */
  base::Rect dragZone{};  // part of the widget we can click to drag it
  /**
   * Coordinates of the minimise button
   */
  base::Point minimiseButton{};  // minimise button coordinates
  /**
   * Coordinates of the close button
   */
  base::Point closeButton{};  // close button coordinates
  bool canDrag{false};
  bool isDragging{false};
};
}  // namespace widget
