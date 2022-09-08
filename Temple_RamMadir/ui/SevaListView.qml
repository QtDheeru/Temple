import QtQuick 2.14
import QtQuick.Controls 2.5
import "./components"
import QtQuick.Layouts 1.3

Rectangle {
    id:_root
    width: 250;
    height:parent.height
    color: "transparent"
    anchors.margins: 20
    property int sevaType :-1
    border.width: 0.5;border.color: "#00A2ED"
    property alias currentIndex: _listView.currentIndex

    property int myHeight : 30
    property int fontPixelSize : 20

    signal sevaSelected(int index, int sevaType, int sevaId)
    signal sevaSelectedByIndex(int index)

    onSevaTypeChanged: {
        console.log(" Seva Type Changed ")
        _listView.model = sevaProxy.getSevaModel(sevaType);
    }

    function selectFirstSeva()
    {
        _listView.currentIndex = -1;
        _listView.currentIndex = 0;
    }

    function recvSevaSelected(idx,sevaType, sevaId) {
        console.log(" VIEW - Index ="+idx + " SevaType ="+sevaType + " SevaID="+sevaId)
        sevaSelected(idx,sevaType,sevaId)
        _listView.currentIndex = idx
    }
    function recvSevaSelected_1(idx) {
        console.log(" VIEW-1 - Index =" + idx )
        sevaSelectedByIndex(idx)
    }

    Rectangle{
        id : _sevaTypeSelection
        width: parent.width-5
        height: 70;
        color: "lightblue"
        border.color: "blue"
        border.width: 1
        anchors.horizontalCenter: parent.horizontalCenter
        ColumnLayout{
            anchors.fill: parent
            spacing: 0
            Rectangle{
                Layout.preferredWidth: parent.width
                //Layout.fillHeight: true
                Layout.minimumHeight: 35
                color: "#00A2ED"
                Text {
                    text :qsTr("Select Seva Type ")
                    font.bold : true
                    font.italic: true
                    font.pixelSize: 20
                    anchors.centerIn: parent
                }
            }

            ComboBox{
                id : _sevaTypes
                width: parent.width
                Layout.fillHeight: true
                Layout.minimumWidth: 35
                Layout.preferredWidth: parent.width
                model : sevaProxy.getSevaTypeModel()
                textRole: "sevaTypeName"
                font.pixelSize: _root.fontPixelSize
                onCurrentIndexChanged: {
                    console.log(" Index =" + currentIndex)
                    console.log(" Current Text =" + sevaProxy.getSevaTypeModel())
                    var currentItem = delegateModel.items.get(currentIndex)
                    console.log("Model SevaType: " + currentItem.model.sevaTypeName);
                    console.log("Model SevaType: " + currentItem.model.sevaTypeId);
                    _root.sevaType = currentItem.model.sevaTypeId;
                }
            }
        }
    }

    ListView{
        id : _listView
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 10
        anchors.top: _sevaTypeSelection.bottom
        width: parent.width-5
        height: parent.height - _sevaTypeSelection.height -5
        highlight :highlightBar
        spacing: 2
        clip: true
        focus: true
        currentIndex: 0
        snapMode: ListView.SnapToItem
        model : sevaListModel
        delegate: MySevaDelegate{
            Component.onCompleted: {
                sevaSelected.connect(recvSevaSelected);
            }
        }
        header :_headerComp
        headerPositioning: ListView.OverlayHeader
        highlightFollowsCurrentItem: true
        onCurrentIndexChanged: {
            console.log(" Current Index changed" + currentIndex)
            recvSevaSelected_1(currentIndex)
        }
    }
    Component{
        id : _headerComp
        Rectangle{
            width: _root.width
            height: 25
            z: 2
            color: "#00A2ED"
            Text {
                text :qsTr("Select Seva ")
                font.bold : true
                font.italic: true
                font.pixelSize: 20
                anchors.centerIn: parent
            }
        }
    }
    Component {
        id: highlightBar
        Rectangle {
            height: 20
            border.color: "green"
            border.width: 1;
            color: Qt.rgba(0,0.0,1,0.5)
            z:5
        }
    }
}

