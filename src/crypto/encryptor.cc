#include "encryptor.h"

#include <array>
#include <boost/beast/core/detail/base64.hpp>
#include <sodium/crypto_aead_chacha20poly1305.h>
#include <sodium/randombytes.h>
#include <stdexcept>

// std::string encrypt(std::string str) {
//   // unsigned char key[crypto_aead_chacha20poly1305_ietf_KEYBYTES];
//   encrypted_data res;
//
//   unsigned char nonce[crypto_aead_chacha20poly1305_ietf_NPUBBYTES];
//
//   size_t size_str = std::size(str);
//
//   std::string cipher_text(
//       std::size(str) + crypto_aead_chacha20poly1305_ietf_ABYTES, '\0');
//
//   unsigned long long cipher_len;
//   randombytes_buf(key, sizeof key);
//   randombytes_buf(nonce, sizeof nonce);
//
//   int ae = crypto_aead_chacha20poly1305_ietf_encrypt(
//       reinterpret_cast<unsigned char *>(cipher_text.data()), &cipher_len,
//       (const unsigned char *)&str, size_str,
//       NULL, // additional authenticated data
//       0, NULL, nonce, key);
//
//   if (ae != 0) {
//     throw std::runtime_error("encrypt failed");
//   }
//
//   cipher_text.resize(cipher_len);
//   return cipher_text;
// }

encrypted_data encrypt(
    const std::string &text,
    const std::array<unsigned char, crypto_aead_chacha20poly1305_ietf_KEYBYTES>
        &key) {
  encrypted_data res;

  res.nonce.resize(crypto_aead_chacha20poly1305_ietf_NPUBBYTES);

  randombytes_buf(res.nonce.data(), res.nonce.size());

  res.cipher_text.resize(text.size() +
                         crypto_aead_chacha20poly1305_ietf_ABYTES);
  unsigned long long cipher_len;

  int ae = crypto_aead_chacha20poly1305_ietf_encrypt(
      reinterpret_cast<unsigned char *>(res.cipher_text.data()), &cipher_len,
      reinterpret_cast<const unsigned char *>(text.data()), text.size(),
      NULL, // additional authenticated data
      0, NULL, reinterpret_cast<const unsigned char *>(res.nonce.data()),
      key.data());

  if (ae != 0) {
    throw std::runtime_error("encrypt failed");
  }

  return res;
}

std::string encode(const std::string &data) {
  std::string res;
  res.resize(base64::encoded_size(data.size()));

  base64::encode(res.data(), reinterpret_cast<const uint8_t *>(data.data()),
                 data.size());

  return res;
  // return boost::beast::detail::base64::encode(
  //     reinterpret_cast<const uint8_t *>(data.data()), data.size());
}
