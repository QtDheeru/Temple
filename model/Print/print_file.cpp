﻿#include "print_file.h"
#include <QPrintDialog>

static QString  single_seva;
static int  single_cost;
static QString single_tickets;
static QString single_sevadate;

print_file::print_file(QWidget *parent) : QWidget(parent)
{
    list_seva = new QList<QString>;
    list_cost = new QList<float>;
    list_tickets = new QList<QString>;
    list_sevadate = new QList<QString>;
    voc_purpose = new QList<QString>;
    voc_cat = new QList<QString>;
    voc_pri = new QList<float>;
}

int print_file::write2file(QString seva_S,QString name_S,QString gothram_S,QString nakshatram_S,float cost_S,QString date_S)
{
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream<<"****"<<seva_S<<"****"<<Qt::endl;
        stream<<"Name     ::  "<<name_S<<Qt::endl;
        stream<<"gothram  ::  "<<gothram_S<<Qt::endl;
        stream<<"Nakshatram:: "<<nakshatram_S<<Qt::endl;
        stream<<"price     :: "<<cost_S<<Qt::endl;
        stream<<"Date      :: "<<date_S<<Qt::endl;
        qDebug()<<"data entering into file"<<Qt::endl;
    }
    return 0;
}

void print_file::PrinterPreview()
{
}

int print_file::printing_file(QList<Print_Detail *> *pd)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    this->prin2PixMap(pd);
    QPrinter printer;
    qDebug() << Q_FUNC_INFO << " Start the printing =" << pd->size() << Qt::endl;
    printer.setOrientation(QPrinter::Portrait);
    QPainter painter;

    QPrintDialog *dlg = new QPrintDialog(&printer);
    if(dlg->exec() != QDialog::Accepted){
        qDebug() << Q_FUNC_INFO << " dlg->exec() != QDialog::Accepted" << Qt::endl;
        return 1;
    }else{
        qDebug() << Q_FUNC_INFO << " dlg->exec() == QDialog::Accepted" << Qt::endl;
        QRectF f(150,0,500,550);
        QRectF e(0,0,500,550);
        if (!painter.begin(&printer)){
            qWarning("failed to open file, is it writable?");
            return 10;
        }
        painter.setPen(Qt::black);
        painter.drawPixmap(f,m_map,e);
        return 1;
    }
}

int print_file::printing_file(Print_VoucherDetail *pvd)
{
    qDebug()<<Q_FUNC_INFO << Qt::endl;
    this->prin2PixMap(pvd);
    QPrinter printer;
    qDebug()<<Q_FUNC_INFO << " Start the printing ="<< Qt::endl;
    printer.setOrientation(QPrinter::Portrait);
    QPainter painter;

    QPrintDialog *dlg = new QPrintDialog(&printer);
    if(dlg->exec() != QDialog::Accepted){
        qDebug() << Q_FUNC_INFO << " dlg->exec() != QDialog::Accepted" << Qt::endl;
        return 1;
    }else{
        qDebug() << Q_FUNC_INFO << " dlg->exec() == QDialog::Accepted" << Qt::endl;
        QRectF f(150,0,500,550);
        QRectF e(0,0,500,550);
        if (!painter.begin(&printer)){
            qDebug()<<Q_FUNC_INFO <<"In side if"<< Qt::endl;
            qWarning("failed to open file, is it writable?");
            return 10;
        }
        qDebug()<<Q_FUNC_INFO <<"In ////////// 1"<<  Qt::endl;
        painter.setPen(Qt::black);
        painter.drawPixmap(f,m_map,e);
        qDebug()<<Q_FUNC_INFO <<"In 2*******"<<  Qt::endl;
        return 1;
    }
}

int print_file::printing_file(Print_BookingDetail *pbd)
{
    qDebug()<<Q_FUNC_INFO << Qt::endl;
    QList<Print_Detail*> printList;
    this->prin2PixMap(pbd);
    QPrinter printer;
    qDebug()<<Q_FUNC_INFO << " Start the printing ="<< Qt::endl;
    printer.setOrientation(QPrinter::Portrait);
    QPainter painter;

    QPrintDialog *dlg = new QPrintDialog(&printer);
    if(dlg->exec() != QDialog::Accepted){
        qDebug() << Q_FUNC_INFO << " dlg->exec() != QDialog::Accepted" << Qt::endl;
        return 1;
    }else{
        qDebug() << Q_FUNC_INFO << " dlg->exec() == QDialog::Accepted" << Qt::endl;
        QRectF f(150,0,500,550);
        QRectF e(0,0,500,550);
        if (!painter.begin(&printer)){
            qDebug()<<Q_FUNC_INFO <<"In side if"<< Qt::endl;
            qWarning("failed to open file, is it writable?");
            return 10;
        }
        qDebug()<<Q_FUNC_INFO <<"In ////////// 1"<<  Qt::endl;
        painter.setPen(Qt::black);
        painter.drawPixmap(f,m_map,e);
        qDebug()<<Q_FUNC_INFO <<"In 2*******"<<  Qt::endl;

        return 1;
    }
}

