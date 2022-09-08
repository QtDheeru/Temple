import QtQuick 2.0
import QtQuick.Layouts 1.3
import "./components"

Rectangle{
    id : root
    width: parent.width
    height: styles.lastRowHeight;//150
    property int subComponentHeight : height/8
    property int subComponentPixelSize : styles.fontSize
    Layout.fillWidth: true
    color: "#00A2ED"
    property double value:0
    property int sum :0
    property alias amout2Pay : _t1.text
    function addTotal(val,count=""){
        if(val=="")
            return;
        var value = parseInt(val);
        if(count.length ===0){
            sum +=value;
        } else{
            var c = parseInt(count);
            console.log("value = " + value)
            console.log("count  = " + c)
            sum += value*c;
        }
        _t1.text  = "Rs : "+sum;
    }

    function clearData(){
        root.sum = 0;
        _t1.text = "";
    }

    RowLayout {
        width: parent.width
        height: parent.height
        spacing:0
        Rectangle{
            Layout.fillHeight: true;
            Layout.fillWidth: true
            color: "#00A2ED"
            Text {
                Layout.fillWidth: true;font.pixelSize: 25;
                text :"Total"
                anchors.centerIn: parent
            }
        }
        Rectangle{
            Layout.fillHeight: true;
            Layout.alignment: Qt.AlignVCenter
            Layout.fillWidth: true
            color: "lightblue"
            Text {
                id:_t1
                Layout.fillWidth: true;font.pixelSize: 25;
                text :"Rs :"+"0"
                anchors.centerIn: parent
            }
        }
    }
    Timer{
        id : _tim
        interval: 500
//        running: true
//        repeat: true
        onTriggered: {
            _t1.visible = !_t1.visible;
        }
    }
}
