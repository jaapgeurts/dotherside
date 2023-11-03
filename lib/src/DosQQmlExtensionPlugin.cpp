#include "DOtherSide/DosQQmlExtensionPlugin.h"

#include <iostream>

namespace DOS {

/// This class models a QQmlExtensionPlugin
DosQQmlExtensionPlugin::DosQQmlExtensionPlugin(void* dPluginObject,
    ::DosIQMetaObjectPtr metaObject,
    ::DObjectCallback dObjectCallback,
    ::DosQQmlExtensionPluginCallbacks callbacks)
    : m_impl(new DosQObjectImpl(::createParentMetaCall<T>(this), std::move(metaObject), dPluginObject, dObjectCallback))
    , m_pluginObject(dPluginObject)
    , m_callbacks(callbacks)

{
    std::cout << "Created plugin\n";
}

/**
 * Destructor
 */
DosQQmlExtensionPlugin::~DosQQmlExtensionPlugin()
{
}

// void initializeEngine ( QQmlEngine * engine, const char * uri ) override;
void DosQQmlExtensionPlugin::registerTypes(const char* uri)
{
    Q_UNUSED(uri)
    std::cout << ">Register types\n";
    m_callbacks.registerTypes(m_pluginObject, uri);
}
}
