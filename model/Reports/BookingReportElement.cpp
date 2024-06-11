#include "BookingReportElement.h"

BookingReportElement::BookingReportElement(QObject *parent)
    : QObject{parent}
{
    this->m_reportGenerationSource = ReportEnums::CLICK_ON_LEFT_SELECTION;
}

const QString &BookingReportElement::name() const
{
    return m_name;
}

void BookingReportElement::setName(const QString &newName)
{
    m_name = newName;
}

const QString &BookingReportElement::gothra() const
{
    return m_gothra;
}

void BookingReportElement::setGothra(const QString &newGothra)
{
    m_gothra = newGothra;
}

const QString &BookingReportElement::nakshatra() const
{
    return m_nakshatra;
}

void BookingReportElement::setNakshatra(const QString &newNakshatra)
{
    m_nakshatra = newNakshatra;
}

const QString &BookingReportElement::sevaName() const
{
    return m_sevaName;
}

void BookingReportElement::setSevaName(const QString &newSevaName)
{
    m_sevaName = newSevaName;
}

int BookingReportElement::teerthaPrasada() const
{
    return m_teerthaPrasada;
}

void BookingReportElement::setTeerthaPrasada(int newTeerthaPrasada)
{
    m_teerthaPrasada = newTeerthaPrasada;
}

const QString &BookingReportElement::mobileNumber() const
{
    return m_mobileNumber;
}

void BookingReportElement::setMobileNumber(const QString &newMobileNumber)
{
    m_mobileNumber = newMobileNumber;
}

const QString &BookingReportElement::note() const
{
    return m_note;
}

void BookingReportElement::setNote(const QString &newNote)
{
    m_note = newNote;
}

const QString &BookingReportElement::sevaDate() const
{
    return m_sevaDate;
}

void BookingReportElement::setSevaDate(const QString &newSevaDate)
{
    m_sevaDate = newSevaDate;
}

const QString &BookingReportElement::receiptDate() const
{
    return m_receiptDate;
}

void BookingReportElement::setReceiptDate(const QString &newReceiptDate)
{
    m_receiptDate = newReceiptDate;
}

const QString &BookingReportElement::total() const
{
    return m_total;
}

void BookingReportElement::setTotal(const QString &newTotal)
{
    m_total = newTotal;
}

const QString &BookingReportElement::paymntMode() const
{
    return m_paymntMode;
}

void BookingReportElement::setPaymntMode(const QString &newPaymntMode)
{
    m_paymntMode = newPaymntMode;
}

const QString &BookingReportElement::referenceNo() const
{
    return m_referenceNo;
}

void BookingReportElement::setReferenceNo(const QString &newReferenceNo)
{
    m_referenceNo = newReferenceNo;
}

const QString &BookingReportElement::address() const
{
    return m_address;
}

void BookingReportElement::setAddress(const QString &newAddress)
{
    m_address = newAddress;
}

int BookingReportElement::sNO() const
{
    return m_sNO;
}

void BookingReportElement::setSNO(int newSNO)
{
    m_sNO = newSNO;
}

int BookingReportElement::sevaCount() const
{
    return m_sevaCount;
}

void BookingReportElement::setSevaCount(int newSevaCount)
{
    m_sevaCount = newSevaCount;
}

ReportEnums::REPORT_GENERATION_SOURCE BookingReportElement::reportGenerationSource() const
{
    return m_reportGenerationSource;
}

void BookingReportElement::setReportGenerationSource(const ReportEnums::REPORT_GENERATION_SOURCE &newReportGenerationSource)
{
    if (m_reportGenerationSource == newReportGenerationSource)
        return;
    m_reportGenerationSource = newReportGenerationSource;
    emit reportGenerationSourceChanged();
}

QString BookingReportElement::sevaTypeName() const
{
    return m_sevaTypeName;
}

void BookingReportElement::setSevaTypeName(const QString &newSevaTypeName)
{
    if (m_sevaTypeName == newSevaTypeName)
        return;
    m_sevaTypeName = newSevaTypeName;
    emit sevaTypeNameChanged();
}

int BookingReportElement::sevaType() const
{
    return m_sevaType;
}

void BookingReportElement::setSevaType(int newSevaType)
{
    if (m_sevaType == newSevaType)
        return;
    m_sevaType = newSevaType;
    emit sevaTypeChanged();
}
