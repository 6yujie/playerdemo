#pragma once

#include <QSlider>
#include <QMouseEvent>

class CustomSlider : public QSlider
{
    Q_OBJECT

public:
    CustomSlider(QWidget *parent);
    ~CustomSlider();
protected:
    void mousePressEvent(QMouseEvent *ev) override;//重写QSlider的mousePressEvent事件
    void mouseReleaseEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
	void enterEvent(QEvent *ev) override;
	void leaveEvent(QEvent *ev) override;
signals:
    void SigCustomSliderValueChanged();//自定义的鼠标单击信号，用于捕获并处理
	void SigCustomSliderHoverMove(double pos);
	void SigCustomSliderHoverEnter();
	void SigCustomSliderHoverLeave();
};
