type t;

[@bs.set] external onAbort : (t, Dom.event => unit) => unit = "onabort";

[@bs.set] external onError : (t, Dom.errorEvent => unit) => unit = "onerror";

[@bs.set] external onLoad : (t, Dom.event => unit) => unit = "onload";

[@bs.set]
external onLoadEnd : (t, Dom.progressEvent => unit) => unit = "onloadend";

[@bs.set]
external onLoadStart : (t, Dom.progressEvent => unit) => unit = "onloadstart";

[@bs.set]
external onProgress : (t, Dom.progressEvent => unit) => unit = "onprogress";

[@bs.set]
external onTimeout : (t, Dom.progressEvent => unit) => unit = "ontimeout";

[@bs.send]
external addEventListener :
  (
    t,
    [@bs.string] [
      | `abort(Dom.event => unit)
      | `error(Dom.errorEvent => unit)
      | `load(Dom.event => unit)
      | [@bs.as "loadend"] `loadEnd(Dom.progressEvent => unit)
      | [@bs.as "loadstart"] `loadStart(Dom.progressEvent => unit)
      | `progress(Dom.progressEvent => unit)
      | `timeout(Dom.progressEvent => unit)
    ]
  ) =>
  unit =
  "addEventListener";

[@bs.send]
external removeEventListener :
  (
    t,
    [@bs.string] [
      | `abort(Dom.event => unit)
      | `error(Dom.errorEvent => unit)
      | `load(Dom.event => unit)
      | [@bs.as "loadend"] `loadEnd(Dom.progressEvent => unit)
      | [@bs.as "loadstart"] `loadStart(Dom.progressEvent => unit)
      | `progress(Dom.progressEvent => unit)
      | `timeout(Dom.progressEvent => unit)
    ]
  ) =>
  unit =
  "removeEventListener";