#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include "findreplacedialog.h"

class FindDialog : public FindReplaceDialog
{
    Q_OBJECT
public:
    FindDialog(QWidget *parent = nullptr);
    ~FindDialog();

    virtual void writeSettings(QSettings &settings,
                               const QString &prefix = "FindDialog");

    virtual void readSettings(QSettings &settings,
                              const QString &prefix = "FindDialog");
};

#endif // FINDDIALOG_H
