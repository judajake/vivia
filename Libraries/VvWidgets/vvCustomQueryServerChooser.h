/*ckwg +5
 * Copyright 2013 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef __vvCustomQueryServerChooser_h
#define __vvCustomQueryServerChooser_h

#include <qtGlobal.h>

#include <vgExport.h>

#include "vvAbstractQueryServerChooser.h"

class QTreeWidgetItem;

class vvCustomQueryServerChooserPrivate;

class VV_WIDGETS_EXPORT vvCustomQueryServerChooser
  : public vvAbstractQueryServerChooser
{
  Q_OBJECT

public:
  vvCustomQueryServerChooser(QWidget* parent = 0);
  virtual ~vvCustomQueryServerChooser();

  virtual QUrl uri() const;
  virtual void setUri(QUrl);

protected slots:
  void updateUri();
  void addArgument(QString name = QString(), QString value = QString());
  void removeArgument();
  void moveArgumentUp();
  void moveArgumentDown();
  void updateArgumentButtons();

protected:
  QTE_DECLARE_PRIVATE_RPTR(vvCustomQueryServerChooser)

  void setSelectedArgument(QTreeWidgetItem*);

private:
  QTE_DECLARE_PRIVATE(vvCustomQueryServerChooser)
  Q_DISABLE_COPY(vvCustomQueryServerChooser)
};

#endif
