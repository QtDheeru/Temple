import QtQuick 2.0
import QtQuick.Controls 2.14

Button {
    id : b1
    implicitWidth: parent.width;
    implicitHeight: _t1.contentHeight + 10;
    anchors.margins: 10
    background: Rectangle{color : "skyblue"}
    height:_t1.contentHeight+10
    signal sevaSelected(int index, int sevaType, int sevaId)
    signal sevaSelectedFromView(int index, int sevaType, int sevaId)

    contentItem: Text {
        id : _t1
        text : SevaName;
        font.pixelSize: 20
        color: "black"
        wrapMode: Text.WordWrap
        verticalAlignment: Text.AlignVCenter
    }
    onClicked: {
        // sevaType,sevaId - These are coming as roles from model
        console.log(" Index =" + index + " SevaType =" + SevaType + " SevaID=" + SevaId)
        sevaSelected(index,SevaType,SevaId)
        sevaProxy.print(SevaType,SevaId);
    }
    Component.onCompleted: {
        console.log("my seva delegate is created")
    }
}
