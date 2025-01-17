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
#ifndef UMBRA_CONFIG_HPP
#define UMBRA_CONFIG_HPP
#include <filesystem>
#include <libtcod/list.hpp>
#include <vector>

#include "base/font.hpp"

namespace config {
enum LogLevel { LOGLEVEL_INFO, LOGLEVEL_NOTICE, LOGLEVEL_WARN, LOGLEVEL_ERROR, LOGLEVEL_FATAL, LOGLEVEL_NONE };

class Config {
  friend class Engine;
  friend class Log;

 public:
  static inline int rootWidth{};
  static inline int rootHeight{};
  static inline bool fullScreen{};
  static inline LogLevel logLevel{LOGLEVEL_INFO};
  static inline const base::Font* font{};
  static inline std::filesystem::path fileName{};
  static inline std::filesystem::path fontDir{};
  static inline const char* moduleChain{};
  static inline int fontID{};
  static inline std::vector<base::Font> fonts{};

  // private:
  /**
   * Activates a different font. This method is called by the engine.
   * @param shift a number indicating whether to activate the next or the previous font in the registered fonts
   * list.<br>This can be -1 (switch down) or 1 (switch up). All other numbers will be clamped to these values.<br>A
   * value of 0 results in doing nothing.
   * @return <code>true</code> if the font has been successfully changed, <code>false</code> otherwise
   */
  static bool activateFont(int shift = 0);
  /**
   * Loads configuration variables from a config file.
   * @param fileName the filename (with path to it) of the configuration file
   */
  static void load(std::filesystem::path fileName);
  /**
   * Saves the configuration to a config file. It is called on application exit, so any changes to the configuration are
   * stored.
   */
  static void save();
  /**
   * Adds a font to the registered fonts list
   * @param new_font the font object to be added to the list
   */
  static void registerFont(const base::Font& new_font);
  [[deprecated]] static void registerFont(base::Font* new_font) { registerFont(*new_font); }
};
}  // namespace config
#endif
