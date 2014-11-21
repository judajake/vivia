/*ckwg +5
 * Copyright 2013 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef __qtDrawer_h
#define __qtDrawer_h

#include <QWidget>

#include "../Core/qtGlobal.h"

class QGridLayout;

class qtDrawerWidget;
class qtDrawerPrivate;

class QTE_EXPORT qtDrawer : public QWidget
{
  Q_OBJECT
  Q_PROPERTY(ExpanderPolicy expanderPolicy READ expanderPolicy
                                           WRITE setExpanderPolicy)

public:
  enum ExpanderPolicy
    {
    ExpanderAsNeeded = 0,
    ExpanderAlwaysShown = 1
    };

  explicit qtDrawer(qtDrawer* parent, qtDrawer* nextSibling = 0);
  virtual ~qtDrawer();

  qtDrawer* parent();

  virtual void addWidget(QWidget* widget, int col = 0);

  ExpanderPolicy expanderPolicy() const;
  void setExpanderPolicy(ExpanderPolicy);

signals:
  void expandToggled(bool);

public slots:
  void setExpanded(bool);
  virtual void setVisible(bool);
  virtual void setVisibility(bool);

protected:
  QTE_DECLARE_PRIVATE_RPTR(qtDrawer)
  friend class qtDrawerWidget;

  qtDrawer(qtDrawerWidget* container, QGridLayout* layout);

  virtual void addChild(qtDrawer* child, qtDrawer* before = 0);
  virtual void removeChild(qtDrawer* child);
  void setChildVisibility(qtDrawer* child = 0);

  int countDescendants() const;
  void shiftChildrenDown(qtDrawer* afterChild = 0);
  void shiftChildrenUp(qtDrawer* afterChild = 0);
  void shiftDown();
  void shiftUp();
  void shift();

  virtual void clear();

private:
  QTE_DECLARE_PRIVATE(qtDrawer)
  Q_DISABLE_COPY(qtDrawer)
};

#endif
