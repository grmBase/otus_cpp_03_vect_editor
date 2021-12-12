//---------------------------------------------------------------------------
#include <vector>
//---------------------------------------------------------------------------
#include "modules/t_engine.h"
#include "interfaces/t_factory.h"

#include "interfaces/i_marshal.h"
//---------------------------------------------------------------------------


// Запрос добавить элемент из меню, тулбара, по шорткату:
void tst::t_engine::on_click_add_elem(const std::string& a_str_elem_type)
{
  tst::i_item* pObject = m_p_factory->create(a_str_elem_type, m_p_canvas);

  //t_gr_elem tmp(pObject);

  std::unique_ptr<tst::i_item> tmp{ pObject };
  m_vec_elems.push_back(std::move(tmp));

};
//---------------------------------------------------------------------------


// запрос на удалить элемент на который сейчас указывает мышка
void tst::t_engine::on_click_del([[maybe_unused]]int an_x_pos, [[maybe_unused]]int an_y_pos)
{
  // here we should find somehow which elem is pointed by mouse.

  m_vec_elems.erase(m_vec_elems.begin() + 33);
};
//---------------------------------------------------------------------------


// запрос на сохранение текущего документа в файл
int tst::t_engine::save_to_file([[maybe_unused]] const std::string& a_str_file_name)
{

  std::string str_stream;


  tst::i_marshal* p_marshall = nullptr;

  for([[maybe_unused]]auto& curr_elem : m_vec_elems) {


    p_marshall = dynamic_cast<tst::i_marshal*>(curr_elem.get());
    if (!p_marshall) {
      // исключение? просто skip? по вкусу
    }

    p_marshall->save_to_stream();
  }

  return 0;
};
//---------------------------------------------------------------------------


// запрос на зачитывание документа с диска. Сначал очищает всё, потом загружает
int tst::t_engine::load_from_file([[maybe_unused]]const std::string& a_str_file_name)
{


  // all should be clear before load
  clear();


  /*
    open file, load whole contents to str_stream:
  */
  std::string str_stream;
  size_t un_file_size = 33; // got after reading whole content of file

  size_t un_position = 0;

  tst::i_marshal* p_marshall = nullptr;
  while(un_position < un_file_size) 
  {

    std::string strCurrType;

    // тут как-то вычитали из потока:
    //oustream >> strCurrType;

    std::unique_ptr<i_item> sp_item(m_p_factory->create(strCurrType, m_p_canvas));
    if(!sp_item) {
        // return, continue, exception по вкусу
    }

    p_marshall = dynamic_cast<tst::i_marshal*>(sp_item.get());
    if (!p_marshall) {
      // return, continue, exception по вкусу
    }

    p_marshall->load_from_stream(/*текущий поток*/);

    // сохраняем в списке элементов
    m_vec_elems.push_back(std::move(sp_item));

  }

  return 0;
};
//---------------------------------------------------------------------------


// реализуем обработчик GUI-ёв на перерисовку
void tst::t_engine::on_repaint()
{
  /* Получаем координаты области, которую нужно перерисовать, далее
  * по какому-то алгоритму ищем те элементы, которые в этой области находятся
  * вызываем у них repaint() в историческом порядке их расположения
  */
};
//---------------------------------------------------------------------------
