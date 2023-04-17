import QtQuick 2.14
import QtQuick.Controls 2.5
import "../../components"
import "../../Admin"
import QtQuick.Layouts 1.3

Rectangle {
    id:_root
    width: 200;
    color: "transparent"
    anchors.margins: 20
    signal errorOccur(string errorMsg);
    property int sevaType :-1
    border.width: 0.5;
    border.color: "black"
    property alias currentIndex: _listView.currentIndex

    property int myHeight : 30
    property int fontPixelSize : 20

    signal sevaTypeSel(int index, int sevaType)
    signal sevaTypeSelectedByIndex(int index)
    signal sevaTypeSelected(variant sevaType)
    focus: true

    function changeItem(idx){
        _listView.currentIndex  = idx
    }

    function getSevaTypeDetails(idx){
        var sevaTypeObject = sevaProxy.getSevaTypeByIndex(currentIndex);
        _root.sevaTypeSelected(sevaTypeObject);
    }

    ListView{
        id : _listView
        anchors.fill: parent
        anchors.centerIn: parent
        anchors.margins: 3
        highlight :highlightBar
        spacing: 1
        clip: true
        focus: true
        currentIndex: 0
        snapMode: ListView.SnapToItem
        delegate: SevaDetailDelegate{
                        id : del
                        Component.onCompleted: del.itemClicked.connect(_root.changeItem);
        }
        model: sevaProxy.getSevaTypeModel()

        header :_headerComp
        headerPositioning: ListView.OverlayHeader
        highlightFollowsCurrentItem: true
        onCurrentIndexChanged: {
            console.log(" Current Index changed" + currentIndex)
            _root.getSevaTypeDetails(currentIndex);
        }
        Component.onCompleted: {
             _root.getSevaTypeDetails(0);
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
                text :qsTr("Select Seva Type")
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
            border.color: "gold"
            border.width: 0.5;
            color: Qt.rgba(0,0.0,1,0.2)
            z:5
        }
    }
    Component.onCompleted: {
        console.log("Component.onCompleted: of seva list view")
    }
}

