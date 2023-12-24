import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

Item {
    property string myText
    property int myTextSize
    property bool myTextBold: false
    property string myTextFamily: "Arial"
    property string myTextColor
    property int myRectWidth: 17
    property int myRectHeight: 17
    property bool boxChecked: false
    property string imgSource: "qrc:/Images/check-mark.png"
    property bool myFillHeight
    property bool myFillWidth

    signal myClick()
    signal myChecked()

    Layout.fillHeight: myFillHeight
    Layout.fillWidth: myFillWidth

    RowLayout {
        anchors.fill: parent
        spacing: 3

        CheckBox {
            id: customCheckbox
            checked: boxChecked
            Layout.preferredWidth: myRectWidth
            Layout.preferredHeight: myRectHeight

            indicator: Rectangle {
                width: customCheckbox.width
                height: customCheckbox.height
                color: customCheckbox.checked ? "white" : "transparent"

                Image {
                    source: customCheckbox.checked ? imgSource : ""
                    anchors.centerIn: parent
                    width: customCheckbox.width * 0.4
                    height: customCheckbox.height * 0.4
                }
            }

            onClicked: myClick()
            onCheckedChanged: myChecked()
        }

        Text {
            id: txt
            text: myText
            color: myTextColor
            font.pixelSize: myTextSize
            font.bold: myTextBold
            font.family: myTextFamily
        }
    }
}
