// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: echo_str.proto

#include "stdafx.h"
#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "echo_str.pb.h"

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

namespace TEST {

namespace {

const ::google::protobuf::Descriptor* Echo_Str_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Echo_Str_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_echo_5fstr_2eproto() {
  protobuf_AddDesc_echo_5fstr_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "echo_str.proto");
  GOOGLE_CHECK(file != NULL);
  Echo_Str_descriptor_ = file->message_type(0);
  static const int Echo_Str_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Echo_Str, text_),
  };
  Echo_Str_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Echo_Str_descriptor_,
      Echo_Str::default_instance_,
      Echo_Str_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Echo_Str, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Echo_Str, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Echo_Str));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_echo_5fstr_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Echo_Str_descriptor_, &Echo_Str::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_echo_5fstr_2eproto() {
  delete Echo_Str::default_instance_;
  delete Echo_Str_reflection_;
}

void protobuf_AddDesc_echo_5fstr_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016echo_str.proto\022\004TEST\"\030\n\010Echo_Str\022\014\n\004te"
    "xt\030\001 \002(\t", 48);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "echo_str.proto", &protobuf_RegisterTypes);
  Echo_Str::default_instance_ = new Echo_Str();
  Echo_Str::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_echo_5fstr_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_echo_5fstr_2eproto {
  StaticDescriptorInitializer_echo_5fstr_2eproto() {
    protobuf_AddDesc_echo_5fstr_2eproto();
  }
} static_descriptor_initializer_echo_5fstr_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Echo_Str::kTextFieldNumber;
#endif  // !_MSC_VER

Echo_Str::Echo_Str()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:TEST.Echo_Str)
}

void Echo_Str::InitAsDefaultInstance() {
}

Echo_Str::Echo_Str(const Echo_Str& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:TEST.Echo_Str)
}

void Echo_Str::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  text_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Echo_Str::~Echo_Str() {
  // @@protoc_insertion_point(destructor:TEST.Echo_Str)
  SharedDtor();
}

void Echo_Str::SharedDtor() {
  if (text_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete text_;
  }
  if (this != default_instance_) {
  }
}

void Echo_Str::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Echo_Str::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Echo_Str_descriptor_;
}

const Echo_Str& Echo_Str::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_echo_5fstr_2eproto();
  return *default_instance_;
}

Echo_Str* Echo_Str::default_instance_ = NULL;

Echo_Str* Echo_Str::New() const {
  return new Echo_Str;
}

void Echo_Str::Clear() {
  if (has_text()) {
    if (text_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
      text_->clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Echo_Str::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:TEST.Echo_Str)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string text = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_text()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->text().data(), this->text().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "text");
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
  // @@protoc_insertion_point(parse_success:TEST.Echo_Str)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:TEST.Echo_Str)
  return false;
#undef DO_
}

void Echo_Str::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:TEST.Echo_Str)
  // required string text = 1;
  if (has_text()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->text().data(), this->text().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "text");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->text(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:TEST.Echo_Str)
}

::google::protobuf::uint8* Echo_Str::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:TEST.Echo_Str)
  // required string text = 1;
  if (has_text()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->text().data(), this->text().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "text");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->text(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:TEST.Echo_Str)
  return target;
}

int Echo_Str::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string text = 1;
    if (has_text()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->text());
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

void Echo_Str::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Echo_Str* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Echo_Str*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Echo_Str::MergeFrom(const Echo_Str& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_text()) {
      set_text(from.text());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Echo_Str::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Echo_Str::CopyFrom(const Echo_Str& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Echo_Str::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void Echo_Str::Swap(Echo_Str* other) {
  if (other != this) {
    std::swap(text_, other->text_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Echo_Str::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Echo_Str_descriptor_;
  metadata.reflection = Echo_Str_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace TEST

// @@protoc_insertion_point(global_scope)