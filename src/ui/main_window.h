#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

class QPlainTextEdit;
class QPushButton;

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);

private slots:
  void encryptText();

private:
  QPlainTextEdit *inputText;
  QPlainTextEdit *outputText;
  QPushButton *encryptButton;
};

#endif
