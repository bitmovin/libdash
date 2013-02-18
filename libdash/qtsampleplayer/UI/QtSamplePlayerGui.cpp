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

using namespace sampleplayer;
using namespace sampleplayer::renderer;
using namespace dash::mpd;

QtSamplePlayerGui::QtSamplePlayerGui    (QWidget *parent)
    : QMainWindow(parent), ui(new Ui::QtSamplePlayerClass)
{
    this->ui->setupUi(this);
    this->SetBufferFillState(0);
    this->ui->button_stop->setEnabled(false);
}
QtSamplePlayerGui::~QtSamplePlayerGui   ()
{
    delete this->ui;
}

QTGLRenderer*   QtSamplePlayerGui::GetVideoElement                                  ()
{
    return this->ui->videoelement;
}
void            QtSamplePlayerGui::SetGuiFields                                     (dash::mpd::IMPD* mpd)
{
    this->ui->cb_video_adaption->clear();
    this->ui->cb_video_representation->clear();
    this->RemoveAllKeyValues();

    this->setEnabled(false);

    std::vector<IAdaptationSet*> adaptationSets = mpd->GetPeriods().at(0)->GetAdaptationSets();

    for(size_t i = 0; i < adaptationSets.size(); i++)
    {
        IAdaptationSet* adaptationSet = adaptationSets.at(i);
        QString str(adaptationSet->GetContentType().c_str());
        this->ui->cb_video_adaption->addItem(str);
       
    }

    this->updateRepresentation(adaptationSets.at(0), this->ui->cb_video_representation);

    /* Disabled Audio
    {
        this->ui->cb_audio_adaption->addItem(str);
        this->updateRepresentation(adaptation,this->ui->cb_audio_representation);
    }*/
    this->mpd = mpd;
    this->setEnabled(true);
}
void            QtSamplePlayerGui::SetBufferFillState                               (int percentage)
{
    this->ui->progressBar->setValue(percentage);
}
void            QtSamplePlayerGui::UpdateKeyValue                                   (const std::string& key, const std::string& value)
{
}
void            QtSamplePlayerGui::RemoveAllKeyValues                               ()
{
}
void            QtSamplePlayerGui::AddWidgetObserver                                (IDASHPlayerGuiObserver* observer)
{
    this->observer.push_back(observer);
}
void            QtSamplePlayerGui::RemoveWidgetObserver                             (IDASHPlayerGuiObserver* observer)
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
void            QtSamplePlayerGui::SetStatusBar                                     (const std::string& text)
{
    QString str(text.c_str());
    this->ui->statusBar->showMessage(str);
}
void            QtSamplePlayerGui::on_cb_video_adaption_currentIndexChanged         (const QString &arg1)
{
    if(this->isEnabled())
    {
        this->setEnabled(false);
        this->ui->cb_video_representation->clear();
        int index = this->ui->cb_video_adaption->currentIndex();
        this->updateRepresentation(this->mpd->GetPeriods()[0]->GetAdaptationSets()[index], this->ui->cb_video_representation);
        this->setEnabled(true);
        this->settingsChanged();
    }
}
void            QtSamplePlayerGui::on_cb_video_representation_currentIndexChanged   (const QString &arg1)
{
    if(this->isEnabled())
    {
        this->settingsChanged();
    }
}
void            QtSamplePlayerGui::on_cb_audio_adaption_currentIndexChanged         (const QString &arg1)
{
}
void            QtSamplePlayerGui::on_cb_audio_representation_currentIndexChanged   (const QString &arg1)
{
    if(this->isEnabled())
    {
        this->settingsChanged();
    }
}
void            QtSamplePlayerGui::on_lineEdit_returnPressed                        ()
{
    this->lockUI();
    for(unsigned int i=0; i < this->observer.size(); i++)
    {
        this->observer[i]->OnURLEntered(this, this->ui->lineEdit->text().toStdString());
    }
    this->unlockUI();
}
void            QtSamplePlayerGui::on_button_start_clicked                          ()
{
    this->ui->button_start->setEnabled(false);
    this->ui->button_stop->setEnabled(true);
    for(unsigned int i=0; i < this->observer.size(); i++)
    {
        this->observer[i]->OnStartButtonPressed(this);
    }
}
void            QtSamplePlayerGui::on_button_stop_clicked                           ()
{
    this->ui->button_start->setEnabled(true);
    this->ui->button_stop->setEnabled(false);
    for(unsigned int i=0; i < this->observer.size(); i++)
    {
        this->observer[i]->OnStopButtonPressed(this);
    }
}
void            QtSamplePlayerGui::on_ckb_automatic_toggled                         (bool checked)
{
    
    if(checked)
    {
        this->ui->cb_video_representation->setEnabled(false);
    }
    else
    {
        this->ui->cb_video_representation->setEnabled(true);
    }
    
    for(unsigned int i=0; i < this->observer.size(); i++)
    {
        this->observer[i]->OnCheckboxChanged(this, checked);
    }
}
void            QtSamplePlayerGui::settingsChanged                                  ()
{
    this->lockUI();
    int v_adaption = this->ui->cb_video_adaption->currentIndex();
    int v_representation = this->ui->cb_video_representation->currentIndex();
    for(unsigned int i=0; i < this->observer.size(); i++)
    {
        this->observer[i]->OnSettingsChanged(this,v_adaption, v_representation);
    }
    this->unlockUI();
}
void            QtSamplePlayerGui::updateRepresentation                             (dash::mpd::IAdaptationSet* adaptation, QComboBox* cb)
{
    std::vector<IRepresentation*> represenations = adaptation->GetRepresentation();
    cb->clear();
    for(unsigned int j=0; j < represenations.size(); j++)
    {
        IRepresentation* representation = represenations.at(j);
        std::stringstream ss;
        ss << representation->GetId() << " " << representation->GetBandwidth() << "kbps "  << representation->GetWidth() << "x" << representation->GetHeight();
        QString str2(ss.str().c_str());
        cb->addItem(str2);
    }
}
void            QtSamplePlayerGui::lockUI                                           ()
{
    this->setEnabled(false);
}
void            QtSamplePlayerGui::unlockUI                                         ()
{
    this->setEnabled(true);
}
std::string     QtSamplePlayerGui::GetUrl                                           ()
{
    return this->ui->lineEdit->text().toStdString();
}
bool            QtSamplePlayerGui::GetAutomatic                                     ()
{
    return false;
}