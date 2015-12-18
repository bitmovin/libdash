/****************************************************************************
 *
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * For more information, please refer to <http://unlicense.org>
 *
 ****************************************************************************/

var PreferredStartupQuality = function(player, preferredStartupQualityBps, startupPhaseSeconds) {
  var availableQualities = null;
  var isInStartup        = true;
  var startupTimerID;

  var preferredQuality = preferredStartupQualityBps || 1000000;
  var startupSeconds   = startupPhaseSeconds        || 10;

  var onVideoAdaptation = function(e) {
    if (isInStartup) {
      if (!availableQualities) {
        availableQualities = this.getAvailableVideoQualities();
        startupTimerID = setTimeout(function() {
          isInStartup = false;
        }, startupSeconds * 1000);
      }

      for (var i = availableQualities.length - 1; i >= 0; i--) {
        if (availableQualities[i].id === e.suggested) {
          // Use the suggested quality if it's higher than the preferred
          return e.suggested;
        }
        if (availableQualities[i].bitrate <= preferredQuality) {
          return availableQualities[i].id;
        }
      }

      return availableQualities[availableQualities.length - 1].id;
    }

    return e.suggested;
  };

  var onReady = function() {
    isInStartup = true;
    clearTimeout(startupTimerID);
    availableQualities = null;
  };

  player.addEventHandler('onReady', onReady);
  player.addEventHandler('onVideoAdaptation', onVideoAdaptation);

  this.remove = function() {
    player.removeEventHandler('onReady', onReady);
    player.removeEventHandler('onVideoAdaptation', onVideoAdaptation);

    clearTimeout(startupTimerID);
    isInStartup   = true;
    availableQualities = null;
  };

  this.stopStartup = function() {
    isInStartup = false;
    clearTimeout(startupTimerID);
  };
};
