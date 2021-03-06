/*ckwg +5
 * Copyright 2013 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef __vtkVgImageIcon_h
#define __vtkVgImageIcon_h

#include "vtkBalloonRepresentation.h"
#include "vtkSmartPointer.h"

#include <vgExport.h>

class vtkJPEGReader;

class VTKVG_CORE_EXPORT vtkVgImageIcon : public vtkBalloonRepresentation
{
public:

  // Description:
  // Standard VTK functions.
  static vtkVgImageIcon* New();
  vtkTypeMacro(vtkVgImageIcon, vtkBalloonRepresentation);
  virtual void PrintSelf(ostream& os, vtkIndent indent);

  void SetPosition(int x, int y)
    {
    if (x != this->StartEventPosition[0] ||
        y != this->StartEventPosition[0])
      {
      this->StartEventPosition[0] = x;
      this->StartEventPosition[1] = y;
      this->StartEventPosition[2] = 0.0;
      this->Modified();
      }
    }
  void SetPosition(int pos[2])
    {
    this->SetPosition(pos[0], pos[1]);
    }

  // Description:
  // Specify file name for the image file. If the data is stored in
  // multiple files, then use SetFileNames or SetFilePrefix instead.
  virtual void SetFileName(const char*);
  vtkGetStringMacro(FileName);

  // Description:
  // Fix bug in vtkBalloonRepresentation.
  virtual void ReleaseGraphicsResources(vtkWindow* w);

protected:
  // Description:
  // Constructor / Destructor.
  vtkVgImageIcon();
  ~vtkVgImageIcon();

  char* FileName;

private:
  vtkVgImageIcon(const vtkVgImageIcon&); // Not implemented.
  void operator=(const vtkVgImageIcon&);  // Not implemented.

  vtkSmartPointer<vtkJPEGReader> JPEGReader;
};

#endif // __vtkVgImageIcon_h
