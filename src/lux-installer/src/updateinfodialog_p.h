#ifndef QTASTRAUPDATER_UPDATEINFODIALOG_H
#define QTASTRAUPDATER_UPDATEINFODIALOG_H

#include "luxupdater/luxupdater.h"

#include <QDialog>

namespace Ui {
class UpdateInfoDialog;
}

namespace QtAstraUpdater
{

class UpdateInfoDialog : public QDialog
{
	Q_OBJECT

public:
	enum DialogResult {
		InstallNow = QDialog::Accepted,
		InstallLater = QDialog::Accepted + 1,
		NoInstall = QDialog::Rejected
	};
	Q_ENUM(DialogResult)

	static DialogResult showUpdateInfo(QList<AstraUpdater::AstraUpdateInfo> updates,
									   bool &runAsAdmin,
									   bool editable,
									   bool detailed,
									   QWidget *parent);

private Q_SLOTS:
	void on_acceptButton_clicked();
	void on_delayButton_clicked();

private:
	QScopedPointer<Ui::UpdateInfoDialog> ui;

	explicit UpdateInfoDialog(QWidget *parent = nullptr);
	~UpdateInfoDialog();

	static QString getByteText(qint64 bytes);
};

}

#endif // QTASTRAUPDATER_UPDATEINFODIALOG_H
