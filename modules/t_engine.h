//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include "interfaces/t_gr_elem.h"  // 
//---------------------------------------------------------------------------
class t_canvas;
//---------------------------------------------------------------------------


namespace tst
{
  class t_factory;


// Объект "графический движок"
class t_engine
{
  public:

    t_engine(t_canvas* ap_canvas, tst::t_factory* ap_factory)
    :m_p_canvas(ap_canvas),
     m_p_factory(ap_factory)
    {
    };

    // Запрос добавить элемент из меню, тулбара, по шорткату:
    void on_click_add_elem(const std::string& a_str_elem_type);

    // запрос на удалить элемент на который сейчас указывает мышка
    void on_click_del(int an_x_pos, int an_y_pos);

    // запрос на сохранение текущего документа в файл
    int save_to_file(const std::string& a_str_file_name);

    // запрос на зачитывание документа с диска. Сначал очищает всё, потом загружает
    int load_from_file(const std::string& a_str_file_name);

    // реализуем обработчик GUI-ёв на перерисовку
    void on_repaint();

    void clear() { 
      m_vec_elems.clear(); 
      // some other manipulation to make it in default state.
      // todo: the better is to kill this instance and recreate it from scratch from
      // outer space
    };


  
  private:

    // viewport - то что сейчас видим. Для всякого зумирования, скрола
    double m_dbl_left = 0;
    double m_dbl_top = 0;
    double m_dbl_width = 0;
    double m_dbl_height = 0;

    // коэффициент пересчёта координат документа в экранные. Возможно может быть
    // разным для x & y, но для простого примера и так будет норм
    double m_dbl_ratio = 1;

    // список элементов расположенных на документе
    std::vector<std::unique_ptr<t_gr_elem>> m_vec_elems;

    // Канва основного GUI документа, на которой рисуем
    // скорее всего не влаедеем ею, т.к. "окно" скорее всего будут удалять после
    // удаления движка
    t_canvas* m_p_canvas;

    tst::t_factory* m_p_factory;
    
};


}
//---------------------------------------------------------------------------