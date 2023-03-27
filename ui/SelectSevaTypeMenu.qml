import QtQuick 2.0
import QtQuick.Controls 2.5
Rectangle{
    id:_root
    anchors.fill: parent
    color: "#445566"
//    border.color: "#F4C430"
//    border.width: 50
    signal loadMenuPage()

    function onSevaTypeSelected(index,sevaTypeId){
        console.log(" Seva Type Selected =" + index + " SevaType=" + sevaTypeId)
        _sevaBookingView.sevaType = sevaTypeId
        _sevaBookingView.open()
    }
    ScrollView {
//        anchors.fill: parent
        width: 400;height: 400
        anchors.centerIn: parent
        focus: true
        GridView {
            anchors.fill: parent
            cellHeight: 250
            cellWidth: 250
            width: 400;height: 400
            model: sevaProxy.getSevaTypeModel()
            delegate : MySevaTypeDelegate {
                Component.onCompleted: {
                    sevaTypeSelected.connect(_root.onSevaTypeSelected)
                }
            }
        }
    }
    SevaBookingView {
        id : _sevaBookingView
        focus: true
    }
    Keys.onEscapePressed: {
        console.log("Esc pressed in select seva type view")
        loadMenuPage()
    }
//    Keys.onEscapePressed: {
//        this.close();
//    }
}
