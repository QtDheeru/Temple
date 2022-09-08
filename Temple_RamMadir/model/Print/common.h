#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <QString>
#include "ConfigureApp.h"

using namespace std;

struct SigninDetails{
    QString firstName;
    QString LastName;
    QString UserName;
    QString Password;
};

typedef struct print_details Print_Detail;

struct print_details
{
    QString NAME;
    QString RECPT_NO;
    QString MOB_NO;
    QString DATE;
    QString GOTHRA;
    QString SEVA_DATE;
    QString NAKSHATRA;
    QString SEVA_TIME;
    QString SL_NO;
    QString SEVA_DESCR;
    QString QTY;
    QString ADDITIONAL;
    QString AMT;
    QString RATE;
    QString TOTAL_AMT;
    QString TOTAL_IN_WORDS;
    QString NOTE;
    QString CASH;
    QString BANK_REF;
};

struct PersonDetails{
    QString NAME;
    QString MOB_NO;
    QString GOTHRA;
    QString NAKSHATRA;
};

struct SevaTypeDetails {
    int seva_type_id;
    QString seva_type_name;
};

struct SevaNameDetails{
    int sNumber;
    QString sevaName;
    int sevaType;
    int sevaCost;
    int teerthaPrasada;
    QString sevaDate;
};

namespace PRINT_HEADER {
//#ifdef HUBBALLI
//    const QString HEADER_1="Kuberapuram Rayaramutt";
//    constexpr int HEADER_1_FONT=14;
//    const QString HEADER_2="Solapur Road";
//    constexpr int HEADER_2_FONT=11;
//    const QString HEADER_3="Kuberapuram,   Bengaluru- 580020";
//    constexpr int HEADER_3_FONT=11;
//    const QString HEADER_4="Ph:080-48520969      Office Timings: 8AM to 1PM & 6PM to 8.30PM";
//    constexpr int HEADER_4_FONT=12;

//#endif
//#ifdef Hubballi
//const QString HEADER_1="ಶ್ರೀ ಕೃಷ್ಣ ವಿದ್ಯಾಪೀಠ ಟ್ರಸ್ಟ್";
//constexpr int HEADER_1_FONT=9;
//const QString HEADER_2="ಶ್ರೀ ಲಕ್ಷ್ಮೀ ವೆಂಕಟೇಶ್ವರ ಸ್ವಾಮಿ	ಮತ್ತು";
//constexpr int HEADER_2_FONT=11;
//const QString HEADER_3="ರಾಘವೇಂದ್ರ ಸ್ವಾಮಿ ಮಠ ";
//constexpr int HEADER_3_FONT=11;
//const QString HEADER_4="ಹುಬ್ಬಳ್ಳಿ";
//constexpr int HEADER_4_FONT=9;
//const QString HEADER_LEFT="ಸಂಪರ್ಕಿಸಿ: 9448482044";
//constexpr int HEADER_LEFT_FONT=9;

//const QString FOOTER_2="1. ಸೇವಾಕರ್ತರು ಸೇವಾ ದಿನಾಂಕದಂದು ನಿಗದಿತ ಸಮಯಕ್ಕೆ ಬಂದು ಸಂಕಲ್ಪ ಮಾಡಿ ಸೇವೆ ಮಾಡಿಸಬೇಕು.";
//constexpr int FOOTER_2_FONT=5;
//const QString FOOTER_1="ನಿಬಂಧನೆಗಳು - ";
//constexpr int FOOTER_1_FONT=8;
//const QString FOOTER_3= "2. ಸೇವಾಕರ್ತರು ಬರದಿದ್ದ ತಡಮಾಡಿದ ಪಕ್ಷದಲ್ಲಿ ಅವರ ಹೆಸರಿನಲ್ಲಿ ಸಂಕಲ್ಪ ಮಾಡಿ ಸೇವೆ ಮಾಡಲಾಗುವುದು.";
//constexpr int FOOTER_3_FONT=5;
//const QString FOOTER_4= "3.ಸೇವಕತೃಗಳು ಭಾರತೀಯ ಉಡುಪಿನಲ್ಲಿ ಬರುವುದು ಸೂಕ್ತ.";
//constexpr int FOOTER_4_FONT=6;
//const QString FOOTER_5= "4.ಚಟಕ /ಸಂಕಲ್ಪ- ಇಬ್ಬರಿಗೆ ತೀರ್ಥ ಪ್ರಸಾದದ ವ್ಯವಸ್ಥೆ ಸೇರಿರುತ್ತದೆ.";
//constexpr int FOOTER_5_FONT=8;
//const QString FOOTER_6=  "ಮಧ್ವ ಮತದ ಸಿದ್ಧಾಂತದ ಪದ್ಧತಿ ಬಿಡಬ್ಯಾಡಿ, ಬಿಟ್ಟು ಕೆಡಬ್ಯಾಡಿ - ಶ್ರೀ ಪುರಂದರದಾಸರು.";
//constexpr int FOOTER_6_FONT=8;
//const QString FOOTER_7=  " ";
//constexpr int FOOTER_7_FONT=8;
//const QString FOOTER_8=  " ";
//constexpr int FOOTER_8_FONT=6;

//const QString TRUST_SEAL = "For .........";
//#endif

//#ifdef RAMMANDIR
    const QString HEADER_1="SRIMAN MADHVA SANGHA RELIGIOUS AND CHARITABLE TRUST";
    constexpr int HEADER_1_FONT=9;
    const QString HEADER_2="Account No: 7720000100023495 PUNJAB NATIONAL BANK RR Nagar Branch";
    constexpr int HEADER_2_FONT=8;
    const QString HEADER_3="IFSC CODE- PUNB0772000 ";
    constexpr int HEADER_3_FONT=9;
    const QString HEADER_4="Ph:080-48520969      Office Timings: 8AM to 1PM & 6PM to 8.30PM";
    constexpr int HEADER_4_FONT=9;
    const QString HEADER_LEFT=" ";
    constexpr int HEADER_LEFT_FONT=9;

