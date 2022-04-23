#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"



using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() // Шифр
{
        QString openMessage;
        QString key;

        openMessage = ui->textedit->text();
        key = ui->keyline->text();

        if (openMessage.isEmpty() || ui->keyline->text().isEmpty())
        {
            QMessageBox::warning(this,"Ошибка", "Поле открытого текста пусто или ключ");
        }
        else
        {
            int message_length = openMessage.size(), key_length = key.size(); // длина
                message_length++;
                QString temp_key;
                QString encrypted_message;

                for (int i = 0, j = 0; i < message_length - 1; i++, j++)
                    {
                        if (j == key_length) j = 0;
                        temp_key.insert(i,key[j]);
                    }

                    for (int i = 0; i < message_length - 1; i++)
                    {
                        int temp = (openMessage[i].unicode() + temp_key[i].unicode()-48);
                        if ((openMessage[i].unicode()>=1040 && openMessage[i].unicode()<=1071) && temp >1071) temp -=32;
                        if ((openMessage[i].unicode()>=1072 && openMessage[i].unicode()<=1103) && temp >1103) temp -=32;

                        if ((openMessage[i].unicode()>=65 && openMessage[i].unicode()<=90) && temp >90) temp -=26;
                        if ((openMessage[i].unicode()>=97 && openMessage[i].unicode()<=122) && temp >122) temp -=26;
                        encrypted_message.insert(i,(QChar)temp);
                    }
        ui -> textedit_2 -> setText(encrypted_message);
        }
}

void MainWindow::on_pushButton_2_clicked() // Дешифр
{
    QString closeMessage;
    QString key;

    closeMessage = ui->textedit_2->text();
    key = ui->keyline->text();

    if (closeMessage.isEmpty() || ui->keyline->text().isEmpty())
    {
        QMessageBox::warning(this,"Ошибка", "Поле открытого текста пусто или ключ");
    }
    else
    {
        int message_length = closeMessage.size(), key_length = key.size(); // длина
            message_length++;
            QString temp_key;
            QString decrypted_message;

            for (int i = 0, j = 0; i < message_length - 1; i++, j++)
                {
                    if (j == key_length) j = 0;
                    temp_key.insert(i,key[j]);
                }

                for (int i = 0; i < message_length - 1; i++)
                {
                    int temp = (closeMessage[i].unicode() - (temp_key[i].unicode()-48));
                    if ((closeMessage[i].unicode()>=1040 && closeMessage[i].unicode()<=1071) && temp >1071) temp -=32;
                    if ((closeMessage[i].unicode()>=1072 && closeMessage[i].unicode()<=1103) && temp >1103) temp -=32;

                    if ((closeMessage[i].unicode()>=65 && closeMessage[i].unicode()<=90) && temp >90) temp -=26;
                    if ((closeMessage[i].unicode()>=97 && closeMessage[i].unicode()<=122) && temp >122) temp -=26;
                    decrypted_message.insert(i,(QChar)temp);
                }
    ui -> textedit -> setText(decrypted_message);
    }

}

