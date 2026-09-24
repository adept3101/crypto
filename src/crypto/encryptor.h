#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H
#include <array>
#include <sodium.h>
#include <string>
#include <boost/beast/core/detail/base64.hpp>
#include <sodium/crypto_aead_chacha20poly1305.h>

namespace base64 = boost::beast::detail::base64;

typedef struct {
  std::string cipher_text;
  std::string nonce;
} encrypted_data;

encrypted_data encrypt(
    const std::string &text,
    const std::array<unsigned char, crypto_aead_chacha20poly1305_ietf_KEYBYTES>
        &key);

std::string encode(const std::string &data);

#endif // !ENCRYPTOR_H
#define ENCRYPTOR_H
