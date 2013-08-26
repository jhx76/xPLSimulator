
/*
    This file is part of Zigbus Home Automation API. 
    Copyright (C) 2012 jhx

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

#ifndef SYSUTILS_H
#define SYSUTILS_H

#include <QString>
#include <QBitArray>
#include <exception>
#define STR_LF              "\n"
#define STR_BRACE_LEFT      "{"
#define STR_BRACE_RIGHT     "}"
#define STR_EQUALS          "="
#define STR_GREATER         ">"
#define STR_LESS            "<"
#define STR_PIPE            "|"
#define STR_SLASH           "/"

/* MACRO pour recuperer la localisation d'une trace*/
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define AT QString(" [" __FILE__ "]" TOSTRING(__LINE__)" ")
/**
  @namespace utils
  @author jhx
  @brief Le namespace utils centralise toutes les fonctions globales et classes qui sont utilisés pour effectuer des traitements
  internes ainsi que la majorité des classes heritant de std::exception qui permettent la remontée d'erreurs considérées comme standards.
  */
namespace utils {

/**
  @author jhx
  Fonction permettant de tronquer des chaines de caracteres grace a un separateur et une position. Tres pratique
  lorsqu'il s'agit d'analyser des protocoles de communication, il est utilise partout dans le code du systeme.
  @param base C'est la chaine de base depuis laquelle on essaie de recuperer une sous chaine
  @param separator Chaine de caractere contenant le separateur avec lequel on va tronquer la chaine de base.
  @param position C'est la position de la sous chaine que l'on veut recuperer par rapport au separateur. La premiere position est a 0.
  @param returnbase booleen specifiant que s'il y a une erreur pendant le traitement, on renvoie la chaine de base ou non. Lorsqu'il est
  a false, ce qui est la valeur par defaut, on renvoie une chaine vide. Lorsqu'il est a true, on renvoie la chaine de base.
  */
QString getSousChaine(const QString& base, const QString& separator, int position, bool returnbase = false);


/**
 * @brief The QException class
 */
class QException : public std::exception {
protected:
    /**
     * @brief message
     */
    QString message;
    /**
     * @brief codePosition
     */
    QString codePosition;

public:
    /**
     * @brief QException
     */
    QException() throw() : exception() {
        message = "";
        codePosition = "";
    }

    /**
     * @brief QException
     * @param message
     * @param codePosition
     */
    QException(const QString& message, const QString& codePosition) throw() : exception() {
        this->message = message;
        this->codePosition = codePosition;
    }

    /**
     * @brief QException
     * @param other
     */
    QException(const QException& other) throw() : exception(other){
        this->message = other.message;
        this->codePosition = codePosition;
    }

    /**
     * @brief ~QException
     */
    virtual ~QException() throw() {

    }

    /**
     * @brief operator =
     * @param other
     * @return
     */
    QException& operator=(const QException& other) throw() {
        this->message = other.message;
        this->codePosition = codePosition;
        return *this;
    }

    /**
     * @brief what
     * @return
     */
    virtual const char* what() const throw() {
        return message.toLocal8Bit().data();
    }

    /**
     * @brief toString
     * @return
     */
    virtual QString toString() const throw() {
        return QString("[QException] "+codePosition+"\n"+message);
    }

    /**
     * @brief getMessage
     * @return
     */
    const QString& getMessage() const  throw() {
        return message;
    }

    /**
     * @brief setMessage
     * @param message
     */
    void setMessage(const QString& message)  throw() {
        this->message = message;
    }

    /**
     * @brief getCodePosition
     * @return
     */
    const QString& getCodePosition() const throw() {
        return codePosition;
    }

    /**
     * @brief setCodePosition
     * @param codePosition
     */
    void setCodePosition(const QString& codePosition) throw() {
        this->codePosition = codePosition;
    }
};

/**
 * @brief The QNumberFormatException class
 */
class QNumberFormatException : public QException {
private:
public:
    /**
     * @brief QNumberFormatException
     */
    QNumberFormatException() throw() : QException() {

    }

    /**
     * @brief QNumberFormatException
     * @param message
     * @param codePosition
     */
    QNumberFormatException(const QString& message, const QString& codePosition) throw() : QException(message, codePosition) {

    }

    /**
     * @brief QNumberFormatException
     * @param other
     */
    QNumberFormatException(const QNumberFormatException& other) throw() : QException(other) {

    }

    /**
     * @brief ~QNumberFormatException
     */
    virtual ~QNumberFormatException() throw() { }

    /**
     * @brief toString
     * @return
     */
    virtual QString toString() const throw() {
        return QString("[QNumberFormatException] "+codePosition+"\n"+message);
    }
};

/**
 * @brief The QMemoryCorruptionException class
 */
class QMemoryCorruptionException : public QException {
private:
public:
    /**
     * @brief QMemoryCorruptionException
     */
    QMemoryCorruptionException() throw() : QException() {

    }

    /**
     * @brief QMemoryCorruptionException
     * @param message
     * @param codePosition
     */
    QMemoryCorruptionException(const QString& message, const QString& codePosition) throw() : QException(message, codePosition) {

    }

    /**
     * @brief QMemoryCorruptionException
     * @param other
     */
    QMemoryCorruptionException(const QMemoryCorruptionException& other) throw() : QException(other) {

    }

    /**
     * @brief ~QMemoryCorruptionException
     */
    virtual ~QMemoryCorruptionException() throw() { }

    /**
     * @brief toString
     * @return
     */
    virtual QString toString() const throw() {
        return QString("[QMemoryCorruptionException] "+codePosition+"\n"+message);
    }
};

}
#endif // SYSUTILS_H
