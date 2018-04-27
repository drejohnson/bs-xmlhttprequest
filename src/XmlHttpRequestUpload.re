type t;

[@bs.send]
external addEventListener :
  (
    t,
    [@bs.string] [
      | `abort(Dom.event => unit)
      | `error(Dom.errorEvent => unit)
      | `load(Dom.event => unit)
      | [@bs.as "loadend"] `loadEnd(Dom.progressEvent => unit)
      | [@bs.as "loadstart"] `loadStart(Dom.event => unit)
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
      | [@bs.as "loadstart"] `loadStart(Dom.event => unit)
      | `progress(Dom.progressEvent => unit)
      | `timeout(Dom.progressEvent => unit)
    ]
  ) =>
  unit =
  "removeEventListener";
