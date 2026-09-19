#include "encryptor.h"
#include <iterator>
#include <iostream>
#include <sodium/crypto_aead_chacha20poly1305.h>

void encrypt(std::string str) {
  unsigned char key[crypto_aead_chacha20poly1305_ietf_KEYBYTES];
  unsigned char nonce[crypto_aead_chacha20poly1305_ietf_NPUBBYTES];
  
  size_t size_str = std::size(str);

  unsigned char
      cipher_text[size_str + crypto_aead_chacha20poly1305_ietf_ABYTES];

  unsigned long long cipher_len;
  randombytes_buf(key, sizeof key);
  randombytes_buf(nonce, sizeof nonce);

  int ae = crypto_aead_xchacha20poly1305_ietf_encrypt(
      cipher_text, &cipher_len, (const unsigned char *)&str, size_str,
      NULL, // additional authenticated data
      0, NULL, nonce, key);

  for (int i = 0; i < cipher_len; i++) {
    std::cout << cipher_text[i];
  }
}