    const QString FOOTER_2="1. ಸೇವಾಕರ್ತರು ಸೇವಾ ದಿನಾಂಕದಂದು ನಿಗದಿತ ಸಮಯಕ್ಕೆ ಬಂದು ಸಂಕಲ್ಪ ಮಾಡಿ ಸೇವೆ ಮಾಡಿಸಬೇಕು.";
    constexpr int FOOTER_2_FONT=5;
    const QString FOOTER_1="ನಿಬಂಧನೆಗಳು - ";
    constexpr int FOOTER_1_FONT=8;
    const QString FOOTER_3= "2. ಸೇವಾಕರ್ತರು ಬರದಿದ್ದ ತಡಮಾಡಿದ ಪಕ್ಷದಲ್ಲಿ ಅವರ ಹೆಸರಿನಲ್ಲಿ ಸಂಕಲ್ಪ ಮಾಡಿ ಸೇವೆ ಮಾಡಲಾಗುವುದು.";
    constexpr int FOOTER_3_FONT=5;
    const QString FOOTER_4= "3.ಸೇವಕತೃಗಳು ಭಾರತೀಯ ಉಡುಪಿನಲ್ಲಿ ಬರುವುದು ಸೂಕ್ತ.";
    constexpr int FOOTER_4_FONT=7;
    const QString FOOTER_5= "4.ಚಟಕ/ಸಂಕಲ್ಪ- ಇಬ್ಬರಿಗೆ ತೀರ್ಥ ಪ್ರಸಾದದ ವ್ಯವಸ್ಥೆ ಸೇರಿರುತ್ತದೆ.";
    constexpr int FOOTER_5_FONT=8;
    const QString FOOTER_6=  "ಮಧ್ವ ಮತದ ಸಿದ್ಧಾಂತದ ಪದ್ಧತಿ ಬಿಡಬ್ಯಾಡಿ, ಬಿಟ್ಟು ಕೆಡಬ್ಯಾಡಿ - ಶ್ರೀ ಪುರಂದರದಾಸರು.";
    constexpr int FOOTER_6_FONT=6;
    const QString FOOTER_7=  " ";
    constexpr int FOOTER_7_FONT=8;
    const QString FOOTER_8=  " ";
    constexpr int FOOTER_8_FONT=8;

