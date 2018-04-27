type t;

type readyState =
  | Unsent
  | Opened
  | HeadersReceived
  | Loading
  | Done
  | Unknown;

let decodeReadyState =
  fun
  | 0 => Unsent
  | 1 => Opened
  | 2 => HeadersReceived
  | 3 => Loading
  | 4 => Done
  | _ => Unknown;

[@bs.new] external make : unit => t = "XMLHttpRequest";

[@bs.get] external readyStateExternal : t => int = "readyState";

let readyState = (xhr: t) =>
  decodeReadyState(readyStateExternal(xhr));

[@bs.get]
external responseArrayBuffer : t => Js.Nullable.t(Js.Typed_array.array_buffer) =
  "response";

[@bs.get]
external responseDocument : t => Js.Nullable.t(Dom.document) = "response";

[@bs.get] external responseJson : t => Js.Nullable.t(Js.Json.t) = "response";

[@bs.get] external responseText : t => Js.Nullable.t(string) = "";

[@bs.get] external responseType : t => string = "";

[@bs.get] external responseUrl : t => Js.Nullable.t(string) = "";

[@bs.get] external responseXml : t => Js.Nullable.t(Dom.xmlDocument) = "";

[@bs.set]
external setResponseType :
  (
    t,
    [@bs.string] [
      | [@bs.as "arraybuffer"] `arrayBuffer
      | `document
      | `json
      | `text
    ]
  ) =>
  string =
  "responseType";

[@bs.get] external status : t => int = "";

[@bs.get] external statusText : t => string = "";

[@bs.get] external timeout : t => int = "";

[@bs.get] external upload : t => XmlHttpRequestUpload.t = "";

[@bs.set] external setTimeout : (t, int) => int = "timeout";

[@bs.get] external withCredentials : t => bool = "";

[@bs.set] external setWithCredentials : (t, bool) => bool = "withCredentials";

[@bs.send] external abort : t => unit = "";

[@bs.send] external getAllResponseHeaders : t => Js.Nullable.t(string) = "";

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

[@bs.send]
external sendArrayBuffer : (t, Js.Typed_array.array_buffer) => unit = "send";

[@bs.send] external sendDocument : (t, Dom.document) => unit = "send";

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
      | [@bs.as "readystatechange"] `readyStateChange((. Dom.event) => unit)
      | `abort((. Dom.event) => unit)
      | `error((. Dom.errorEvent) => unit)
      | `load((. Dom.event) => unit)
      | [@bs.as "loadend"] `loadEnd((. Dom.progressEvent) => unit)
      | [@bs.as "loadstart"] `loadStart((. Dom.event) => unit)
      | `progress((. Dom.progressEvent) => unit)
      | `timeout((. Dom.progressEvent) => unit)
    ]
  ) =>
  unit =
  "addEventListener";

[@bs.send]
external removeEventListener :
  (
    t,
    [@bs.string] [
      | [@bs.as "readystatechange"] `readyStateChange((. Dom.event) => unit)
      | `abort((. Dom.event) => unit)
      | `error((. Dom.errorEvent) => unit)
      | `load((. Dom.event) => unit)
      | [@bs.as "loadend"] `loadEnd((. Dom.progressEvent) => unit)
      | [@bs.as "loadstart"] `loadStart((. Dom.event) => unit)
      | `progress((. Dom.progressEvent) => unit)
      | `timeout((. Dom.progressEvent) => unit)
    ]
  ) =>
  unit =
  "removeEventListener";