import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5


ColumnLayout
{
    anchors.fill: parent
    spacing:-30
    property var comp;
    signal loadMenuPage()
    Component.onCompleted:
    {
        comp=Qt.createComponent("qrc:/ui/QmlVoucher/SubTableCategory.qml")
    }

    Rectangle{
        id: _rec1
        Layout.preferredHeight: parent.height/6
        Layout.preferredWidth: parent.width
        color: "#CCFFFF"
        border.color: "black"
        border.width: 2
        signal my_display();
        RowLayout{
            spacing: 30
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin:parent.height/2-15
            RadioButton
            {
                id:rb1
                text: "Main Head"
                checked: true
                Layout.preferredWidth: 150
                font.pixelSize: (parent.width+parent.height)/25
                onClicked: {
                    console.log("clicked Main App")
                    _ld.source="qrc:/ui/QmlVoucher/VoucherMainCategory.qml"
                }
            }
            RadioButton
            {
                id:rb2
                text: "Sub Head"
                Layout.preferredWidth: 150
                font.pixelSize: (parent.width+parent.height)/25
                onClicked:
                {
                    console.log("clicked Sub App")
                    _ld.source="qrc:/ui/QmlVoucher/SubTableMain.qml"
                }
            }
        }
    }

    Rectangle
    {
        id: _rec2
        color: "#CCCCCC"
        Layout.preferredWidth: parent.width
        Layout.preferredHeight:parent.height-(parent.height/5)
        VoucherMainCategory{
            id:vmc
        }
        Loader
        {
            z:2
            id: _ld
            anchors.fill:parent
        }
    }

    Keys.onEscapePressed: {
        loadMenuPage();
        console.log("Escape pressed in VoucherApplication");
    }

}
