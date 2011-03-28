/*
 * Copyright 2011 Intel Corporation.
 *
 * This program is licensed under the terms and conditions of the
 * Apache License, version 2.0.  The full text of the Apache License is at 
 * http://www.apache.org/licenses/LICENSE-2.0
 */

#include <QSensorPluginInterface>
#include <QSensorBackendFactory>
#include <QFile>

#include "orientation.h"

class SensorPlugin : public QObject, public QSensorPluginInterface, public QSensorBackendFactory
{
    Q_OBJECT
    Q_INTERFACES(QtMobility::QSensorPluginInterface)
public:
    void registerSensors()
    {
        QSensorManager::registerBackend(QOrientationSensor::type, Orientation::id, this);
    }

    QSensorBackend *createBackend(QSensor *sensor)
    {
        if (sensor->identifier() == Orientation::id) 
            return new Orientation(sensor);

        return 0;
    }
};

Q_EXPORT_PLUGIN2(qtsensors_orientation, SensorPlugin)

#include "plugin.moc"

