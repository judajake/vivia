/*ckwg +5
 * Copyright 2013 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef __vpCreateEventDialog_h
#define __vpCreateEventDialog_h

#include <QDialog>

#include <qtGlobal.h>

class vpCreateEventDialogPrivate;
class vpViewCore;

class vtkVgTimeStamp;

class vpCreateEventDialog : public QDialog
{
  Q_OBJECT

public:
  vpCreateEventDialog(vpViewCore* coreInstance, int session,
                      QWidget* parent = 0, Qt::WindowFlags flags = 0);
  ~vpCreateEventDialog();

  void initialize();

signals:
  void eventCreated(int id);

public slots:
  void addTrack(int trackId, int session);

  virtual void accept();
  virtual void reject();

protected slots:
  void setEventType(int typeIndex);

  void startEventHere();
  void endEventHere();

  void moveTrackUp();
  void moveTrackDown();
  void removeTrack();

protected:
  QTE_DECLARE_PRIVATE_RPTR(vpCreateEventDialog)

  void updateEventTimeRange();
  void updateTrackTimeRanges();

  void validate();

  static vtkVgTimeStamp clamp(const vtkVgTimeStamp& val,
                              const vtkVgTimeStamp& a,
                              const vtkVgTimeStamp& b);

private:
  QTE_DECLARE_PRIVATE(vpCreateEventDialog)
};

#endif // __vpCreateEventDialog_h
