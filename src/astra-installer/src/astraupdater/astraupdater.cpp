#include "astraupdater.h"
#include "astraupdater_p.h"
#include "../updatecontroller_p.h"

#include <QtCore/QDebug>
#include <QtCore/QList>
#include <QtCore/QMap>

using namespace QtAstraUpdater;

const QStringList AstraUpdater::NormalUpdateArguments = {QStringLiteral("--updater")};
const QStringList AstraUpdater::PassiveUpdateArguments = {QStringLiteral("--updater"), QStringLiteral("skipPrompt=true")};
const QStringList AstraUpdater::HiddenUpdateArguments = {QStringLiteral("--silentUpdate")};

AstraUpdater::AstraUpdater(QObject *parent) :
	AstraUpdater("", parent)
{}

AstraUpdater::AstraUpdater(const QString &currentVersion, QObject *parent) :
	QObject(parent),
	d(new AstraUpdaterPrivate(this))
{
	d->currentVersion = currentVersion;
}

AstraUpdater::~AstraUpdater() {}

bool AstraUpdater::exitedNormally() const
{
	return d->normalExit;
}

int AstraUpdater::errorCode() const
{
	return d->lastErrorCode;
}

QByteArray AstraUpdater::errorLog() const
{
	return d->lastErrorLog;
}

bool AstraUpdater::willRunOnExit() const
{
	return d->runOnExit;
}

QString AstraUpdater::currentVersion() const
{
	return d->currentVersion;
}

bool AstraUpdater::isRunning() const
{
	return isUpdaterRunning;
}

QList<AstraUpdater::AstraUpdateInfo> AstraUpdater::updateInfo() const
{
	return d->updateInfos;
}

bool AstraUpdater::checkForUpdates()
{
	return d->startUpdateCheck();
}

void AstraUpdater::abortUpdateCheck(int maxDelay, bool async)
{
	d->stopUpdateCheck(maxDelay, async);
}

int AstraUpdater::scheduleUpdate(int delaySeconds, bool repeated)
{
	if((((qint64)delaySeconds) * 1000ll) > (qint64)INT_MAX) {
		qCWarning(logAstraUpdater) << "delaySeconds to big to be converted to msecs";
		return 0;
	}
	return d->scheduler->startSchedule(delaySeconds * 1000, repeated);
}

int AstraUpdater::scheduleUpdate(const QDateTime &when)
{
	return d->scheduler->startSchedule(when);
}

void AstraUpdater::cancelScheduledUpdate(int taskId)
{
	d->scheduler->cancelSchedule(taskId);
}

void AstraUpdater::runUpdaterOnExit(AdminAuthoriser *authoriser)
{
	runUpdaterOnExit(NormalUpdateArguments, authoriser);
}

void AstraUpdater::runUpdaterOnExit(const QStringList &arguments, AdminAuthoriser *authoriser)
{
	d->runOnExit = true;
	d->runArguments = arguments;
	d->adminAuth.reset(authoriser);
}

void AstraUpdater::cancelExitRun()
{
	d->runOnExit = false;
	d->adminAuth.reset();
}



AstraUpdater::AstraUpdateInfo::AstraUpdateInfo() :
	name(),
	version(),
	size(0ull)
{}

AstraUpdater::AstraUpdateInfo::AstraUpdateInfo(const AstraUpdater::AstraUpdateInfo &other) :
	name(other.name),
	version(other.version),
	size(other.size)
{}

AstraUpdater::AstraUpdateInfo::AstraUpdateInfo(QString name, QString version, quint64 size) :
	name(name),
	version(version),
	size(size)
{}

QDebug &operator<<(QDebug &debug, const AstraUpdater::AstraUpdateInfo &info)
{
	QDebugStateSaver state(debug);
	Q_UNUSED(state);

	debug.noquote() << QStringLiteral("{Name: \"%1\"; Version: %2; Size: %3}")
					   .arg(info.name)
					   .arg(info.version.toUtf8().constData())
					   .arg(info.size);
	return debug;
}
