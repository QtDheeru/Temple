import QtQuick.Controls 1.4
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4

    Calendar {
        id:rect
        width: 245
        height: 250
        property var currentDate: new Date()
        minimumDate: new Date(2023, 0, 1)
        maximumDate: currentDate
        anchors.left: parent.right
        style: CalendarStyle {
            gridVisible: false
            dayDelegate: Rectangle {
                gradient: Gradient {
                    GradientStop {
                        position: 0.00
                        color: styleData.selected ? "#3399FF" : (styleData.visibleMonth && styleData.valid ? "#444" : "#666");
                    }
                    GradientStop {
                        position: 1.00
                        color: styleData.selected ? "#3399FF" : (styleData.visibleMonth && styleData.valid ? "#111" : "#666");
                    }
                    GradientStop {
                        position: 1.00
                        color: styleData.selected ? "#3399FF" : (styleData.visibleMonth && styleData.valid ? "#111" : "#666");
                    }
                }
                Label {
                    text: styleData.date.getDate()
                    anchors.centerIn: parent
                    color: styleData.valid ? "white" : "grey"
                }
                Rectangle {
                    width: parent.width
                    height: 1
                    color: "#555"
                    anchors.bottom: parent.bottom
                }
                Rectangle {
                    width: 1
                    height: parent.height
                    color: "#555"
                    anchors.right: parent.right
                }
            }
        }
        ScaleAnimator {
                id:scala
                target:rect;
                from: 0.1;
                to: 1;
                duration: 400
                running: visible
            }
        transformOrigin:"TopLeft"
    }


