//---------------------------------------------------------------------------
#ifndef __work_obj_h__
#define __work_obj_h__
//---------------------------------------------------------------------------
#include <memory> //unique_ptr
//---------------------------------------------------------------------------
#include "modules/t_engine.h"
#include "interfaces/t_factory.h"
//---------------------------------------------------------------------------
class t_canvas;
//---------------------------------------------------------------------------


/*!
    Class combination of engine, document and reference to GUI canvas
*/
class t_work_obj
{
  public:

    t_work_obj(t_canvas* ap_canvas)
      :mp_canvas(ap_canvas),
      m_sp_factory(new tst::t_factory()),
      m_sp_engine(new tst::t_engine(ap_canvas, m_sp_factory.get()))
    { 
    }


    void on_add_elem();
    void on_del_elem();
    void on_load_from_file();
    void on_save_to_file();

  private:

    // фабрика всяких делегаторов, подгружаемых объектов. Она будет
    // едина для любого числа открытых документов
    std::unique_ptr<tst::t_factory> m_sp_factory;

    // Движок или "один загруженный документ". Редактор будет у нас с возможностью подгрузить только один документ
    std::unique_ptr<tst::t_engine> m_sp_engine;

    // где всё рисуем
    t_canvas* mp_canvas;

};
//---------------------------------------------------------------------------


#endif
