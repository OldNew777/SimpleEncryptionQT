#include "encryption.h"
#include "ui_encryption.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>

encryption::encryption(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::encryption)
{
    ui->setupUi(this);
    connect(ui->pushButtonchoose, SIGNAL(clicked()), this, SLOT(choose()));
    connect(ui->pushButtonstart, SIGNAL(clicked()), this, SLOT(start()));
    this->setFixedSize(600, 300);
}

encryption::~encryption()
{
    delete ui;
}

void encryption::start()
{
    QString tmp = ui->textEditkey->text();
    if (tmp == "" || filename == "")
    {
        QMessageBox::warning(this, "Warning", "The filename/key can not be empty. ");
        return;
    }
    std::string key = tmp.toStdString(), file = filename.toStdString();
    unsigned char k[256];
    generate_key_RC4(k, key);
    encryption_process(k, file);
}

void encryption::choose()
{
    filename = QFileDialog::getOpenFileName(this, tr("选择加密文件..."), ".\\", tr("文件(*)"));
    if (filename == "")
        return;
    ui->textEditfile->setText(filename);
}



void encryption::generate_key_RC4(unsigned char k[], const std::string& key)
{
    unsigned char t[256];
    for (unsigned int i = 0; i < 256; ++i)
    {
        k[i] = i;
        t[i] = key[i % key.length()];
    }
    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + k[i] + t[i]) % 256;
        std::swap(k[i], k[j]);
    }
    return;
}

unsigned long long int encryption::get_size(const std::string& in_name)
{
    FILE* fp = nullptr;
    unsigned long long int nFileLen = 0;
    char name_char[200];
    for (unsigned int i = 0; i < in_name.length(); ++i)
        name_char[i] = in_name[i];
    name_char[in_name.length()] = '\0';
    fp = fopen(name_char, "r");
    if (fp != nullptr)
    {
        fseek(fp, 0, SEEK_END); //定位到文件末
        nFileLen = ftell(fp); //文件长度
        fclose(fp);
    }
    return nFileLen;
}

void encryption::encryption_process(unsigned char key[], const std::string& in_name)
{
    unsigned long long int nFileLen = get_size(in_name);
    std::string out_name = in_name;
    unsigned int tmp = out_name.length()-1;
    while (out_name[tmp] != '.')
        tmp--;
    out_name.insert(tmp, "_encrypted");

    unsigned char s[256];
    for (int i = 0; i < 256; ++i)
        s[i] = key[i];

    std::ifstream fin(in_name, std::ios::binary);
    std::ofstream fout(out_name, std::ios::binary);

    unsigned char* ch = new unsigned char;
    int i = 0, j = 0;
    for (; nFileLen > 0; --nFileLen)
    {
        fin.read(reinterpret_cast<char*>(ch), sizeof(char));
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;
        std::swap(s[i], s[j]);
        int f = (s[i] + s[j]) % 256;
        *ch ^= s[f];
        fout.write(reinterpret_cast<char*>(ch), sizeof(char));
    }
    delete ch;
    fin.close();
    fout.close();
    return;
}
