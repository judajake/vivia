/*ckwg +5
 * Copyright 2013 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef __vsEventTreeView_h
#define __vsEventTreeView_h

#include <QTreeView>

#include <vtkType.h>

#include <vtkVgTypeDefs.h>

#include "vsEventStatus.h"

class vsEventTreeModel;
class vsEventTreeSelectionModel;

class QSortFilterProxyModel;

class vsEventTreeView : public QTreeView
{
  Q_OBJECT

public:
  vsEventTreeView(QWidget* parent = 0);
  virtual ~vsEventTreeView();

  void setStatusFilter(vsEventStatus s) { this->viewMode = s; }

  // Reimplemented from QWidget
  virtual void setModel(QAbstractItemModel* m);
  virtual void setSelectionModel(QItemSelectionModel* selectionModel);
  virtual void dropEvent(QDropEvent* event);
  virtual void mousePressEvent(QMouseEvent* event);

  const vsEventTreeSelectionModel* underlyingSelectionModel()
    {
    return this->eventTreeSelectionModel;
    }

signals:
  void jumpToEvent(vtkIdType eventId, bool jumpToEnd);

public slots:
  void hideAllItems();
  void showAllItems();
  void setHiddenItemsShown(bool enable);

  void hideSelectedItems();
  void showSelectedItems();

  void setSelectedItemsRating(vgObjectStatus::enumObjectStatus rating);
  void setSelectedItemsStatus(vsEventStatus status);
  void setSelectedItemsStarred(bool starred);

  void jumpToSelectedStart();
  void jumpToSelectedEnd();

protected slots:
  void itemActivated(const QModelIndex& index);

  void updateRows(const QModelIndex& parent, int start, int end);
  void updateRows(const QModelIndex& start, const QModelIndex& end);

  void updateSelection(const QItemSelection& selected,
                       const QItemSelection& deselected);
  void setCurrentIndex(const QModelIndex& current);

protected:
  vtkIdType eventIdFromIndex(const QModelIndex& index) const;

private:
  Q_DISABLE_COPY(vsEventTreeView)

  vsEventTreeModel* eventTreeModel;
  vsEventTreeSelectionModel* eventTreeSelectionModel;
  QScopedPointer<QSortFilterProxyModel> proxyModel;
  QScopedPointer<QItemSelectionModel> proxySelectionModel;

  bool showHiddenItems;
  vsEventStatus viewMode;
};

#endif
