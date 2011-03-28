/*
 * Copyright 2011 Intel Corporation.
 *
 * This program is licensed under the terms and conditions of the
 * Apache License, version 2.0.  The full text of the Apache License is at 
 * http://www.apache.org/licenses/LICENSE-2.0
 */

#include <contextsubscriber/contextproperty.h>

#include "orientation.h"

char const * const Orientation::id("contextkit.orientation");

Orientation::Orientation(QSensor *sensor)
    : QSensorBackend(sensor)
{
    setReading<QOrientationReading>(&m_reading);
}

Orientation::~Orientation()
{
}

void Orientation::updateSensor()
{
    ContextProperty *prop = qobject_cast<ContextProperty*>(sender());
    QString data = prop->value().toString();
    if (data == "bottom")
    {
        m_reading.setOrientation(QOrientationReading::TopDown);
    }
    else if (data == "left")
    {
        m_reading.setOrientation(QOrientationReading::LeftUp);
    }
    else if (data == "right")
    {
        m_reading.setOrientation(QOrientationReading::RightUp);
    }
    else
    {
        m_reading.setOrientation(QOrientationReading::TopUp);
    }
    m_reading.setTimestamp(clock());
    newReadingAvailable();
}

void Orientation::start()
{
    topEdgeProperty = new ContextProperty("Screen.TopEdge",this);
    topEdgeProperty->subscribe();
    connect(topEdgeProperty,SIGNAL(valueChanged()),this,SLOT(updateSensor()));
}

void Orientation::stop()
{
    delete topEdgeProperty;
}
