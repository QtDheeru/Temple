import QtQuick 2.14
import QtQuick.Controls 2.5
import "../../components"
import "../../Admin"
import QtQuick.Layouts 1.3

Rectangle
{
    id:_root
    width: 200;
    color: "skyblue"
    anchors.margins: 20
    signal errorOccur(string errorMsg);
    property int sevaType :-1
    border.width: 0.5;
    border.color: "black"
    property alias currentIndex: _listView.currentIndex
    property int sindex
    property int myHeight : 30
    property int fontPixelSize : 20
    property var sevaTypeObject
    signal sevaTypeSel(int index, int sevaType)
    signal sevaTypeSelectedByIndex(int index)
    signal sevaTypeSelected(variant sevaType)
    //signal sendSevaCurrentIndex(int idx)
    signal sendSevaCurrentIndex(int sevaType,int index);
    focus: true

    function changeItem(idx)
    {
        _listView.currentIndex  = idx
    }

    function getSevaTypeDetails(idx){
        sevaTypeObject = sevaProxy.getSevaTypeByIndex(idx);
        _root.sevaTypeSelected(sevaTypeObject);
    }
    onSindexChanged: {
        console.log("hello world.....",sindex);
        _root.getSevaTypeDetails(sindex);
        _listView.model= sevaProxy.getSevaModel(sevaTypeObject.sevaTypeId)
    }

    ListView
    {
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
        delegate: SevaNameDelegate{
            id : del
            Component.onCompleted: del.itemClicked.connect(_root.changeItem);
        }
        model: sevaProxy.getSevaModel(sevaTypeObject.sevaTypeId)

        header :_headerComp
        headerPositioning: ListView.OverlayHeader
        highlightFollowsCurrentItem: true
        onCurrentIndexChanged:
        {
            console.log("hello Current Index changed" + currentIndex)
            sendSevaCurrentIndex(sevaTypeObject.sevaTypeId,currentIndex)
            //sendSevaCurrentIndex(currentIndex)
            //getSevaNameDetailsBySevaType(sevaTypeObject.sevaTypeId,currentIndex)
        }
        Component.onCompleted:
        {
            _root.getSevaTypeDetails(0);
        }
    }
    Component
    {
        id : _headerComp
        Rectangle
        {
            width: _root.width
            height: 25
            z: 2
            color: "#00A2ED"
            //                    Text {
            //                        text :qsTr("Seva Name")
            //                        font.bold : true
            //                        font.italic: true
            //                        font.pixelSize: 20
            //                        anchors.centerIn: parent
            //                    }

            RowLayout
            {
                anchors.fill: parent
                spacing: 13

                Text
                {
                    text: "Serial No"
                    width: parent.width / 3
                    font.pixelSize: 17
                    font.bold: true
                }

                Text
                {
                    text: "Seva Name"
                    width: parent.width / 3
                    font.pixelSize: 17
                    font.bold: true
                }

                Text
                {
                    Layout.alignment: Qt.AlignRight
                    Layout.rightMargin: 12
                    text: "SevaID"
                    width: parent.width / 3
                    font.pixelSize: 17
                    font.bold: true
                }
            }
        }
    }
    Component
    {
        id: highlightBar
        Rectangle {
            height: 20
            border.color: "gold"
            border.width: 0.5;
            color: Qt.rgba(0,0.0,1,0.2)
            z:5
        }
    }
    Component.onCompleted:
    {
        console.log("SevaNamesView is created...")
    }
}

