# bs-xmlhttprequest

[XMLHttpRequest](https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/XMLHttpRequest) bindings for [BuckleScript](https://bucklescript.github.io).

## Install

yarn:

```
yarn add https://github.com/drejohnson/bs-xmlhttprequest
```

npm:

```
npm install https://github.com/drejohnson/bs-xmlhttprequest
```

Add `bs-xmlhttprequest` to `bs-dependencies` in `bsconfig.json`.

## Example

```reason
let xhr = XmlHttpRequest.makeXMLHttpRequest();

XmlHttpRequest.open_(xhr, ~method="GET", ~url="https://api.github.com/", ~async=true, ());

XmlHttpRequest.setRequestHeader(xhr, "user-agent", "bs-xmlhttprequest");

XmlHttpRequest.addEventListener(
  xhr,
  `load(
    _event => {
      let body = XmlHttpRequest.responseText(xhr);
      let status = XmlHttpRequest.status(xhr);
      Js.log2(status, body);
    },
  ),
);

XmlHttpRequest.send(xhr);
```

> These bindings were forked from [bs-xmlhttprequest](https://github.com/stefanduberg/bs-xmlhttprequest)
