import QtQuick 2.0
import QtQuick.Controls 2.5

TextField{
    property alias txt: _txtFld.text
    id: _txtFld
    implicitWidth: _root.width/2
    implicitHeight: _root.height/12
    font.pixelSize: 20
    placeholderText: "Enter characters to search in names";
}
