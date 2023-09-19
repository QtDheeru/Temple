import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle
{
    id:sub
    width: parent.width
    height:parent.height

    RowLayout
    {
        anchors.fill: parent
        spacing:0
        MainTableCategory
        {
            id:tb
            Layout.preferredWidth: parent.width / 3
            Layout.preferredHeight: parent.height

            onMyTableClicked:
            {

                myld.source = ""
                myld.source="qrc:/ui/QmlVoucher/SubTableCategory.qml"
            }
            onRefresh:
            {

                myld.source = ""
                myld.source="qrc:/ui/QmlVoucher/SubTableCategory.qml"
            }

        }

        Loader
        {
            id:myld
            Layout.preferredWidth:  parent.width/3
            Layout.preferredHeight: parent.height
            anchors.left: tb.right

        }

    }

}









