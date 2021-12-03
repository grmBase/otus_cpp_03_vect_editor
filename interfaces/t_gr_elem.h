//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <memory> //unique_ptr
//---------------------------------------------------------------------------
#include "interfaces/i_item.h"  // реализация прям тут же
//---------------------------------------------------------------------------



namespace tst
{


// Объект "место" под любой графический элемент
class t_gr_elem
{
  public:

    t_gr_elem(i_item* apItem)
      :msp_final_figure(apItem) {};

    t_gr_elem(double adbl_left, double adbl_top, double adbl_width, double adbl_height);

  
  private:

    // координаты внешней рамки вокруг примитива
    double m_dbl_left = 0;
    double m_dbl_top = 0;
    double m_dbl_width = 0;
    double m_dbl_height = 0;

    // здесь храним реальный объект
    std::unique_ptr<i_item> msp_final_figure = nullptr;
    
};


}
//---------------------------------------------------------------------------
