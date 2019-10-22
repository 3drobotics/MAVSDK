// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: passthrough/passthrough.proto

#include "passthrough/passthrough.pb.h"
#include "passthrough/passthrough.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace mavsdk {
namespace rpc {
namespace passthrough {

static const char* PassthroughService_method_names[] = {
  "/mavsdk.rpc.passthrough.PassthroughService/SendMessage",
  "/mavsdk.rpc.passthrough.PassthroughService/GetOurSysId",
  "/mavsdk.rpc.passthrough.PassthroughService/GetOurCompId",
  "/mavsdk.rpc.passthrough.PassthroughService/GetTargetSysId",
  "/mavsdk.rpc.passthrough.PassthroughService/GetTargetCompId",
  "/mavsdk.rpc.passthrough.PassthroughService/SendCommandInt",
  "/mavsdk.rpc.passthrough.PassthroughService/SendCommandLong",
};

std::unique_ptr< PassthroughService::Stub> PassthroughService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< PassthroughService::Stub> stub(new PassthroughService::Stub(channel));
  return stub;
}

PassthroughService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_SendMessage_(PassthroughService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetOurSysId_(PassthroughService_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetOurCompId_(PassthroughService_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetTargetSysId_(PassthroughService_method_names[3], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetTargetCompId_(PassthroughService_method_names[4], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_SendCommandInt_(PassthroughService_method_names[5], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_SendCommandLong_(PassthroughService_method_names[6], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status PassthroughService::Stub::SendMessage(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::SendMessageRequest& request, ::mavsdk::rpc::passthrough::SendMessageResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_SendMessage_, context, request, response);
}

void PassthroughService::Stub::experimental_async::SendMessage(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::SendMessageRequest* request, ::mavsdk::rpc::passthrough::SendMessageResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_SendMessage_, context, request, response, std::move(f));
}

void PassthroughService::Stub::experimental_async::SendMessage(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::mavsdk::rpc::passthrough::SendMessageResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_SendMessage_, context, request, response, std::move(f));
}

void PassthroughService::Stub::experimental_async::SendMessage(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::SendMessageRequest* request, ::mavsdk::rpc::passthrough::SendMessageResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_SendMessage_, context, request, response, reactor);
}

void PassthroughService::Stub::experimental_async::SendMessage(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::mavsdk::rpc::passthrough::SendMessageResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_SendMessage_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::mavsdk::rpc::passthrough::SendMessageResponse>* PassthroughService::Stub::AsyncSendMessageRaw(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::SendMessageRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::mavsdk::rpc::passthrough::SendMessageResponse>::Create(channel_.get(), cq, rpcmethod_SendMessage_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::mavsdk::rpc::passthrough::SendMessageResponse>* PassthroughService::Stub::PrepareAsyncSendMessageRaw(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::SendMessageRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::mavsdk::rpc::passthrough::SendMessageResponse>::Create(channel_.get(), cq, rpcmethod_SendMessage_, context, request, false);
}

::grpc::Status PassthroughService::Stub::GetOurSysId(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::GetOurSysIdRequest& request, ::mavsdk::rpc::passthrough::GetOurSysIdResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetOurSysId_, context, request, response);
}

void PassthroughService::Stub::experimental_async::GetOurSysId(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::GetOurSysIdRequest* request, ::mavsdk::rpc::passthrough::GetOurSysIdResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetOurSysId_, context, request, response, std::move(f));
}

void PassthroughService::Stub::experimental_async::GetOurSysId(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::mavsdk::rpc::passthrough::GetOurSysIdResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetOurSysId_, context, request, response, std::move(f));
}

void PassthroughService::Stub::experimental_async::GetOurSysId(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::GetOurSysIdRequest* request, ::mavsdk::rpc::passthrough::GetOurSysIdResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GetOurSysId_, context, request, response, reactor);
}

void PassthroughService::Stub::experimental_async::GetOurSysId(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::mavsdk::rpc::passthrough::GetOurSysIdResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GetOurSysId_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::mavsdk::rpc::passthrough::GetOurSysIdResponse>* PassthroughService::Stub::AsyncGetOurSysIdRaw(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::GetOurSysIdRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::mavsdk::rpc::passthrough::GetOurSysIdResponse>::Create(channel_.get(), cq, rpcmethod_GetOurSysId_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::mavsdk::rpc::passthrough::GetOurSysIdResponse>* PassthroughService::Stub::PrepareAsyncGetOurSysIdRaw(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::GetOurSysIdRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::mavsdk::rpc::passthrough::GetOurSysIdResponse>::Create(channel_.get(), cq, rpcmethod_GetOurSysId_, context, request, false);
}

::grpc::Status PassthroughService::Stub::GetOurCompId(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::GetOurCompIdRequest& request, ::mavsdk::rpc::passthrough::GetOurCompIdResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetOurCompId_, context, request, response);
}

void PassthroughService::Stub::experimental_async::GetOurCompId(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::GetOurCompIdRequest* request, ::mavsdk::rpc::passthrough::GetOurCompIdResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetOurCompId_, context, request, response, std::move(f));
}

void PassthroughService::Stub::experimental_async::GetOurCompId(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::mavsdk::rpc::passthrough::GetOurCompIdResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetOurCompId_, context, request, response, std::move(f));
}

void PassthroughService::Stub::experimental_async::GetOurCompId(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::GetOurCompIdRequest* request, ::mavsdk::rpc::passthrough::GetOurCompIdResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GetOurCompId_, context, request, response, reactor);
}

void PassthroughService::Stub::experimental_async::GetOurCompId(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::mavsdk::rpc::passthrough::GetOurCompIdResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GetOurCompId_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::mavsdk::rpc::passthrough::GetOurCompIdResponse>* PassthroughService::Stub::AsyncGetOurCompIdRaw(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::GetOurCompIdRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::mavsdk::rpc::passthrough::GetOurCompIdResponse>::Create(channel_.get(), cq, rpcmethod_GetOurCompId_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::mavsdk::rpc::passthrough::GetOurCompIdResponse>* PassthroughService::Stub::PrepareAsyncGetOurCompIdRaw(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::GetOurCompIdRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::mavsdk::rpc::passthrough::GetOurCompIdResponse>::Create(channel_.get(), cq, rpcmethod_GetOurCompId_, context, request, false);
}

::grpc::Status PassthroughService::Stub::GetTargetSysId(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::GetTargetSysIdRequest& request, ::mavsdk::rpc::passthrough::GetTargetSysIdResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetTargetSysId_, context, request, response);
}

void PassthroughService::Stub::experimental_async::GetTargetSysId(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::GetTargetSysIdRequest* request, ::mavsdk::rpc::passthrough::GetTargetSysIdResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetTargetSysId_, context, request, response, std::move(f));
}

void PassthroughService::Stub::experimental_async::GetTargetSysId(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::mavsdk::rpc::passthrough::GetTargetSysIdResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetTargetSysId_, context, request, response, std::move(f));
}

void PassthroughService::Stub::experimental_async::GetTargetSysId(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::GetTargetSysIdRequest* request, ::mavsdk::rpc::passthrough::GetTargetSysIdResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GetTargetSysId_, context, request, response, reactor);
}

void PassthroughService::Stub::experimental_async::GetTargetSysId(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::mavsdk::rpc::passthrough::GetTargetSysIdResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GetTargetSysId_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::mavsdk::rpc::passthrough::GetTargetSysIdResponse>* PassthroughService::Stub::AsyncGetTargetSysIdRaw(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::GetTargetSysIdRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::mavsdk::rpc::passthrough::GetTargetSysIdResponse>::Create(channel_.get(), cq, rpcmethod_GetTargetSysId_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::mavsdk::rpc::passthrough::GetTargetSysIdResponse>* PassthroughService::Stub::PrepareAsyncGetTargetSysIdRaw(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::GetTargetSysIdRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::mavsdk::rpc::passthrough::GetTargetSysIdResponse>::Create(channel_.get(), cq, rpcmethod_GetTargetSysId_, context, request, false);
}

::grpc::Status PassthroughService::Stub::GetTargetCompId(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::GetTargetCompIdRequest& request, ::mavsdk::rpc::passthrough::GetTargetCompIdResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetTargetCompId_, context, request, response);
}

void PassthroughService::Stub::experimental_async::GetTargetCompId(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::GetTargetCompIdRequest* request, ::mavsdk::rpc::passthrough::GetTargetCompIdResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetTargetCompId_, context, request, response, std::move(f));
}

void PassthroughService::Stub::experimental_async::GetTargetCompId(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::mavsdk::rpc::passthrough::GetTargetCompIdResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetTargetCompId_, context, request, response, std::move(f));
}

void PassthroughService::Stub::experimental_async::GetTargetCompId(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::GetTargetCompIdRequest* request, ::mavsdk::rpc::passthrough::GetTargetCompIdResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GetTargetCompId_, context, request, response, reactor);
}

