# Demo ABI compatibility issue

Demonstrates ABI compatibility issue with the exported Node API in Electron.

## Compiles on 12.20.0
Run `npm run build:working` to test this build on Node 12.20.0 for a successful example of this code compiling.

## Fails to compile on Electron 10.1.4 and higher
Run `npm run build:broken` to see the following error:
```
addon.obj : error LNK2001: unresolved external symbol "__declspec(dllimport) class std::unique_ptr<struct node::ACHHand
le,struct node::DeleteACHHandle> __cdecl node::AddEnvironmentCleanupHook(class v8::Isolate *,void (__cdecl*)(void *,voi
d (__cdecl*)(void *),void *),void *)" (__imp_?AddEnvironmentCleanupHook@node@@YA?AV?$unique_ptr@UACHHandle@node@@UDelet
eACHHandle@2@@std@@PEAVIsolate@v8@@P6AXPEAXP6AX1@Z1@Z1@Z)
```
