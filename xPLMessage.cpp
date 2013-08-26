/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "xPLMessage.h"

xPLMessage::xPLMessage() {
    this->nvlist = new QList<xPLNameValuePair>();
}

xPLMessage::xPLMessage(MessageType messageType, const QString &messageSchema, const QString &messageClass,
                       const QString& sourceAddress, const QString& targetAddress)
{
    this->nvlist = new QList<xPLNameValuePair>();
    hop = 1;
    this->messageType = messageType;
    this->messageSchema = messageSchema;
    this->messageClass = messageClass;
    this->sourceAddress = sourceAddress;
    this->targetAddress = targetAddress;
}

xPLMessage::xPLMessage(const xPLMessage &other) {
    this->nvlist = new QList<xPLNameValuePair>();
    hop = other.hop;
    this->messageType = other.messageType;
    this->messageSchema = other.messageSchema;
    this->messageClass = other.messageClass;
    this->sourceAddress = other.sourceAddress;
    this->targetAddress = other.targetAddress;
    for(int i = 0; i < other.count(); i++) {
        this->append(other.at(i));
    }
}

xPLMessage::xPLMessage(const QString &str) {
    bool conversionOK = false;
    int tmpi = 0;
    QString tmp = utils::getSousChaine(str, "\n", 0, false);
    if(tmp == "xpl-stat")
        this->messageType = STATUS;
    else if(tmp == "xpl-cmnd")
        this->messageType = COMMAND;
    else if(tmp == "xpl-trig")
        this->messageType = TRIGGER;
    else
        throw QString("unknwown message type");
    tmp = utils::getSousChaine(str, "hop=", 1, false);
    tmp = utils::getSousChaine(tmp, "\n", 0, false);
    tmpi = tmp.toInt(&conversionOK);
    if(!conversionOK)
        throw QString("unknown hop count");
    hop = tmpi;
    tmp = utils::getSousChaine(str, "source=", 1, false);
    tmp = utils::getSousChaine(tmp, "\n", 0, false);
    if(tmp.isEmpty())
        throw QString("uknwown source address");
    sourceAddress = tmp;
    tmp = utils::getSousChaine(str, "target=", 1, false);
    tmp = utils::getSousChaine(tmp, "\n", 0, false);
    if(tmp.isEmpty())
        throw QString("uknwown target address");
    targetAddress = tmp;

    QString body = utils::getSousChaine(str, "}\n", 1, false);
    if(body.isEmpty())
        throw QString("invalid message body");
    tmp = utils::getSousChaine(body, "{", 0, false);
    tmp = utils::getSousChaine(tmp, "\n", 0, false);
    if(tmp.isEmpty())
        throw QString("invalid schema and class");
    QString tmpSchema = utils::getSousChaine(tmp, ".", 0, false);
    if(tmpSchema.isEmpty())
        throw QString("invalid schema");
    messageSchema = tmpSchema;
    QString tmpClass = utils::getSousChaine(tmp, ".", 1, false);
    if(tmpClass.isEmpty())
        throw QString("invalid class");
    messageClass = tmpClass;

    this->nvlist = new QList<xPLNameValuePair>();
    QString effectiveBody = utils::getSousChaine(body, "{\n", 1, false);
    effectiveBody = utils::getSousChaine(effectiveBody, "}", 0, false);
    if(effectiveBody.isEmpty())
        throw QString("invalid effective body");
    for(int i = 0; i < effectiveBody.count("\n"); i++) {
        tmp = utils::getSousChaine(effectiveBody, "\n", i, false);
        if(tmp.isEmpty())
            continue;
        QString name = utils::getSousChaine(tmp, "=", 0, false);
        QString value = utils::getSousChaine(tmp, "=", 1, false);
        if(name.isEmpty())
            throw QString("emppty name in nvpair \""+tmp+"\"");
        xPLNameValuePair nvpair(name, value);
        nvlist->append(nvpair);
    }
}

xPLMessage::~xPLMessage() {
    if(nvlist) {
        this->clear();
        delete nvlist;
    }
}

void xPLMessage::clear() {
    while(!nvlist->isEmpty()) {
        nvlist->takeFirst();
    }
}

xPLMessage& xPLMessage::operator=(const xPLMessage& other) {
    this->hop = other.hop;
    this->messageType = other.messageType;
    this->messageSchema = other.messageSchema;
    this->messageClass = other.messageClass;
    this->sourceAddress = other.sourceAddress;
    this->targetAddress = other.targetAddress;
    for(int i = 0; i < other.count(); i++) {
        this->append(other.at(i));
    }
    return *this;
}

xPLMessage& xPLMessage::operator<<(const xPLNameValuePair& nvpair) {
    nvlist->append(nvpair);
    return *this;
}

QString xPLMessage::toString() const {
    QString rslt = "";
    try
    {
        if(!nvlist)
            throw QString("bad memory alloc for nvlist");
        rslt = "xpl-";
        switch(messageType) {
        case COMMAND: rslt += "cmnd\n{\n"; break;
        case STATUS: rslt += "stat\n{\n"; break;
        case TRIGGER: rslt += "trig\n{\n"; break;
        default: throw QString("invalid message type");
        }
        rslt += "hop="+QString::number(hop)+"\n";
        rslt += "source="+sourceAddress+"\n";
        rslt += "target="+targetAddress+"\n";
        rslt += "}\n";
        rslt += messageSchema+"."+messageClass+"\n";
        rslt += "{\n";
        for(int i = 0; i < nvlist->count(); i++) {
            rslt += nvlist->at(i).getName()+"="+nvlist->at(i).getValue()+"\n";
        }
        rslt += "}\n";
    }
    catch(const QString& exception) {
        qDebug() << exception;
        rslt = "";
    }
    return rslt;
}
