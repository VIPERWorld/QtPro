/*
CustomWindow is a simple, native and easy to use custom top-level window created by Qt

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details
Full License:https://github.com/QtTools/CustomWindow/blob/master/LICENSE

Copyright (c) 2016 Iman Ahmadvand (IMAN4K), Contact:iman72411@yahoo.com
*/

#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QRubberBand>
#include <QtCore/QObject>
#include <QtCore/QEvent>
#include <QtCore/QRect>
#include <QtCore/QPoint>
#include <QtCore/Qt>
#include <QtGui/QHoverEvent>
#include <QtGui/QMouseEvent>

class FrameLess : public QObject {
public:
	explicit FrameLess(QWidget *parent);
	~FrameLess();
	void setBorderWidth(const qint16 &borderWidth);
	qint16 borderWidth() const;

private:
	QWidget *_parent = new QWidget();
	enum Edge {
		None = 0x00,
		Left = 0x01,
		Top = 0x02,
		Right = 0x03,
		Bottom = 0x04,
		TopLeft = 0x05,
		TopRight = 0x06,
		BottomLeft = 0x07,
		BottomRight = 0x08
	};
	QRubberBand *_rubberband;
	bool _cursorchanged;
	bool _leftButtonPressed;
	Edge _mousePress;
	Edge _mouseMove;
	qint16 _borderWidth;

private:
	void mouseHover(QHoverEvent *e);
	void mouseLeave(QEvent *e);
	void mousePress(QMouseEvent *e);
	void mouseRealese(QMouseEvent *e);
	void mouseMove(QMouseEvent *e);
	void updateCursorShape(const QPoint &pos);
	void calculateCursorPosition(const QPoint &pos, const QRect &framerect, Edge &_edge);

protected:
	bool eventFilter(QObject *o, QEvent *e) Q_DECL_OVERRIDE;
};
