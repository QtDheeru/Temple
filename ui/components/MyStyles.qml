//pragma Singleton
import QtQuick 2.0
import QtQuick.Window 2.14

QtObject  {
    id:style
    property int screenWidth: Screen.width
//    property int screenHeight: Screen.height - 100 //590
    property int screenHeight: Screen.height-80 //590
    property int textSize: screenHeight/90      //12
    property int headerTextFont1: screenHeight/40   //27
    property int headerTextFont2: screenHeight/45   //24
    property int headerTextFont3: screenHeight/50   //21
    property int headerTextFont4: screenHeight/60   //18
    property int headerTextFont5: screenHeight/70   //15

    // Devide the screen height in ration of 4:4:2
    property real firstRowHeight : screenHeight*4/10    //360
    property real fontSize : screenHeight/40
    property real firstRowFontSize : screenHeight/40
    property real lastRowHeight : screenHeight*1/11
    property real verticalSpacing : 5 //screenHeight/50
    property real receiptDateFontSize: screenHeight/30

    property color backgroundcolorOfApp: "white"//"#445566" //"#4169e1"//"#445566"
    property color buttonColor: "#FFE5B4"
    property color sevaBookingPagebackgroundcolor: "#445566"

    property  string  loginPageImage: "file:" + confApp.appPath + "/" + confApp.loginImg //"qrc:/ui/assets/Images/TempleInviteSnap.jpeg"

    Component.onCompleted: {
        console.log("SingleTon is created. Screen density  == " + Screen.pixelDensity)
        console.log("Screen screenWidth size ="+Screen.width)
        console.log("Screen screenHeight size ="+(Screen.height-80))
    }
}
