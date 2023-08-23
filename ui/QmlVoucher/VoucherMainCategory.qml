import QtQuick 2.0
import QtQuick.Layouts 1.3

RowLayout{
    anchors.fill: parent
    spacing: 0
    MainTableCategory{
        id:tb
        Layout.fillWidth: true
        Layout.fillHeight: true
    }
    MainCategory{
        id:mc
        Layout.fillWidth: true
        Layout.fillHeight: true
    }
}
