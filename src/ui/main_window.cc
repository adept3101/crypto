#include "main_window.h"
#include "encryptor.h"

#include <QLabel>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  setWindowTitle("Шифратор");
  resize(600, 500);

  QWidget *centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);

  QVBoxLayout *layout = new QVBoxLayout(centralWidget);

  QLabel *inputLabel = new QLabel("Исходный текст:");
  layout->addWidget(inputLabel);

  inputText = new QPlainTextEdit();
  inputText->setPlaceholderText("Введите текст...");
  layout->addWidget(inputText);

  encryptButton = new QPushButton("Зашифровать");
  layout->addWidget(encryptButton);

  QLabel *outputLabel = new QLabel("Зашифрованный текст:");
  layout->addWidget(outputLabel);

  outputText = new QPlainTextEdit();
  outputText->setReadOnly(true);
  layout->addWidget(outputText);

  connect(encryptButton, &QPushButton::clicked, this, &MainWindow::encryptText);
}

void MainWindow::encryptText() {
  QString text = inputText->toPlainText();

  std::string encrypted_ = encrypt(text.toStdString());
  std::string encrypted = encrypt(encrypted_);

  outputText->setPlainText(
      QString::fromLatin1(encrypted.data(), encrypted.size()));
}
