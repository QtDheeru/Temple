import QtQuick 2.15
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.14
Rectangle{
    id:_r1
    anchors.fill: parent
    Rectangle{
        id : _header
        width: _r1.width
        height: 25
        color: "#00A2ED"
        anchors.top: parent.top
        RowLayout {
            width: parent.width
            height: parent.height
            Text {
                text:"Sno"
                Layout.alignment: Qt.AlignLeft
                Layout.preferredWidth: 20
                Layout.maximumWidth: 20
                font.bold : true

            }
            Text {
                text:"Name"
                Layout.alignment: Qt.AlignLeft
                //Layout.leftMargin: 20
                Layout.preferredWidth: 150
                Layout.maximumWidth: 150
                font.bold : true
            }
            Text {
                text:"Mobile No."
                Layout.alignment: Qt.AlignLeft
                Layout.preferredWidth: 100
                Layout.maximumWidth: 100
                font.bold : true
            }
            Text {
                text:"Seva Name"
                Layout.alignment: Qt.AlignLeft
                Layout.preferredWidth: 150
                Layout.maximumWidth: 150
                font.bold : true
            }
            Text {
                text:"Seva Date"
                Layout.alignment: Qt.AlignLeft
                Layout.preferredWidth: 100
                Layout.maximumWidth: 100
                font.bold : true
            }
            Text {
                text:"Reciept Date"
                Layout.alignment: Qt.AlignLeft
                Layout.preferredWidth: 100
                Layout.maximumWidth: 100
                font.bold : true
            }
            Text {
                text:"Total"
                Layout.alignment: Qt.AlignLeft
                Layout.preferredWidth: 100
                Layout.maximumWidth: 100
                font.bold : true
            }
            Text {
                text:"Cash"
                Layout.alignment: Qt.AlignLeft
                Layout.preferredWidth: 100
                Layout.maximumWidth: 100
                font.bold : true
            }
            Text {
                text:"Bank"
                Layout.alignment: Qt.AlignLeft
                Layout.preferredWidth: 100
                Layout.maximumWidth: 100
                font.bold : true
            }
            Text {
                text:"Reference"
                Layout.alignment: Qt.AlignLeft
                Layout.preferredWidth: 100
                Layout.maximumWidth: 100
                font.bold : true
            }
            Text {
                text:"Momento"
                Layout.alignment: Qt.AlignLeft
                Layout.preferredWidth: 100
                Layout.maximumWidth: 100
                font.bold : true
            }
            Text {
                text:"Address"
                Layout.alignment: Qt.AlignLeft
                Layout.preferredWidth: 100
                Layout.maximumWidth: 100
                font.bold : true
            }

        }
    }
    ListView{
        width:parent.width
        height: parent.height - _header.height
         anchors.top: _header.bottom
        id:dateCountList
        //model: sevaDateCount
        model: sevaProxy.sevaReport.reportOnDateModel
        spacing: 2
        delegate:_comp2
Component.onCompleted: {
    if(sevaProxy.sevaReport.reportOnDateModel===null)
    {
        errorOccur("seva details on date model not found");
    }
}

    }

    Component{
        id: _comp2
        Rectangle {
            id: _b1
            width: parent.width
            height: 30
            color: (index%2 ==0)?"gray":"lightgray"


            RowLayout{
                anchors.fill: parent
                Text{
                    Layout.alignment: Qt.AlignLeft
                    //Layout.leftMargin: 10
                    Layout.preferredWidth: 20
                    Layout.maximumWidth: 20
                    text:Sno   }
                Text{
                    Layout.alignment: Qt.AlignLeft
                    //Layout.leftMargin: 20
                    Layout.preferredWidth: 150
                    Layout.maximumWidth: 150
                    elide: Text.ElideRight
                    text:name   }
                Text{
                    Layout.alignment: Qt.AlignLeft
                    //Layout.leftMargin: 60
                    Layout.preferredWidth: 100
                    Layout.maximumWidth: 100
                    text:mobile
                }
                Text{
                    Layout.alignment: Qt.AlignLeft
                    //Layout.leftMargin: 60
                    Layout.preferredWidth: 150
                    Layout.maximumWidth: 150
                    elide: Text.ElideRight
                    text:sevaName   }
                Text{
                    Layout.alignment: Qt.AlignLeft
                    //Layout.leftMargin: 60
                    Layout.preferredWidth: 100
                    Layout.maximumWidth: 100
                    text:sevaDate   }
                Text{
                    Layout.alignment: Qt.AlignLeft
                    //Layout.leftMargin: 60
                    Layout.preferredWidth: 100
                    Layout.maximumWidth: 100
                    text:receiptDate   }
                Text{
                    Layout.alignment: Qt.AlignLeft
                    //Layout.leftMargin: 60
                    Layout.preferredWidth: 100
                    Layout.maximumWidth: 100
                    text:total   }
                Text{
                    Layout.alignment: Qt.AlignLeft
                    //Layout.leftMargin: 60
                    Layout.preferredWidth: 100
                    Layout.maximumWidth: 100
                    text:cash   }
                Text{
                    Layout.alignment: Qt.AlignLeft
                    //Layout.leftMargin: 60
                    Layout.preferredWidth: 100
                    Layout.maximumWidth: 100
                    text:bank   }
                Text{
                    Layout.alignment: Qt.AlignLeft
                    //Layout.leftMargin: 60
                    Layout.preferredWidth: 100
                    Layout.maximumWidth: 100
                    text:refernce   }
                Text{
                    Layout.alignment: Qt.AlignLeft
                    //Layout.leftMargin: 60
                    Layout.preferredWidth: 100
                    Layout.maximumWidth: 100
                    text:momento   }
                Text{
                    Layout.alignment: Qt.AlignLeft
                    //Layout.leftMargin: 60
                    Layout.preferredWidth: 100
                    Layout.maximumWidth: 100
                    text:address   }




            }

        }
    }
}


