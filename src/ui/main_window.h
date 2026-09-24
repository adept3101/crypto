#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <array>
#include <sodium.h>

class QPlainTextEdit;
class QPushButton;

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);

private slots:
  void encryptText();

private:
  std::array<unsigned char, crypto_aead_chacha20poly1305_ietf_KEYBYTES> key;
  QPlainTextEdit *inputText;
  QPlainTextEdit *outputText;
  QPushButton *encryptButton;
};

#endif