void PassthroughService::Stub::experimental_async::GetTargetCompId(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::mavsdk::rpc::passthrough::GetTargetCompIdResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GetTargetCompId_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::mavsdk::rpc::passthrough::GetTargetCompIdResponse>* PassthroughService::Stub::AsyncGetTargetCompIdRaw(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::GetTargetCompIdRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::mavsdk::rpc::passthrough::GetTargetCompIdResponse>::Create(channel_.get(), cq, rpcmethod_GetTargetCompId_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::mavsdk::rpc::passthrough::GetTargetCompIdResponse>* PassthroughService::Stub::PrepareAsyncGetTargetCompIdRaw(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::GetTargetCompIdRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::mavsdk::rpc::passthrough::GetTargetCompIdResponse>::Create(channel_.get(), cq, rpcmethod_GetTargetCompId_, context, request, false);
}

::grpc::Status PassthroughService::Stub::SendCommandInt(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::SendCommandIntRequest& request, ::mavsdk::rpc::passthrough::SendCommandIntResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_SendCommandInt_, context, request, response);
}

void PassthroughService::Stub::experimental_async::SendCommandInt(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::SendCommandIntRequest* request, ::mavsdk::rpc::passthrough::SendCommandIntResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_SendCommandInt_, context, request, response, std::move(f));
}

void PassthroughService::Stub::experimental_async::SendCommandInt(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::mavsdk::rpc::passthrough::SendCommandIntResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_SendCommandInt_, context, request, response, std::move(f));
}

