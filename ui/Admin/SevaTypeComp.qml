import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQml.Models 2.14
import QtQuick.Layouts 1.3
Item {
    property int sevaTypeHeight
    property int sevaTypeWidth
    height:sevaTypeHeight
    width: sevaTypeWidth
    Rectangle{
        anchors.fill: parent
        border.width: 0.5
        ColumnLayout{
            anchors.fill: parent
            spacing: 0
            Rectangle{
                Layout.preferredWidth: parent.width
                Layout.minimumHeight: 35
                Layout.preferredHeight: parent.height/10
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
                // Layout.preferredHeight: parent.height/10
                Layout.minimumWidth: 35
                Layout.preferredWidth: parent.width
                model : sevaProxy.getSevaTypeModel()
                textRole: "sevaTypeName"
                font.pixelSize: 14
                onCurrentIndexChanged: {
                    var currentItem = delegateModel.items.get(currentIndex)
                    console.log("--------------- onCurrentIndexChanged: of combo box sevaListView"+sevaProxy.getSevaModel(currentItem.model.sevaTypeId).getSevaListViewSize());
                    console.log(" Index =" + currentIndex)
                    if(sevaProxy.getSevaModel(currentItem.model.sevaTypeId).getSevaListViewSize()===0)
                    {
                        console.log("if of onCurrentIndexChanged: of combo box sevaListView");
                        console.log("before ---------------   errorOccur");
                        errorOccur("  Sevas not present for
     "+currentItem.model.sevaTypeName);
                        _listView.model = 0;
                        console.log("after ---------------   errorOccur");
                    }
                    else{
                        _root.sevaType = currentItem.model.sevaTypeId;
                    }
                    console.log("Current Text =" + sevaProxy.getSevaTypeModel())
                    console.log("Model SevaType--------: "+currentItem);
                    console.log("Model SevaType: " + currentItem.model.sevaTypeName);
                    console.log("Model SevaType: " + currentItem.model.sevaTypeId);
                }
                Component.onCompleted: {
                    var currentItem = delegateModel.items.get(currentIndex)
                    console.log("Component.onCompleted of combo box sevaListView current index ="+currentIndex+" "+sevaProxy.getSevaModel(currentItem.model.sevaTypeId).getSevaListViewSize());
                }
            }
        }
    }
}
