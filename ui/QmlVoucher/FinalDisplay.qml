import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Rectangle{
    id:main_rect
    color: "#FFFFFF"
    border.color:"black"
    border.width: 2
    width:parent.width
    height:parent.height
    anchors.left: parent.right

    Component.onCompleted:
    {
        voucherProxy.toDataModel()
    }

    Connections
    {
        target:voucherProxy
        onUse_Data:
        {
            console.log("subcat"+subcat)
            console.log("subname"+subname)
            console.log("voucherId"+voucherId)
            t2.text=voucherId
            t5.text=subname
            t4.text=subcat
        }

    }

    MyDialogBox{
        id:dlog
        anchors.centerIn: parent
        visible: false
    }

    Label
    {
        text:"ADD,UPDATE AND DELETE OPERATION"
        anchors.top: parent.top
        anchors.topMargin: 70
        color: "black"
        font.pixelSize:parent.width/40
        font.underline: true
        anchors.horizontalCenter: parent.horizontalCenter
    }

    ColumnLayout
    {
        anchors.centerIn: parent
        spacing: 20
        RowLayout{
            spacing: 17
            Label{
                text: "Serial Number:"
                font.pixelSize: 15
                font.bold: true
                color: "black"
            }
            TextField{
                id:t1
                Layout.preferredWidth: 180

                placeholderText: "S.No"
                placeholderTextColor: "#000000"
                font.pixelSize: 16
                KeyNavigation.down: t2
                color: "black"
                text: voucherProxy.my_serial
                validator:IntValidator{ bottom: 0;top:9999999}
                background: Rectangle{color: "Transparent"}
                UnderLine{}
            }

        }
        RowLayout{
            spacing: 17
            Label{
                text: "Category ID:"
                font.pixelSize: 15
                color: "black"
                font.bold: true
            }
            TextField{
                id:t2
                Layout.preferredWidth: 180
                placeholderText: "Category Id"
                placeholderTextColor: "#000000"
                font.pixelSize: 16
                KeyNavigation.down: t3
                color: "black"
                background: Rectangle{color: "Transparent"}
                validator:IntValidator{ bottom: 0;top:9999999}
                UnderLine{}
            }
        }
        RowLayout{
            spacing: 17
            Label{
                text: "Category Name:"
                font.pixelSize: 15
                color: "black"
                font.bold: true
            }
            TextField{
                id:t3
                Layout.preferredWidth: 180
                placeholderText: "Category Name"
                placeholderTextColor: "#000000"
                font.pixelSize: 16
                KeyNavigation.down: t3
                text: voucherProxy.my_vname
                color: "black"
                background: Rectangle{color: "Transparent"}
                UnderLine{}
            }
        }
        RowLayout{
            spacing: 17
            Label{
                text: "SubCategory Id"
                font.pixelSize: 15
                color: "black"
                font.bold: true
            }
            TextField{
                id:t4
                Layout.preferredWidth: 180
                placeholderText: "SubCategory Id"
                placeholderTextColor: "#000000"
                font.pixelSize: 16
                KeyNavigation.down: t3
                color: "black"
                background: Rectangle{color: "Transparent"}
                UnderLine{}
            }
        }

        RowLayout{
            spacing: 17
            Label{
                text: "SubCategory Name"
                font.pixelSize: 15
                color: "black"
                font.bold: true
            }
            TextField{
                id:t5
                Layout.preferredWidth: 180
                placeholderText: "SubCategory Name"
                placeholderTextColor: "#000000"
                font.pixelSize: 16
                KeyNavigation.down: t3
                color: "black"
                background: Rectangle{color: "Transparent"}
                UnderLine{}
            }
        }

        MyButton
        {
            id:add_button
            text: "ADD"
            onMouseClicked:
            {

                voucherProxy.addToDb(t2.text,t4.text,t5.text)

            }
        }

        MyButton
        {
            id:myupdate
            text: "UPDATE"
            onMouseClicked:
            {

                voucherProxy.updateToDb(t2.text,t4.text,t5.text);

            }
        }

        MyButton
        {
            id:mydelete

            text: "DELETE"
            onMouseClicked:
            {

                voucherProxy.deleteToDb(t2.text,t4.text,t5.text);
                t5.clear()
                t4.clear()
            }

        }
    }


    Connections
    {
        target:voucherProxy
        onQmlDialog:
        {
            myD.dTxt = "SubcategoryID already Present"
            myD.dImage="qrc:/Images/fail.png"
            myD.visible = "true";


        }
        onProxyUpdate:
        {
            myD.dTxt = "SubcategoryID not present"
            myD.visible = "true";
            myD.dImage="qrc:/Images/fail.png"

        }
        onUpdateQml:
        {
            myD.dTxt = "Update Success"
            myD.visible = "true";
            myD.dImage="qrc:/Images/good.png"

        }
        onProxyDelete:
        {
            console.log("Inside onProxyDelete qml slot")
            myD.dTxt = "SubcategoryID Not Present"
            myD.dImage="qrc:/Images/fail.png"
            myD.visible = "true";
        }
        onDeleteQml:
        {
            myD.dTxt = "Delete Success"
            myD.visible = "true";
            myD.dImage="qrc:/Images/good.png"


        }
        onInsertQml:
        {
            myD.dTxt = "Insert Success"
            myD.visible = "true";
            myD.dImage="qrc:/Images/good.png"

        }

    }

    MyDialogBox
    {
        id:myD
        visible: false
        anchors.centerIn: parent
    }




}

