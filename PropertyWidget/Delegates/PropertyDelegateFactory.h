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

#ifndef QTN_PROPERTY_DELEGATE_FACTORY_H
#define QTN_PROPERTY_DELEGATE_FACTORY_H

#include "PropertyDelegate.h"
#include <QMap>

namespace Qtinuum
{

class QTN_PW_EXPORT PropertyDelegateFactory
{
    Q_DISABLE_COPY(PropertyDelegateFactory)

public:
    typedef PropertyDelegate *CreateFunction(Property&);

    explicit PropertyDelegateFactory(const PropertyDelegateFactory* superFactory = 0);

    PropertyDelegate* createDelegate(Property& owner) const;

    bool registerDelegateDefault(const QMetaObject* propertyMetaObject, CreateFunction* createFunction, const QByteArray& delegateName = "");
    bool registerDelegate(const QMetaObject* propertyMetaObject, CreateFunction* createFunction, const QByteArray& delegateName);

    static PropertyDelegateFactory& staticInstance();

private:
    const PropertyDelegateFactory* m_superFactory;

    struct CreateItem
    {
        CreateItem()
            : defaultCreateFunction(0)
        {
        }

        CreateFunction* defaultCreateFunction;
        QMap<QByteArray, CreateFunction*> createFunctions;
    };

    QMap<QByteArray, CreateItem> m_createItems;
};

template <typename PropertyDelegateClass, typename PropertyClass>
PropertyDelegate* createDelegate(Property& owner)
{
    PropertyClass* theOwner = qobject_cast<PropertyClass*>(&owner);
    if (!theOwner)
        return nullptr;

    return new PropertyDelegateClass(*theOwner);
}

} // end namespace Qtinuum

#endif // QTN_PROPERTY_DELEGATE_FACTORY_H
