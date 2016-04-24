#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include <QtWidgets>

class QWidget;
class QPainter;
class QTimer;

enum Type
{
	Close,
	Minimize,
	Maxmimize 
};a

class TitleButton : public QWidget
{
	Q_OBJECT

private:
	enum State
	{
		Normal,
		Disable,
		Hover,
		Over
	};
	State _state = Normal;
	Type _type = Close;
	QColor _color = "#FFFFFF";
	qint16 _weight = 2, _size = 14;
	qreal _opacity = 0.550, _step = 0.003;
	QTimer _timer;
	bool _maxmized = 0;

public:
	explicit TitleButton(Type _tp, QWidget *parent = 0);
	~TitleButton();
	void setMaximized(bool _control);

protected:
	virtual void paintEvent(QPaintEvent *);
	virtual void enterEvent(QEvent *);
	virtual void leaveEvent(QEvent *);
	virtual void mousePressEvent(QMouseEvent *e);
	virtual QSize minimumSizeHint() const;
	virtual QSize sizeHint() const;

	signals:
	void clicked();

public slots:
	void timercall();

};

#endif // BUTTON_H
