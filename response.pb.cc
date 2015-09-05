// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: response.proto
#include "stdafx.h"

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "response.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace CommonProto {

namespace {

const ::google::protobuf::Descriptor* Response_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Response_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_response_2eproto() {
  protobuf_AddDesc_response_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "response.proto");
  GOOGLE_CHECK(file != NULL);
  Response_descriptor_ = file->message_type(0);
  static const int Response_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Response, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Response, desc_),
  };
  Response_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Response_descriptor_,
      Response::default_instance_,
      Response_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Response, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Response, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Response));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_response_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Response_descriptor_, &Response::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_response_2eproto() {
  delete Response::default_instance_;
  delete Response_reflection_;
}

void protobuf_AddDesc_response_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016response.proto\022\013CommonProto\"$\n\010Respons"
    "e\022\n\n\002id\030\001 \002(\005\022\014\n\004desc\030\002 \001(\t", 67);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "response.proto", &protobuf_RegisterTypes);
  Response::default_instance_ = new Response();
  Response::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_response_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_response_2eproto {
  StaticDescriptorInitializer_response_2eproto() {
    protobuf_AddDesc_response_2eproto();
  }
} static_descriptor_initializer_response_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Response::kIdFieldNumber;
const int Response::kDescFieldNumber;
#endif  // !_MSC_VER

Response::Response()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:CommonProto.Response)
}

void Response::InitAsDefaultInstance() {
}

Response::Response(const Response& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:CommonProto.Response)
}

void Response::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = 0;
  desc_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Response::~Response() {
  // @@protoc_insertion_point(destructor:CommonProto.Response)
  SharedDtor();
}

void Response::SharedDtor() {
  if (desc_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete desc_;
  }
  if (this != default_instance_) {
  }
}

void Response::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Response::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Response_descriptor_;
}

const Response& Response::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_response_2eproto();
  return *default_instance_;
}

Response* Response::default_instance_ = NULL;

Response* Response::New() const {
  return new Response;
}

void Response::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    id_ = 0;
    if (has_desc()) {
      if (desc_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        desc_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Response::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:CommonProto.Response)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_desc;
        break;
      }

      // optional string desc = 2;
      case 2: {
        if (tag == 18) {
         parse_desc:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_desc()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->desc().data(), this->desc().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "desc");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:CommonProto.Response)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:CommonProto.Response)
  return false;
#undef DO_
}

void Response::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:CommonProto.Response)
  // required int32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // optional string desc = 2;
  if (has_desc()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->desc().data(), this->desc().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "desc");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->desc(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:CommonProto.Response)
}

::google::protobuf::uint8* Response::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:CommonProto.Response)
  // required int32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // optional string desc = 2;
  if (has_desc()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->desc().data(), this->desc().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "desc");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->desc(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CommonProto.Response)
  return target;
}

int Response::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->id());
    }

    // optional string desc = 2;
    if (has_desc()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->desc());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Response::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Response* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Response*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Response::MergeFrom(const Response& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_desc()) {
      set_desc(from.desc());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Response::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Response::CopyFrom(const Response& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Response::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void Response::Swap(Response* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(desc_, other->desc_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Response::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Response_descriptor_;
  metadata.reflection = Response_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace CommonProto

// @@protoc_insertion_point(global_scope)
