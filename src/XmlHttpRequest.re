type t;

[@bs.new] external make : unit => t = "XMLHttpRequest";

[@bs.get] external readyState : t => int = "";

[@bs.get] external responseText : t => string = "";

[@bs.get] external responseURL : t => string = "";

[@bs.get] external responseXML : t => Dom.xmlDocument = "";

[@bs.get] external status : t => int = "";

[@bs.get] external statusText : t => string = "";

[@bs.get] external timeout : t => int = "";

[@bs.get] external upload : t => XmlHttpRequestUpload.t = "";

[@bs.set] external setTimeout : (t, int) => int = "timeout";

[@bs.get] external withCredentials : t => bool = "";

[@bs.set] external setWithCredentials : (t, bool) => bool = "withCredentials";

[@bs.send] external abort : t => unit = "";

[@bs.send] external getAllResponseHeaders : t => string = "";

[@bs.send]
external getResponseHeader : (t, string) => Js.Nullable.t(string) = "";

[@bs.send]
external open_ :
  (
    t,
    ~method: string,
    ~url: string,
    ~async: bool=?,
    ~user: string=?,
    ~password: string=?,
    unit
  ) =>
  unit =
  "open";

[@bs.send] external overrideMimeType : (t, string) => unit = "";

[@bs.send] external send : t => unit = "send";

[@bs.send] external sendString : (t, string) => unit = "send";

[@bs.send] external setRequestHeader : (t, string, string) => unit = "";

[@bs.send]
external readyStateChange : (t, Dom.event => unit) => unit =
  "readystatechange";

[@bs.send]
external addEventListener :
  (
    t,
    [@bs.string] [
      | `readystatechange(Dom.event => unit)
      | `abort(Dom.event => unit)
      | `error(Dom.errorEvent => unit)
      | `load(Dom.event => unit)
      | `loadend(Dom.progressEvent => unit)
      | `loadstart(Dom.event => unit)
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
      | `readystatechange(Dom.event => unit)
      | `abort(Dom.event => unit)
      | `error(Dom.errorEvent => unit)
      | `load(Dom.event => unit)
      | `loadend(Dom.progressEvent => unit)
      | `loadstart(Dom.event => unit)
      | `progress(Dom.progressEvent => unit)
      | `timeout(Dom.progressEvent => unit)
    ]
  ) =>
  unit =
  "removeEventListener";