int print_file::printing_file_1(QList<Print_Detail *> *pd)
{
    QPrinter printer;
    qDebug() << Q_FUNC_INFO << " Start the printing =" << pd->size() << Qt::endl;
    printer.setOrientation(QPrinter::Portrait);
    QPainter painter;
    QPrintDialog *dlg = new QPrintDialog(&printer);
    dlg->exec();
    {
        if (!painter.begin(&printer)){
            qWarning("failed to open file, is it writable?");
            return 10;
        }
        painter.setPen(Qt::black);
        unsigned short left_margin=225, top_margin=10, rect_width=550;
        int printW = 370;
        int printHt = 360;
        int verticalSpacing = 0;

        painter.drawRect(left_margin, top_margin, printW,printHt);
        //#ifdef RAMMANDIR
        painter.setFont(QFont("Times New Roman", PRINT_HEADER::HEADER_1_FONT, QFont::Bold));
        painter.drawText(QRectF(left_margin,top_margin+verticalSpacing,printW,20),Qt::AlignCenter,PRINT_HEADER::HEADER_1);
        painter.drawRect(QRectF(left_margin,top_margin,printW,20));
        painter.setFont(QFont("Times New Roman",PRINT_HEADER::HEADER_3_FONT,QFont::Bold));
        verticalSpacing +=10;
        painter.drawText(QRectF(left_margin,top_margin+verticalSpacing,printW,50),Qt::AlignCenter,PRINT_HEADER::HEADER_2);
        painter.setFont(QFont("Times New Roman",PRINT_HEADER::HEADER_2_FONT,QFont::Bold));
        verticalSpacing +=20;
        painter.drawText(QRectF(left_margin,top_margin+verticalSpacing,printW,50),Qt::AlignCenter,PRINT_HEADER::HEADER_3);
        painter.setFont(QFont("Times New Roman", PRINT_HEADER::HEADER_4_FONT));
        verticalSpacing +=20;
        painter.drawText(QRectF(left_margin,top_margin+verticalSpacing,printW,50),Qt::AlignCenter,PRINT_HEADER::HEADER_4);

        QLineF line1(left_margin,top_margin+90,rect_width+45,100);
        painter.drawLine(line1);
        painter.setFont(QFont("Arial",8));
        painter.drawText(left_margin+10,top_margin+105,"Name:");
        painter.drawText(left_margin+60,top_margin+105,pd->front()->NAME);
        QLineF line10(left_margin,top_margin+115,rect_width+45,125);
        painter.drawLine(line10);

        painter.drawText(left_margin+10,top_margin+130,"Mob. No:");
        painter.drawText(left_margin+70,140,pd->front()->MOB_NO);
        QLineF line11(left_margin,top_margin+140,rect_width+45,150);
        painter.drawLine(line11);

        qDebug()<<Q_FUNC_INFO << " Start the printing-6"<<Qt::endl;
        painter.drawText(left_margin+10,top_margin+155,"Gothra:");
        painter.drawText(left_margin+70,top_margin+155,pd->front()->GOTHRA);
        QLineF line12(left_margin,top_margin+165,rect_width+45,175);
        painter.drawLine(line12);

        painter.drawText(left_margin+10,top_margin+180,"Nakshatra: ");
        painter.drawText(left_margin+75,top_margin+180,pd->front()->NAKSHATRA);

        QLineF line4(left_margin+210,top_margin+90,left_margin+210,200);
        painter.drawLine(line4);

        painter.drawText(left_margin+230,top_margin+105,"Recpt.no:");
        painter.drawText(left_margin+285,top_margin+105,pd->front()->RECPT_NO);

        painter.drawText(left_margin+230,top_margin+130,"Date:");
        painter.drawText(left_margin+285,top_margin+130,pd->back()->DATE);

        painter.drawText(left_margin+230,top_margin+155,"Seva Date: ");
        painter.drawText(left_margin+285,top_margin+155,pd->back()->SEVA_DATE);

        painter.drawText(left_margin+230,top_margin+180,"Seva Time:");
        painter.drawText(left_margin+285,top_margin+180,pd->back()->SEVA_TIME);

        QLineF line2(left_margin,top_margin+190,rect_width+45,200);
        painter.drawLine(line2);
        painter.drawText(left_margin+5,top_margin+205,"Sl.no");
        painter.drawText(left_margin+55,top_margin+205,"Seva Name");
        painter.drawText(left_margin+220,top_margin+205,"Cost");

        painter.drawText(left_margin+265,top_margin+205,"Persons");
        painter.drawText(left_margin+322,top_margin+205,"Amount");
        QLineF line9(left_margin,top_margin+215,rect_width+45,225);
        painter.drawLine(line9);

        int next_slot_y = top_margin+215, next_slot_x = left_margin+5;

        for(int i = 0; i < pd->size();i++)
        {
            next_slot_y = next_slot_y + 20;
            painter.drawText(next_slot_x,next_slot_y, QString::number(i+1));
            painter.setFont(QFont("Arial",9));
            painter.drawText(next_slot_x+27,next_slot_y,pd->at(i)->SEVA_DESCR);

            painter.drawText(next_slot_x+213,next_slot_y,pd->at(i)->RATE+".00Rs");
            painter.drawText(next_slot_x+270,next_slot_y,pd->at(i)->QTY);

            QRectF amt_rect(next_slot_x+275,next_slot_y-13,rect_width-left_margin+309,20);
            //painter.drawText(amt_rect, Qt::AlignRight, pd->at(i)->AMT+".00");
            painter.drawText(next_slot_x+270+60,next_slot_y,pd->at(i)->AMT+".00Rs");
            qDebug() << Q_FUNC_INFO << " **** Amount =" << pd->at(i)->AMT <<Qt::endl;
        }

        QLineF line3(left_margin+260,top_margin+190,left_margin+260,370);
        painter.drawLine(line3);

        QLineF line5(left_margin+309,top_margin+190,left_margin+309,370);
        painter.drawLine(line5);

        painter.setFont(QFont("Arial",7));

        painter.drawText(left_margin+285,top_margin+370," Total: ₹ ");
        painter.setFont(QFont("Times New Roman", 8, QFont::Bold));
        painter.drawText(left_margin+327,top_margin+370,pd->back()->TOTAL_AMT+".00Rs");

        painter.setFont(QFont("Arial",7));

        painter.drawText(left_margin,top_margin+386,"Total in words:₹");
        painter.drawText(left_margin+70,top_margin+386,pd->back()->TOTAL_IN_WORDS+" only");

        painter.drawText(left_margin+2,top_margin+405,"Note:");
        painter.drawText(left_margin+37,top_margin+405,pd->back()->NOTE);
        QPixmap mypix(":/Images/Rules.png");
        painter.drawPixmap(left_margin,top_margin+412,370,120,mypix);
        painter.setFont(QFont("Arial",7, QFont::Bold));
        painter.setFont(QFont("Arial",PRINT_HEADER::FOOTER_4_FONT, QFont::Bold));
        painter.drawText(left_margin+270,top_margin+416,PRINT_HEADER::TRUST_SEAL);

        painter.save();
        QPen pen;
        pen.setWidthF(0.5);
        painter.setPen(pen);
        QRectF footerRect(left_margin,top_margin+420,printW,90);
        painter.drawRect(footerRect);
        painter.restore();

        painter.setFont(QFont("Arial",PRINT_HEADER::FOOTER_4_FONT, QFont::Bold));
        painter.drawText(QRectF(left_margin,top_margin+420,printW,20),Qt::AlignCenter,PRINT_HEADER::FOOTER_1);
        painter.drawText(QRectF(left_margin,top_margin+435,printW,20),Qt::AlignCenter,PRINT_HEADER::FOOTER_2);
        painter.drawText(QRectF(left_margin,top_margin+450,printW,20),Qt::AlignCenter,PRINT_HEADER::FOOTER_3);
        painter.drawText(QRectF(left_margin,top_margin+465,printW,20),Qt::AlignCenter,PRINT_HEADER::FOOTER_4);
        painter.drawText(QRectF(left_margin,top_margin+480,printW,20),Qt::AlignCenter,PRINT_HEADER::FOOTER_5);
        printer.setPrintRange(QPrinter::CurrentPage);
        painter.end();
        //#endif
    }
    return 0;
}

