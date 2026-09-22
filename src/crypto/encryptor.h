#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H
#include <sodium.h>
#include <string>
// #include <iterator>
#include <boost/beast/core/detail/base64.hpp>
#include <sodium/crypto_aead_chacha20poly1305.h>

namespace base64 = boost::beast::detail::base64;

std::string encrypt(std::string str);
std::string encode(const std::string &data);

#endif // !ENCRYPTOR_H
#define ENCRYPTOR_H
