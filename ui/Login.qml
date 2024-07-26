import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.15
import "./components"

Item {
    id: root
    width: styles.screenWidth
    height: styles.screenHeight
    visible: true

    property var styles: MyStyles{}
    property int fpixelsize: styles.firstRowFontSize
    property string tex1
    property string tex2
    property int pageNumber:0
    property color backgroundColor :"#f3f8f9"
    property string loginErrorString: "Incorrect password"
    property string loginPageImage: styles.loginPageImage
    property var imgVisible

    signal wrongCred()
    signal closeWindow();
    signal loginSuccess(int pcount)

    Rectangle
    {
        id : mainRectangle
        width: root.width
        height : root.height
        color:backgroundColor
        Image {
            id: image01
            source: "qrc:/ui/assets/Images/background01.jpeg"
            rotation: 90
            anchors.left: parent.left
            height: parent.height/4
            width: parent.width/4
            visible: imgVisible
        }
        Image {
            id: image02
            source: "qrc:/ui/assets/Images/background04.jpeg"
            anchors.right:  parent.right
            anchors.bottom:  parent.bottom
            visible: imgVisible
        }
        Image {
            id: name
            source: "qrc:/ui/assets/Images/remove.png"
            height: 30
            width: 30
            visible: pageNumber===0? false:true
            anchors.right: parent.right
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    console.log("close clicked")
                    closeWindow()
                }
            }
        }
        Text {
            id: mainText
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: root.height/25
            font.pixelSize: styles.headerTextFont1
            font.bold: true
            text: "Login"
        }
        Column
        {
            id: _column
            anchors.bottomMargin: root.height/10
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: root.height/70
            Image {
                id: image03
                source: loginPageImage
                visible: imgVisible
                anchors.horizontalCenter: parent.horizontalCenter
                height: root.height/2
                width: root.width/3
            }
            RoundButton
            {
                id: columnrect
                width: mainRectangle.width/3
                height: mainRectangle.height/13
                radius: columnrect.width/4
                palette { button: "#ebdafe" }
                TextInput {
                    id: userNameID
                    text: ""
                    focus: true
                    horizontalAlignment: TextInput.AlignHCenter
                    verticalAlignment: TextInput.AlignVCenter
                    font.pixelSize: fpixelsize
                    anchors.fill: parent
                    clip: true
                    property string placeholderText: "Enter your Login ID"
                    Text {
                        id: placeHolderTextID
                        text: userNameID.placeholderText
                        color: "#9C51B6"
                        visible: !(userNameID.activeFocus || userNameID.text)
                        font.bold: true
                        font.pixelSize: styles.firstRowFontSize
                        anchors.centerIn: parent
                        clip: true
                    }
                }
                onActiveFocusChanged: {
                    if(activeFocus) userNameID.forceActiveFocus()
                }
            }
            RoundButton
            {
                id: columnrect2
                width: mainRectangle.width/3
                height: mainRectangle.height/13
                radius: columnrect2.width/4
                palette { button: "#ebdafe" }
                TextInput{
                    id: passwordInput
                    text: ""
                    focus: true
                    font.pixelSize: fpixelsize
                    horizontalAlignment: TextInput.AlignHCenter
                    verticalAlignment: TextInput.AlignVCenter
                    anchors.fill: parent
                    property string placeholderText: "Enter your password"
                    echoMode : TextInput.Password
                    clip: true
                    Text {
                        id: passwordPlaceTextID
                        text: passwordInput.placeholderText
                        color: "#9C51B6"
                        visible: !(passwordInput.activeFocus || passwordInput.text)
                        font.bold: true
                        font.pixelSize: styles.firstRowFontSize
                        anchors.centerIn: parent
                        clip: true
                    }
                }
                onActiveFocusChanged: {
                    if(activeFocus) passwordInput.forceActiveFocus()
                }
            }
            RoundButton{
                id: columnrect3
                width: mainRectangle.width/3
                height: mainRectangle.height/13
                radius: columnrect3.width/4
                focus : true
                palette { button:"#9B26B6" }
                Text {
                    id: loginPageLogin
                    text: "Login"
                    font.pixelSize: styles.headerTextFont2
                    font.bold: true
                    anchors.centerIn: parent
                    clip: true
                }
                onClicked: {
                    sevaProxy.userManagement.authorize(userNameID.text,passwordInput.text)
                    userNameID.text = ""
                    passwordInput.text = ""
                }
                onFocusChanged: {
                    console.log("login button focus changed"+ focus)
                }
                Keys.onEnterPressed: {
                    console.log("login button Entered ")
                    sevaProxy.userManagement.authorize(userNameID.text,passwordInput.text)
                    userNameID.text = ""
                    passwordInput.text = ""
                }
                Keys.onPressed: (event)=>{
                                    console.log("login button pressed")
                                    if (event.key == Qt.Key_Enter || event.key == Qt.Key_Return) {
                                        sevaProxy.userManagement.authorize(userNameID.text,passwordInput.text)
                                        userNameID.text = ""
                                        passwordInput.text = ""
                                    }
                                }
                onActiveFocusChanged: {
                    if(activeFocus) columnrect3.forceActiveFocus()
                }
            }
            Rectangle{
                id: error
                width: mainRectangle.width/3
                height: mainRectangle.height/30
                Text {
                    id: errortext
                    text: qsTr(loginErrorString)
                    color: "red"
                    visible: false
                    font.pixelSize: styles.headerTextFont4
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
            Text {
                id: version
                text: qsTr("Version 1.0")
                font.pixelSize: Math.min(parent.height,parent.width) * 0.02
                z:5
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }

    Connections{
        target: dbchecker
        function onCorrectCredentials()
        {
            console.log("Credentials are correct")
            loginSuccess(pageNumber)
        }
        function onWrongCredentials()
        {
            console.log("Credentials are not correct")
            wrongCred()
            errortext.visible = true
        }
    }

    function callLoad(){
        voucherProxy.loadTbViewInProxy();
        voucherProxy.voucherHeadsTableModel.rowClicked(0);
    }

    Keys.onEnterPressed: {
        console.log( "enter key pressed")
        sevaProxy.userManagement.authorize(userNameID.text,passwordInput.text)
        userNameID.text = ""
        passwordInput.text = ""
    }
    Keys.onEscapePressed: {
        console.log("Escape Pressed ==== ",pageNumber)
        if(pageNumber === 2 || pageNumber === 4){
            Qt.quit();
        }
    }
    Component.onCompleted: {
        console.log("Login :: The Page Number===",pageNumber)
        if(pageNumber === 2){
            _column.anchors.centerIn = parent
            columnrect.width = mainRectangle.width/3.5
            columnrect.height = mainRectangle.height/11
            backgroundColor = "cornflowerblue"
            mainRectangle.border.width = 2

            columnrect2.width = mainRectangle.width/3.5
            columnrect2.height = mainRectangle.height/11

            columnrect3.width = mainRectangle.width/3.5
            columnrect3.height = mainRectangle.height/11
        }
        else if(pageNumber === 4){
            _column.anchors.centerIn = parent
            columnrect.width = mainRectangle.width/3.5
            columnrect.height = mainRectangle.height/11
            backgroundColor = "cornflowerblue"
            mainRectangle.border.width = 2

            columnrect2.width = mainRectangle.width/3.5
            columnrect2.height = mainRectangle.height/11

            columnrect3.width = mainRectangle.width/3.5
            columnrect3.height = mainRectangle.height/11
        }
        else {
            console.log( "The page number is 0")
        }
    }
}

