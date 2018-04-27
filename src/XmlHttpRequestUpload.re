type t;

[@bs.send] external onAbort : (t, Dom.event => unit) => unit = "onabort";

[@bs.send] external onError : (t, Dom.errorEvent => unit) => unit = "onerror";

[@bs.send] external onLoad : (t, Dom.event => unit) => unit = "onload";

[@bs.send]
external onLoadEnd : (t, Dom.progressEvent => unit) => unit = "onloadend";

[@bs.send]
external onLoadStart : (t, Dom.progressEvent => unit) => unit = "onloadstart";

[@bs.send]
external onProgress : (t, Dom.progressEvent => unit) => unit = "onprogress";

[@bs.send]
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