#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void slotTimerAlarm();
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void upd();
    void checkFood();
    void placeFood();
    bool checkSelf();
    void newGame();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
    QTimer* timer;

protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
