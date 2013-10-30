/*
 * Copyright (c) 2012 - 2013, the Qtinuum project.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * <qtinuum.team@gmail.com>
 */

#include "PropertyQRect.h"
#include "PropertyInt.h"

namespace Qtinuum
{

PropertyQRectBase::PropertyQRectBase(QObject *parent)
    : SinglePropertyBase<QRect>(parent)
{
    addState(PropertyStateCollapsed);
}

Property* createLeftProperty(QObject *parent, PropertyQRectBase *propertyRect)
{
    PropertyIntCallback *leftProperty = new PropertyIntCallback(parent);
    leftProperty->setName(QObject::tr("Left"));
    leftProperty->setDescription(QObject::tr("Left side of the %1.").arg(propertyRect->name()));
    leftProperty->setCallbackValueGet([propertyRect]()->int { return propertyRect->value().left(); });
    leftProperty->setCallbackValueSet([propertyRect](int newLeft) {
        QRect rect = propertyRect->value();
        rect.setLeft(newLeft);
        propertyRect->setValue(rect);
    });
    PropertyBase::connectMasterState(*propertyRect, *leftProperty);

    return leftProperty;
}

Property* createRightProperty(QObject *parent, PropertyQRectBase *propertyRect)
{
    PropertyIntCallback *rightProperty = new PropertyIntCallback(parent);
    rightProperty->setName(QObject::tr("Right"));
    rightProperty->setDescription(QObject::tr("Right side of the %1.").arg(propertyRect->name()));
    rightProperty->setCallbackValueGet([propertyRect]()->int { return propertyRect->value().right(); });
    rightProperty->setCallbackValueSet([propertyRect](int newRight) {
        QRect rect = propertyRect->value();
        rect.setRight(newRight);
        propertyRect->setValue(rect);
    });
    PropertyBase::connectMasterState(*propertyRect, *rightProperty);

    return rightProperty;
}

Property* createTopProperty(QObject *parent, PropertyQRectBase *propertyRect)
{
    PropertyIntCallback *topProperty = new PropertyIntCallback(parent);
    topProperty->setName(QObject::tr("Top"));
    topProperty->setDescription(QObject::tr("Top side of the %1.").arg(propertyRect->name()));
    topProperty->setCallbackValueGet([propertyRect]()->int { return propertyRect->value().top(); });
    topProperty->setCallbackValueSet([propertyRect](int newTop) {
        QRect rect = propertyRect->value();
        rect.setTop(newTop);
        propertyRect->setValue(rect);
    });
    PropertyBase::connectMasterState(*propertyRect, *topProperty);

    return topProperty;
}

Property* createBottomProperty(QObject *parent, PropertyQRectBase *propertyRect)
{
    PropertyIntCallback *bottomProperty = new PropertyIntCallback(parent);
    bottomProperty->setName(QObject::tr("Bottom"));
    bottomProperty->setDescription(QObject::tr("Bottom side of the %1.").arg(propertyRect->name()));
    bottomProperty->setCallbackValueGet([propertyRect]()->int { return propertyRect->value().bottom(); });
    bottomProperty->setCallbackValueSet([propertyRect](int newBottom) {
        QRect rect = propertyRect->value();
        rect.setBottom(newBottom);
        propertyRect->setValue(rect);
    });
    PropertyBase::connectMasterState(*propertyRect, *bottomProperty);

    return bottomProperty;
}

Property* createWidthProperty(QObject *parent, PropertyQRectBase *propertyRect)
{
    PropertyIntCallback *widthProperty = new PropertyIntCallback(parent);
    widthProperty->setName(QObject::tr("Width"));
    widthProperty->setDescription(QObject::tr("Bottom of the %1.").arg(propertyRect->name()));
    widthProperty->setCallbackValueGet([propertyRect]()->int { return propertyRect->value().width(); });
    widthProperty->setCallbackValueSet([propertyRect](int newWidth) {
        QRect rect = propertyRect->value();
        rect.setWidth(newWidth);
        propertyRect->setValue(rect);
    });
    PropertyBase::connectMasterState(*propertyRect, *widthProperty);

    return widthProperty;
}

Property* createHeightProperty(QObject *parent, PropertyQRectBase *propertyRect)
{
    PropertyIntCallback *heightProperty = new PropertyIntCallback(parent);
    heightProperty->setName(QObject::tr("Height"));
    heightProperty->setDescription(QObject::tr("Height of the %1.").arg(propertyRect->name()));
    heightProperty->setCallbackValueGet([propertyRect]()->int { return propertyRect->value().height(); });
    heightProperty->setCallbackValueSet([propertyRect](int newHeight) {
        QRect rect = propertyRect->value();
        rect.setHeight(newHeight);
        propertyRect->setValue(rect);
    });
    PropertyBase::connectMasterState(*propertyRect, *heightProperty);

    return heightProperty;
}

} // end namespace Qtinuum
