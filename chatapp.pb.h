// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: chatapp.proto

#ifndef PROTOBUF_chatapp_2eproto__INCLUDED
#define PROTOBUF_chatapp_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace ChatApp {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_chatapp_2eproto();
void protobuf_AssignDesc_chatapp_2eproto();
void protobuf_ShutdownFile_chatapp_2eproto();

class User;
class Chat;

// ===================================================================

class User : public ::google::protobuf::Message {
 public:
  User();
  virtual ~User();

  User(const User& from);

  inline User& operator=(const User& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const User& default_instance();

  void Swap(User* other);

  // implements Message ----------------------------------------------

  User* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const User& from);
  void MergeFrom(const User& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string name = 1;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 1;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // required string chat = 2;
  inline bool has_chat() const;
  inline void clear_chat();
  static const int kChatFieldNumber = 2;
  inline const ::std::string& chat() const;
  inline void set_chat(const ::std::string& value);
  inline void set_chat(const char* value);
  inline void set_chat(const char* value, size_t size);
  inline ::std::string* mutable_chat();
  inline ::std::string* release_chat();
  inline void set_allocated_chat(::std::string* chat);

  // optional string email = 3;
  inline bool has_email() const;
  inline void clear_email();
  static const int kEmailFieldNumber = 3;
  inline const ::std::string& email() const;
  inline void set_email(const ::std::string& value);
  inline void set_email(const char* value);
  inline void set_email(const char* value, size_t size);
  inline ::std::string* mutable_email();
  inline ::std::string* release_email();
  inline void set_allocated_email(::std::string* email);

  // @@protoc_insertion_point(class_scope:ChatApp.User)
 private:
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_chat();
  inline void clear_has_chat();
  inline void set_has_email();
  inline void clear_has_email();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* name_;
  ::std::string* chat_;
  ::std::string* email_;
  friend void  protobuf_AddDesc_chatapp_2eproto();
  friend void protobuf_AssignDesc_chatapp_2eproto();
  friend void protobuf_ShutdownFile_chatapp_2eproto();

  void InitAsDefaultInstance();
  static User* default_instance_;
};
// -------------------------------------------------------------------

class Chat : public ::google::protobuf::Message {
 public:
  Chat();
  virtual ~Chat();

  Chat(const Chat& from);

  inline Chat& operator=(const Chat& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Chat& default_instance();

  void Swap(Chat* other);

  // implements Message ----------------------------------------------

  Chat* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Chat& from);
  void MergeFrom(const Chat& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .ChatApp.User user = 1;
  inline int user_size() const;
  inline void clear_user();
  static const int kUserFieldNumber = 1;
  inline const ::ChatApp::User& user(int index) const;
  inline ::ChatApp::User* mutable_user(int index);
  inline ::ChatApp::User* add_user();
  inline const ::google::protobuf::RepeatedPtrField< ::ChatApp::User >&
      user() const;
  inline ::google::protobuf::RepeatedPtrField< ::ChatApp::User >*
      mutable_user();

  // @@protoc_insertion_point(class_scope:ChatApp.Chat)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::ChatApp::User > user_;
  friend void  protobuf_AddDesc_chatapp_2eproto();
  friend void protobuf_AssignDesc_chatapp_2eproto();
  friend void protobuf_ShutdownFile_chatapp_2eproto();

  void InitAsDefaultInstance();
  static Chat* default_instance_;
};
// ===================================================================


// ===================================================================

// User

// required string name = 1;
inline bool User::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void User::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void User::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void User::clear_name() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& User::name() const {
  // @@protoc_insertion_point(field_get:ChatApp.User.name)
  return *name_;
}
inline void User::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  name_->assign(value);
  // @@protoc_insertion_point(field_set:ChatApp.User.name)
}
inline void User::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  name_->assign(value);
  // @@protoc_insertion_point(field_set_char:ChatApp.User.name)
}
inline void User::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:ChatApp.User.name)
}
inline ::std::string* User::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:ChatApp.User.name)
  return name_;
}
inline ::std::string* User::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void User::set_allocated_name(::std::string* name) {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (name) {
    set_has_name();
    name_ = name;
  } else {
    clear_has_name();
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:ChatApp.User.name)
}

