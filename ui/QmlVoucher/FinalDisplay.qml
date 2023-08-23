import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3


Rectangle
{
    width:parent.width
    height:parent.height
    color:"white"
    anchors.left: parent.right
    border.color: "black"
    border.width: 1
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
            myid.text=voucherId
            t3.text=subname
            t2.text=subcat
        }

    }

    Rectangle
    {

        width: 400
        height: 630
        color: "white"
        x:160
        y:150
        id:myRect

        Label
        {
            text:"ADD,UPDATE AND DELETE OPERATION"
            anchors.top: parent.top
            anchors.topMargin: 1
            color: "black"
            font.pixelSize:20
            font.underline: true
            anchors.horizontalCenter: parent.horizontalCenter

        }


        ColumnLayout
        {
            anchors.fill: parent
            spacing:-200
            RowLayout
            {
                spacing: 195
                ColumnLayout
                {
                    spacing: 30
                    Rectangle{
                        width: 20
                        height: 20
                        Label{
                            text: "SNO : "
                            font.bold: true
                        }
                    }
                    Rectangle{
                        width: 20
                        height: 20
                        Label{
                            text: "CATEGORY ID : "
                            font.bold: true

                        }
                    }
                    Rectangle{
                        width: 20
                        height: 20
                        Label{
                            text: "CATEGORY NAME : "
                            font.bold: true

                        }
                    }
                    Rectangle{
                        width: 20
                        height: 20
                        Label{
                            text: "SUB CATEGORY ID : "
                            font.bold: true
                        }
                    }

                    Rectangle{
                        width: 20
                        height: 20
                        Label{
                            text: "SUB CATEGORY NAME : "
                            font.bold: true

                        }
                    }

                }
                ColumnLayout{
                    spacing: 30
                    Rectangle{
                        width: 170
                        height: 20
                        Rectangle{
                            id: rec1
                            width: 170
                            height: 2
                            color: "black"
                            anchors.bottom: parent.bottom
                            TextArea{
                                placeholderText: "Serial Number"
                                anchors.bottom: rec1.top
                                anchors.left: parent.left
                                //anchors.leftMargin: 10
                                text: voucherProxy.my_serial
                                font.pixelSize: 16
                            }
                        }
                    }
                    Rectangle{
                        width: 170
                        height: 20
                        Rectangle{
                            id: rec2
                            width: 170
                            height: 2
                            color: "black"
                            anchors.bottom: parent.bottom
                            TextArea{
                                id:myid
                                placeholderText: "Category ID"
                                anchors.bottom: rec2.top
                                anchors.left: parent.left
                                //anchors.leftMargin: 10
                                text: ""
                                font.pixelSize: 16
                            }
                        }
                    }
                    Rectangle
                    {
                        width: 170
                        height: 20
                        Rectangle{
                            id: rec3
                            width: 170
                            height: 2
                            color: "black"
                            anchors.bottom: parent.bottom
                            TextArea{
                                id:t1
                                placeholderText: "CATEGORY NAME"
                                anchors.bottom: rec3.top
                                anchors.left: parent.left
                                //anchors.leftMargin: 10
                                text: voucherProxy.my_vname
                                font.pixelSize: 16
                            }
                        }
                    }
                    Rectangle
                    {
                        id: _rec4
                        width: 170
                        height: 20
                        Rectangle
                        {

                            id: rec4
                            width: 170
                            height: 2
                            color: "black"
                            anchors.bottom: parent.bottom
                            TextArea
                            {
                                id:t2
                                placeholderText: "Subcategory Id"
                                anchors.bottom: rec4.top
                                anchors.left: parent.left
                                //anchors.leftMargin: 10
                                text: ""
                                font.pixelSize: 16
                            }
                        }
                    }

                    Rectangle
                    {
                        id: _rec5
                        width: 170
                        height: 20
                        Rectangle
                        {

                            id: rec5
                            width: 170
                            height: 2
                            color: "black"
                            anchors.bottom: parent.bottom
                            TextArea
                            {
                                id:t3
                                placeholderText: "SUB CATEGORY NAME"
                                anchors.bottom: rec5.top
                                anchors.left: parent.left
                                //anchors.leftMargin: 10
                                text: ""
                                font.pixelSize: 16
                            }

                        }
                    }
                }

            }


            ColumnLayout
            {
                spacing: 15

                MyButton
                {
                    id:add_button
                    text: "ADD"
                    onMouseClicked:
                    {
                        voucherProxy.clearProxy();
                        voucherProxy.addToDb(myid.text,t2.text,t3.text)
                    }

                }

                MyButton
                {
                    id:_update
                    text: "UPDATE"
                    onMouseClicked:
                    {
                        voucherProxy.clearProxy();
                        voucherProxy.updateToDb(myid.text,t2.text,t3.text);

                    }

                }
                MyButton
                {
                    id:_delete

                    text: "DELETE"
                    onMouseClicked:
                    {
                        voucherProxy.clearProxy();
                        voucherProxy.deleteToDb(myid.text,t2.text,t3.text)
                        t3.clear()
                        t2.clear()
                    }


                }

            }

            Connections
            {
                target:voucherProxy
                onQmlDialog:
                {
                    myD.dTxt = "Insertion Failed"
                    myD.dImage="qrc:/Images/fail.png"
                    myD.visible = "true";


                }
                onProxyUpdate:
                {
                    myD.dTxt = "Update Failed"
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
                    myD.dTxt = "Deletion Failed"
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
        }
    }

    MyDialogBox
    {
        id:myD
        visible: false
        anchors.centerIn: parent
    }

}