void PassthroughService::Stub::experimental_async::SendCommandInt(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::SendCommandIntRequest* request, ::mavsdk::rpc::passthrough::SendCommandIntResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_SendCommandInt_, context, request, response, reactor);
}

void PassthroughService::Stub::experimental_async::SendCommandInt(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::mavsdk::rpc::passthrough::SendCommandIntResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_SendCommandInt_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::mavsdk::rpc::passthrough::SendCommandIntResponse>* PassthroughService::Stub::AsyncSendCommandIntRaw(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::SendCommandIntRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::mavsdk::rpc::passthrough::SendCommandIntResponse>::Create(channel_.get(), cq, rpcmethod_SendCommandInt_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::mavsdk::rpc::passthrough::SendCommandIntResponse>* PassthroughService::Stub::PrepareAsyncSendCommandIntRaw(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::SendCommandIntRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::mavsdk::rpc::passthrough::SendCommandIntResponse>::Create(channel_.get(), cq, rpcmethod_SendCommandInt_, context, request, false);
}

::grpc::Status PassthroughService::Stub::SendCommandLong(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::SendCommandLongRequest& request, ::mavsdk::rpc::passthrough::SendCommandLongResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_SendCommandLong_, context, request, response);
}

void PassthroughService::Stub::experimental_async::SendCommandLong(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::SendCommandLongRequest* request, ::mavsdk::rpc::passthrough::SendCommandLongResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_SendCommandLong_, context, request, response, std::move(f));
}

void PassthroughService::Stub::experimental_async::SendCommandLong(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::mavsdk::rpc::passthrough::SendCommandLongResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_SendCommandLong_, context, request, response, std::move(f));
}

void PassthroughService::Stub::experimental_async::SendCommandLong(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::SendCommandLongRequest* request, ::mavsdk::rpc::passthrough::SendCommandLongResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_SendCommandLong_, context, request, response, reactor);
}

