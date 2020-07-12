#ifndef ASTRAUPDATER_ASTRAUPDATER_H
#define ASTRAUPDATER_ASTRAUPDATER_H

#include "adminauthoriser.h"

#include <QtCore/qobject.h>
#include <QtCore/qstring.h>
#include <QtCore/qlist.h>
#include <QtCore/qstringlist.h>
#include <QtCore/qdatetime.h>
#include <QtCore/qversionnumber.h>
#include <QtCore/qscopedpointer.h>

namespace QtAstraUpdater
{

class AstraUpdaterPrivate;
//! The main updater. Can check for updates and run the current app as updater
class AstraUpdater : public QObject
{
	Q_OBJECT

	//! Holds currentVersion
	Q_PROPERTY(QString currentVersion READ currentVersion CONSTANT FINAL)
	//! Specifies whether the updater is currently checking for updates or not
	Q_PROPERTY(bool running READ isRunning NOTIFY runningChanged)
	//! Holds extended information about the last update check
	Q_PROPERTY(QList<AstraUpdateInfo> updateInfo READ updateInfo NOTIFY updateInfoChanged)

public:
	//! Provides information about updates for components
	struct AstraUpdateInfo
	{
		//! The name of the component that has an update
		QString name;
		//! The new version for that compontent
		QString version;
		//! The update download size (in Bytes)
		quint64 size;

		//! Default Constructor
		AstraUpdateInfo();
		//! Copy Constructor
		AstraUpdateInfo(const AstraUpdateInfo &other);
		//! Constructor that takes name, version and size
		AstraUpdateInfo(QString name, QString version, quint64 size);
	};

	static const QStringList NormalUpdateArguments;
	static const QStringList PassiveUpdateArguments;
	static const QStringList HiddenUpdateArguments;

	//! Default constructor
	explicit AstraUpdater(QObject *parent = nullptr);
	//! Constructer with an explicitly set currentVersion
	explicit AstraUpdater(const QString &currentVersion, QObject *parent = nullptr);
	//! Destroyes the updater and kills the update check (if running)
	~AstraUpdater();

	//! Returns `true`, if the updater exited normally
	bool exitedNormally() const;
	//! Returns the error code of the last update
	int errorCode() const;
	//! returns the error output (stderr) of the last update
	QByteArray errorLog() const;

	//! Returns `true` if will be started on exit
	bool willRunOnExit() const;

	//! readAcFn{AstraUpdater::currentVersion}
	QString currentVersion() const;
	//! readAcFn{AstraUpdater::running}
	bool isRunning() const;
	//! readAcFn{AstraUpdater::updateInfo}
	QList<AstraUpdateInfo> updateInfo() const;

public Q_SLOTS:
	//! Starts checking for updates
	bool checkForUpdates();
	//! Aborts checking for updates
	void abortUpdateCheck(int maxDelay = 5000, bool async = false);

	//! Schedules an update after a specific delay, optionally repeated
	int scheduleUpdate(int delaySeconds, bool repeated = false);
	//! Schedules an update for a specific timepoint
	int scheduleUpdate(const QDateTime &when);
	//! Cancels the scheduled update with taskId
	void cancelScheduledUpdate(int taskId);

	//! Runs the updater on exit, using the given admin authorisation
	void runUpdaterOnExit(AdminAuthoriser *authoriser = nullptr);
	//! Runs the updater on exit, using the given arguments and admin authorisation
	void runUpdaterOnExit(const QStringList &arguments, AdminAuthoriser *authoriser = nullptr);
	//! The updater will not run the updater on exit anymore
	void cancelExitRun();

Q_SIGNALS:
	//! Will be emitted as soon as the updater finished checking for updates
	void checkUpdatesDone(bool hasUpdates, bool hasError);

	//! notifyAcFn{AstraUpdater::running}
	void runningChanged(bool running);
	//! notifyAcFn{AstraUpdater::updateInfo}
	void updateInfoChanged(QList<AstraUpdater::AstraUpdateInfo> updateInfo);

private:
	QScopedPointer<AstraUpdaterPrivate> d;
};

}

Q_DECLARE_METATYPE(QtAstraUpdater::AstraUpdater::AstraUpdateInfo)

QDebug &operator<<(QDebug &debug, const QtAstraUpdater::AstraUpdater::AstraUpdateInfo &info);

#endif // ASTRAUPDATER_ASTRAUPDATER_H
