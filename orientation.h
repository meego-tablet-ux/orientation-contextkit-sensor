/*
 * Copyright 2011 Intel Corporation.
 *
 * This program is licensed under the terms and conditions of the
 * Apache License, version 2.0.  The full text of the Apache License is at 
 * http://www.apache.org/licenses/LICENSE-2.0
 */

#ifndef ORIENTATION_H
#define ORIENTATION_H

#include <QObject>
#include <QSensorBackend>
#include <QOrientationSensor>

class ContextProperty;

QTM_USE_NAMESPACE

class Orientation : public QSensorBackend
{
    Q_OBJECT
public:
    static char const * const id;

    Orientation(QSensor *sensor);
    ~Orientation();

    void start();
    void stop();

private slots:
    void updateSensor();

private:
    QOrientationReading m_reading;
    ContextProperty *topEdgeProperty;
};

#endif