void PassthroughService::Stub::experimental_async::SendCommandLong(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::mavsdk::rpc::passthrough::SendCommandLongResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_SendCommandLong_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::mavsdk::rpc::passthrough::SendCommandLongResponse>* PassthroughService::Stub::AsyncSendCommandLongRaw(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::SendCommandLongRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::mavsdk::rpc::passthrough::SendCommandLongResponse>::Create(channel_.get(), cq, rpcmethod_SendCommandLong_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::mavsdk::rpc::passthrough::SendCommandLongResponse>* PassthroughService::Stub::PrepareAsyncSendCommandLongRaw(::grpc::ClientContext* context, const ::mavsdk::rpc::passthrough::SendCommandLongRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::mavsdk::rpc::passthrough::SendCommandLongResponse>::Create(channel_.get(), cq, rpcmethod_SendCommandLong_, context, request, false);
}

PassthroughService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      PassthroughService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< PassthroughService::Service, ::mavsdk::rpc::passthrough::SendMessageRequest, ::mavsdk::rpc::passthrough::SendMessageResponse>(
          std::mem_fn(&PassthroughService::Service::SendMessage), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      PassthroughService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< PassthroughService::Service, ::mavsdk::rpc::passthrough::GetOurSysIdRequest, ::mavsdk::rpc::passthrough::GetOurSysIdResponse>(
          std::mem_fn(&PassthroughService::Service::GetOurSysId), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      PassthroughService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< PassthroughService::Service, ::mavsdk::rpc::passthrough::GetOurCompIdRequest, ::mavsdk::rpc::passthrough::GetOurCompIdResponse>(
          std::mem_fn(&PassthroughService::Service::GetOurCompId), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      PassthroughService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< PassthroughService::Service, ::mavsdk::rpc::passthrough::GetTargetSysIdRequest, ::mavsdk::rpc::passthrough::GetTargetSysIdResponse>(
          std::mem_fn(&PassthroughService::Service::GetTargetSysId), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      PassthroughService_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< PassthroughService::Service, ::mavsdk::rpc::passthrough::GetTargetCompIdRequest, ::mavsdk::rpc::passthrough::GetTargetCompIdResponse>(
          std::mem_fn(&PassthroughService::Service::GetTargetCompId), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      PassthroughService_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< PassthroughService::Service, ::mavsdk::rpc::passthrough::SendCommandIntRequest, ::mavsdk::rpc::passthrough::SendCommandIntResponse>(
          std::mem_fn(&PassthroughService::Service::SendCommandInt), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      PassthroughService_method_names[6],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< PassthroughService::Service, ::mavsdk::rpc::passthrough::SendCommandLongRequest, ::mavsdk::rpc::passthrough::SendCommandLongResponse>(
          std::mem_fn(&PassthroughService::Service::SendCommandLong), this)));
}

PassthroughService::Service::~Service() {
}

::grpc::Status PassthroughService::Service::SendMessage(::grpc::ServerContext* context, const ::mavsdk::rpc::passthrough::SendMessageRequest* request, ::mavsdk::rpc::passthrough::SendMessageResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status PassthroughService::Service::GetOurSysId(::grpc::ServerContext* context, const ::mavsdk::rpc::passthrough::GetOurSysIdRequest* request, ::mavsdk::rpc::passthrough::GetOurSysIdResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status PassthroughService::Service::GetOurCompId(::grpc::ServerContext* context, const ::mavsdk::rpc::passthrough::GetOurCompIdRequest* request, ::mavsdk::rpc::passthrough::GetOurCompIdResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status PassthroughService::Service::GetTargetSysId(::grpc::ServerContext* context, const ::mavsdk::rpc::passthrough::GetTargetSysIdRequest* request, ::mavsdk::rpc::passthrough::GetTargetSysIdResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status PassthroughService::Service::GetTargetCompId(::grpc::ServerContext* context, const ::mavsdk::rpc::passthrough::GetTargetCompIdRequest* request, ::mavsdk::rpc::passthrough::GetTargetCompIdResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status PassthroughService::Service::SendCommandInt(::grpc::ServerContext* context, const ::mavsdk::rpc::passthrough::SendCommandIntRequest* request, ::mavsdk::rpc::passthrough::SendCommandIntResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status PassthroughService::Service::SendCommandLong(::grpc::ServerContext* context, const ::mavsdk::rpc::passthrough::SendCommandLongRequest* request, ::mavsdk::rpc::passthrough::SendCommandLongResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace mavsdk
}  // namespace rpc
}  // namespace passthrough

