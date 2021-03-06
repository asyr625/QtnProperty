/*
   Copyright (c) 2012-2016 Alex Zhondin <lexxmark.dev@gmail.com>

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef QTN_PROPERTY_DELEGATE_PROPERTY_SET_H
#define QTN_PROPERTY_DELEGATE_PROPERTY_SET_H

#include "../PropertyDelegate.h"

class QtnPropertySet;

class QTN_PW_EXPORT QtnPropertyDelegatePropertySet: public QtnPropertyDelegate
{
    Q_DISABLE_COPY(QtnPropertyDelegatePropertySet)

public:
    QtnPropertyDelegatePropertySet(QtnPropertySet& owner)
        : m_owner(owner)
    {
    }

protected:
    QtnPropertyBase* propertyImpl() override;
    const QtnPropertyBase* propertyImmutableImpl() const override;
    int subPropertyCountImpl() const override;
    QtnPropertyBase* subPropertyImpl(int index) override;

    void createSubItemsImpl(QtnDrawContext& context, QList<QtnSubItem>& subItems) override;

private:
    QtnPropertySet& m_owner;
};


#endif // QTN_PROPERTY_DELEGATE_PROPERTY_SET_H
