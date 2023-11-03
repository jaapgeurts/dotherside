

#pragma once

// Qt
#include <QQmlExtensionPlugin>

// DOtherSide
//#include "DOtherSide/DOtherSideTypes.h"
#include "DOtherSide/DOtherSideTypesCpp.h"
#include "DOtherSide/DosIQObjectImpl.h"

namespace DOS {

/// This class model a QObject
class DosQQmlExtensionPlugin : public QQmlExtensionPlugin {
    Q_OBJECT

public:
    /**
     * Default constructor
     */
    DosQQmlExtensionPlugin(void* dPluginObject,
        ::DosIQMetaObjectPtr metaObject,
        ::DObjectCallback dObjectCallback,
        ::DosQQmlExtensionPluginCallbacks callbacks);

    /**
     * Destructor
     */
    virtual ~DosQQmlExtensionPlugin();

    // void initializeEngine ( QQmlEngine * engine, const char * uri ) override;
    void registerTypes(const char* uri) override;

private:
    std::unique_ptr<DosIQObjectImpl> m_impl;
    void* m_pluginObject;
    DosQQmlExtensionPluginCallbacks m_callbacks;
};

}
