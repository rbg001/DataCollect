// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: AccountConfig.proto

#ifndef PROTOBUF_AccountConfig_2eproto__INCLUDED
#define PROTOBUF_AccountConfig_2eproto__INCLUDED

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

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_AccountConfig_2eproto();
void protobuf_AssignDesc_AccountConfig_2eproto();
void protobuf_ShutdownFile_AccountConfig_2eproto();

class AccountConfig;

// ===================================================================

class AccountConfig : public ::google::protobuf::Message {
 public:
  AccountConfig();
  virtual ~AccountConfig();

  AccountConfig(const AccountConfig& from);

  inline AccountConfig& operator=(const AccountConfig& from) {
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
  static const AccountConfig& default_instance();

  void Swap(AccountConfig* other);

  // implements Message ----------------------------------------------

  AccountConfig* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const AccountConfig& from);
  void MergeFrom(const AccountConfig& from);
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

  // optional string BrokerID = 1;
  inline bool has_brokerid() const;
  inline void clear_brokerid();
  static const int kBrokerIDFieldNumber = 1;
  inline const ::std::string& brokerid() const;
  inline void set_brokerid(const ::std::string& value);
  inline void set_brokerid(const char* value);
  inline void set_brokerid(const char* value, size_t size);
  inline ::std::string* mutable_brokerid();
  inline ::std::string* release_brokerid();
  inline void set_allocated_brokerid(::std::string* brokerid);

  // optional string UserID = 2;
  inline bool has_userid() const;
  inline void clear_userid();
  static const int kUserIDFieldNumber = 2;
  inline const ::std::string& userid() const;
  inline void set_userid(const ::std::string& value);
  inline void set_userid(const char* value);
  inline void set_userid(const char* value, size_t size);
  inline ::std::string* mutable_userid();
  inline ::std::string* release_userid();
  inline void set_allocated_userid(::std::string* userid);

  // optional string Password = 3;
  inline bool has_password() const;
  inline void clear_password();
  static const int kPasswordFieldNumber = 3;
  inline const ::std::string& password() const;
  inline void set_password(const ::std::string& value);
  inline void set_password(const char* value);
  inline void set_password(const char* value, size_t size);
  inline ::std::string* mutable_password();
  inline ::std::string* release_password();
  inline void set_allocated_password(::std::string* password);

  // optional string Front_IP = 4;
  inline bool has_front_ip() const;
  inline void clear_front_ip();
  static const int kFrontIPFieldNumber = 4;
  inline const ::std::string& front_ip() const;
  inline void set_front_ip(const ::std::string& value);
  inline void set_front_ip(const char* value);
  inline void set_front_ip(const char* value, size_t size);
  inline ::std::string* mutable_front_ip();
  inline ::std::string* release_front_ip();
  inline void set_allocated_front_ip(::std::string* front_ip);

  // @@protoc_insertion_point(class_scope:AccountConfig)
 private:
  inline void set_has_brokerid();
  inline void clear_has_brokerid();
  inline void set_has_userid();
  inline void clear_has_userid();
  inline void set_has_password();
  inline void clear_has_password();
  inline void set_has_front_ip();
  inline void clear_has_front_ip();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* brokerid_;
  ::std::string* userid_;
  ::std::string* password_;
  ::std::string* front_ip_;
  friend void  protobuf_AddDesc_AccountConfig_2eproto();
  friend void protobuf_AssignDesc_AccountConfig_2eproto();
  friend void protobuf_ShutdownFile_AccountConfig_2eproto();

  void InitAsDefaultInstance();
  static AccountConfig* default_instance_;
};
// ===================================================================


// ===================================================================

// AccountConfig

