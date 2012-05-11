/****************************************************************************
**
** Copyright (C) 2012 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://qt.digia.com
**
** This file is part of the Qt Commercial Charts Add-on.
**
** $QT_BEGIN_LICENSE$
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.digia.com
** $QT_END_LICENSE$
**
****************************************************************************/

#include "declarativeareaseries.h"
#include "declarativechart.h"
#include "qchart.h"

QTCOMMERCIALCHART_BEGIN_NAMESPACE

DeclarativeAreaSeries::DeclarativeAreaSeries(QObject *parent) :
    QAreaSeries(new QLineSeries(parent), new QLineSeries(parent))
{
}

bool DeclarativeAreaSeries::setDeclarativeUpperModel(DeclarativeXyModel *model)
{
    QAbstractItemModel *m = qobject_cast<QAbstractItemModel *>(model);
    bool value(false);
    if (m) {
        upperSeries()->setModel(m);
        upperSeries()->setModelMapping(0, 1, Qt::Vertical);
    } else {
        qWarning("DeclarativeAreaSeries: Illegal model");
    }
    return value;
}

DeclarativeXyModel *DeclarativeAreaSeries::declarativeUpperModel()
{
    return qobject_cast<DeclarativeXyModel *>(upperSeries()->model());
}

bool DeclarativeAreaSeries::setDeclarativeLowerModel(DeclarativeXyModel *model)
{
    QAbstractItemModel *m = qobject_cast<QAbstractItemModel *>(model);
    bool value(false);
    if (m) {
        lowerSeries()->setModel(m);
        lowerSeries()->setModelMapping(0, 1, Qt::Vertical);
    } else {
        qWarning("DeclarativeAreaSeries: Illegal model");
    }
    return value;
}

DeclarativeXyModel *DeclarativeAreaSeries::declarativeLowerModel()
{
    return qobject_cast<DeclarativeXyModel *>(lowerSeries()->model());
}

#include "moc_declarativeareaseries.cpp"

QTCOMMERCIALCHART_END_NAMESPACE
