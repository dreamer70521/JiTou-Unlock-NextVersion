pragma Singleton

import QtQuick 2.15
import FluentUI 1.0

FluObject{

    property var navigationView

    id:footer_items

    FluPaneItemSeparator{}

    FluPaneItem{
        title:qsTr("Settings")
        icon:FluentIcons.Settings
        url:"qrc:/page/T_Settings.qml"
        onTap:{
            navigationView.push(url)
        }
    }

}
