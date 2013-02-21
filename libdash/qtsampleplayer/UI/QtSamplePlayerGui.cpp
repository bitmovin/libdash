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

QtSamplePlayerGui::QtSamplePlayerGui    (QWidget *parent) : 
                   QMainWindow          (parent),
                   ui                   (new Ui::QtSamplePlayerClass),
                   mpd                  (NULL)
{
    this->ui->setupUi(this);
    this->SetBufferFillState(0);
    this->ui->button_stop->setEnabled(false);
}
QtSamplePlayerGui::~QtSamplePlayerGui   ()
{
    delete this->ui;
}

void            QtSamplePlayerGui::ClearComboBoxes                                  ()
{
    this->ui->cb_period->clear();

    this->ui->cb_video_adaptationset->clear();
    this->ui->cb_video_representation->clear();

    this->ui->cb_audio_adaptationset->clear();
    this->ui->cb_audio_represenation->clear();
}
QTGLRenderer*   QtSamplePlayerGui::GetVideoElement                                  ()
{
    return this->ui->videoelement;
}
void            QtSamplePlayerGui::SetGuiFields                                     (dash::mpd::IMPD* mpd)
{
    this->LockUI();
    this->ClearComboBoxes();
    this->SetPeriodComboBox(mpd, this->ui->cb_period);
    
    if(mpd->GetPeriods().size() > 0)
    {
        IPeriod *period = mpd->GetPeriods().at(0);

        this->SetAdaptationSetComboBox(period, this->ui->cb_video_adaptationset);
        this->SetAdaptationSetComboBox(period, this->ui->cb_audio_adaptationset);

        if(period->GetAdaptationSets().at(0))
        {
            IAdaptationSet *adaptationSet = period->GetAdaptationSets().at(0);

            this->SetRepresentationComoboBox(adaptationSet, this->ui->cb_video_representation);
            this->SetRepresentationComoboBox(adaptationSet, this->ui->cb_audio_represenation);
        }
    }

    this->mpd = mpd;
    this->UnLockUI();
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
void            QtSamplePlayerGui::AddWidgetObserver                                (IDASHPlayerGuiObserver *observer)
{
    this->observers.push_back(observer);
}
void            QtSamplePlayerGui::SetStatusBar                                     (const std::string& text)
{
    QString str(text.c_str());
    this->ui->statusBar->showMessage(str);
}
void            QtSamplePlayerGui::NotifySettingsChanged                            ()
{
    this->LockUI();

    int videoAdaptionSet    = this->ui->cb_video_adaptationset->currentIndex();
    int videoRepresentation = this->ui->cb_video_representation->currentIndex();

    for(size_t i = 0; i < this->observers.size(); i++)
        this->observers.at(i)->OnSettingsChanged(this, videoAdaptionSet, videoRepresentation);

    this->UnLockUI();
}
void            QtSamplePlayerGui::SetRepresentationComoboBox                       (dash::mpd::IAdaptationSet *adaptationSet, QComboBox *cb)
{
    std::vector<IRepresentation *> represenations = adaptationSet->GetRepresentation();
    cb->clear();

    for(size_t i = 0; i < represenations.size(); i++)
    {
        IRepresentation *representation = represenations.at(i);

        std::stringstream ss;
        ss << representation->GetId() << " " << representation->GetBandwidth() << " bps "  << representation->GetWidth() << "x" << representation->GetHeight();

        cb->addItem(QString(ss.str().c_str()));
    }
}
void            QtSamplePlayerGui::SetAdaptationSetComboBox                         (dash::mpd::IPeriod *period, QComboBox *cb)
{
    std::vector<IAdaptationSet *> adaptationSets = period->GetAdaptationSets();
    cb->clear();

    for(size_t i = 0; i < adaptationSets.size(); i++)
    {
        IAdaptationSet *adaptationSet = adaptationSets.at(i);

        std::stringstream ss;
        ss << "AdaptationSet " << i+1;

        cb->addItem(QString(ss.str().c_str()));
    }
}
void            QtSamplePlayerGui::SetPeriodComboBox                                (dash::mpd::IMPD *mpd, QComboBox *cb)
{
    std::vector<IPeriod *> periods = mpd->GetPeriods();
    cb->clear();

    for(size_t i = 0; i < periods.size(); i++)
    {
        IPeriod *period = periods.at(i);

        std::stringstream ss;
        ss << "Period " << i+1;

        cb->addItem(QString(ss.str().c_str()));
    }
}
void            QtSamplePlayerGui::LockUI                                           ()
{
    this->setEnabled(false);
}
void            QtSamplePlayerGui::UnLockUI                                         ()
{
    this->setEnabled(true);
}
std::string     QtSamplePlayerGui::GetUrl                                           ()
{
    this->LockUI();

    std::string ret  = this->ui->lineEdit_mpd->text().toStdString();

    this->UnLockUI();
    return ret;
}
bool            QtSamplePlayerGui::GetAutomatic                                     ()
{
    return false;
}
void            QtSamplePlayerGui::NotifyMPDDownloadPressed                         (const std::string &url)
{
    for(size_t i = 0; i < this->observers.size(); i++)
        this->observers.at(i)->OnDownloadMPDPressed(url);
}

/* UI Slots */
void            QtSamplePlayerGui::on_button_mpd_clicked                            ()
{
    this->NotifyMPDDownloadPressed(this->GetUrl());
}
void            QtSamplePlayerGui::on_cb_period_currentIndexChanged                 (int index)
{
    if(index == -1 || this->mpd == NULL)
        return; // No Item set

    this->LockUI();

    this->SetAdaptationSetComboBox(mpd->GetPeriods().at(index), ui->cb_audio_adaptationset);
    this->SetAdaptationSetComboBox(mpd->GetPeriods().at(index), ui->cb_video_adaptationset);

    this->NotifySettingsChanged();

    this->UnLockUI();
}
void            QtSamplePlayerGui::on_cb_mpd_currentTextChanged                     (const QString &arg1)
{
    this->ui->lineEdit_mpd->setText(arg1);
}
void            QtSamplePlayerGui::on_cb_video_adaptationset_currentIndexChanged    (int index)
{
    if(index == -1 || this->mpd == NULL)
        return; // No Item set

    this->LockUI();

    IPeriod *period = this->mpd->GetPeriods().at(this->ui->cb_period->currentIndex());

    this->SetRepresentationComoboBox(period->GetAdaptationSets().at(index), this->ui->cb_video_representation);

    this->NotifySettingsChanged();

    this->UnLockUI();
}
void            QtSamplePlayerGui::on_cb_video_representation_currentIndexChanged   (int index)
{
    if(index == -1)
        return; // No Item set

    this->NotifySettingsChanged();
}
void            QtSamplePlayerGui::on_cb_audio_adaptationset_currentIndexChanged    (int index)
{
    if(index == -1 || this->mpd == NULL)
        return; // No Item set

    this->LockUI();

    IPeriod *period = this->mpd->GetPeriods().at(this->ui->cb_period->currentIndex());

    this->SetRepresentationComoboBox(period->GetAdaptationSets().at(index), this->ui->cb_audio_represenation);

    this->NotifySettingsChanged();

    this->UnLockUI();
}
void            QtSamplePlayerGui::on_cb_audio_representation_currentIndexChanged   (int index)
{
    if(index == -1)
        return; // No Item set

    this->NotifySettingsChanged();
}
void            QtSamplePlayerGui::on_button_start_clicked                          ()
{
    this->ui->button_start->setEnabled(false);
    this->ui->button_stop->setEnabled(true);
    for(unsigned int i=0; i < this->observers.size(); i++)
    {
        this->observers[i]->OnStartButtonPressed(this);
    }
}
void            QtSamplePlayerGui::on_button_stop_clicked                           ()
{
    this->ui->button_start->setEnabled(true);
    this->ui->button_stop->setEnabled(false);
    for(unsigned int i=0; i < this->observers.size(); i++)
    {
        this->observers[i]->OnStopButtonPressed(this);
    }
}
