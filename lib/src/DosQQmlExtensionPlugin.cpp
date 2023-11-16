#include <iostream>

#include "DOtherSide/DosQQmlExtensionPlugin.h"
#include <QQmlEngine>

namespace DOS {

/// This class models a QQmlExtensionPlugin
DosQQmlExtensionPlugin::DosQQmlExtensionPlugin(void* dPluginObject,
    // TODO: add metaobject support
    // DosIQMetaObjectPtr metaObject,
    // DObjectCallback dObjectCallback,
    DosQQmlExtensionPluginCallbacks callbacks)
    : // TODO: add meta object support
      // m_impl(new DosQObjectImpl(::createParentMetaCall<T>(this), std::move(metaObject), dPluginObject, dObjectCallback)),
    m_pluginObject(dPluginObject)
    , m_callbacks(callbacks)

{
    std::cout << "DosQQmlExtensionPlugin::ctor()\n";
}

/**
 * Destructor
 */
DosQQmlExtensionPlugin::~DosQQmlExtensionPlugin()
{
    std::cout << "DosQQmlExtensionPlugin::dtor()\n";
}

void DosQQmlExtensionPlugin::initializeEngine(QQmlEngine* engine, const char* uri)
{
    std::cout << "DosQQmlExtensionPlugin::initializeEngine()\n";
    m_callbacks.initializeEngine(m_pluginObject, engine, uri);
}

void DosQQmlExtensionPlugin::registerTypes(const char* uri)
{
    std::cout << "DosQQmlExtensionPlugin::registerType()\n";
    m_callbacks.registerTypes(m_pluginObject, uri);
}
}