    const QString TRUST_SEAL = "For .........";

////    #endif

//    const QString HEADER_1="Sri Jagadguru Sreeman Madhwacharya Moolamaha Samsthana";

//#ifdef CHATURMASA
//    const QString HEADER_1 = "Sri Satyavara Satyaparayana";
//    constexpr int HEADER_1_FONT=10;
//    const QString HEADER_2="Brundavana Seva Samithi";
//    constexpr int HEADER_2_FONT=10;
//    const QString HEADER_3="Santhebidanur";
//    constexpr int HEADER_3_FONT=14;
//    const QString HEADER_4="Ph:08xx-252x4xx      Office Timings: 8AM to 1PM & 6PM to 8.30PM";
//    constexpr int HEADER_4_FONT=10;


//    const QString FOOTER_2="1. ಸೇವಾಕರ್ತರು ಸೇವಾ ದಿನಾಂಕದಂದು ನಿಗದಿತ ಸಮಯಕ್ಕೆ ಬಂದು ಸಂಕಲ್ಪ ಮಾಡಿ ಸೇವೆ ಮಾಡಿಸಬೇಕು.";
//    constexpr int FOOTER_2_FONT=14;
//    const QString FOOTER_1="ನಿಬಂಧನೆಗಳು - ";
//    constexpr int FOOTER_1_FONT=11;
//    const QString FOOTER_3= "2. ಸೇವಾಕರ್ತರು ಬರದಿದ್ದ ತಡಮಾಡಿದ ಪಕ್ಷದಲ್ಲಿ ಅವರ ಹೆಸರಿನಲ್ಲಿ ಸಂಕಲ್ಪ ಮಾಡಿ ಸೇವೆ ಮಾಡಲಾಗುವುದು.";
//    constexpr int FOOTER_3_FONT=11;
//    const QString FOOTER_4= "3.ಸೇವಕತೃಗಳು ಭಾರತೀಯ ಉಡುಪಿನಲ್ಲಿ ಬರುವುದು ಸೂಕ್ತ.";
//    constexpr int FOOTER_4_FONT=8;
//    const QString FOOTER_5= "4.ಚಟಕ /ಸಂಕಲ್ಪ- ಇಬ್ಬರಿಗೆ ತೀರ್ಥ ಪ್ರಸಾದದ ವ್ಯವಸ್ಥೆ ಸೇರಿರುತ್ತದೆ.";
//    constexpr int FOOTER_5_FONT=8;
//    const QString FOOTER_6=  "ಮಧ್ವ ಮತದ ಸಿದ್ಧಾಂತದ ಪದ್ಧತಿ ಬಿಡಬ್ಯಾಡಿ, ಬಿಟ್ಟು ಕೆಡಬ್ಯಾಡಿ - ಶ್ರೀ ಪುರಂದರದಾಸರು.";
//    constexpr int FOOTER_6_FONT=8;
//    const QString FOOTER_7=  "ಮಧ್ವ ಮತದ ಸಿದ್ಧಾಂತದ ಪದ್ಧತಿ ಬಿಡಬ್ಯಾಡಿ, ಬಿಟ್ಟು ಕೆಡಬ್ಯಾಡಿ - ಶ್ರೀ ಪುರಂದರದಾಸರು.";
//    constexpr int FOOTER_7_FONT=8;
//    const QString FOOTER_8=  "ಮಧ್ವ ಮತದ ಸಿದ್ಧಾಂತದ ಪದ್ಧತಿ ಬಿಡಬ್ಯಾಡಿ, ಬಿಟ್ಟು ಕೆಡಬ್ಯಾಡಿ - ಶ್ರೀ ಪುರಂದರದಾಸರು.";
//    constexpr int FOOTER_8_FONT=8;

//    const QString TRUST_SEAL = "For .........";
//#endif
}


#endif // COMMON_H