// This method is used for printing the receipt.
int print_file::prin2PixMap(QList<Print_Detail *> *pd)
{
    int wid = 470;
    int ht = 800;
    m_map = QPixmap(wid,ht);
    //QImage map(wid,ht,QImage::Format_RGB555);
    m_map.fill(Qt::white);
    QPrinter printer;
    qDebug() << Q_FUNC_INFO << " Start the printing =" << pd->size() << Qt::endl;
    printer.setOrientation(QPrinter::Portrait);
    QPainter painter;
    {
        if (!painter.begin(&m_map)){
            qWarning("failed to open file, is it writable?");
            return 10;
        }
        painter.setPen(QColor(255,0,0));
        painter.setRenderHint(QPainter::SmoothPixmapTransform);

        unsigned short leftSideMargin = 40, top_margin = 10;
        int printW = wid - leftSideMargin * 1.5;
        int printHt = 350;
        int verticalSpacing = 0;

        int yFromTop = top_margin;
        int xFromLeft = leftSideMargin;

        painter.save();
        QPen pen1;
        pen1.setWidthF(0.5);
        pen1.setColor(Qt::gray);
        painter.setPen(pen1);

        QRect boundingRect(xFromLeft, yFromTop, printW,printHt);
        painter.drawRect(boundingRect);

        painter.restore();
        pen1.setColor(Qt::black);
        painter.setPen(pen1);

        painter.setFont(QFont("Times New Roman", PRINT_HEADER::HEADER_1_FONT,QFont::Bold));
        painter.drawText(QRectF(xFromLeft,yFromTop,printW,20),Qt::AlignCenter,PRINT_HEADER::HEADER_1);
        painter.setFont(QFont("Times New Roman",PRINT_HEADER::HEADER_2_FONT));
        painter.drawText(QRectF(xFromLeft,yFromTop,printW,50),Qt::AlignCenter,PRINT_HEADER::HEADER_2);
        painter.setFont(QFont("Times New Roman",PRINT_HEADER::HEADER_3_FONT));
        yFromTop += 10;
        painter.drawText(QRectF(xFromLeft,yFromTop,printW,50),Qt::AlignCenter,PRINT_HEADER::HEADER_3);
        painter.setFont(QFont("Times New Roman", PRINT_HEADER::HEADER_4_FONT));
        yFromTop += 10;
        painter.drawText(QRectF(xFromLeft,yFromTop,printW,50),Qt::AlignCenter,PRINT_HEADER::HEADER_4);
        yFromTop += 10;
        painter.drawText(QRectF(xFromLeft,yFromTop,printW,50),Qt::AlignLeft,PRINT_HEADER::HEADER_LEFT);
        yFromTop += 25;

        painter.save();
        pen1.setWidthF(0.5);
        pen1.setColor(Qt::gray);
        painter.setPen(pen1);
        QLineF line1(xFromLeft,yFromTop,printW + 40,yFromTop);
        painter.drawLine(line1);
        painter.restore();
        painter.setFont(QFont("Arial",8));
        yFromTop += 12;
        painter.drawText(xFromLeft + 10,yFromTop,"Name");
        painter.drawText(xFromLeft + 60,yFromTop,pd->front()->NAME);

        painter.drawText(xFromLeft+230,yFromTop,"Recpt.No");
        painter.drawText(xFromLeft+295,yFromTop,pd->front()->RECPT_NO);

        painter.save();
        pen1.setWidthF(0.5);
        pen1.setColor(Qt::gray);
        painter.setPen(pen1);
        yFromTop += 8;
        QLineF line2(xFromLeft,yFromTop,printW + 40,yFromTop);
        painter.drawLine(line2);
        painter.restore();


        yFromTop += 12;
        painter.drawText(xFromLeft + 10,yFromTop,"Mobile");
        painter.drawText(xFromLeft + 60,yFromTop,pd->front()->MOB_NO);

        painter.drawText(xFromLeft+230,yFromTop,"Date");
        painter.drawText(xFromLeft+295,yFromTop,pd->back()->DATE);

        yFromTop += 12;
        painter.save();
        pen1.setWidthF(0.5);
        pen1.setColor(Qt::gray);
        painter.setPen(pen1);
        QLineF line3(xFromLeft,yFromTop,printW + 40,yFromTop);
        painter.drawLine(line3);
        painter.restore();

        yFromTop += 10;
        painter.drawText(xFromLeft + 10,yFromTop,"Gothra");
        painter.drawText(xFromLeft + 60,yFromTop,pd->front()->GOTHRA);

        painter.drawText(xFromLeft+230,yFromTop,"Seva Date");
        painter.drawText(xFromLeft+295,yFromTop,pd->back()->SEVA_DATE);

        painter.save();
        pen1.setWidthF(0.5);
        pen1.setColor(Qt::gray);
        painter.setPen(pen1);
        yFromTop += 12;
        QLineF line4(xFromLeft,yFromTop,printW + 40,yFromTop);
        painter.drawLine(line4);
        painter.restore();

        yFromTop += 10;
        painter.drawText(xFromLeft+10,yFromTop,"Nakshatra");
        painter.drawText(xFromLeft+60,yFromTop,pd->front()->NAKSHATRA);

        painter.drawText(xFromLeft+230,yFromTop,"Seva Time");
        painter.drawText(xFromLeft+310,yFromTop,pd->back()->SEVA_TIME);

        painter.save();
        pen1.setWidthF(0.5);
        pen1.setColor(Qt::gray);
        painter.setPen(pen1);
        yFromTop += 10;
        QLineF line5(xFromLeft,yFromTop,printW+40,yFromTop);//horizontal
        painter.drawLine(line5);
        painter.restore();

        painter.save();
        pen1.setWidthF(0.5);
        pen1.setColor(Qt::gray);
        painter.setPen(pen1);
        QLineF verticalline4(xFromLeft+210,line1.y1(),xFromLeft+210,line5.y1());
        painter.drawLine(verticalline4);
        painter.restore();

        yFromTop += 10;
        painter.drawText(xFromLeft+3,yFromTop,"Sl");
        painter.drawText(xFromLeft+35,yFromTop,"Seva Name");
        painter.drawText(xFromLeft+260,yFromTop,"Cost");

        painter.drawText(xFromLeft+310,yFromTop,"Qty");
        painter.drawText(xFromLeft+350,yFromTop,"Amount");

        painter.save();
        pen1.setWidthF(0.5);
        pen1.setColor(Qt::gray);
        painter.setPen(pen1);
        yFromTop += 10;
        QLineF line6(xFromLeft,yFromTop,printW+40,yFromTop);//horizontal
        painter.drawLine(line6);
        painter.restore();

        yFromTop += 8;
        int sevaXPos = xFromLeft+5;

        int sevaYPos = yFromTop+5;
        int addCostYPos = 10;

        QStringList amtList;
        QStringList addOnList;

        QStringList rateList;
        QStringList addOnRateList;
        int max = 0,max1=0;
        for(int i = 0; i < pd->size();i++){
            QString total = pd->at(i)->AMT+".00";
            QString addOn = pd->at(i)->ADDITIONAL + ".00";
            QString rate = pd->at(i)->RATE + ".00";
            int s1 = total.length();
            int s2 = addOn.length();
            int s3 = rate.length();
            amtList.append( total );
            addOnList.append( addOn );

            rateList.append(rate);
            addOnRateList.append(addOn);
            if (s1 > max) max = s1;
            if (s2 > max ) max = s2;

            if (s3 > max1) max1 = s3;
            if (s2 > max1 ) max1 = s2;
        }
        for(int i=0;i<amtList.size();i++){
            QString one = amtList.at(i);
            if (max > one.length()){
                int diff = max - one.length();
                while(diff != 0){
                    one.prepend("  ");
                    diff--;
                }
            }
            amtList.replace(i,one);
            QString two = addOnList.at(i);
            if (max > two.length()){
                int diff = max - two.length();
                while(diff != 0){
                    two.prepend("  ");
                    diff--;
                }
            }
            addOnList.replace(i,two);
        }

        for(int i=0;i<rateList.size();i++){
            QString one = rateList.at(i);
            if (max1 > one.length()){
                int diff = max1 - one.length();
                while(diff != 0){
                    one.prepend("  ");
                    diff--;
                }
            }
            rateList.replace(i,one);
            QString two = addOnRateList.at(i);
            if (max1 > two.length()){
                int diff = max1 - two.length();
                while(diff != 0){
                    two.prepend("  ");
                    diff--;
                }
            }
            addOnRateList.replace(i,two);
        }


        for(int i = 0; i < pd->size();i++){
            painter.drawText(sevaXPos, sevaYPos, QString::number(i+1));
            painter.setFont(QFont("Arial",8));
            //painter.drawText(next_slot_x+35,sevaYPos,260,5,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,pd->at(i)->SEVA_DESCR);
            painter.drawText(sevaXPos+35,sevaYPos,pd->at(i)->SEVA_DESCR);
            painter.drawText(sevaXPos+245,sevaYPos,rateList.at(i));
            painter.drawText(sevaXPos+310,sevaYPos,pd->at(i)->QTY);
            painter.drawText(sevaXPos+300+35,sevaYPos,amtList.at(i));
            if(pd->at(i)->ADDITIONAL.toInt() > 0){
                sevaYPos +=addCostYPos;
                painter.drawText(sevaXPos+40,sevaYPos,"Additional cost ");
                painter.drawText(sevaXPos+245,sevaYPos,addOnRateList.at(i));
                painter.drawText(sevaXPos+300+35,sevaYPos,addOnList.at(i));
            }
            sevaYPos += 15;
            qDebug() << Q_FUNC_INFO << " **** Amount =" << pd->at(i)->AMT <<Qt::endl;
        }
        int yLinePos = line5.y1();

        painter.save();
        pen1.setWidthF(0.5);
        pen1.setColor(Qt::gray);
        painter.setPen(pen1);

        QLineF lineslno(xFromLeft+30,yLinePos,xFromLeft+30,boundingRect.bottomRight().y());//vertical
        painter.drawLine(lineslno);

        QLineF verticalLine7(xFromLeft+240,yLinePos,xFromLeft+240,boundingRect.bottomRight().y());// the cost verticle line
        painter.drawLine(verticalLine7);

        QLineF verticalLine8(xFromLeft+305,yLinePos,xFromLeft+305,boundingRect.bottomRight().y());
        painter.drawLine(verticalLine8);

        QLineF verticalLine9(xFromLeft+330,yLinePos,xFromLeft+330,boundingRect.bottomRight().y());
        painter.drawLine(verticalLine9);

        painter.restore();

        yLinePos = boundingRect.bottomRight().y() + 15;
        painter.setFont(QFont("Arial",8));
        QString words = "Total in words:₹  - ";
        words.append(pd->back()->TOTAL_IN_WORDS);
        words.append("  only");

        int wordsBoxHeight = 30;
        int wordsBoxWidth = 250;
        painter.drawText(xFromLeft,yLinePos-5,wordsBoxWidth,wordsBoxHeight,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,words);
        painter.drawText(xFromLeft+280,yLinePos," Total: ₹ ");
        QString value = QString(pd->back()->TOTAL_AMT);
        QString toDisplay = QString::number(value.toDouble(), 'f', 2);
        painter.drawText(xFromLeft+330,yLinePos,pd->back()->TOTAL_AMT);
        qDebug() << " Exponential Value =" << toDisplay << Qt::endl;

        yLinePos += 20;

        QString note = "Note - ";
        note.append(pd->back()->NOTE);
        painter.drawText(xFromLeft,yLinePos,wordsBoxWidth,wordsBoxHeight,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,note);


        yLinePos += 10;
        painter.setFont(QFont("Arial",PRINT_HEADER::FOOTER_10_FONT));
        painter.drawText(xFromLeft+300,yLinePos,PRINT_HEADER::TRUST_SEAL);

        painter.save();

        yLinePos += 15;
        painter.setFont(QFont("Arial",PRINT_HEADER::FOOTER_10_FONT));
        painter.drawText(QRectF(xFromLeft,yLinePos,printW,20),Qt::AlignLeft,PRINT_HEADER::FOOTER_1);
        yLinePos += 15;
        painter.drawText(QRectF(xFromLeft,yLinePos,printW,20),Qt::AlignLeft,PRINT_HEADER::FOOTER_2);
        yLinePos += 15;
        painter.drawText(QRectF(xFromLeft,yLinePos,printW,20),Qt::AlignLeft,PRINT_HEADER::FOOTER_3);
        yLinePos += 15;
        painter.drawText(QRectF(xFromLeft,yLinePos,printW,20),Qt::AlignLeft,PRINT_HEADER::FOOTER_4);
        yLinePos += 15;
        painter.drawText(QRectF(xFromLeft,yLinePos,printW,20),Qt::AlignLeft,PRINT_HEADER::FOOTER_5);

        painter.save();
        pen1.setWidthF(0.5);
        pen1.setColor(Qt::gray);
        painter.setPen(pen1);
        yLinePos += 15;
        QRectF rectF(xFromLeft,yLinePos,printW,45);
        painter.drawRect(rectF);
        painter.restore();

        painter.drawText(QRectF(xFromLeft,yLinePos,printW,20),Qt::AlignCenter,PRINT_HEADER::FOOTER_6);
        painter.drawText(QRectF(xFromLeft,yLinePos,printW,50),Qt::AlignCenter,PRINT_HEADER::FOOTER_7);
        yLinePos += 15;
        painter.setFont(QFont("Times New Roman",PRINT_HEADER::FOOTER_10_FONT));
        painter.drawText(QRectF(xFromLeft,yLinePos,printW,50),Qt::AlignCenter,PRINT_HEADER::FOOTER_8);

        printer.setPrintRange(QPrinter::CurrentPage);
        painter.end();
    }
    QString receiptFileName = QString("%1%2%3").arg("Data/Receipt_").arg(pd->front()->RECPT_NO).arg(".png");
    m_map.save(receiptFileName,"PNG");
    return 0;
}

