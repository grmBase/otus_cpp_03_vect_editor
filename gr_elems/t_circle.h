//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "interfaces/i_item.h"
//---------------------------------------------------------------------------
class t_canvas;
//---------------------------------------------------------------------------


namespace tst
{


class t_circle : public i_item
{
  public:

    t_circle(t_canvas* ap_canvas)
      : m_dbl_x(0),
      m_dbl_y(0),
      m_dbl_radius(1),
      m_p_canvas(ap_canvas)
    {
    };

  private:

    [[maybe_unused]]double m_dbl_x;
    [[maybe_unused]]double m_dbl_y;
    [[maybe_unused]]double m_dbl_radius;

    [[maybe_unused]]t_canvas* m_p_canvas;

};


}
//---------------------------------------------------------------------------
