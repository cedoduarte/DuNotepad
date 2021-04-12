#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "finddialog.h"
#include "findreplacedialog.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QFontDialog>
#include <QColorDialog>
#include <QPrintDialog>
#include <QPrinter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);
    m_findDialog = new FindDialog(this);
    m_findDialog->setModal(false);
    m_findDialog->setTextEdit(ui->textEdit);
    m_findReplaceDialog = new FindReplaceDialog(this);
    m_findReplaceDialog->setModal(false);
    m_findReplaceDialog->setTextEdit(ui->textEdit); 
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbrir_triggered()
{
    QFileDialog dialogo(this);
    dialogo.setAcceptMode(QFileDialog::AcceptOpen);
    dialogo.setFileMode(QFileDialog::AnyFile);
    if (dialogo.exec() == QDialog::Rejected) {
        return;
    }
    const QString nombreArchivo = dialogo.selectedFiles().first();
    QFile archivo(nombreArchivo);
    archivo.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!archivo.isOpen()) {
        return;
    }
    QTextStream str(&archivo);
    QString contenido;
    contenido = str.readAll();
    archivo.flush();
    archivo.close();
    ui->textEdit->setText(contenido);
}

void MainWindow::on_actionNuevo_triggered()
{
    ui->textEdit->clear();
}

void MainWindow::on_actionGuardar_como_triggered()
{
    QFileDialog dialogo(this);
    dialogo.setAcceptMode(QFileDialog::AcceptSave);
    dialogo.setFileMode(QFileDialog::AnyFile);
    if (dialogo.exec() == QDialog::Rejected) {
        return;
    }
    const QString nombreArchivo = dialogo.selectedFiles().first();
    QFile archivo(nombreArchivo);
    archivo.open(QIODevice::WriteOnly | QIODevice::Text);
    if (!archivo.isOpen()) { return; }
    QTextStream str(&archivo);
    const QString contenido = ui->textEdit->toPlainText();
    str << contenido;
    archivo.flush();
    archivo.close();
}

void MainWindow::on_actionQuitar_triggered()
{
    close();
}

void MainWindow::on_actionCopiar_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPegar_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionCortar_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionSeleccionar_todo_triggered()
{
    ui->textEdit->selectAll();
}

void MainWindow::on_actionTipo_de_fuente_triggered()
{
    bool ok = true;
    QFont fuente = QFontDialog::getFont(&ok, this);
    if (!ok) {
        return;
    }
    ui->textEdit->setCurrentFont(fuente);
}

void MainWindow::on_actionColor_de_fuente_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this);
    ui->textEdit->setTextColor(color);
}

void MainWindow::on_actionColor_de_fondo_triggered()
{
    QPalette paleta;  
    QColorDialog dialogo(this);
    if (dialogo.exec() == QDialog::Rejected) {
        return;
    }
    QColor color = dialogo.selectedColor();
    paleta.setColor(QPalette::Base, color);
    ui->textEdit->setPalette(paleta);
}

void MainWindow::on_actionAcerca_de_Bloc_de_notas_triggered()
{
    const QString texto = "Autor: Carlos Enrique Duarte Ortiz\n" \
            "Fecha: 17/03/2013\nCompañía: DuarteCorporation";
    QMessageBox::about(this, "Acerca de Mi Bloc de notas", texto);
}

void MainWindow::on_actionImprimir_triggered()
{
    QPrinter impresora;
    QTextDocument *documento = ui->textEdit->document();
    QPrintDialog dialogo(&impresora, this);
    if (dialogo.exec() == QDialog::Rejected) {
        return;
    }
    documento->print(&impresora);
}

void MainWindow::on_actionDeshacer_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRehacer_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionEncontrar_triggered()
{
    m_findDialog->show();
}

void MainWindow::on_actionReemplazar_triggered()
{
    m_findReplaceDialog->show();
}

void MainWindow::on_actionEncontrar_anterior_triggered()
{
    m_findDialog->findNext();
}

void MainWindow::on_actionEncontrar_siguiente_triggered()
{
    m_findDialog->findPrev();
}
