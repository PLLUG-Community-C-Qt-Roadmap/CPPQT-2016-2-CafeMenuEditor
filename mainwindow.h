#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <memory>

namespace Ui {
class MainWindow;
}

class AbstractMenuItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void slotPrintMenu();

private slots:
    void menuElementSelected();

    void slotUpdateMenu();
    void slotAddNewItem();

    void slotItemChanged();
    void slotSaveEditedItem();

private:
    void createMenu();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<AbstractMenuItem> mRoot;
};

#endif // MAINWINDOW_H
