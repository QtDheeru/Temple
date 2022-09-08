import QtQuick 2.0
import "./components"

Rectangle {
    id:root
    property Constants constant: Constants{}
    color: constant.backgroundColor
    anchors.fill: parent
    signal timerTriggered()
    Timer {
        interval: 5000; running: true;
        repeat: false
        onTriggered: timerTriggered()
    }
    Column{
        height:parent.height
        width:parent.width
        anchors.horizontalCenter: parent.horizontalCenter
        TextPage {
            id: headText
            height:root.height/8
            width: root.width
            color: constant.headerBackgroundColor
            anchors.horizontalCenter: parent.horizontalCenter
            headOrText1: constant.headerText1
            horAddfontSize1: root.width/60
            hOrAddTextcolor1:constant.headerTextColor
            hOrAddtextBold1:true

            headOrText2: constant.headerText2
            horAddfontSize2: root.width/52
            hOrAddTextcolor2:constant.headerTextColor
            hOrAddtextBold2:true
        }
        Rectangle{
            id:underLine
            width:root.width
            height: root.height/170
            color: constant.topUnderLineColor
        }
        Image {
            id: imgTemple
            height: root.height/1.6
            width: root.width/2
            anchors.horizontalCenter: parent.horizontalCenter
            source: constant.templePic
        }
        Rectangle{
            id:underLine1
            width:root.width
            height: root.height/130
            color: constant.bottomUnderLineColor
        }
        TextPage {
            height:root.height/4
            width: root.width
            color: constant.addressBackgroundColor
            anchors.horizontalCenter: parent.horizontalCenter
            headOrText1: constant.addressText1
            horAddfontSize1: root.width/55
            hOrAddTextcolor1:constant.addressTextColor
            hOrAddtextBold1:false

            headOrText2: constant.addressText2
            horAddfontSize2: root.width/55
            hOrAddTextcolor2:constant.addressTextColor
            hOrAddtextBold2:false

            headOrText3: constant.addressText3
            horAddfontSize3: root.width/55
            hOrAddTextcolor3:constant.addressTextColor
            hOrAddtextBold3:false
        }
    }
}
