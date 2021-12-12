//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "interfaces/i_item.h"     // наследуемся
#include "interfaces/i_marshal.h"  // наследуемся
//---------------------------------------------------------------------------
class t_canvas;
//---------------------------------------------------------------------------


namespace tst
{


class t_circle : 
  public i_item,
  public i_marshal
{

  public:

    t_circle(t_canvas* ap_canvas)
      : m_dbl_x(0),
      m_dbl_y(0),
      m_dbl_radius(1),
      m_p_canvas(ap_canvas)
    {
    };



    // сохраняем объект в поток:
    void save_to_stream(/*здесь какой-то поток. Бинарный, json...*/) const
    {
      /*
         stream.put(m_dbl_x);
         stream.put(m_dbl_y);
         ....
      */
    };

    // загружаем объект из потока
    void load_from_stream(/*здесь какой-то поток. Бинарный, json...*/)
    {
      /*
         m_dbl_x = stream.get();
         m_dbl_y = stream.get();
         ....
      */
    };




  private:

    [[maybe_unused]]double m_dbl_x;
    [[maybe_unused]]double m_dbl_y;
    [[maybe_unused]]double m_dbl_radius;

    [[maybe_unused]]t_canvas* m_p_canvas;

};


}
//---------------------------------------------------------------------------
