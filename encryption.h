#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <QWidget>
#include <string>
#include <fstream>
#include <QLineEdit>

namespace Ui {
class encryption;
}

class encryption : public QWidget
{
    Q_OBJECT

public:
    explicit encryption(QWidget *parent = nullptr);
    ~encryption();

private:
    Ui::encryption *ui;
    QString filename;
    void generate_key_RC4(unsigned char k[], const std::string& key);
    unsigned long long int get_size(const std::string& in_name);
    void encryption_process(unsigned char key[], const std::string& in_name);

private slots:
    void start();
    void choose();
};

#endif // ENCRYPTION_H