int print_file::prin2PixMap(Print_VoucherDetail *pvd)
{
    int wid = 500;
    int ht = 580;
    m_map = QPixmap(wid,ht);
    //QImage map(wid,ht,QImage::Format_RGB555);
    m_map.fill(Qt::white);
    QPrinter printer;
    qDebug()<<Q_FUNC_INFO << " Start the printing =" <<Qt::endl;
    printer.setOrientation(QPrinter::Portrait);
    QPainter painter;
    {
        if (!painter.begin(&m_map)){
            qWarning("failed to open file, is it writable?");
            return 10;
        }
        painter.setPen(QColor(255,0,0));
        painter.setRenderHint(QPainter::SmoothPixmapTransform);

        unsigned short margin=10, top_margin=10, rect_width=580;
        int printW = wid-margin*2;
        int printHt = 360;
        int verticalSpacing = 0;

        QPen pen1;
        pen1.setWidthF(1.5);
        pen1.setColor(Qt::black);
        painter.setPen(pen1);
        painter.drawRect(margin, top_margin, printW,printHt);
        painter.setFont(QFont("Times New Roman", PRINT_HEADER::HEADER_1_FONT, QFont::Bold));
        painter.drawText(QRectF(margin,top_margin+verticalSpacing,printW,20),Qt::AlignCenter,PRINT_HEADER::HEADER_1);
        painter.drawRect(QRectF(margin,top_margin,printW,20));
        painter.setFont(QFont("Times New Roman",PRINT_HEADER::HEADER_3_FONT,QFont::Bold));
        verticalSpacing +=10;
        painter.drawText(QRectF(margin,top_margin+verticalSpacing,printW,50),Qt::AlignCenter,PRINT_HEADER::HEADER_2);
        painter.setFont(QFont("Times New Roman",PRINT_HEADER::HEADER_2_FONT,QFont::Bold));
        verticalSpacing +=20;
        painter.drawText(QRectF(margin,top_margin+verticalSpacing,printW,50),Qt::AlignCenter,PRINT_HEADER::HEADER_3);
        painter.setFont(QFont("Times New Roman", PRINT_HEADER::HEADER_4_FONT));
        verticalSpacing +=20;
        painter.drawText(QRectF(margin,top_margin+verticalSpacing,printW,50),Qt::AlignCenter,PRINT_HEADER::HEADER_4);
        verticalSpacing +=20;
        painter.drawText(QRectF(margin,top_margin+verticalSpacing,printW,50),Qt::AlignLeft,PRINT_HEADER::HEADER_LEFT);

        QLineF line1(margin,top_margin+90,printW+10,100);
        painter.drawLine(line1);

        painter.setFont(QFont("Times New Roman", PRINT_HEADER::HEADER_Title_Font,QFont::Bold));
        verticalSpacing +=10;
        painter.drawText(QRectF(margin,top_margin+verticalSpacing,printW,50),Qt::AlignCenter,PRINT_HEADER::HEADER_Title);

        QLineF linetophorizontal(margin,top_margin+120,printW+10,130);
        painter.drawLine(linetophorizontal);

        QLineF verticleLine(margin+310,170,margin+310,368);
        painter.drawLine(verticleLine);


        painter.drawText(margin+10,top_margin+150,"Voucher.No:");
        qDebug()<<"The Voucher Number ------------- "<<pvd->VOUCHER_NO<<Qt::endl;
        painter.drawText(margin+100,top_margin+150,pvd->VOUCHER_NO);

        QLineF linetophorizontal2(margin,170,printW+10,170);
        painter.drawLine(linetophorizontal2);

        painter.setFont(QFont("Arial",10));
        painter.drawText(margin+10,top_margin+180,"Name:");

        painter.drawText(margin+60,top_margin+180,pvd->VOUCHER_NAME);
        //        QLineF line10(margin,top_margin+115,printW+10,top_margin+115);
        //        painter.drawLine(line10);

        painter.drawText(margin+10,top_margin+210,"Mob. No:");
        painter.drawText(margin+75,top_margin+210,pvd->MOB_NO);
        //        QLineF line11(margin,top_margin+140,printW+10,150);
        //        painter.drawLine(line11);

        qDebug()<<Q_FUNC_INFO << " Start the printing-6"<<Qt::endl;

        //        QLineF line4(margin+210,top_margin+90,margin+210,200);
        //        painter.drawLine(line4);


        painter.drawText(margin+320,top_margin+150,"Date:");
        painter.drawText(margin+370,top_margin+150,pvd->VOUCHER_DATE);

        painter.drawText(margin+10,top_margin+240,"Voucher Type:");
        painter.drawText(margin+120,top_margin+240,pvd->VOUCHER_TYPE);
        painter.drawText(margin+10,top_margin+260,"Item: "+pvd->VOUCHER_ITEM);

        painter.drawText(margin+10,top_margin+290,"Total Amount: ");
        painter.drawText(margin+370,top_margin+290,pvd->VOUCHER_COST+".00");

        painter.drawText(margin+10,top_margin+320,"Payment Ref: ");
        painter.drawText(margin+110,top_margin+320,pvd->VOUCHER_PAYMENT_REFERENCE);

        painter.drawText(margin+10,top_margin+350,"Payment Mode: ");
        painter.drawText(margin+130,top_margin+350,pvd->VOUCHER_PAYMENT_MOD);


        //        QLineF line2(margin,top_margin+190,printW+10,200);
        //        painter.drawLine(line2);


        //painter.drawText(margin,top_margin+290,"Total ");
        //        QLineF line9(margin,top_margin+215,printW+10,225);
        //        painter.drawLine(line9);

        int next_slot_y = top_margin+215, next_slot_x = margin+5;

        //                for(int i = 0; i < pvd->size();i++)
        //                {
        next_slot_y = next_slot_y + 20;
        painter.setFont(QFont("Arial",9));

        painter.setFont(QFont("Arial",9));
       // painter.drawText(next_slot_x+293,next_slot_y,pvd->VOUCHER_COST);
        qDebug() << Q_FUNC_INFO << " **** rate =" << pvd->VOUCHER_COST <<Qt::endl;
        //painter.drawText(next_slot_x+365,next_slot_y,"1");

        //QRectF amt_rect(next_slot_x+275,next_slot_y-13,rect_width-margin+309,20);
        //painter.drawText(amt_rect, Qt::AlignRight, pd->at(i)->AMT+".00");
        //painter.drawText(amt_rect, Qt::AlignRight, pd->at(i)->AMT+".00");
       // painter.drawText(next_slot_x+360+50,next_slot_y,pvd->VOUCHER_COST);

        qDebug() << Q_FUNC_INFO << " **** Amount =" << pvd->VOUCHER_COST <<Qt::endl;
        //                }
        //        QLineF line6(margin+280,top_margin+190,margin+280,370);// the cost verticle line
        //        painter.drawLine(line6);
        //        QLineF line3(margin+360,top_margin+190,margin+360,370);
        //        painter.drawLine(line3);

        //        QLineF line5(margin+409,top_margin+190,margin+409,370);
        //        painter.drawLine(line5);

        painter.setFont(QFont("Arial",10));

        painter.drawText(margin+300,top_margin+380," Total: ₹ ");
        painter.drawText(margin+380,top_margin+380,pvd->VOUCHER_COST+".00");

        painter.setFont(QFont("Arial",10));

        painter.drawText(margin,top_margin+400,"Total in words:₹");
        painter.drawText(margin+112,top_margin+400,print_file::NumberToWord(pvd->VOUCHER_COST.toInt())+" only");

        painter.drawText(margin+2,top_margin+420,"Note:");
         painter.drawText(margin+42,top_margin+420,pvd->VOUCHER_NOTE);
        //QPixmap mypix(":/Images/Rules.png");
       // painter.drawPixmap(margin,top_margin+412,370,120,mypix);
        painter.setFont(QFont("Arial",10, QFont::Bold));
        painter.setFont(QFont("Arial",PRINT_HEADER::FOOTER_4_FONT, QFont::Bold));
        painter.drawText(margin+350,top_margin+460,PRINT_HEADER::TRUST_SEAL);

         painter.drawText(margin+10,top_margin+520,"Authorised By");
         painter.drawText(margin+190,top_margin+520,"Accountant");
         painter.drawText(margin+350,top_margin+520,"Receiver's Signature");

         QLineF linetbottomhorizontal(margin,top_margin+530,printW+10,540);
         painter.drawLine(linetbottomhorizontal);

        painter.save();
        QPen pen;
        pen.setWidthF(0.5);
        painter.setPen(pen);
        //QRectF footerRect(margin,top_margin+420,printW,110);
        //painter.drawRect(footerRect);
        painter.restore();


//        painter.setFont(QFont("Arial",PRINT_HEADER::FOOTER_4_FONT, QFont::Bold));
//        painter.drawText(QRectF(margin,top_margin+420,printW,20),Qt::AlignCenter,PRINT_HEADER::FOOTER_1);
//        painter.drawText(QRectF(margin,top_margin+435,printW,20),Qt::AlignCenter,PRINT_HEADER::FOOTER_2);
//        painter.drawText(QRectF(margin,top_margin+450,printW,20),Qt::AlignCenter,PRINT_HEADER::FOOTER_3);
//        painter.drawText(QRectF(margin,top_margin+465,printW,20),Qt::AlignCenter,PRINT_HEADER::FOOTER_4);
//        painter.drawText(QRectF(margin,top_margin+480,printW,20),Qt::AlignCenter,PRINT_HEADER::FOOTER_5);
//        painter.drawText(QRectF(margin,top_margin+495,printW,20),Qt::AlignCenter,PRINT_HEADER::FOOTER_6);
//        painter.drawText(QRectF(margin,top_margin+505,printW,50),Qt::AlignCenter,PRINT_HEADER::FOOTER_7);

//        painter.setFont(QFont("Times New Roman",PRINT_HEADER::FOOTER_7_FONT,QFont::Bold));
//        painter.drawText(QRectF(margin,top_margin+510,printW,50),Qt::AlignCenter,PRINT_HEADER::FOOTER_8);
//        painter.setFont(QFont("Times New Roman",PRINT_HEADER::FOOTER_8_FONT,QFont::Bold));
//        printer.setPrintRange(QPrinter::CurrentPage);
        painter.end();
    }
    QString receiptFileName = QString("%1%2%3").arg("Data/Receipt_").arg(pvd->VOUCHER_NO).arg(".png");
    m_map.save(receiptFileName,"PNG");
    return 0;
}

