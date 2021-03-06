/*
 * QDigiDoc4
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#pragma once

#include <functional>

#include <QEvent>
#include <QIcon>
#include <QObject>

// Qt work-around to enable changing icon when hovering over the button
class HoverFilter : public QObject
{
	Q_OBJECT

public:
	explicit HoverFilter( const QObject *observed, std::function<void(int)> callback, QObject *parent = nullptr );

protected:
	virtual bool eventFilter( QObject *watched, QEvent *event ) override;

private:
	const QObject *observed;
	std::function<void(int)> callback;
};
