#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_v0_clicked();

    void on_v1_clicked();

    void on_v2_clicked();

    void on_v3_clicked();

    void on_v4_clicked();

    void on_v5_clicked();

    void on_v6_clicked();

    void on_v7_clicked();

    void on_v8_clicked();

    void on_buscar_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