int print_file::prin2PixMap(Print_BookingDetail *pbd)
{
    QList<SevaName*> listOfSevaName;
    QList<QString> listOfTotal;
    int wid = 500;
    int ht = 580;
    m_map = QPixmap(wid,ht);
    //QImage map(wid,ht,QImage::Format_RGB555);
    m_map.fill(Qt::white);
    QPrinter printer;
    qDebug() << Q_FUNC_INFO << " Start Printing the receipt = " << pbd->serial_No << Qt::endl;
    printer.setOrientation(QPrinter::Portrait);
    QPainter painter;
    {
        if (!painter.begin(&m_map)){
            qWarning("failed to open file, is it writable?");
            return 10;
        }
        painter.setPen(QColor(255,0,0));
        painter.setRenderHint(QPainter::SmoothPixmapTransform);

        unsigned short margin=10, top_margin=10, rect_width=580;
        int printW = wid-margin*2;
        int printHt = 360;
        int verticalSpacing = 0;

        qreal penWidth = 1;
        QPen pen1;
        pen1.setWidthF(penWidth);
        pen1.setColor(Qt::gray);
        painter.setPen(pen1);
        painter.save();
        painter.drawRect(margin, top_margin, printW,printHt);
        painter.setFont(QFont("Times New Roman", PRINT_HEADER::HEADER_1_FONT, QFont::Bold));
        painter.drawText(QRectF(margin,top_margin+verticalSpacing,printW,20),Qt::AlignCenter,PRINT_HEADER::HEADER_1);
        painter.drawRect(QRectF(margin,top_margin,printW,20));
        painter.setFont(QFont("Times New Roman",PRINT_HEADER::HEADER_3_FONT,QFont::Bold));
        verticalSpacing +=10;
        painter.drawText(QRectF(margin,top_margin+verticalSpacing,printW,50),Qt::AlignCenter,PRINT_HEADER::HEADER_2);
        painter.setFont(QFont("Times New Roman",PRINT_HEADER::HEADER_2_FONT,QFont::Bold));
        verticalSpacing +=20;
        painter.drawText(QRectF(margin,top_margin+verticalSpacing,printW,50),Qt::AlignCenter,PRINT_HEADER::HEADER_3);
        painter.setFont(QFont("Times New Roman", PRINT_HEADER::HEADER_4_FONT));
        verticalSpacing +=20;
        painter.drawText(QRectF(margin,top_margin+verticalSpacing,printW,50),Qt::AlignCenter,PRINT_HEADER::HEADER_4);
        verticalSpacing +=20;
        painter.drawText(QRectF(margin,top_margin+verticalSpacing,printW,50),Qt::AlignLeft,PRINT_HEADER::HEADER_LEFT);

        QLineF line1(margin,top_margin+90,printW+10,100);
        painter.drawLine(line1);
        painter.setFont(QFont("Arial",10));
        painter.drawText(margin+10,top_margin+105,"Name:");
        painter.drawText(margin+60,top_margin+105,pbd->devotee_Name);
        QLineF line10(margin,top_margin+115,printW+10,top_margin+115);
        painter.drawLine(line10);

        painter.drawText(margin+10,top_margin+130,"Mob. No:");
        painter.drawText(margin+75,140,pbd->mobile_No);
        QLineF line11(margin,top_margin+140,printW+10,150);
        painter.drawLine(line11);

        qDebug()<<Q_FUNC_INFO << " Start the printing-6"<<Qt::endl;
        painter.drawText(margin+10,top_margin+155,"Gothra:");
        painter.drawText(margin+70,top_margin+155,pbd->gothra);
        QLineF line12(margin,top_margin+165,printW+10,175);
        painter.drawLine(line12);

        painter.drawText(margin+10,top_margin+180,"Nakshatra:");
        painter.drawText(margin+82,top_margin+180,pbd->nakshatra);

        QLineF line4(margin+210,top_margin+90,margin+210,200);
        painter.drawLine(line4);

        painter.drawText(margin+230,top_margin+105,"Recpt.no:");
        painter.drawText(margin+295,top_margin+105,pbd->serial_No);

        painter.drawText(margin+230,top_margin+130,"Date:");
        qDebug()<<"suman getting rcpet date--"<<pbd->receipt_Date<<Qt::endl;
        painter.drawText(margin+295,top_margin+130,pbd->receipt_Date);

        painter.drawText(margin+230,top_margin+155,"Seva Date:");
        painter.drawText(margin+305,top_margin+155,pbd->seva_Date);

        painter.drawText(margin+230,top_margin+180,"Seva Time:");
        // painter.drawText(margin+285,top_margin+180,pbd.s);

        QLineF line2(margin,top_margin+190,printW+10,200);
        painter.drawLine(line2);
        painter.drawText(margin+5,top_margin+205,"Sl.no");

        painter.drawText(margin+55,top_margin+205,"Seva Name");
        painter.drawText(margin+290,top_margin+205,"Cost");

        painter.drawText(margin+360,top_margin+205,"Count");
        painter.drawText(margin+418,top_margin+205,"Amount");
        QLineF line9(margin,top_margin+215,printW+10,225);
        painter.drawLine(line9);

        QSqlQuery query_other1;
        QString que;
        que = ("select * from sevabooking where sevabooking.RECPT_NUM ='%1';");
        que = que.arg(pbd->serial_No);
        query_other1.prepare(que);
        query_other1.exec();
        double totalAmount= 0;
        while(query_other1.next()){
            QString  sName= query_other1.value(3).toString().trimmed();
            QString  sQty= query_other1.value(4).toString().trimmed();
            QString  sCost= query_other1.value(14).toString().trimmed();
            double  sTotAmt= query_other1.value(16).toDouble();

            SevaName* sn = new SevaName;
            sn->setSevaName(sName);
            sn->setSevaCost(sCost.toDouble());
            sn->setCount(sQty.toInt());
            listOfSevaName.append(sn);
            listOfTotal.append(QString::number(sTotAmt));
            totalAmount += sTotAmt;
            sn->setObjectName("printfile");
        }
        int next_slot_y = top_margin+215, next_slot_x = margin+5;

        for(int i = 0; i < listOfSevaName.size();i++)
        {
            next_slot_y = next_slot_y + 20;
            painter.drawText(next_slot_x,next_slot_y, QString::number(i+1));
            painter.setFont(QFont("Arial",9));
            painter.drawText(next_slot_x+27,next_slot_y,260,320,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,listOfSevaName.at(i)->sevaName());
            //            painter.setFont(QFont("Arial",9));
            qDebug() << Q_FUNC_INFO  << " addition cost: " << listOfSevaName.at(i)->additionalCost() << Qt::endl;
            if(listOfSevaName.at(i)->additionalCost() > 0){
                qDebug() << Q_FUNC_INFO  << "addition cost" << Qt::endl;
                painter.drawText(next_slot_x+30,next_slot_y+10,"Additional cost :");
                painter.drawText(next_slot_x+293,next_slot_y+10,QString::number(listOfSevaName.at(i)->additionalCost()));
                painter.drawText(next_slot_x+360+50,next_slot_y+10,QString::number(listOfSevaName.at(i)->additionalCost()));
            }
            painter.drawText(next_slot_x+293,next_slot_y,QString::number(listOfSevaName.at(i)->sevaCost()));
            qDebug() << Q_FUNC_INFO << " **** rate =" << listOfSevaName.at(i)->sevaCost() <<Qt::endl;
            painter.drawText(next_slot_x+365,next_slot_y,QString::number(listOfSevaName.at(i)->count()));

            QRectF amt_rect(next_slot_x+275,next_slot_y-13,rect_width-margin+309,20);
            //painter.drawText(amt_rect, Qt::AlignRight, pd->at(i)->AMT+".00");
            //painter.drawText(amt_rect, Qt::AlignRight, pd->at(i)->AMT+".00");
            painter.drawText(next_slot_x+360+50,next_slot_y,listOfTotal.at(i));

            qDebug() << Q_FUNC_INFO << " ####**** Amount =" << listOfTotal.at(i) <<Qt::endl;
        }

        QLineF line3(margin+360,top_margin+190,margin+360,370);
        painter.drawLine(line3);

        QLineF line5(margin+409,top_margin+190,margin+409,370);
        painter.drawLine(line5);

        painter.setFont(QFont("Arial",10));
        qDebug() << Q_FUNC_INFO << " **** Amount = 1" << Qt::endl;
        painter.drawText(margin+330,top_margin+375," Total: ₹ ");
        painter.drawText(margin+387,top_margin+375,QString::number(totalAmount)+".00");

        //painter.setFont(QFont("Arial",10));
        //print_file::NumberToWord(pbd->total_Cost.toUInt());
        qDebug() << Q_FUNC_INFO << " **** Amount = 2" << Qt::endl;
        painter.drawText(margin,top_margin + 387,"Total in words:₹");
        qDebug() << Q_FUNC_INFO << " **** Amount = 3" << Qt::endl;
        painter.drawText(margin + 108,top_margin + 386,print_file::NumberToWord(totalAmount)+" only");
        qDebug() << Q_FUNC_INFO << " **** Amount = 4" << Qt::endl;
        painter.drawText(margin + 2,top_margin + 405,"Note:");
        painter.drawText(margin + 37,top_margin + 405,"");
        qDebug() << Q_FUNC_INFO << " **** Amount = 5" << Qt::endl;
        QPixmap mypix(":/Images/Rules.png");
        qDebug() << Q_FUNC_INFO << " **** Amount = 6" << Qt::endl;
        painter.drawPixmap(margin,top_margin + 412,370,120,mypix);
        painter.setFont(QFont("Arial",10, QFont::Bold));
        painter.setFont(QFont("Arial",PRINT_HEADER::FOOTER_4_FONT, QFont::Bold));
        qDebug() << Q_FUNC_INFO << " **** Amount = 7" << Qt::endl;
        painter.drawText(margin + 270,top_margin + 416,PRINT_HEADER::TRUST_SEAL);

        painter.save();
        QPen pen;
        pen.setWidthF(0.5);
        painter.setPen(pen);
        QRectF footerRect(margin,top_margin + 420,printW,110);
        painter.drawRect(footerRect);
        painter.restore();

        painter.setFont(QFont("Arial",PRINT_HEADER::FOOTER_4_FONT, QFont::Bold));
        painter.drawText(QRectF(margin,top_margin + 420,printW,20),Qt::AlignCenter,PRINT_HEADER::FOOTER_1);
        painter.drawText(QRectF(margin,top_margin + 435,printW,20),Qt::AlignCenter,PRINT_HEADER::FOOTER_2);
        painter.drawText(QRectF(margin,top_margin + 450,printW,20),Qt::AlignCenter,PRINT_HEADER::FOOTER_3);
        painter.drawText(QRectF(margin,top_margin + 465,printW,20),Qt::AlignCenter,PRINT_HEADER::FOOTER_4);
        painter.drawText(QRectF(margin,top_margin + 480,printW,20),Qt::AlignCenter,PRINT_HEADER::FOOTER_5);
        painter.drawText(QRectF(margin,top_margin + 495,printW,20),Qt::AlignCenter,PRINT_HEADER::FOOTER_6);
        //      qDebug() << Q_FUNC_INFO << " **** Amount = 5" << Qt::endl;
        printer.setPrintRange(QPrinter::CurrentPage);
        painter.end();
    }
    QString receiptFileName = QString("%1%2%3").arg("Data/Receipt_").arg(pbd->devotee_Name).arg(".png");
    m_map.save(receiptFileName,"PNG");
    //  qDebug() << Q_FUNC_INFO << " **** Amount = 6" << Qt::endl;
    return 0;
}