// optional string BrokerID = 1;
inline bool AccountConfig::has_brokerid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void AccountConfig::set_has_brokerid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void AccountConfig::clear_has_brokerid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void AccountConfig::clear_brokerid() {
  if (brokerid_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    brokerid_->clear();
  }
  clear_has_brokerid();
}
inline const ::std::string& AccountConfig::brokerid() const {
  // @@protoc_insertion_point(field_get:AccountConfig.BrokerID)
  return *brokerid_;
}
inline void AccountConfig::set_brokerid(const ::std::string& value) {
  set_has_brokerid();
  if (brokerid_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    brokerid_ = new ::std::string;
  }
  brokerid_->assign(value);
  // @@protoc_insertion_point(field_set:AccountConfig.BrokerID)
}
inline void AccountConfig::set_brokerid(const char* value) {
  set_has_brokerid();
  if (brokerid_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    brokerid_ = new ::std::string;
  }
  brokerid_->assign(value);
  // @@protoc_insertion_point(field_set_char:AccountConfig.BrokerID)
}
inline void AccountConfig::set_brokerid(const char* value, size_t size) {
  set_has_brokerid();
  if (brokerid_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    brokerid_ = new ::std::string;
  }
  brokerid_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:AccountConfig.BrokerID)
}
inline ::std::string* AccountConfig::mutable_brokerid() {
  set_has_brokerid();
  if (brokerid_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    brokerid_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:AccountConfig.BrokerID)
  return brokerid_;
}
inline ::std::string* AccountConfig::release_brokerid() {
  clear_has_brokerid();
  if (brokerid_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = brokerid_;
    brokerid_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void AccountConfig::set_allocated_brokerid(::std::string* brokerid) {
  if (brokerid_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete brokerid_;
  }
  if (brokerid) {
    set_has_brokerid();
    brokerid_ = brokerid;
  } else {
    clear_has_brokerid();
    brokerid_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:AccountConfig.BrokerID)
}

// optional string UserID = 2;
inline bool AccountConfig::has_userid() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void AccountConfig::set_has_userid() {
  _has_bits_[0] |= 0x00000002u;
}
inline void AccountConfig::clear_has_userid() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void AccountConfig::clear_userid() {
  if (userid_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    userid_->clear();
  }
  clear_has_userid();
}
inline const ::std::string& AccountConfig::userid() const {
  // @@protoc_insertion_point(field_get:AccountConfig.UserID)
  return *userid_;
}
inline void AccountConfig::set_userid(const ::std::string& value) {
  set_has_userid();
  if (userid_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    userid_ = new ::std::string;
  }
  userid_->assign(value);
  // @@protoc_insertion_point(field_set:AccountConfig.UserID)
}
inline void AccountConfig::set_userid(const char* value) {
  set_has_userid();
  if (userid_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    userid_ = new ::std::string;
  }
  userid_->assign(value);
  // @@protoc_insertion_point(field_set_char:AccountConfig.UserID)
}
inline void AccountConfig::set_userid(const char* value, size_t size) {
  set_has_userid();
  if (userid_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    userid_ = new ::std::string;
  }
  userid_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:AccountConfig.UserID)
}
inline ::std::string* AccountConfig::mutable_userid() {
  set_has_userid();
  if (userid_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    userid_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:AccountConfig.UserID)
  return userid_;
}
inline ::std::string* AccountConfig::release_userid() {
  clear_has_userid();
  if (userid_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = userid_;
    userid_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void AccountConfig::set_allocated_userid(::std::string* userid) {
  if (userid_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete userid_;
  }
  if (userid) {
    set_has_userid();
    userid_ = userid;
  } else {
    clear_has_userid();
    userid_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:AccountConfig.UserID)
}

// optional string Password = 3;
inline bool AccountConfig::has_password() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void AccountConfig::set_has_password() {
  _has_bits_[0] |= 0x00000004u;
}
inline void AccountConfig::clear_has_password() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void AccountConfig::clear_password() {
  if (password_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_->clear();
  }
  clear_has_password();
}
inline const ::std::string& AccountConfig::password() const {
  // @@protoc_insertion_point(field_get:AccountConfig.Password)
  return *password_;
}
inline void AccountConfig::set_password(const ::std::string& value) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_ = new ::std::string;
  }
  password_->assign(value);
  // @@protoc_insertion_point(field_set:AccountConfig.Password)
}
inline void AccountConfig::set_password(const char* value) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_ = new ::std::string;
  }
  password_->assign(value);
  // @@protoc_insertion_point(field_set_char:AccountConfig.Password)
}
inline void AccountConfig::set_password(const char* value, size_t size) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_ = new ::std::string;
  }
  password_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:AccountConfig.Password)
}
inline ::std::string* AccountConfig::mutable_password() {
  set_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:AccountConfig.Password)
  return password_;
}
inline ::std::string* AccountConfig::release_password() {
  clear_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = password_;
    password_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void AccountConfig::set_allocated_password(::std::string* password) {
  if (password_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete password_;
  }
  if (password) {
    set_has_password();
    password_ = password;
  } else {
    clear_has_password();
    password_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:AccountConfig.Password)
}

// optional string Front_IP = 4;
inline bool AccountConfig::has_front_ip() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void AccountConfig::set_has_front_ip() {
  _has_bits_[0] |= 0x00000008u;
}
inline void AccountConfig::clear_has_front_ip() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void AccountConfig::clear_front_ip() {
  if (front_ip_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    front_ip_->clear();
  }
  clear_has_front_ip();
}
inline const ::std::string& AccountConfig::front_ip() const {
  // @@protoc_insertion_point(field_get:AccountConfig.Front_IP)
  return *front_ip_;
}
inline void AccountConfig::set_front_ip(const ::std::string& value) {
  set_has_front_ip();
  if (front_ip_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    front_ip_ = new ::std::string;
  }
  front_ip_->assign(value);
  // @@protoc_insertion_point(field_set:AccountConfig.Front_IP)
}
inline void AccountConfig::set_front_ip(const char* value) {
  set_has_front_ip();
  if (front_ip_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    front_ip_ = new ::std::string;
  }
  front_ip_->assign(value);
  // @@protoc_insertion_point(field_set_char:AccountConfig.Front_IP)
}
inline void AccountConfig::set_front_ip(const char* value, size_t size) {
  set_has_front_ip();
  if (front_ip_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    front_ip_ = new ::std::string;
  }
  front_ip_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:AccountConfig.Front_IP)
}
inline ::std::string* AccountConfig::mutable_front_ip() {
  set_has_front_ip();
  if (front_ip_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    front_ip_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:AccountConfig.Front_IP)
  return front_ip_;
}
inline ::std::string* AccountConfig::release_front_ip() {
  clear_has_front_ip();
  if (front_ip_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = front_ip_;
    front_ip_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void AccountConfig::set_allocated_front_ip(::std::string* front_ip) {
  if (front_ip_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete front_ip_;
  }
  if (front_ip) {
    set_has_front_ip();
    front_ip_ = front_ip;
  } else {
    clear_has_front_ip();
    front_ip_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:AccountConfig.Front_IP)
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_AccountConfig_2eproto__INCLUDED
