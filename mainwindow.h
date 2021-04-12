#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class FindDialog;
class FindReplaceDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();    
private slots:
    void on_actionAbrir_triggered();
    void on_actionNuevo_triggered();
    void on_actionGuardar_como_triggered();
    void on_actionQuitar_triggered();
    void on_actionCopiar_triggered();
    void on_actionPegar_triggered();
    void on_actionCortar_triggered();
    void on_actionSeleccionar_todo_triggered();
    void on_actionTipo_de_fuente_triggered();
    void on_actionColor_de_fuente_triggered();
    void on_actionColor_de_fondo_triggered();
    void on_actionAcerca_de_Bloc_de_notas_triggered();
    void on_actionImprimir_triggered();
    void on_actionDeshacer_triggered();
    void on_actionRehacer_triggered();
    void on_actionEncontrar_triggered();
    void on_actionReemplazar_triggered();
    void on_actionEncontrar_anterior_triggered();
    void on_actionEncontrar_siguiente_triggered();
private:
    Ui::MainWindow *ui;
    FindDialog *m_findDialog;
    FindReplaceDialog *m_findReplaceDialog;
};

#endif // MAINWINDOW_H
