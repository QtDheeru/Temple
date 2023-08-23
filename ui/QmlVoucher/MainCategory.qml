import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Rectangle{
    id:main_rect
    color: "#FFFFFF"
    border.color:"black"
    border.width: 2

    MyDialogBox{
        id:dlog
        anchors.centerIn: parent
        visible: false
    }

    Label
    {
        text:"ADD,UPDATE AND DELETE OPERATION"
        anchors.top: parent.top
        anchors.topMargin: 20
        color: "black"
        font.pixelSize:parent.width/40
        font.underline: true
        anchors.horizontalCenter: parent.horizontalCenter
    }

    ColumnLayout{
        anchors.centerIn: parent
        spacing: 15
        RowLayout{
            spacing: 20
            Label{
                text: "Serial Number:"
                font.pixelSize: 15
                font.bold: true
                color: "black"
            }
            TextField{
                id:t1
                Layout.preferredWidth: 180
                placeholderText: "Enter S.No"
                placeholderTextColor: "#000000"
                font.pixelSize: 16
                KeyNavigation.down: t2
                color: "black"
                validator:IntValidator{ bottom: 0;top:9999999}
                background: Rectangle{color: "Transparent"}
                UnderLine{}
            }
        }
        RowLayout{
            spacing: 40
            Label{
                text: "Category ID:"
                font.pixelSize: 15
                color: "black"
                font.bold: true
            }
            TextField{
                id:t2
                Layout.preferredWidth: 180
                placeholderText: "Enter Id"
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
                placeholderText: "Enter Name"
                placeholderTextColor: "#000000"
                font.pixelSize: 16
                KeyNavigation.down: t3
                color: "black"
                background: Rectangle{color: "Transparent"}
                UnderLine{}
            }
        }

        MyButton{
            id:bt
            btxt:"ADD"
            onMouseClicked: {
                console.log("add function called");
                voucherProxy.addVoucherMainType(t1.text,t2.text,t3.text);
            }
        }

        MyButton{
            btxt: "UPDATE"
            onMouseClicked: {
                voucherProxy.updateVoucherInProxy(t1.text,t2.text,t3.text)
            }
        }

        MyButton{
            btxt: "DELETE"
            onMouseClicked:{
                voucherProxy.removeVoucherInProxy(t2.text);
            }
        }
    }

    Connections{
        target:voucherProxy
        function onVouchToQml(serial,voucherId,voucherName)
        {
            t1.text=serial
            t2.text=voucherId
            t3.text=voucherName
        }
        function onListCountToQml(serial){
            t1.text=serial
            t2.clear();
            t3.clear();
        }
        function onSigToQml(){
            dlog.dTxt="Invalid Data!";
            setImageForFail()
            dlog.visible=true
        }
        function onSerialErrorInProxy(){
            dlog.dTxt="Serial Number already Present!"
            setImageForFail()
            dlog.visible=true
        }
        function onVoucherErrorInProxy(){
            dlog.dTxt="Voucher ID already Present!"
            setImageForFail()
            dlog.visible=true
        }
        function onVoucherNameErrorInProxy(){
            dlog.dTxt="Voucher Name already exists!"
            setImageForFail()
            dlog.visible=true
        }

        function onAddSucsessInProxy(){
            dlog.dTxt="Added Data Successfully"
            setImageForSuccess()
            dlog.visible=true
        }
        function onAddFailInProxy(){
            dlog.dTxt="Data Addition Failed"
            setImageForFail()
            dlog.visible=true
        }
        function onUpdateFailInProxy(){
            dlog.dTxt="Update Failed!"
            setImageForFail()
            dlog.visible=true
        }
        function onUpdateSuccessInProxy(){
            dlog.dTxt="Update Successful"
            setImageForSuccess()
            dlog.visible=true
        }
        function onRemoveSuccessInProxy(){
            dlog.dTxt="Deletion Successful"
            setImageForSuccess()
            dlog.visible=true
        }
        function onRemoveFailInProxy(){
            dlog.dTxt="Deletion Failed!"
            setImageForFail()
            dlog.visible=true
        }
    }

    function setImageForSuccess(){
        dlog.dImage="qrc:/Images/good.png"
    }
    function setImageForFail(){
        dlog.dImage="qrc:/Images/fail.png"
    }
}
