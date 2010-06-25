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

#ifndef QTWITSTATUS_H
#define QTWITSTATUS_H

#include <QSharedDataPointer>

class QTwitStatusData;
class QTwitUser;

class QTwitStatus
{
public:
    QTwitStatus();
    QTwitStatus(const QTwitStatus &);
    QTwitStatus &operator=(const QTwitStatus &);
    ~QTwitStatus();

    void setId(qint64 id);
    qint64 id() const;
    void setText(const QString& text);
    QString text() const;
    void setSource(const QString& source);
    QString source() const;
    void setInReplyToStatusId(qint64 id);
    qint64 inReplyToStatusId() const;
    void setInReplyToUserId(qint64 id);
    qint64 inReplyToUserId() const;
    void setInReplyToScreenName(const QString& screenName);
    QString inReplyToScreenName() const;
    void setUser(const QTwitUser& user);
    QTwitUser user() const;

private:
    QSharedDataPointer<QTwitStatusData> data;
};

#endif // QTWITSTATUS_H