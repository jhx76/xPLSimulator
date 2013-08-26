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

#ifndef XPLMESSAGE_H
#define XPLMESSAGE_H

#include <QString>
#include <QList>
#include <core/utils.h>
#include <QDebug>
#include <xPLNameValuePair.h>

/**
 * @brief The xPLMessage class
 */
class xPLMessage
{
public:
    typedef enum {
        STATUS,
        TRIGGER,
        COMMAND,
        UNKNOWN
    } MessageType;

private:
    ///
    MessageType messageType;

    ///
    QString messageSchema;

    ///
    QString messageClass;

    ///
    QList<xPLNameValuePair>* nvlist;

    ///
    QString targetAddress;

    ///
    QString sourceAddress;

    ///
    int hop;

public:
    /**
     * @brief xPLMessage default constructor
     */
    xPLMessage();

    /**
     * @brief xPLMessage constructor.
     * Build a xPLMessage object in the memory, with the given parameters and an
     * empty name-value pair list. You will have to set the list manually.
     * @param messageType The type of the message (cmnd, stat or trig)
     * @param messageSchema The schema of the message
     * @param messageClass The class of the message
     * @param sourceAddress The xPL source address of the message
     * @param targetAddress The xPL target address of the message
     */
    xPLMessage(MessageType messageType, const QString& messageSchema, const QString& messageClass,
               const QString& sourceAddress, const QString& targetAddress);

    /**
     * @brief xPLMessage constructor.
     * Build a xPLMessage object in the memory from a given string. If the string is invalid,
     * a QString object will be thrown
     * @param str The given character string from which to build the xPLMessage
     * @throw QString
     */
    xPLMessage(const QString& str);

    /**
     * @brief xPLMessage The copy constructor
     * @param other The xPLMessage to copy
     */
    xPLMessage(const xPLMessage& other);

    /**
     * @brief ~xPLMessage The destructor
     */
    virtual ~xPLMessage();

    /**
     * @brief operator = override
     * @param other
     * @return
     */
    xPLMessage& operator=(const xPLMessage& other);

    /**
     * @brief operator << override
     * @param nvpair
     * @return
     */
    xPLMessage& operator<<(const xPLNameValuePair& nvpair);

    /**
     * @brief toString
     * @return
     */
    QString toString() const;

    /**
     * @brief count
     * @return
     */
    inline int count() const { return nvlist->count(); }

    /**
     * @brief append
     * @param nvpair
     */
    inline void append(const xPLNameValuePair& nvpair) { nvlist->append(nvpair); }

    /**
     * @brief removeAt
     * @param i
     */
    inline void removeAt(int i) { nvlist->removeAt(i); }

    /**
     * @brief at
     * @param i
     * @return
     */
    inline const xPLNameValuePair& at(int i) const { return nvlist->at(i); }

    /**
     * @brief elementAt
     * @param i
     * @return
     */
    inline xPLNameValuePair& elementAt(int i) { return (*nvlist)[i]; }

    /**
     * @brief clear
     */
    inline void clear();

    /**
     * @brief getSourceAddress
     * @return
     */
    inline const QString& getSourceAddress() const { return sourceAddress; }

    /**
     * @brief setSourceAddress
     * @param address
     */
    inline void setSourceAddress(const QString& address) { sourceAddress = address; }

    /**
     * @brief getTargetAddress
     * @return
     */
    inline const QString& getTargetAddress() const { return targetAddress; }

    /**
     * @brief setTargetAddress
     * @param address
     */
    inline void setTargetAddress(const QString& address) { targetAddress = address; }

    /**
     * @brief getMessageSchema
     * @return
     */
    inline const QString& getMessageSchema() const { return messageSchema; }

    /**
     * @brief setMessageSchema
     * @param messageSchema
     */
    inline void setMessageSchema(const QString& messageSchema) { this->messageSchema = messageSchema; }

    /**
     * @brief getMessageClass
     * @return
     */
    inline const QString& getMessageClass() const { return messageClass; }

    /**
     * @brief setMessageClass
     * @param messageClass
     */
    inline void setMessageClass(const QString& messageClass) { this->messageClass = messageClass; }

    /**
     * @brief getMessageType
     * @return
     */
    inline MessageType getMessageType() const { return messageType; }

    /**
     * @brief setMessageType
     * @param messageType
     */
    inline void setMessageType(MessageType messageType) { this->messageType = messageType; }

    /**
     * @brief getHop
     * @return
     */
    inline int getHop() const { return hop; }

    /**
     * @brief setHop
     * @param h
     */
    inline void setHop(int h) { hop = h; }
};

#endif // XPLMESSAGE_H
