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

#ifndef XPLNAMEVALUEPAIR_H
#define XPLNAMEVALUEPAIR_H
#include <QString>

/**
 * @brief The xPLNameValuePair class
 */
class xPLNameValuePair
{
private:
    /**
     * @brief name
     */
    QString name;

    /**
     * @brief value
     */
    QString value;

public:
    /**
     * @brief xPLNameValuePair
     */
    xPLNameValuePair();

    /**
     * @brief xPLNameValuePair
     * @param name
     * @param value
     */
    xPLNameValuePair(const QString& name, const QString& value);

    /**
     * @brief xPLNameValuePair
     * @param other
     */
    xPLNameValuePair(const xPLNameValuePair& other);

    /**
     * @brief operator =
     * @param other
     * @return
     */
    xPLNameValuePair& operator=(const xPLNameValuePair& other);

    /**
     * @brief getName
     * @return
     */
    inline const QString& getName() const { return name; }

    /**
     * @brief setName
     * @param name
     */
    inline void setName(const QString& name) { this->name = name; }

    /**
     * @brief getValue
     * @return
     */
    inline const QString& getValue() const { return value; }

    /**
     * @brief setValue
     * @param value
     */
    inline void setValue(const QString& value) { this->value = value; }
};

#endif // XPLNAMEVALUEPAIR_H
