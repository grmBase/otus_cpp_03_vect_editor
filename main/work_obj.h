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


class t_work_obj
{
  public:

    t_work_obj(t_canvas* ap_canvas)
      :m_sp_factory(new tst::t_factory()),
      m_sp_engine(new tst::t_engine(ap_canvas, m_sp_factory.get()))
    { 
    }


    void on_add_elem();
    void on_del_elem();
    void on_load_from_file();
    void on_save_to_file();

  private:
    std::unique_ptr<tst::t_factory> m_sp_factory;
    std::unique_ptr<tst::t_engine> m_sp_engine;

};
//---------------------------------------------------------------------------


#endif
