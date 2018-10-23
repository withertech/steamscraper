/***************************************************************************
 *            attractmode.h
 *
 *  Wed Jun 18 12:00:00 CEST 2017
 *  Copyright 2017 Lars Muldjord
 *  muldjordlars@gmail.com
 ****************************************************************************/
/*
 *  This file is part of skyscraper.
 *
 *  skyscraper is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  skyscraper is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with skyscraper; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
 */

#ifndef ATTRACTMODE_H
#define ATTRACTMODE_H

#include "abstractfrontend.h"

class AttractMode : public AbstractFrontend
{
  Q_OBJECT

public:
  AttractMode();
  void checkReqs() override;
  bool skipExisting(QList<GameEntry> &gameEntries, QSharedPointer<Queue> queue) override;
  void assembleList(QString &finalOutput, const QList<GameEntry> &gameEntries, int maxDescLength) override;
  bool canSkip() override;
  bool loadOldGameList(const QString &gameListFileString) override;
  void preserveFromOld(GameEntry &entry) override;
  QString getGameListFileName() override;
  QString getInputFolder() override;
  QString getGameListFolder() override;
  QString getCoversFolder() override;
  QString getScreenshotsFolder() override;
  QString getWheelsFolder() override;
  QString getMarqueesFolder() override;
  QString getVideosFolder() override;

private:
  QString getMediaTypeFolder(QString type);
  bool checkEmulatorFile(QString fileName);
  void setCfgLine(QString filename, QByteArray key, QByteArray content);

};

#endif // ATTRACTMODE_H
