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
#include <vector>
#include <sstream>
#include "QtSamplePlayerGui.h"
#include "IDASHPlayerGuiObserver.h"
#include "libdash.h"

using namespace dash::sampleplayer;
using namespace dash::mpd;

QtSamplePlayerGui::QtSamplePlayerGui(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::QtSamplePlayerClass), player(0, QMediaPlayer::VideoSurface)
{
	this->ui->setupUi(this);
	this->setBufferFillState(98);
	this->videoWidget = new QVideoWidget();
	this->player.setVideoOutput(this->videoWidget);
	this->ui->videoLayout->addWidget(this->videoWidget);

	/*QString fileName = QFileDialog::getOpenFileName(this, tr("Open Movie"),QDir::homePath());

    if (!fileName.isEmpty()) {
		this->player.setMedia(QUrl::fromLocalFile(fileName));
		this->player.play();
    }*/

}
QtSamplePlayerGui::~QtSamplePlayerGui()
{
	delete this->ui;
}
void QtSamplePlayerGui::setGuiFields(dash::mpd::IMPD* mpd)
{
    this->ui->cb_audio_adaption->clear();
    this->ui->cb_video_adaption->clear();
    this->ui->cb_audio_representation->clear();
    this->ui->cb_video_representation->clear();
    this->removeAllKeyValues();

    this->setEnabled(false);

	std::vector<IAdaptationSet*> adaptations = mpd->GetPeriods().at(0)->GetAdaptationSets();
	IAdaptationSet* adaptation = adaptations.at(0);
	QString str("ID: " + adaptation->GetId());

	if(true)		//TODO: distinguish between audio and video
	{
		this->ui->cb_video_adaption->addItem(str);
		this->updateRepresentation(adaptation,this->ui->cb_video_representation);
	}
	else
	{
		this->ui->cb_audio_adaption->addItem(str);
		this->updateRepresentation(adaptation,this->ui->cb_audio_representation);
	}
	this->mpd = mpd;
    this->setEnabled(true);
}
void QtSamplePlayerGui::setBufferFillState(int percentage)
{
    this->ui->progressBar->setMaximum(100);
    this->ui->progressBar->setMinimum(0);
    this->ui->progressBar->setValue(percentage);
}
void QtSamplePlayerGui::updateKeyValue(const std::string& key, const std::string& value)
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
void QtSamplePlayerGui::removeAllKeyValues()
{
    this->keyValues.clear();
    this->keyIndices.clear();
    for(int i= this->ui->tableWidget->rowCount()-1; i >= 0; i--)
    {
        this->ui->tableWidget->removeRow(i);
    }
}
void QtSamplePlayerGui::addWidgetObserver(IDASHPlayerGuiObserver* observer)
{
    this->observer.push_back(observer);
	observer->OnURLChanged(this,this->ui->lineEdit->text().toStdString());
	int v_adaption = this->ui->cb_video_adaption->currentIndex();
    int v_representation = this->ui->cb_video_representation->currentIndex();
    int a_adaption = this->ui->cb_audio_adaption->currentIndex();
    int a_representation = this->ui->cb_audio_representation->currentIndex();
   
    observer->OnSettingsChanged(this,v_adaption, v_representation, a_adaption, a_representation);
}
void QtSamplePlayerGui::removeWidgetObserver(IDASHPlayerGuiObserver* observer)
{
    std::vector<IDASHPlayerGuiObserver*>::iterator it;
    for(it = this->observer.begin(); it != this->observer.end(); it++)
    {
        if((*it) == observer)
        {
            this->observer.erase(it);
            break;
        }
    }
}
void QtSamplePlayerGui::setStatusBar(const std::string& text)
{
	QString str(text.c_str());
	this->ui->statusBar->showMessage(str);
}
void QtSamplePlayerGui::on_cb_video_adaption_currentIndexChanged(const QString &arg1)
{
	if(this->isEnabled())
	{
		this->setEnabled(false);
		this->ui->cb_video_representation->clear();
		int index = this->ui->cb_video_adaption->currentIndex();
		this->updateRepresentation(this->mpd->GetPeriods()[0]->GetAdaptationSets()[index], this->ui->cb_video_representation);
		this->settingsChanged();
		this->setEnabled(true);
	}
}
void QtSamplePlayerGui::on_cb_video_representation_currentIndexChanged(const QString &arg1)
{
    if(this->isEnabled())
    {
        this->settingsChanged();
    }
}
void QtSamplePlayerGui::on_cb_audio_adaption_currentIndexChanged(const QString &arg1)
{
	if(this->isEnabled())
	{
		this->setEnabled(false);
		this->ui->cb_video_representation->clear();
		int index = this->ui->cb_audio_adaption->currentIndex();
		this->updateRepresentation(this->mpd->GetPeriods()[0]->GetAdaptationSets()[index], this->ui->cb_audio_representation);
		this->settingsChanged();
		this->setEnabled(true);
	}
}
void QtSamplePlayerGui::on_cb_audio_representation_currentIndexChanged(const QString &arg1)
{
    if(this->isEnabled())
    {
        this->settingsChanged();
    }
}
//fired if MPD URL has changed
void QtSamplePlayerGui::on_lineEdit_returnPressed()
{
    this->lockUI();
    for(unsigned int i=0; i < this->observer.size(); i++)
    {
        this->observer[i]->OnURLChanged(this, this->ui->lineEdit->text().toStdString());
    }
    this->unlockUI();
}
void QtSamplePlayerGui::settingsChanged()
{
    this->lockUI();
	int v_adaption = this->ui->cb_video_adaption->currentIndex();
    int v_representation = this->ui->cb_video_representation->currentIndex();
    int a_adaption = this->ui->cb_audio_adaption->currentIndex();
    int a_representation = this->ui->cb_audio_representation->currentIndex();
    for(unsigned int i=0; i < this->observer.size(); i++)
    {
        this->observer[i]->OnSettingsChanged(this,v_adaption, v_representation, a_adaption, a_representation);
    }
    this->unlockUI();
}
void QtSamplePlayerGui::updateRepresentation(dash::mpd::IAdaptationSet* adaptation, QComboBox* cb)
{
	std::vector<IRepresentation*> represenations = adaptation->GetRepresentation();
	cb->clear();
	for(unsigned int j=0; j < represenations.size(); j++)
	{
		IRepresentation* representation = represenations.at(j);
		std::stringstream ss;
		ss << representation->GetId() << " " << representation->GetBandwidth() << "kbps "  << representation->GetWidth() << "/" << representation->GetHeight();
		QString str2(ss.str().c_str());
		cb->addItem(str2);
	}
}
void QtSamplePlayerGui::lockUI()
{
    this->setEnabled(false);
}
void QtSamplePlayerGui::unlockUI()
{
    this->setEnabled(true);
}