/*
 * @file 	ctrlbar.cpp
 * @date 	2018/03/10 22:27
 *
 * @author 	itisyang
 * @Contact	itisyang@gmail.com
 *
 * @brief 	控制界面
 * @note
 */
#include <QDebug>
#include <QTime>
#include <QSettings>
#include <QLabel>
#include <QImage>
#include <QPixmap>
 
#include "ctrlbar.h"
#include "ui_ctrlbar.h"
#include "videoctl.h"

#include "globalhelper.h"

CtrlBar::CtrlBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtrlBar),
	m_lastPreviewImg(nullptr)
{
    ui->setupUi(this);

	m_previewImgLabel = new QLabel();
	m_previewImgLabel->resize(200, 200);

    m_dLastVolumePercent = 1.0;

}

CtrlBar::~CtrlBar()
{
    delete ui;
	delete m_previewImgLabel;
	delete m_lastPreviewImg;
}

bool CtrlBar::Init()
{
    setStyleSheet(GlobalHelper::GetQssStr("://res/qss/ctrlbar.css"));

    GlobalHelper::SetIcon(ui->PlayOrPauseBtn, 12, QChar(0xf04b));
    GlobalHelper::SetIcon(ui->StopBtn, 12, QChar(0xf04d));
    GlobalHelper::SetIcon(ui->VolumeBtn, 12, QChar(0xf028));
    GlobalHelper::SetIcon(ui->PlaylistCtrlBtn, 12, QChar(0xf036));
    GlobalHelper::SetIcon(ui->ForwardBtn, 12, QChar(0xf051));
    GlobalHelper::SetIcon(ui->BackwardBtn, 12, QChar(0xf048));
    GlobalHelper::SetIcon(ui->SettingBtn, 12, QChar(0xf013));

    ui->PlaylistCtrlBtn->setToolTip("播放列表");
    ui->SettingBtn->setToolTip("设置");
    ui->VolumeBtn->setToolTip("静音");
    ui->ForwardBtn->setToolTip("下一个");
    ui->BackwardBtn->setToolTip("上一个");
    ui->StopBtn->setToolTip("停止");
    ui->PlayOrPauseBtn->setToolTip("播放");
	ui->PlaySlider->setMouseTracking(true);
    
    ConnectSignalSlots();

    double dPercent = -1.0;
    GlobalHelper::GetPlayVolume(dPercent);
    if (dPercent != -1.0)
    {
        emit SigPlayVolume(dPercent);
        OnVideopVolume(dPercent);
    }

    return true;

}

bool g_saveFrame = false;
int g_seekTime = 0;	// in seconds
bool CtrlBar::ConnectSignalSlots()
{
    QList<bool> listRet;
    bool bRet;

    connect(ui->PlaylistCtrlBtn, &QPushButton::clicked, this, &CtrlBar::SigShowOrHidePlaylist);
    connect(ui->PlaySlider, &CustomSlider::SigCustomSliderValueChanged, this, &CtrlBar::OnPlaySliderValueChanged);
	connect(ui->PlaySlider, &CustomSlider::SigCustomSliderHoverEnter, this, 
		[&] {
		g_saveFrame = true; 
		m_previewImgLabel->show(); 
		qDebug() << "start preview";
	});
	connect(ui->PlaySlider, &CustomSlider::SigCustomSliderHoverLeave, this, 
		[&] {
		g_saveFrame = false; 
		m_previewImgLabel->hide(); 
		qDebug() << "stop preview";
	});
	connect(ui->PlaySlider, &CustomSlider::SigCustomSliderHoverMove, this, &CtrlBar::OnPlaySliderHoverMoved);
    connect(ui->VolumeSlider, &CustomSlider::SigCustomSliderValueChanged, this, &CtrlBar::OnVolumeSliderValueChanged);
    connect(ui->BackwardBtn, &QPushButton::clicked, this, &CtrlBar::SigBackwardPlay);
    connect(ui->ForwardBtn, &QPushButton::clicked, this, &CtrlBar::SigForwardPlay);
	connect(VideoCtl::GetInstance(), &VideoCtl::SigPreviewFrame, this, &CtrlBar::OnPreviewImage);

    return true;
}

void CtrlBar::OnVideoTotalSeconds(int nSeconds)
{
    m_nTotalPlaySeconds = nSeconds;

    int thh, tmm, tss;
    thh = nSeconds / 3600;
    tmm = (nSeconds % 3600) / 60;
    tss = (nSeconds % 60);
    QTime TotalTime(thh, tmm, tss);

    ui->VideoTotalTimeTimeEdit->setTime(TotalTime);
}


