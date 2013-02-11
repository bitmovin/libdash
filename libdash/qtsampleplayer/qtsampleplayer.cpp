/*
 * qtsampleplayer.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include <QtWidgets>
#include "qtsampleplayer.h"
#include "dashplayerobserver.h"

QtSamplePlayer::QtSamplePlayer(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::QtSamplePlayerClass), player(0, QMediaPlayer::VideoSurface)
{
	this->ui->setupUi(this);
	this->setBufferFillState(98);
	
	this->videoWidget = new QVideoWidget();
	this->player.setVideoOutput(this->videoWidget);
	this->ui->videoLayout->addWidget(this->videoWidget);


	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Movie"),QDir::homePath());

    if (!fileName.isEmpty()) {
		this->player.setMedia(QUrl::fromLocalFile(fileName));
		this->player.play();
    }

}
QtSamplePlayer::~QtSamplePlayer()
{
	delete this->ui;
}
void QtSamplePlayer::setGuiFields(std::map<std::string, std::vector<std::string> > video, std::map<std::string, std::vector<std::string> > audio)
{
    this->video = video;
    this->audio = audio;

    this->ui->cb_audio_adaption->clear();
    this->ui->cb_video_adaption->clear();
    this->ui->cb_audio_representation->clear();
    this->ui->cb_video_representation->clear();
    this->removeAllKeyValues();

    std::map<std::string, std::vector<std::string> >::iterator it;
    std::vector<std::string>::iterator it2;

    this->setEnabled(false);

    for(it = video.begin(); it != video.end(); it++)
    {
        QString str(it->first.c_str());
        this->ui->cb_video_adaption->addItem(str);
    }

    it = video.begin();
    for(it2 = it->second.begin(); it2 != it->second.end(); it2++)
    {
        QString str((*it2).c_str());
        this->ui->cb_video_representation->addItem(str);
    }

    for(it = audio.begin(); it != audio.end(); it++)
    {
        QString str(it->first.c_str());
        this->ui->cb_audio_adaption->addItem(str);
    }

    it = audio.begin();
    for(it2 = it->second.begin(); it2 != it->second.end(); it2++)
    {
        QString str((*it2).c_str());
        this->ui->cb_audio_representation->addItem(str);
    }

    this->setEnabled(true);
}
void QtSamplePlayer::setBufferFillState(int percentage)
{
    this->ui->progressBar->setMaximum(100);
    this->ui->progressBar->setMinimum(0);
    this->ui->progressBar->setValue(percentage);
}
void QtSamplePlayer::updateKeyValue(const std::string& key, const std::string& value)
{
    if (this->keyValues.find(key) == this->keyValues.end()) {
        this->keyValues[key] = value;

        this->keyIndices[key] = this->ui->tableWidget->rowCount();
        this->ui->tableWidget->insertRow(this->ui->tableWidget->rowCount());
    }

    //TODO: proper memory mgmt.
    QTableWidgetItem *key_item = new QTableWidgetItem;
    key_item->setText(key.c_str());

    QTableWidgetItem *value_item = new QTableWidgetItem;
    value_item->setText(value.c_str());

    this->ui->tableWidget->setItem(this->keyIndices[key], 0, key_item);
    this->ui->tableWidget->setItem(this->keyIndices[key], 1, value_item);
}
void QtSamplePlayer::removeAllKeyValues()
{
    this->keyValues.clear();
    this->keyIndices.clear();

    for(int i= this->ui->tableWidget->rowCount()-1; i >= 0; i--)
    {
        this->ui->tableWidget->removeRow(i);
    }
}
void QtSamplePlayer::addWidgetObserver(DashPlayerObserver* observer)
{
    this->observer.push_back(observer);
}
void QtSamplePlayer::removeWidgetObserver(DashPlayerObserver* observer)
{
    std::vector<DashPlayerObserver*>::iterator it;
    for(it = this->observer.begin(); it != this->observer.end(); it++)
    {
        if((*it) == observer)
        {
            this->observer.erase(it);
            break;
        }
    }
}
void QtSamplePlayer::on_cb_video_adaption_currentIndexChanged(const QString &arg1)
{
    this->setEnabled(false);
    this->ui->cb_video_representation->clear();
    for(unsigned int i=0; i < this->video[arg1.toStdString()].size(); i++)
    {
        QString str(this->video[arg1.toStdString()][i].c_str());
        this->ui->cb_video_representation->addItem(str);
    }
    this->settingsChanged();
}
void QtSamplePlayer::on_cb_video_representation_currentIndexChanged(const QString &arg1)
{
    if(this->isEnabled())
    {
        this->settingsChanged();
    }
}
void QtSamplePlayer::on_cb_audio_adaption_currentIndexChanged(const QString &arg1)
{
    this->setEnabled(false);
    this->ui->cb_audio_representation->clear();
    for(unsigned int i=0; i < this->audio[arg1.toStdString()].size(); i++)
    {
        QString str(this->audio[arg1.toStdString()][i].c_str());
        this->ui->cb_audio_representation->addItem(str);
    }
    this->settingsChanged();
}
void QtSamplePlayer::on_cb_audio_representation_currentIndexChanged(const QString &arg1)
{
    if(this->isEnabled())
    {
        this->settingsChanged();
    }
}
//fired if MPD URL has changed
void QtSamplePlayer::on_lineEdit_returnPressed()
{
    this->lockUI();
    for(unsigned int i=0; i < this->observer.size(); i++)
    {
        this->observer[i]->OnURLChanged(this, this->ui->lineEdit->text().toStdString());
    }
    this->unlockUI();
}
void QtSamplePlayer::settingsChanged()
{
    this->lockUI();
    std::string v_adaption = this->ui->cb_video_adaption->itemData(this->ui->cb_video_adaption->currentIndex()).toString().toStdString();
    std::string v_representation = this->ui->cb_video_representation->itemData(this->ui->cb_video_representation->currentIndex()).toString().toStdString();
    std::string a_adaption = this->ui->cb_audio_adaption->itemData(this->ui->cb_audio_adaption->currentIndex()).toString().toStdString();
    std::string a_representation = this->ui->cb_audio_representation->itemData(this->ui->cb_audio_representation->currentIndex()).toString().toStdString();
    for(unsigned int i=0; i < this->observer.size(); i++)
    {
        this->observer[i]->OnSettingsChanged(this,v_adaption, v_representation, a_adaption, a_representation);
    }
    this->unlockUI();
}
void QtSamplePlayer::lockUI()
{
    this->setEnabled(false);
}
void QtSamplePlayer::unlockUI()
{
    this->setEnabled(true);
}