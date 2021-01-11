#include <node.h>

struct AsyncData {
  node::AsyncCleanupHookHandle handle;
};

void AsyncCleanupHook(void *arg, void(*cb)(void *), void *cbarg) {
  AsyncData *data = static_cast<AsyncData *>(arg);
  delete data;
}

void Initialize(
  v8::Local<v8::Object> exports,
  v8::Local<v8::Value> module,
  v8::Local<v8::Context> context
) {
  AsyncData *data = new AsyncData;
  auto handle = node::AddEnvironmentCleanupHook(
    context->GetIsolate(),
    AsyncCleanupHook,
    data
  );
  data->handle = std::move(handle);
}

NODE_MODULE_CONTEXT_AWARE(NODE_GYP_MODULE_NAME, Initialize)