void print_file::singleentry(QString devoteSevaName,QString devoteCount,int sevacharge, QString priviusformatdatesevadate)
{
    single_seva = devoteSevaName;
    single_cost = sevacharge;
    single_tickets = devoteCount;
    single_sevadate = priviusformatdatesevadate;
}

QString print_file::NumberToWord(const unsigned long number)
{
    qDebug() << Q_FUNC_INFO << " Number to Converstion =" << number << Qt::endl;
    const std::vector<QString> first14=
    {"Zero", "One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven",
     "Twelve", "Thirteen", "Fourteen" };
    const std::vector<QString> prefixes=
    {"Twen","Thir","For","Fif","Six","Seven","Eigh","Nine"};

    if( number <= 14 )
    {
        return first14.at(number);
    }
    if( number < 20 )
    {
        return prefixes.at(number-12) + "teen";
    }
    if( number < 100 )
    {
        unsigned int remainder = number - (static_cast<int>(number/10)*10);
        return prefixes.at(number/10-2) + (0 != remainder ? "ty " + NumberToWord(remainder) : "ty");
    }
    if( number < 1000 )
    {
        unsigned int remainder = number - (static_cast<int>(number/100)*100);
        return first14.at(number/100) + (0 != remainder ? " Hundred " + NumberToWord(remainder) : " Hundred");
    }
    if( number < 100000 )
    {
        unsigned int thousands = static_cast<int>(number/1000);
        unsigned int remainder = number - (thousands*1000);
        return NumberToWord(thousands) + (0 != remainder ? " Thousand " + NumberToWord(remainder) : " Thousand");
    }
    if( number < 10000000 )
    {
        unsigned int millions = static_cast<int>(number/100000);
        unsigned int remainder = number - (millions*100000);
        return NumberToWord(millions) + (0 != remainder ? " Lakhs " + NumberToWord(remainder) : " Lakhs");
    }
    if( number < 1000000000 )
    {
        unsigned int millions = static_cast<int>(number/10000000);
        unsigned int remainder = number - (millions*10000000);
        return NumberToWord(millions) + (0 != remainder ? " Crores " + NumberToWord(remainder) : " Crores");
    }
    return "Number is too large";
}


