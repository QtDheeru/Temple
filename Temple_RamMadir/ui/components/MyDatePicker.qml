import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4 as Cal
import "../assets/Images"
import QtQuick.Controls.Styles 1.4 as CalStyle

Item {
    id : _rootDataPicker
    property int myWidth: 200
    //height : parent.height
    property alias dateSelected : textDate.text
    property int fontPixelSize : 20
    property int myheight:20
    signal dateChanged(var date)
    TextField {
        id: textDate
        width: _rootDataPicker.myWidth
        height: _rootDataPicker.myheight
        placeholderText: qsTr("Text Field")
        text: Qt.formatDate(cal.selectedDate, "dd-MM-yyyy")
        font.bold: true
        font.family: "times new roman"
        //font.pointSize: _rootDataPicker.fontPixelSize
        font.pixelSize: _rootDataPicker.fontPixelSize
        readOnly: true
        onTextChanged: {
            dateChanged(textDate.text)
        }
    }
    Button {
        id: button
        width: textDate.height
        height: textDate.height
        anchors.left: textDate.right
        anchors.leftMargin: -(textDate.height)
        anchors.top: parent.top
        Image {
            id: img
            anchors.fill: parent
            source: "qrc:/ui/assets/Images/calender.jpeg"
        }
        onClicked: calPopup.showCalendar(true)
    }
    Popup{
        id: calPopup
        width: _rootDataPicker.width-_rootDataPicker.width/4
        height: 350
        visible: false
        Cal.Calendar{
            id: cal
            style: CalStyle.CalendarStyle {
                gridVisible: true
//                dayDelegate: Rectangle
//                {
//                    Label {
//                        text: styleData.date.getDate()
//                        anchors.centerIn: parent
//                        color: styleData.valid ? "black" : "grey"
//                        font.pixelSize: 20
//                        font.bold: true
//                    }

//                    Rectangle {
//                        width: parent.width
//                        height: 1
//                        color: "#555"
//                        anchors.bottom: parent.bottom
//                    }

//                    Rectangle {
//                        width: 1
//                        height: parent.height
//                        color: "#555"
//                        anchors.right: parent.right
//                    }
//                }
//                dayOfWeekDelegate :
//                    Rectangle {
//                    width: parent.width
//                    Label {
//                        text: styleData.dayOfWeek
//                        anchors.centerIn: parent
//                        color: styleData.valid ? "black" : "grey"
//                        font.pixelSize: 20
//                        font.bold: true
//                    }
//                    Rectangle {
//                        width: parent.width
//                        height: 1
//                        color: "#555"
//                        anchors.bottom: parent.bottom
//                    }

//                    Rectangle {
//                        width: 1
//                        height: parent.height
//                        color: "#555"
//                        anchors.right: parent.right
//                    }
//                }


            }


            width: _rootDataPicker.width-_rootDataPicker.width/4
            height: calPopup.height
            visible: false
            selectedDate: new Date()

            z: 10
            onClicked: {
                textDate.text=Qt.formatDate(cal.selectedDate, "dd-MM-yyyy");
                calPopup.showCalendar(false);
                console.log(" Date selected ="+textDate.text)
            }
        }
        function showCalendar(showMe){
            cal.visible     = showMe;
            calPopup.visible = showMe
            if (showMe===true)
                calPopup.open();
            else
                calPopup.close();
        }
    }
}
