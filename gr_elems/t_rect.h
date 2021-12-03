//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "interfaces/i_item.h"
//---------------------------------------------------------------------------
class t_canvas;
//---------------------------------------------------------------------------


namespace tst
{


class t_rect : public i_item
{
  public:

    t_rect(t_canvas* ap_canvas)
    : m_p_canvas(ap_canvas) 
    {
    };

  private:

    double m_dbl_x = 0;
    double m_dbl_y = 0;
    double m_dbl_width = 20;
    double m_dbl_height = 10;

    t_canvas* m_p_canvas;

};


}
//---------------------------------------------------------------------------