#ifndef FINDREPLACEDIALOG_H
#define FINDREPLACEDIALOG_H

#include <QDialog>

namespace Ui {
    class FindReplaceDialog;
}

class QTextEdit;
class QSettings;

class FindReplaceDialog : public QDialog
{
    Q_OBJECT
public:
    FindReplaceDialog(QWidget *parent = nullptr);
    virtual ~FindReplaceDialog();

    void setTextEdit(QTextEdit *textEdit);

    virtual void writeSettings(QSettings &settings,
                               const QString &prefix = "FindReplaceDialog");

    virtual void readSettings(QSettings &settings,
                              const QString &prefix = "FindReplaceDialog");
public slots:
    void findNext();
    void findPrev();
protected:
    void changeEvent(QEvent *e);

    Ui::FindReplaceDialog *ui;
};

#endif // FINDREPLACEDIALOG_H
