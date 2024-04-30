import QtQuick 2.14
import QtQuick.Controls 2.5
import "./components"
import QtQuick.Layouts 1.3

Rectangle {
    id: _root
    width: 200;
    height: parent.height
    color: "transparent"
    anchors.margins: 20
    border.width: 0.5;border.color: "#00A2ED"

    property int sevaType : -1
    property alias currentIndex: _listView.currentIndex
    property int myHeight : 30
    property int fontPixelSize : 20

    signal errorOccur(string errorMsg);
    signal sevaSelected(int index, int sevaType, int sevaId)
    signal sevaSelectedByIndex(int sevaType, int index)

    Rectangle{
        id : _sevaTypeSelection
        width: parent.width - 5
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
                    var currentItem = delegateModel.items.get(currentIndex)
                    console.log(" Index =" + currentIndex)
                    if(sevaProxy.getSevaModel(currentItem.model.sevaTypeId).getSevaListViewSize()===0)
                    {
                        errorOccur(" Sevas not present for " + currentItem.model.sevaTypeName);
                        _listView.model = 0;
                        console.log("after ---------------   errorOccur");
                    }
                    else{
                        console.log("Sevas are not 0 in seva type =" + sevaType)
                        _root.sevaType = currentItem.model.sevaTypeId;
                    }
                    console.log("Current Text =" + sevaProxy.getSevaTypeModel())
                    console.log("Model SevaType--------: "+currentItem);
                    console.log("Model SevaType: " + currentItem.model.sevaTypeName);
                    console.log("Model SevaType: " + currentItem.model.sevaTypeId);
                    _listView.currentIndex = 0;
                }
                Component.onCompleted: {
                    var currentItem = delegateModel.items.get(currentIndex)
                    console.log("Component.onCompleted of combo box sevaListView current index ="+currentIndex+" "+sevaProxy.getSevaModel(currentItem.model.sevaTypeId).getSevaListViewSize());
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
        height: parent.height - _sevaTypeSelection.height * 1.5
        highlight : highlightBar
        spacing: 2
        clip: true
        focus: true
        currentIndex: 0
        snapMode: ListView.SnapToItem
        delegate: MySevaDelegate {
            Component.onCompleted: {
                sevaSelected.connect(recvSevaSelected);
            }
        }
        header :_headerComp
        headerPositioning: ListView.OverlayHeader
        highlightFollowsCurrentItem: true
        onCurrentIndexChanged: {
            recvSevaSelected_1((_sevaTypes.delegateModel.items.get( _sevaTypes.currentIndex)).model.sevaTypeId,currentIndex)
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
            z: 5
        }
    }

    onSevaTypeChanged: {
        console.log(" Seva Type Changed: " +sevaType)
        _listView.model = sevaProxy.getSevaModel(sevaType);
    }

    function selectFirstSeva() {
        _listView.currentIndex = -1;
        _listView.currentIndex = 0;
    }
    function recvSevaSelected(idx,sevaType, sevaId) {
        console.log(" VIEW - Index =" + idx + " SevaType =" + sevaType + " SevaID=" + sevaId)
        sevaSelected(idx,sevaType,sevaId)
        _listView.currentIndex = idx
    }
    function recvSevaSelected_1(sevaType,idx) {
        console.log(" VIEW-1 - Index =" + idx )
        sevaSelectedByIndex(sevaType,idx)
    }

    Component.onCompleted: {
        console.log("Component.onCompleted: of seva list view")
    }
}

