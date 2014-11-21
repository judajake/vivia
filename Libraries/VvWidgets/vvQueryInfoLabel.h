/*ckwg +5
 * Copyright 2013 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef __vvQueryInfoLabel_h
#define __vvQueryInfoLabel_h

#include <QLabel>

#include <qtGlobal.h>

#include <vgExport.h>

#include <vvQueryResult.h>

#include <vvQueryInstance.h>

class vvQueryInfoLabelPrivate;

class VV_WIDGETS_EXPORT vvQueryInfoLabel : public QLabel
{
  Q_OBJECT
  Q_PROPERTY(QString errorText READ errorText WRITE setErrorText)

public:
  explicit vvQueryInfoLabel(QWidget* parent = 0);
  virtual ~vvQueryInfoLabel();

  QString errorText() const;
  QList<vvTrack> tracks() const;
  QList<vvDescriptor> descriptors() const;

public slots:
  void setErrorText(QString);

  void setQuery(vvSimilarityQuery);
  void setQuery(vvQueryInstance);

  void setResult(vvQueryResult);

  void setTracks(QList<vvTrack>);
  void setTracks(std::vector<vvTrack>);

  void setDescriptors(QList<vvDescriptor>);
  void setDescriptors(std::vector<vvDescriptor>);

  void clearData();

  virtual void showTrackInfoDialog();
  virtual void showDescriptorInfoDialog();

protected slots:
  virtual void showInfoDialog(QString uri);

protected:
  QTE_DECLARE_PRIVATE_RPTR(vvQueryInfoLabel)

  void updateText();
  virtual void changeEvent(QEvent*);

private:
  QTE_DECLARE_PRIVATE(vvQueryInfoLabel)
  Q_DISABLE_COPY(vvQueryInfoLabel)
};

#endif
