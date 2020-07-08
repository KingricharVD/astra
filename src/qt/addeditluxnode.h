#ifndef ADDEDITASTRANODE_H
#define ADDEDITASTRANODE_H

#include <QDialog>

namespace Ui {
class AddEditAstraNode;
}


class AddEditAstraNode : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditAstraNode(QWidget *parent = 0);
    ~AddEditAstraNode();

protected:

private Q_SLOTS:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

signals:

private:
    Ui::AddEditAstraNode *ui;
};

#endif // ADDEDITASTRANODE_H
