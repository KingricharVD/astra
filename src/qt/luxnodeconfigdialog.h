#ifndef ASTRANODECONFIGDIALOG_H
#define ASTRANODECONFIGDIALOG_H

#include <QDialog>

namespace Ui {
    class AstraNodeConfigDialog;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Dialog showing transaction details. */
class AstraNodeConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AstraNodeConfigDialog(QWidget *parent = 0, QString nodeAddress = "123.456.789.123:28666", QString privkey="MASTERNODEPRIVKEY");
    ~AstraNodeConfigDialog();

private:
    Ui::AstraNodeConfigDialog *ui;
};

#endif // ASTRANODECONFIGDIALOG_H
