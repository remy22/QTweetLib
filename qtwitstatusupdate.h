/* Copyright (c) 2010, Antonie Jovanoski
 *
 * All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Contact e-mail: Antonie Jovanoski <minimoog77_at_gmail.com>
 */

#ifndef QTWITSTATUSUPDATE_H
#define QTWITSTATUSUPDATE_H

#include "qtwitnetbase.h"

class QTWITLIBSHARED_EXPORT QTwitStatusUpdate : public QTwitNetBase
{
    Q_OBJECT
public:
    QTwitStatusUpdate(QObject *parent = 0);
    QTwitStatusUpdate(OAuthTwitter *oauthTwitter, QObject *parent = 0);
    void post(const QString& status,
              qint64 inReplyToStatus = 0,
              qreal latitude = 0,
              qreal longitude = 0,
              const QString& placeid = QString(),
              bool displayCoordinates = false,
              ResponseType respType = QTwitNetBase::JSON);

private slots:
    void reply();
    void error();
};

#endif // QTWITSTATUSUPDATE_H