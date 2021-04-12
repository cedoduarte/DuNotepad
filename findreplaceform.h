#ifndef FINDREPLACEFORM_H
#define FINDREPLACEFORM_H

#include <QWidget>
#include <QTextCursor>

namespace Ui
{
class FindReplaceForm;
}

class QTextEdit;
class QSettings;

class FindReplaceForm : public QWidget
{
    Q_OBJECT
public:
    FindReplaceForm(QWidget *parent = nullptr);
    virtual ~FindReplaceForm();
    void setTextEdit(QTextEdit *textEdit_);
    void hideReplaceWidgets();

    virtual void writeSettings(QSettings &settings,
                               const QString &prefix = "FindReplaceDialog");

    virtual void readSettings(QSettings &settings,
                              const QString &prefix = "FindReplaceDialog");
public slots:
    void find(bool down);
    void find();

    void findNext()
    {
        find(true);
    }

    void findPrev()
    {
        find(false);
    }

    void replace();
    void replaceAll();
protected:
    void changeEvent(QEvent *e);
    void showError(const QString &error);
    void showMessage(const QString &message);
protected slots:
    void textToFindChanged();
    void validateRegExp(const QString &text);
    void regexpSelected(bool sel);
protected:
    Ui::FindReplaceForm *ui;
    QTextCursor textCursor;
    QTextEdit *textEdit;
};

#endif // FINDREPLACEFORM_H
