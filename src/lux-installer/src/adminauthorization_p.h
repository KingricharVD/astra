#ifndef QTASTRAUPDATER_ADMINAUTHORIZATION_P_H
#define QTASTRAUPDATER_ADMINAUTHORIZATION_P_H

#include "luxupdater/adminauthoriser.h"

namespace QtAstraUpdater
{

class AdminAuthorization : public AdminAuthoriser
{
public:
	bool hasAdminRights() override;
	bool executeAsAdmin(const QString &program, const QStringList &arguments) override;
};

}

#endif // QTASTRAUPDATER_ADMINAUTHORIZATION_P_H