// required string chat = 2;
inline bool User::has_chat() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void User::set_has_chat() {
  _has_bits_[0] |= 0x00000002u;
}
inline void User::clear_has_chat() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void User::clear_chat() {
  if (chat_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    chat_->clear();
  }
  clear_has_chat();
}
inline const ::std::string& User::chat() const {
  // @@protoc_insertion_point(field_get:ChatApp.User.chat)
  return *chat_;
}
inline void User::set_chat(const ::std::string& value) {
  set_has_chat();
  if (chat_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    chat_ = new ::std::string;
  }
  chat_->assign(value);
  // @@protoc_insertion_point(field_set:ChatApp.User.chat)
}
inline void User::set_chat(const char* value) {
  set_has_chat();
  if (chat_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    chat_ = new ::std::string;
  }
  chat_->assign(value);
  // @@protoc_insertion_point(field_set_char:ChatApp.User.chat)
}
inline void User::set_chat(const char* value, size_t size) {
  set_has_chat();
  if (chat_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    chat_ = new ::std::string;
  }
  chat_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:ChatApp.User.chat)
}
inline ::std::string* User::mutable_chat() {
  set_has_chat();
  if (chat_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    chat_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:ChatApp.User.chat)
  return chat_;
}
inline ::std::string* User::release_chat() {
  clear_has_chat();
  if (chat_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = chat_;
    chat_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void User::set_allocated_chat(::std::string* chat) {
  if (chat_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete chat_;
  }
  if (chat) {
    set_has_chat();
    chat_ = chat;
  } else {
    clear_has_chat();
    chat_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:ChatApp.User.chat)
}

// optional string email = 3;
inline bool User::has_email() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void User::set_has_email() {
  _has_bits_[0] |= 0x00000004u;
}
inline void User::clear_has_email() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void User::clear_email() {
  if (email_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    email_->clear();
  }
  clear_has_email();
}
inline const ::std::string& User::email() const {
  // @@protoc_insertion_point(field_get:ChatApp.User.email)
  return *email_;
}
inline void User::set_email(const ::std::string& value) {
  set_has_email();
  if (email_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    email_ = new ::std::string;
  }
  email_->assign(value);
  // @@protoc_insertion_point(field_set:ChatApp.User.email)
}
inline void User::set_email(const char* value) {
  set_has_email();
  if (email_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    email_ = new ::std::string;
  }
  email_->assign(value);
  // @@protoc_insertion_point(field_set_char:ChatApp.User.email)
}
inline void User::set_email(const char* value, size_t size) {
  set_has_email();
  if (email_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    email_ = new ::std::string;
  }
  email_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:ChatApp.User.email)
}
inline ::std::string* User::mutable_email() {
  set_has_email();
  if (email_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    email_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:ChatApp.User.email)
  return email_;
}
inline ::std::string* User::release_email() {
  clear_has_email();
  if (email_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = email_;
    email_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void User::set_allocated_email(::std::string* email) {
  if (email_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete email_;
  }
  if (email) {
    set_has_email();
    email_ = email;
  } else {
    clear_has_email();
    email_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:ChatApp.User.email)
}

// -------------------------------------------------------------------

// Chat

// repeated .ChatApp.User user = 1;
inline int Chat::user_size() const {
  return user_.size();
}
inline void Chat::clear_user() {
  user_.Clear();
}
inline const ::ChatApp::User& Chat::user(int index) const {
  // @@protoc_insertion_point(field_get:ChatApp.Chat.user)
  return user_.Get(index);
}
inline ::ChatApp::User* Chat::mutable_user(int index) {
  // @@protoc_insertion_point(field_mutable:ChatApp.Chat.user)
  return user_.Mutable(index);
}
inline ::ChatApp::User* Chat::add_user() {
  // @@protoc_insertion_point(field_add:ChatApp.Chat.user)
  return user_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::ChatApp::User >&
Chat::user() const {
  // @@protoc_insertion_point(field_list:ChatApp.Chat.user)
  return user_;
}
inline ::google::protobuf::RepeatedPtrField< ::ChatApp::User >*
Chat::mutable_user() {
  // @@protoc_insertion_point(field_mutable_list:ChatApp.Chat.user)
  return &user_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace ChatApp

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_chatapp_2eproto__INCLUDED
