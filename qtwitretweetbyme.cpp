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

#include <QNetworkRequest>
#include <QNetworkReply>
#include "qtwitretweetbyme.h"

QTwitRetweetByMe::QTwitRetweetByMe(QObject *parent) :
    QTwitNetBase(parent)
{
}

QTwitRetweetByMe::QTwitRetweetByMe(OAuthTwitter *oauthTwitter, QObject *parent) :
        QTwitNetBase(oauthTwitter, parent)
{
}

void QTwitRetweetByMe::fetch(ResponseType respType,
                                qint64 sinceid,
                                qint64 maxid,
                                int count,
                                int page)
{
    Q_ASSERT(oauthTwitter() != 0);

    QUrl url;

    if (respType == QTwitNetBase::JSON)
        url.setUrl("http://api.twitter.com/1/statuses/retweeted_by_me.json");
    else
        url.setUrl("http://api.twitter.com/1/statuses/retweeted_by_me.xml");

    if (sinceid != 0)
        url.addQueryItem("since_id", QString::number(sinceid));

    if (maxid != 0)
        url.addQueryItem("max_id", QString::number(maxid));

    if (count != 0)
        url.addQueryItem("count", QString::number(count));

    if (page != 0)
        url.addQueryItem("page", QString::number(page));

    QNetworkRequest req(url);

    QByteArray oauthHeader = oauthTwitter()->generateAuthorizationHeader(url, OAuth::GET);
    req.setRawHeader(AUTH_HEADER, oauthHeader);

    QNetworkReply *reply = oauthTwitter()->networkAccessManager()->get(req);
    connect(reply, SIGNAL(finished()), this, SLOT(reply()));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error()));
}

void QTwitRetweetByMe::reply()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());

    if (reply) {
         m_response = reply->readAll();
        emit finished(m_response);

        reply->deleteLater();
    }
}

void QTwitRetweetByMe::error()
{
    // ### TODO
}