void CtrlBar::OnVideoPlaySeconds(int nSeconds)
{
    int thh, tmm, tss;
    thh = nSeconds / 3600;
    tmm = (nSeconds % 3600) / 60;
    tss = (nSeconds % 60);
    QTime TotalTime(thh, tmm, tss);

    ui->VideoPlayTimeTimeEdit->setTime(TotalTime);

    ui->PlaySlider->setValue(nSeconds * 1.0 / m_nTotalPlaySeconds * MAX_SLIDER_VALUE);
}

void CtrlBar::OnVideopVolume(double dPercent)
{
    ui->VolumeSlider->setValue(dPercent * MAX_SLIDER_VALUE);
    m_dLastVolumePercent = dPercent;

    if (m_dLastVolumePercent == 0)
    {
        GlobalHelper::SetIcon(ui->VolumeBtn, 12, QChar(0xf026));
    }
    else
    {
        GlobalHelper::SetIcon(ui->VolumeBtn, 12, QChar(0xf028));
    }

    GlobalHelper::SavePlayVolume(dPercent);
}

void CtrlBar::OnPauseStat(bool bPaused)
{
    qDebug() << "CtrlBar::OnPauseStat" << bPaused;
    if (bPaused)
    {
        GlobalHelper::SetIcon(ui->PlayOrPauseBtn, 12, QChar(0xf04b));
        ui->PlayOrPauseBtn->setToolTip("播放");
    }
    else
    {
        GlobalHelper::SetIcon(ui->PlayOrPauseBtn, 12, QChar(0xf04c));
        ui->PlayOrPauseBtn->setToolTip("暂停");
    }
}

void CtrlBar::OnStopFinished()
{
    ui->PlaySlider->setValue(0);
    QTime StopTime(0, 0, 0);
    ui->VideoTotalTimeTimeEdit->setTime(StopTime);
    ui->VideoPlayTimeTimeEdit->setTime(StopTime);
    GlobalHelper::SetIcon(ui->PlayOrPauseBtn, 12, QChar(0xf04b));
    ui->PlayOrPauseBtn->setToolTip("播放");
}

void CtrlBar::OnPlaySliderValueChanged()
{
    double dPercent = ui->PlaySlider->value()*1.0 / ui->PlaySlider->maximum();
    emit SigPlaySeek(dPercent);
}

void CtrlBar::OnPlaySliderHoverMoved(double value)
{
	g_seekTime = int(value * m_nTotalPlaySeconds);

	int thh, tmm, tss;
	thh = m_nTotalPlaySeconds / 3600;
	tmm = (m_nTotalPlaySeconds % 3600) / 60;
	tss = (m_nTotalPlaySeconds % 60);
	qDebug() << "try seek to: " << g_seekTime << " seconds, " << thh << ":" << tmm << ":" << tss;
}

void CtrlBar::OnVolumeSliderValueChanged()
{
    double dPercent = ui->VolumeSlider->value()*1.0 / ui->VolumeSlider->maximum();
    emit SigPlayVolume(dPercent);

    OnVideopVolume(dPercent);
}

void CtrlBar::OnPreviewImage()
{
	QPixmap pix("preview.jpg");
	m_previewImgLabel->setPixmap(pix.scaled(m_previewImgLabel->size(), Qt::KeepAspectRatio));
}

void CtrlBar::on_PlayOrPauseBtn_clicked()
{
    emit SigPlayOrPause();
}

void CtrlBar::on_VolumeBtn_clicked()
{
    if (ui->VolumeBtn->text() == QChar(0xf028))
    {
        GlobalHelper::SetIcon(ui->VolumeBtn, 12, QChar(0xf026));
        ui->VolumeSlider->setValue(0);
        emit SigPlayVolume(0);
    }
    else
    {
        GlobalHelper::SetIcon(ui->VolumeBtn, 12, QChar(0xf028));
        ui->VolumeSlider->setValue(m_dLastVolumePercent * MAX_SLIDER_VALUE);
        emit SigPlayVolume(m_dLastVolumePercent);
    }

}

void CtrlBar::on_StopBtn_clicked()
{
    emit SigStop();
}

void CtrlBar::on_SettingBtn_clicked()
{
    //emit SigShowSetting();
}
