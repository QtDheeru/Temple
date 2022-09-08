//import QtQuick 2.0
import QtQuick 2.11
Item {
    property color backgroundColor: "#F2F3F4" ;
    property color headerBackgroundColor: "black";
    property color topUnderLineColor: "#000000"
    property color headerTextColor: "#F4C430"
    property color addressTextColor: "#F4C430"
    property color bottomUnderLineColor: "#3c3b3d"
    property color addressBackgroundColor:"black"

    property string headerText1: "SRIMAN MADHVA SANGHA RELIGIOUS AND CHARITABLE TRUST";
    property string headerText2: "RR Nagar"
    property string addressText1: "Bengaluru "
    property string addressText2: "Ph:080-48520969      Office Timings: 8AM to 1PM & 6PM to 8.30PM "
    property string addressText3: " "
    property string addressText4: " "

    //Hubballi
//    property string headerText1: "ಶ್ರೀ ಕೃಷ್ಣ ವಿದ್ಯಾಪೀಠ ಟ್ರಸ್ಟ್";
//    property string headerText2: "ಶ್ರೀ ಲಕ್ಷ್ಮೀ ವೆಂಕಟೇಶ್ವರ ಸ್ವಾಮಿ ಮತ್ತು ರಾಘವೇಂದ್ರ ಸ್ವಾಮಿ ಮಠ "
//    property string addressText1: "ಹುಬ್ಬಳ್ಳಿ"
//    property string addressText2: " "
//    property string addressText3: " "
//    property string addressText4: " "



    readonly property string templePic: "file:" + confApp.appPath + "/" + confApp.loginImg
            //"qrc:/ui/assets/Images/TempleInviteSnap.jpeg"
}
