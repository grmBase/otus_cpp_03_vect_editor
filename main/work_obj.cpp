//---------------------------------------------------------------------------
#include "work_obj.h"
//---------------------------------------------------------------------------


void t_work_obj::on_add_elem()
{
  if (!m_sp_engine) {
    // сказать что документ не открыт
    return;
  }

  m_sp_engine->on_click_add_elem(std::string("some_type_of_figure"));
}
//---------------------------------------------------------------------------


void t_work_obj::on_del_elem()
{
  if (!m_sp_engine) {
    // сказать что документ не открыт
    return;
  }

  m_sp_engine->on_click_del(1, 1);
}
//---------------------------------------------------------------------------


void t_work_obj::on_load_from_file()
{

  if (m_sp_engine) {
    // тут спросить будем ли сохранять?
  }

  m_sp_engine.reset(new tst::t_engine(mp_canvas, m_sp_factory.get()));
  m_sp_engine->load_from_file(std::string("/user/home/doc/document1.svg"));
}
//---------------------------------------------------------------------------


void t_work_obj::on_save_to_file()
{
  if (!m_sp_engine) {
    // сказать что документ не открыт
    return;
  }

  m_sp_engine->save_to_file(std::string("/user/home/doc/document2.svg"));
};
//---------------------------------------------------------------------------
